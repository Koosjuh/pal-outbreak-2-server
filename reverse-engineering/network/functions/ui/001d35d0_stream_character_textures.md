# 0x001d35d0 stream_character_textures

| field | value |
|---|---|
| Original address | 0x001d35d0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d35d0 |
| Resolved name | stream_character_textures |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_00109728, FUN_001cb360
**Referenced globals:** 0x4f9474 last-loaded id; 0x4fa6e8 entry count; 0x4e5c40/0x4e5c58 entry table; 0x7cf964 status flags; 0x24d310.. path fmts; 0x24d2f0 region ptr
**Referenced strings:** (path fmts @0x24d310/40/60/90/b0/e0/400/430)
**Referenced opcodes:** —
**State vars:** cRam00343577; bRam004f9474

## Behavioral explanation
Iterates active character entries and streams their texture chunks (0x12800/0x8000-stride) from disk into VRAM staging buffers.

## Notes / uncertainty
Change-gated (bRam004f9474) two-class texture streamer over entry table 0x4e5c40 stride 0x1100; variant switch 0/0x5b/else+9; VRAM-stage reads mode 0x10001; size guards 0x12800/0x8000/0xc000; 0xff status marks in 0x7cf964. 'Character texture' domain + upload-kind inferred. Non-network.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d35d0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
