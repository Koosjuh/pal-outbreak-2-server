# 0x001d0b90 load_pc_motion_dual_grid_cond

| field | value |
|---|---|
| Original address | 0x001d0b90 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d0b90 |
| Resolved name | load_pc_motion_dual_grid_cond |
| Subsystem | rooms (MISCLASSIFIED — actually assets/motion) |
| Relevance | support |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_00109728 (sprintf), FUN_001cb360 (file loader dispatch), FUN_001d0a50 (dual-grid motion decode)
**Referenced globals:** `uRam003435bc` (=work/heap base handed to loader+decoder), motion grids `0x528200`/`0x5262b0` (via FUN_001d0a50)
**Referenced strings:** `0x24cd00` = `"data\rom\motion\player\pc_%03d.bin"`
**Referenced opcodes:** — (NOT a network function)
**State vars:** —

## Behavioral explanation
**This is a motion-asset loader, not a roster/network function.** The prior "roster" name/classification was
wrong; the template string at 0x24cd00 is a disc file path for playable-character motion data
(`data\rom\motion\player\pc_%03d.bin`).

When the `short` gate `param_1` is non-zero, it formats that path into a 128-byte stack buffer, loads the
file via the loader dispatcher FUN_001cb360 (flags `0x20001` → buffer-return variant), and decodes the loaded
blob into two parallel motion-handle grids (`0x528200` and `0x5262b0`) via FUN_001d0a50 with **mode=1** (the
"alternate bank" branch of the decoder). It is the conditional sibling of FUN_001d0b00 (`sp_%03d.bin`, mode=0);
together they populate two banks of the same player-motion table.

## Input / output
- `param_1` : `short` gate. `!=0` → do the load; `0` → no-op. (Semantically "load PC motion for this slot/bank".)
- returns `void`.
- The `%03d` format argument is not recovered by the decompiler (FUN_00109728 is varargs sprintf; sibling
  FUN_001d0b00 passes `uRam0034357a` as the id). **[inferred]** the same id source feeds this call.

## Side effects
- Writes motion-handle grids at `0x528200` (+dim header bytes `uRam00528200/01`) and `0x5262b0`
  (+`uRam005262b0/b1`) — see FUN_001d0a50 / FUN_001d06d0.
- Registers/releases motion resources via the decoder (FUN_00188a30 alloc handle, FUN_00188ad0 free) — a
  handle-table mutation, no packets, no state-machine transition.

## Important branches
- `param_1 == 0` → return immediately (skip load). Only decision point.

## Constants & flags
- `0x20001` loader flags: bit16 (`0x10000`) **clear** + low16 (`0x0001`) set → FUN_001cb360 routes to
  FUN_001a0e90 (the "return loaded buffer" loader variant). Evidence: FUN_001cb360 body.
- FUN_001d0a50 mode arg `1` = alternate decode bank (`param_5!=0` path in FUN_001d06d0 uses `2000 - iVar10`
  as the base offset). `0x24cd00` = motion path string (ELF read, Confirmed).

## Corrected reconstruction
```c
// data\rom\motion\player\pc_%03d.bin  (playable-character motion, "bank 1")
// sibling: FUN_001d0b00 loads sp_%03d.bin as bank 0.
void load_pc_motion_dual_grid_cond(short do_load /*param_1*/)
{
    if (do_load == 0)
        return;

    char path[128];
    // [inferred] id arg (sibling uses uRam0034357a) dropped by decompiler:
    sprintf(path, "data\\rom\\motion\\player\\pc_%03d.bin" /*, motion_id */);   // FUN_00109728

    void *blob = load_file(path, g_motion_work_base /*uRam003435bc*/,
                           0x20001, 0);                                          // FUN_001cb360

    decode_player_motion_dual(g_motion_work_base, blob, /*bank=*/1);             // FUN_001d0a50
}
```

## Evidence
- ELF string read: file off = 0x24cd00-0x100000+0x280 → `"data\rom\motion\player\pc_%03d.bin"` (Confirmed).
- FUN_001cb360 body: `0x20001` selects the buffer-returning loader (FUN_001a0e90).
- FUN_001d0a50 → FUN_001d06d0: writes 2-byte dim header then registers motion handles (FUN_00188a30/ad0)
  into the two grids. Runtime-unvalidated.

## Remaining uncertainty
- The `%03d` id argument is not visible in the decompile (varargs). Whether `param_1` doubles as that id or
  is purely a gate is unconfirmed.
- Grid `0x528200` is shared with FUN_001d0d50's third demo grid — bank ownership vs reuse not runtime-checked.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d0b90.c`  — untouched decompiler output.
