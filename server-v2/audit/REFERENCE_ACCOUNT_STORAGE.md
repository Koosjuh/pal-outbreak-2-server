# Reference server account storage comparison

Date: 2026-07-31

## Conclusion

The bundled BioServer Docker reference uses **MySQL**, not PostgreSQL. Its web application hashes the
submitted password with unsalted MD5, stores the 32-character hex digest in `users.passwd`, and checks
login by comparing that digest in SQL. V2 does not copy this storage design.

## Reference evidence

- MySQL JDBC URL:
  `references/bioserver/bioserver-docker-2.4.1/bioserver-docker-2.4.1/bioserv2/bioserver/Database.java:62`
- MySQL schema bootstrap:
  `references/bioserver/bioserver-docker-2.4.1/bioserver-docker-2.4.1/docker/vars/mysql/2_init_db.sh`
- `users(userid varchar(14), passwd varchar(32))`: same script, lines 44-47.
- Password conversion to `md5($value)`:
  `references/bioserver/bioserver-docker-2.4.1/bioserver-docker-2.4.1/web/src/Domain/Outbreak/ValueObjects/Password.php:22`
- Registration inserts the converted value with a prepared statement:
  `references/bioserver/bioserver-docker-2.4.1/bioserver-docker-2.4.1/web/src/Application/Actions/Outbreak/Handlers/RegisterHandler.php:25`
- Login compares `userid` and the converted password value:
  `references/bioserver/bioserver-docker-2.4.1/bioserver-docker-2.4.1/web/src/Application/Actions/Outbreak/Handlers/LoginHandler.php:25`

The reference schema also persists:

- `sessions`: user, IP/port, eight-character session id, game session, area, room, slot, state, and
  game id;
- `hnpairs`: user id, six-character handle, and nickname;
- `motd`: versioned message-of-the-day records.

Room objects and their passwords are held by the Java server model; they are not account credentials
and must not be conflated with `users.passwd`.

## V2 current design

V2 currently uses a single SQLite file, `pal-server-v2.sqlite3`, through an isolated repository
boundary:

- `server-v2/src/database/sqlite-database.js`
- `server-v2/src/database/secure-account-repository.js`
- `server-v2/src/database/sqlite-session-registry.js`
- `server-v2/src/database/production-repositories.js`

Account authentication uses scrypt with a random per-account salt. The current PAL UDP compatibility
design also needs the server to recover the exact client secret during registration, so V2 stores a
second copy encrypted with AES-256-GCM under a deployment master key. The database does not contain
the plaintext secret. This protects the stored value against passive database-file disclosure when
the deployment key is held separately; it does not protect against compromise of the running server
or its key. Key rotation, retention, backup encryption, and a written threat model remain production
requirements.

Current persisted V2 entities:

- accounts;
- authenticated HTTP/LBS sessions.

Not yet added:

- handle/nickname collections beyond the account's current handle;
- durable area/room/slot/gameplay membership;
- MOTD/admin content;
- audit/ban/moderation state.

Those tables must be added with the corresponding proven PAL vertical slices, not copied blindly from
the KDDI-based reference protocol.

## SQLite versus PostgreSQL/MySQL

For the planned topology of one Raspberry Pi and one authoritative server process, SQLite is the
current engineering choice because it avoids another service and offers an atomic single-file backup
boundary. That choice is not yet production-approved: WAL recovery, corruption, power-loss, concurrent
access, backup, and restore tests are still required.

PostgreSQL becomes the stronger operational candidate if the service will run multiple application
instances, needs remote administration/reporting, or exceeds the single-writer topology. MySQL is
needed to run this reference stack unchanged. No decoded PAL packet field or captured transaction in
the current evidence identifies a database engine, but backend interchangeability still requires a
repository-contract test; therefore it remains an architectural inference, not a protocol fact.

Current deployment blocker: the Pi runs Node 20.19.2, while this V2 implementation imports
`node:sqlite`. Deployment therefore requires a supported newer Node runtime, a maintained SQLite
driver behind the same repository interface, or a PostgreSQL/MySQL adapter. This must be resolved and
restore-tested before V2 is called production-ready.

## Confidence

- Reference database engine and schema: Verified from reference source.
- Reference unsalted-MD5 password storage: Verified from reference source.
- V2 SQLite/scrypt/AES-256-GCM implementation: Verified from V2 source and local tests.
- Database-backend independence from client-visible behavior: Probable architectural inference; no
  current wire evidence names an engine, but a backend-contract test is still missing.
- SQLite production suitability: Unknown until the operational tests and threat model above exist.

## Mandatory review

The second opinion agreed with the factual MySQL/MD5 and V2 implementation comparison, but rejected
an absolute production-security or backend-independence conclusion. This revision narrows AES-GCM's
claim to its passive-at-rest threat boundary and explicitly records the missing threat model,
key-management, backend-contract, and restore evidence.
