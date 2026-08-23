# 0x005bd250 build_identity_hostname_buf

| field | value |
|---|---|
| Original address | 0x005bd250 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bd250 |
| Resolved name | build_identity_hostname_buf |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005bd2e0, FUN_00626900
**Callees:** —
**Referenced globals:** 0x86f820 (local id); 0x35b7d0/0x35b7e0 (host record len/data); 0x639e80 (format template)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Builds the identity/hostname buffer for session open: with no extra host record (0x35b7d0==0) formats local id (0x86f820) into the buffer via template 0x639e80; otherwise concatenates the raw id blob and the 0x35b7e0 host suffix.

## Notes / uncertainty
sprintf(local id 0x86f820 via template 0x639e80) when host-suffix len(0x35b7d0)==0, else raw concat id+suffix(0x35b7e0). Concat path relies on pre-zeroed buffer (no NUL). Template text not dumped.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bd250.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
