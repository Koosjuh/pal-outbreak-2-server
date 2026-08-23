# 0x005dedb0 FUN_005dedb0

| field | value |
|---|---|
| Original address | 0x005dedb0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005dedb0 |
| Resolved name | FUN_005dedb0 |
| Subsystem | unknown |
| Relevance | helper |
| Status | documented |
| Confidence | Low |
| Runtime validated | no |

**Callers:** FUN_005d6a70
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Opaque. The decompiler aborted on bad/truncated instruction data (`halt_baddata`) at the function
entry, so no control flow was recovered. Size is only 8 bytes and it sits immediately before
`strncpy_255` (0x005dedc0) in the same helper cluster, so it is most plausibly a tiny leaf accessor
or a mis-disassembled tail of the preceding routine that Ghidra failed to decode (likely a
delay-slot / branch-target misalignment). No recoverable logic; NOT reconstructable from this output.

## Input / output
- Unknown (single caller FUN_005d6a70; args not recoverable).

## Side effects
- Unknown.

## Important branches
- None recovered (decode failure).

## Constants & flags
- None recovered.

## Corrected reconstruction
Not possible — decompilation failed (`halt_baddata`). Preserving the low-level fact only. Re-decode
with corrected MIPS alignment (or read the raw bytes) is required to recover this.

## Notes / uncertainty
Bad-instruction decode failure; entirely opaque. Only the single-caller edge is known. Marked
**Low**; do not promote without a re-decode or a live trace.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005dedb0.c`  — untouched decompiler output.

## Evidence
- Raw: `halt_baddata()` at entry; size=8; caller FUN_005d6a70.
- Confidence **Low**; opaque.
