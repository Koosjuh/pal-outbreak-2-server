# 0x0061e940 input_sample_reset

| field | value |
|---|---|
| Original address | 0x0061e940 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0061e940 |
| Resolved name | input_sample_reset |
| Subsystem | ui |
| Relevance | support |
| Status | documented |
| Confidence | Low |
| Runtime validated | no |

**Callers (10):** FUN_005af340, FUN_0061f9f0, FUN_0061fd70, FUN_00620250, FUN_006205c0, FUN_00620b60, FUN_00620d60, FUN_00623090, FUN_00623600, FUN_00624c70
**Callees:** — (tail decode failed)
**Referenced globals:** 0x715268 (input/sample word)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x715268

## Behavioral explanation
Resets the input-sample cache: stores `uRam00715268 = 0` — the same global e910 samples into.
Ghidra recovers that store, then hits `halt_baddata()` (decode failure) before the end, so the
remainder of the body (if any beyond the store + return) is not recovered. Given the caller set
(the same menu/UI handlers that call e910) and the single recovered store, its role is the clear-side
counterpart of e910: zero the last-sample state, typically on menu entry/exit or state change.

## Input / output
- Input: none (recovered portion).
- Output: none recovered (declared void).

## Side effects
- Writes global `uRam00715268 = 0`.
- Any further effect after the store is unrecovered (decode failure).

## Important branches
None recovered.

## Constants & flags
- Store literal `0` to `0x715268`.

## Corrected reconstruction
```c
extern uint32_t g_last_input_sample;   // uRam00715268

void input_sample_reset(void)
{
    g_last_input_sample = 0;   // recovered store
    // <bad instruction data — Ghidra halt_baddata; remainder of body unrecovered>
}
```

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0061e940.c`  — untouched decompiler output.

## Evidence
- Raw decompile: `uRam00715268 = 0;` then `halt_baddata()` (size=12).
- Same global as e910; complementary caller set. The store is certain; anything past it is not
  recovered ⇒ Confidence **Low**.

## Remaining uncertainty
Whether the function does only the zero-store or has further logic hidden by the decode failure.
