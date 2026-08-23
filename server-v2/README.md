# PAL Outbreak File #2 server v2

This is the second, corpus-driven server implementation. It is intentionally isolated from
`server/`; the existing compatibility server remains available and unchanged.

Authority order:

1. PAL `SLES_533.19` decoded client code and runtime captures.
2. Findings that reconcile both sources.
3. The JP Bioserver only for high-level room/session semantics. Its KDDI wire format is never used as
   evidence for PAL SN@P bytes.
4. Existing server behavior only when a reproducible PAL test has validated it.

Unknown fields remain unknown. Application features are added as vertical slices and are not marked
complete without deterministic fixtures plus a real-client run where the repository harness supports
one.

## Current slice

The first slice is the SN@P UDP transport boundary:

- 16-byte segment header and fixed observed trailer.
- Reliable, ACK, set, data, and aggregate flags.
- Low-10-bit inner length.
- Selector/opcode split.
- Source token, sequence, and acknowledgment fields.
- Reliable receive reordering and one shared outbound sequence allocator.
- Byte-exact tests built from repository wire evidence.

Run:

```text
cd server-v2
npm test
```

Primary evidence:

- `reverse-engineering/network/functions/transport/001e180c_snap_packet_enqueue_send.md`
- `reverse-engineering/network/functions/transport/001d6988_snap_recv_accept_reorder_gate.md`
- `reverse-engineering/network/functions/transport/001d63b8_snap_build_ack_header.md`
- `docs/findings/protocol/_archive/snap-recvbase-delivery-contract-RE-2026-06-28.md`

