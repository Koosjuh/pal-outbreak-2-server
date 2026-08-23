# 0x005f4040 screen2_init_sm

| field | value |
|---|---|
| Original address | 0x005f4040 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f4040 |
| Resolved name | screen2_init_sm |
| Subsystem | menus |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f3ff0
**Callees:** FUN_005ac610, FUN_005de2a0, FUN_00606a20, FUN_006386f0
**Referenced globals:** puRam00715298(display obj: [0]=0x25,[1]=2,[0x108]=1); uRam0035b746/748; uRam0034357a(asset lock); uRam00343639; iRam00337dd0
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** param+0x08 (phase), param+0x09 (substate)

## Behavioral explanation
Multi-phase scene-init state machine; builds a 0x25/0x02 display-object record and waits on a load result.

## Notes / uncertainty
Two-level init state machine: sub-state +0x09 (0 build buffers+display-object@0x7152e0 type 0x25, 1 render setup, 2 wait async load via 00606a20 then advance outer phase). 0x25 = UI display-object type tag NOT wire opcode. sub-0 fall-through step count inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f4040.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
