# 0x0061f0e0 redraw_flags_set_1

| field | value |
|---|---|
| Original address | 0x0061f0e0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0061f0e0 |
| Resolved name | redraw_flags_set_base |
| Subsystem | ui |
| Relevance | support |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00620250, FUN_00620d60, FUN_00623800, FUN_00624850, FUN_00624c70, FUN_00625190, FUN_00625670, FUN_00625ea0, FUN_006265f0, FUN_00626900, FUN_00626e70, FUN_00627400, FUN_00627540
**Callees:** —
**Referenced globals:** `0x71530c` (`ui_redraw_mask`)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** `0x71530c`

## Behavioral explanation
Assigns `ui_redraw_mask = 1` — an overwrite (not OR) that sets the base/root element visible bit while clearing every other bit. Effectively "show only the base element / reset to the minimal visible page." Used by menu machines when entering a state whose baseline is just the root panel.

## Input / output
- **Params:** none (`void`). **Returns:** `void`.

## Side effects
- Overwrites `ui_redraw_mask` with `1` (drops any previously-set bits).

## Important branches
- None.

## Constants & flags
- `UI_REDRAW_BASE = 0x1` — root/base element visible bit.

## Corrected reconstruction
```c
void redraw_flags_set_base(void)
{
    ui_redraw_mask = UI_REDRAW_BASE;   // = 1 : show base element only (clears others)
}
```

## Evidence
- Raw decompile: `uRam0071530c = 1; return;` (16 bytes). Note it is an assignment, not `|=`.
- Runtime-unvalidated; behavior certain.

## Remaining uncertainty
- That bit 0x1 is specifically the "base panel" element is inferred from its use as the reset value; on-screen meaning unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0061f0e0.c`  — untouched decompiler output.
