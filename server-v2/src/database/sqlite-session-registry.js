import crypto from 'node:crypto';

export class SqliteSessionRegistry {
  constructor(
    database,
    {
      clock = () => Date.now(),
      idFactory = () => String(crypto.randomInt(10_000_000, 100_000_000)),
      ttlMs = 60 * 60 * 1000
    } = {}
  ) {
    this.database = database;
    this.connection = database.connection;
    this.clock = clock;
    this.idFactory = idFactory;
    this.ttlMs = ttlMs;
  }

  create({ account, remoteAddress }) {
    let connectionId;
    do {
      connectionId = this.idFactory();
    } while (
      this.connection
        .prepare('SELECT 1 FROM sessions WHERE connection_id = ?')
        .get(connectionId)
    );

    const now = this.clock();
    this.connection
      .prepare(`
        INSERT INTO sessions (
          connection_id, userid, remote_address, created_at_ms, updated_at_ms,
          expires_at_ms, lobby_provisioned_at_ms
        ) VALUES (?, ?, ?, ?, ?, ?, NULL)
      `)
      .run(
        connectionId,
        account.userid,
        String(remoteAddress ?? ''),
        now,
        now,
        now + this.ttlMs
      );
    return this.get(connectionId);
  }

  get(connectionId) {
    const id = String(connectionId ?? '');
    const row = this.connection
      .prepare(`
        SELECT s.*, a.handle AS display_name
        FROM sessions s
        JOIN accounts a ON a.userid = s.userid
        WHERE s.connection_id = ?
      `)
      .get(id);
    if (!row) return null;
    if (row.expires_at_ms <= this.clock()) {
      this.connection.prepare('DELETE FROM sessions WHERE connection_id = ?').run(id);
      return null;
    }
    return {
      connectionId: row.connection_id,
      userid: row.userid,
      displayName: row.display_name,
      remoteAddress: row.remote_address,
      createdAtMs: row.created_at_ms,
      updatedAtMs: row.updated_at_ms,
      expiresAtMs: row.expires_at_ms,
      lobbyProvisionedAtMs: row.lobby_provisioned_at_ms
    };
  }

  markLobbyProvisioned(connectionId, remoteAddress) {
    const existing = this.get(connectionId);
    if (!existing) return null;
    const now = this.clock();
    this.connection
      .prepare(`
        UPDATE sessions
        SET remote_address = ?, updated_at_ms = ?, expires_at_ms = ?,
            lobby_provisioned_at_ms = ?
        WHERE connection_id = ?
      `)
      .run(String(remoteAddress ?? ''), now, now + this.ttlMs, now, existing.connectionId);
    return this.get(existing.connectionId);
  }

  purgeExpired() {
    return this.connection
      .prepare('DELETE FROM sessions WHERE expires_at_ms <= ?')
      .run(this.clock()).changes;
  }
}

