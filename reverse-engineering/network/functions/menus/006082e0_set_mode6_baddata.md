# 0x006082e0 set_mode6_baddata

| field | value |
|---|---|
| Original address | 0x006082e0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006082e0 |
| Resolved name | set_mode6_baddata |
| Subsystem | menus |
| Relevance | helper |
| Status | reconstructed |
| Confidence | Low |
| Runtime validated | no |

**Callers:** FUN_00606cb0
**Callees:** —
**Referenced globals:** 0x006c4faa mode
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** uRam006c4faa

## Behavioral explanation
A one-line state setter: it writes the constant `6` to the global mode byte at `0x006c4faa`,
then the decompiler hit an undecodable instruction (`halt_baddata`) and truncated. The single
verifiable effect is the mode write; the tail of the function is not recovered. In context (sole
caller is menu handler `FUN_00606cb0`) this is one arm of a menu/screen state selector that pushes
the UI into "mode 6". Not on the network path.

## Input / output
- **Params:** none (`void`).
- **Return:** none.

## Side effects
- Writes `g_menu_mode6c4faa = 6` (global byte at `0x006c4faa`).
- Anything after the write is lost to the bad-instruction truncation.

## Important branches
- None recovered. Straight-line write followed by truncation.

## Constants & flags
- `6` — the mode value assigned to `0x006c4faa`. Sibling handlers around `FUN_00606cb0` write other
  small constants to the same byte (evidence: it is a shared mode selector), so `6` is one enumerated
  screen/mode id. Exact enum meaning unproven.

## Corrected reconstruction
```c
// Menu mode selector arm. [inferred] name for the global.
extern uint8_t g_menu_mode; // 0x006c4faa

void set_menu_mode6(void)
{
    g_menu_mode = 6;
    // WARNING: decompiler hit bad instruction data here (halt_baddata);
    // remaining body not recovered. Likely tail-call / jump into the mode-6
    // screen setup that the disassembler could not follow.
}
```

## Evidence
- Raw decompile `sources/overlays/overlay-3dat-decompile/FUN_006082e0.c`: `uRam006c4faa = 6;` then
  `halt_baddata()` (Ghidra "Bad instruction - Truncating control flow here").
- Single caller `FUN_00606cb0` (menu handler). Runtime-unvalidated.

## Remaining uncertainty
- Everything after the mode write is unknown (truncated). The meaning of mode value `6` is inferred
  from it being a shared selector byte, not proven. Confidence **Low** because the function body is
  incomplete.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006082e0.c`  — untouched decompiler output.
