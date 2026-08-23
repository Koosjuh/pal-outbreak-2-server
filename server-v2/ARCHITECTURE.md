# Server v2 architecture and evidence policy

V2 is a ground-up PAL server. It does not import V1 protocol handlers.

## Authority

1. Original PAL `SLES_533.19` instructions and decoded overlays/modules.
2. PAL packet captures and runtime state observations.
3. Conclusions supported by both sources.
4. The JP Bioserver solely for semantic responsibilities such as ownership and broadcast audience.
5. V1 solely as a candidate implementation or source of recorded fixtures.

Decompiler-generated names and human labels are not protocol evidence. Every field implemented by V2
must trace to reads, writes, comparisons, masks, call sites, or a captured PAL packet. Unknown bytes
stay unknown.

## Unknown-field stop rule

When a required behavior is unknown:

1. Stop that vertical slice at the unknown boundary.
2. Record the exact missing field, branch, function, executable/module, and evidence conflict.
3. Return to raw decompilation and disassembly.
4. Add a deterministic fixture for the resolved behavior.
5. Resume implementation only after the evidence register is updated.

Other independent, proven slices may continue. No placeholder response is promoted to production.

## Standalone service boundary

V2 will provide:

- Optional authoritative DNS for the configured PAL service names.
- DNAS-compatible TLS/application exchange.
- HTTP account creation, login, and LBS provisioning.
- TCP lobby/session service.
- SN@P UDP multiplayer service.
- Gameplay-session and in-game synchronization services proven by the corpus.
- Persistent accounts, sessions, areas, rooms, members, rules, and recovery metadata.
- Health checks, structured logs, graceful shutdown, service definitions, backup, and restore tools.

The existing `server/` tree remains runnable and unchanged. V2 receives separate entry points, data
directories, configuration, tests, and deployment units.

## Completion criterion

V2 is production-ready only after a fresh deployment can complete, with reproducible evidence:

boot → DNAS → account create/login → lobby → two-client room create/join → roster/rules/ready →
game start → gameplay synchronization → leave/disconnect/reconnect → clean shutdown/restart.

