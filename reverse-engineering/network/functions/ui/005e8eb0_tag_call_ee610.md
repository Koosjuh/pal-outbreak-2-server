# 0x005e8eb0 tag_emit_run

| field | value |
|---|---|
| Original address | 0x005e8eb0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e8eb0 |
| Resolved name | tag_call_ee610 |
| Subsystem | ui |
| Relevance | unrelated |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** — (markup-tag jump table)
**Callees:** FUN_005ee610 (emit/advance current run)
**Referenced globals:** (via callee) +0x10 (max line width), +0x12 (delay), +0x182 (max-width tracker), +0x186 (layout pass), +0xdf6/+0xdf8 (advance/height), +0xd8bc..+0xd8cc (pen)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** — (delegated)

## Behavioral explanation
Zero-argument markup tag whose entire body invokes `FUN_005ee610`, the run **emit/advance** step:
measure the current run against the right margin `+0x10`, word-wrap via `FUN_005ed460` if it overflows,
commit the glyph advance, and update the pen (`+0xd8bc/+0xd8c0`) and layout bounding box (`+0x182`). It
takes no parse cursor — this handler forces a run commit at the tag position without consuming text.
Alt-mode path delegates to `FUN_005f2e50`.

## Input / output
- No parameters (declared `void`).
- Returns `0`.

## Side effects
- Via `FUN_005ee610`: pen advance/wrap, `+0xd8cc = 1` (content-emitted flag), bbox `+0x182` grow;
  in measure pass (`+0x186 == 1`) grows the record's width/height mins.

## Important branches
- None locally; `+0xd892` / `+0x186` branches are inside `FUN_005ee610`.

## Constants & flags
- (see `FUN_005ee610`) `+0x186` pass selector: `0` normal, `1` measure, `-10` (0xf6) max-width pass.

## Corrected reconstruction
```c
undefined8 tag_emit_run(void)
{
    text_emit_run();   // FUN_005ee610: measure+wrap+advance current run, update pen/bbox
    return 0;
}
```

## Evidence
- Raw: `sources/overlays/overlay-3dat-decompile/FUN_005e8eb0.c` (32 bytes) — single call.
- `FUN_005ee610.c`: the word-wrap/advance emitter.
- Runtime-unvalidated.

## Remaining uncertainty
- Suggested rename `tag_emit_run`. Which markup token forces a mid-line commit is unresolved.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e8eb0.c`  — untouched decompiler output.
