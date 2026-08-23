# EE↔IOP RPC service map (network stack)

The EE game reaches the IOP-side network module (sockets/TCP/DNS/DNAS) via Sony SIF RPC. These are the
EE-side stubs (now in the corpus); the IOP handlers live in separate `.irx` module images (not loaded).

| RPC service / fno | EE stub | Role (reconstructed) | Conf |
|---|---|---|---|
| 0x80000592 | net_rpc_init_term (0x1010a8) | master init/terminate; mode 5 = teardown | High |
| 0x80000593 | net_rpc_bind_svc593 (0x100e88) | bind channel B | Medium |
| 0x80000595 | net_rpc_bind_svc595 (0x100b70) | bind/readiness gate | Medium |
| 0x80000597 | net_rpc_resolve_request (0x100838) | string→0x24 result (resolve/DNAS) | Medium |
| 0x8000059a | net_rpc_ctl_svc59a (0x101388) | control (fallback) | Medium |
| 0x8000059c | net_rpc_ctl_svc59c (0x101580) | control (preferred, retry-bound) | High |
| 0x80000400 fno 0xfe | netlib_init_version_gate (0x1f58b8) | IOP netlib init; version gates 0x20a/0x20e | High |
| 0x80001316 | dbcman_ctl_0x316 (0x17f568) | dbcman socket control | High |
| 0x80001317 | dbcman_ctl_0x317 (0x17f5d8) | dbcman socket control | High |
| 0x80001318 | dbcman_transfer_0x318 (0x17f6d0) | bidirectional transfer (send/recv) | High |
| 0x8000131d | dbcman_set_pair_0x31d (0x17f648) | set value pair (mode 2) | High |
| (0x319 transact / 0x31b send_data2) | dbcman family | send/transact (per strings) | Medium |
| SIF core: cmd 0x80000009/0a | sif_rpc_bind/call (0x115a98/115c68) | generic SIF RPC bind/call | Medium |

**dbcman** = libdbc/sceDbc, the IOP socket-RPC server (`sceDbcCreateSocket`/`SendData2`/…). **Avetcp** =
the TCP/IP stack it fronts. The private server never reimplements these — the client's socket plumbing —
it only speaks the SN@P/app wire protocol. Kept for completeness + DNAS-bypass understanding.
