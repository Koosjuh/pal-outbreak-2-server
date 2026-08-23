# 0x006386f0 halt_baddata_stub

| field | value |
|---|---|
| Original address | 0x006386f0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006386f0 |
| Resolved name | halt_baddata_stub |
| Subsystem | unknown |
| Relevance | unrelated |
| Status | documented |
| Confidence | Low |
| Runtime validated | no |

**Callers:** FUN_005f3e30, FUN_005f4040
**Callees:** — (Ghidra `halt_baddata()` sentinel; no real callee)
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
**Opaque — not a recoverable function.** Ghidra reports "Control flow encountered bad instruction
data" and truncates at the first byte, emitting the `halt_baddata()` sentinel. The nominal size is
28 bytes but no valid MIPS/EE instruction stream was decoded, so there is no analyzable body to
reconstruct. This record deliberately does **not** invent behavior.

Most likely one of:
- **Misaligned / mis-scoped disassembly** in the overlay — the analyzer began decoding at an address
  that is not a real function entry (padding, a data island, or the interior of another routine),
  and the overlay's relocation/segmentation left the first bytes undecodable.
- A **jump-table / branch-delay landing pad** whose real target bytes were resolved elsewhere.
- A tiny **thunk/tail region** the analyzer failed on due to bad overlay relocation.

It has two callers (`FUN_005f3e30`, `FUN_005f4040`) — both in the same overlay code band as the GS
UI helpers above (0x5f3e30 / 0x5f4040), so if it is a real routine it is almost certainly more
graphics/UI glue, **not** network protocol. There is no evidence tying it to any SN@P opcode, global,
or string.

## Input / output
Unknown — no valid prologue decoded, so parameters and return cannot be inferred.

## Side effects
Unknown — no instructions recovered.

## Important branches
None recoverable — control flow truncated at byte 0.

## Constants & flags
None recoverable.

## Corrected reconstruction
No corrected C is possible without inventing behavior. Preserving the low-level state instead:

```c
// 0x006386f0  size≈28 bytes
// Ghidra: "WARNING: Bad instruction - Truncating control flow here"
// No valid instruction stream decoded -> no reconstructable body.
void FUN_006386f0(void) {
    halt_baddata();   // decoder sentinel, NOT a real call
}
// Callers (same overlay UI band, likely graphics glue):
//   FUN_005f3e30 @ 0x005f3e30
//   FUN_005f4040 @ 0x005f4040
// To resolve: re-run disassembly with corrected overlay base/relocations,
// or inspect the raw 28 bytes at 0x6386f0 and the two call sites' expectations.
```

## Evidence
- Raw decompile `sources/overlays/overlay-3dat-decompile/FUN_006386f0.c` (size 28): body is solely
  the `halt_baddata()` sentinel under the "Bad instruction / Truncating control flow" warning.
- Callers `FUN_005f3e30`, `FUN_005f4040` place it in the graphics/UI overlay band (adjacent to the
  0x638xxx GS drawers), not near any known network handler.
- No referenced globals, strings, or opcodes — nothing links it to the SN@P/lobby protocol.

## Remaining uncertainty
- Whether 0x6386f0 is a genuine function at all vs. padding/data/mid-routine bytes.
- If real, its actual signature and behavior — unrecoverable until the overlay is re-disassembled
  with correct base/relocation and the raw bytes are examined.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006386f0.c`  — untouched decompiler output.
