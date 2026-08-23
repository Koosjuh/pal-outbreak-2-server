# 0x00605d60 recv_framed_chunk

| field | value |
|---|---|
| Original address | 0x00605d60 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00605d60 |
| Resolved name | recv_framed_chunk |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00606780
**Callees:** FUN_00605d00
**Referenced globals:** sRam0035a714 (poll type); uRam0035a71a (bytes available); 0x70cdd8/0x70cde0/0x70cde8/0x70cdf0 (framer state)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x70cdd8; 0x70cde0; 0x70cdd0

## Behavioral explanation
Length-prefixed stream reader: polls the socket (func_0x001ee430), parses a 12-byte header once (magic/type==4) to latch expected length from bytes +4/+5, then copies body in bounded chunks into the caller buffer, tracking consumed vs expected and returning progress/rollover/-1.

## Notes / uncertainty
TCP lobby framer (global state, 3.DAT): poll type==4, 12-byte header, BE length at hdr[4..5], chunked body copy clamped by avail+cap; returns 1 complete / >1 chunk-rollover / 0 pending / -1 err. Twin of 0x001c3880. First 4 header bytes unparsed (route/type). TCP path, not SN@P UDP.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00605d60.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
