import crypto from 'node:crypto';

export class SessionRegistry {
  constructor(
    jsonFile,
    {
      clock = () => Date.now(),
      idFactory = () => String(crypto.randomInt(10_000_000, 100_000_000)),
      ttlMs = 60 * 60 * 1000
    } = {}
  ) {
    this.jsonFile = jsonFile;
    this.clock = clock;
    this.idFactory = idFactory;
    this.ttlMs = ttlMs;
    const document = this.jsonFile.read();
    if (document.schemaVersion !== 1 || typeof document.sessions !== 'object') {
      throw new Error('unsupported or malformed session store');
    }
  }

  static emptyDocument() {
    return { schemaVersion: 1, sessions: {} };
  }

  create({ account, remoteAddress }) {
    const document = this.jsonFile.read();
    let connectionId;
    do {
      connectionId = this.idFactory();
    } while (document.sessions[connectionId]);

    const now = this.clock();
    const session = {
      connectionId,
      userid: account.userid,
      displayName: account.displayName,
      remoteAddress,
      createdAtMs: now,
      updatedAtMs: now,
      expiresAtMs: now + this.ttlMs,
      lobbyProvisionedAtMs: null
    };
    document.sessions[connectionId] = session;
    this.jsonFile.replace(document);
    return { ...session };
  }

  get(connectionId) {
    const document = this.jsonFile.read();
    const session = document.sessions[String(connectionId ?? '')];
    if (!session) return null;
    if (session.expiresAtMs <= this.clock()) {
      delete document.sessions[session.connectionId];
      this.jsonFile.replace(document);
      return null;
    }
    return { ...session };
  }

  markLobbyProvisioned(connectionId, remoteAddress) {
    const document = this.jsonFile.read();
    const session = document.sessions[String(connectionId ?? '')];
    if (!session || session.expiresAtMs <= this.clock()) return null;

    const now = this.clock();
    session.remoteAddress = remoteAddress;
    session.lobbyProvisionedAtMs = now;
    session.updatedAtMs = now;
    session.expiresAtMs = now + this.ttlMs;
    this.jsonFile.replace(document);
    return { ...session };
  }
}

