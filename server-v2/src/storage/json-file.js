import fs from 'node:fs';
import path from 'node:path';

/**
 * Small synchronous JSON persistence primitive.
 *
 * Protocol handlers remain deterministic and single-process. Writes use same-directory
 * write-then-rename so a process interruption cannot leave a partially written JSON document.
 */
export class JsonFile {
  constructor(filePath, { createDefault }) {
    if (!filePath) throw new Error('filePath is required');
    if (typeof createDefault !== 'function') throw new Error('createDefault must be a function');
    this.filePath = path.resolve(filePath);
    this.createDefault = createDefault;
    this.value = this.#load();
  }

  #load() {
    try {
      return JSON.parse(fs.readFileSync(this.filePath, 'utf8'));
    } catch (error) {
      if (error.code !== 'ENOENT') {
        throw new Error(`cannot read JSON store ${this.filePath}: ${error.message}`, {
          cause: error
        });
      }
      return this.createDefault();
    }
  }

  read() {
    return structuredClone(this.value);
  }

  replace(value) {
    const directory = path.dirname(this.filePath);
    fs.mkdirSync(directory, { recursive: true });

    const temporaryPath = `${this.filePath}.${process.pid}.tmp`;
    const serialized = `${JSON.stringify(value, null, 2)}\n`;
    try {
      fs.writeFileSync(temporaryPath, serialized, { encoding: 'utf8', mode: 0o600 });
      fs.renameSync(temporaryPath, this.filePath);
    } finally {
      try {
        fs.unlinkSync(temporaryPath);
      } catch (error) {
        if (error.code !== 'ENOENT') throw error;
      }
    }
    this.value = structuredClone(value);
    return this.read();
  }
}

