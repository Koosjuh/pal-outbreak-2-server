# 0x001d0c00 load_player_slot_motion

| field | value |
|---|---|
| Original address | 0x001d0c00 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d0c00 |
| Resolved name | load_player_slot_motion |
| Subsystem | rooms (MISCLASSIFIED — actually assets/motion) |
| Relevance | support |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_00109728 (sprintf), FUN_001cb360 (file loader dispatch), FUN_001d09c0 (single-grid motion decode)
**Referenced globals:** per-slot motion grid array `0x516870` (stride `0x1f48`; +1 = per-slot "loaded" guard byte), `uRam003435bc` work base
**Referenced strings:** `0x24cd30` = `"data\rom\motion\player\pl%02d_pc_000.bin"`
**Referenced opcodes:** — (NOT a network function)
**State vars:** guard byte `*(idx*0x1f48 + 0x516871)`

## Behavioral explanation
**Motion-asset loader, not a roster fetch.** For player slot `param_1` (`&0xff`), if that slot's motion is not
already loaded (guard byte at `idx*0x1f48 + 0x516871 == 0`), it builds the per-character motion path
`data\rom\motion\player\pl%02d_pc_000.bin`, loads the file, and decodes it into that slot's motion-handle grid
at `idx*0x1f48 + 0x516870` via FUN_001d09c0. The `0x1f48`-strided array is a per-player-slot motion table; the
byte at `+1` of each entry (written to `1` by FUN_001d09c0 / FUN_001d06d0) is the "columns"/loaded marker.

## Input / output
- `param_1` : `uint` player-slot index (only low 8 bits used). Doubles as the `%02d` id **[inferred]** — same
  varargs-drop caveat as the sibling loaders; here the index is clearly available.
- returns `void`.

## Side effects
- Writes the slot's motion grid at `0x516870 + idx*0x1f48` (dim header at bytes +0/+1, handle table following).
- Registers/releases motion handles (FUN_00188a30/ad0). No packets, no SM transition.

## Important branches
- `*(idx*0x1f48 + 0x516871) != 0` → slot already loaded, return (idempotent load guard). Only branch.

## Constants & flags
- `0x1f48` = per-slot motion-grid stride (grid header 2 bytes + handle table; matches FUN_001d09c0 layout).
- `0x20001` loader flags → buffer-returning loader (FUN_001a0e90), same as siblings.
- `0x24cd30` = motion path string (ELF read, Confirmed).

## Corrected reconstruction
```c
// data\rom\motion\player\pl%02d_pc_000.bin  — per-player-slot character motion
struct motion_slot { u8 rows; u8 cols_loaded; /* ... 0x1f48 handle table ... */ };
static struct motion_slot g_player_motion[?] /* @0x516870, stride 0x1f48 */;

void load_player_slot_motion(uint slot /*param_1*/)
{
    struct motion_slot *ms = &g_player_motion[slot & 0xff];   // idx*0x1f48 + 0x516870
    if (ms->cols_loaded != 0)          // *(idx*0x1f48 + 0x516871) — already loaded
        return;

    char path[128];
    sprintf(path, "data\\rom\\motion\\player\\pl%02d_pc_000.bin" /*, slot */);  // FUN_00109728
    void *blob = load_file(path, g_motion_work_base, 0x20001, 0);               // FUN_001cb360
    decode_motion_grid(g_motion_work_base, ms, blob, 0);                        // FUN_001d09c0
}
```

## Evidence
- ELF string read at 0x24cd30 → `"data\rom\motion\player\pl%02d_pc_000.bin"` (Confirmed).
- FUN_001d09c0: `dest[0]=blob[0]; dest[1]=blob[2]; decode(blob, dest, blob+4, …)` — writes the 2-byte dim
  header into the grid then decodes the handle table. Runtime-unvalidated.

## Remaining uncertainty
- Number of slots / bound on `param_1` not enforced here (caller-guaranteed). The `%02d` arg is the varargs
  caveat shared across this family.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d0c00.c`  — untouched decompiler output.
