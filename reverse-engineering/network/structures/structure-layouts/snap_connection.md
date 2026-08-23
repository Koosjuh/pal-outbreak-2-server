# struct snap_connection  (SN@P reliable UDP connection object)

| field | value |
|---|---|
| Proposed name | snap_connection |
| Pointer | `*(0x0025b78c)` (current conn); resolved per session |
| Confidence | High (offsets Confirmed where a runtime read backs them) |

The per-session SN@P transport control block. Offsets confirmed from transport records + rig reads.

| Offset | Type | Name | Meaning | Readers/Writers | Conf |
|---|---|---|---|---|---|
| +0x44 | u32 | ack_base | cumulative ACK base sent in the 0x60 ack (header 0x6010) | FUN_001d63b8 (build), FUN_001d6988 (advance) | High |
| +0x5c | ptr→u32 | expected_seq | reorder gate: inbound reliable seg acked iff msgSeq >= **(conn+0x5c) | FUN_001d6988 | Confirmed |
| +0x520 | ptr | reliable_pool | send/reorder sub-pool base | FUN_001ec1f8 family | High |
| +0x618 | u32 | gen_seq | per-cycle generation / send-seq (op06 SUB echo key) | create/enter SMs | High |
| pool+0x28 | — | sub2 | sub-pool-2 (op49 alloc); disable-bit pool+0x36; watermark pool+0x74 | FUN_001ec1f8/FUN_001eb* | High |

**Related packets:** all reliable (0x8000). **Related fns:** transport subsystem (189 fns).
**Evidence:** functions/transport/001d6988_*.md; analysis/op06-accept-criterion-RE-2026-07-26.txt; FACTS.md.
**Uncertainty:** full field map (0x00-0x520) incomplete — expand from transport records.
