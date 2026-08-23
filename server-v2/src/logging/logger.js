/**
 * Structured logging: one JSON object per line, on stdout.
 *
 * systemd-journald captures stdout, so a process managed by a unit file needs no
 * log file, no rotation and no write permissions anywhere. One object per line
 * survives `journalctl -o cat | jq` without a parser.
 *
 * Every record carries a timestamp, a level, the service that emitted it and an
 * event name. Service loggers are children so a subsystem cannot forget to say
 * which one it is.
 */

const LEVELS = Object.freeze({ debug: 10, info: 20, warn: 30, error: 40 });

function safeValue(value, depth = 0) {
  if (value == null) return value;
  if (Buffer.isBuffer(value)) return value.toString('hex');
  if (value instanceof Error) {
    return { name: value.name, message: value.message, code: value.code };
  }
  if (typeof value === 'bigint') return value.toString();
  if (Array.isArray(value)) {
    return depth >= 4 ? '[array]' : value.slice(0, 64).map((item) => safeValue(item, depth + 1));
  }
  if (typeof value === 'object') {
    if (depth >= 4) return '[object]';
    const output = {};
    for (const [key, item] of Object.entries(value)) {
      output[key] = safeValue(item, depth + 1);
    }
    return output;
  }
  return value;
}

export function createLogger({
  level = 'info',
  service = 'pal-server-v2',
  write = (line) => process.stdout.write(line),
  clock = () => new Date().toISOString()
} = {}) {
  const threshold = LEVELS[level];
  if (threshold == null) {
    throw new TypeError(`unknown log level ${JSON.stringify(level)}`);
  }

  function emit(recordLevel, event, fields) {
    if (LEVELS[recordLevel] < threshold) return;
    const record = {
      time: clock(),
      level: recordLevel,
      service,
      event,
      ...safeValue(fields ?? {})
    };
    let line;
    try {
      line = JSON.stringify(record);
    } catch {
      line = JSON.stringify({
        time: record.time,
        level: 'error',
        service,
        event: 'log-serialization-failed',
        originalEvent: event
      });
    }
    write(`${line}\n`);
  }

  return {
    level,
    service,
    debug: (event, fields) => emit('debug', event, fields),
    info: (event, fields) => emit('info', event, fields),
    warn: (event, fields) => emit('warn', event, fields),
    error: (event, fields) => emit('error', event, fields),
    child: (childService) => createLogger({
      level,
      service: `${service}.${childService}`,
      write,
      clock
    })
  };
}
