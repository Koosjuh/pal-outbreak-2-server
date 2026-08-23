# 0x001d0c90 load_npc_motion_table_if_allowed

| field | value |
|---|---|
| Original address | 0x001d0c90 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d0c90 |
| Resolved name | load_npc_motion_table_if_allowed |
| Subsystem | rooms (MISCLASSIFIED — actually assets/motion) |
| Relevance | support |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_00109728 (sprintf), FUN_001cb360 (file loader dispatch), FUN_001d09c0 (single-grid motion decode)
**Referenced globals:** NPC-id allowlist `DAT_00259258` (`-1`/`0xff`-terminated `char[]`), NPC motion grid `0x502fa0`, `uRam003435bc` work base
**Referenced strings:** `0x24cd60` = `"data\rom\motion\npc\rn%02d_tbl.bin"`
**Referenced opcodes:** — (NOT a network function)
**State vars:** —

## Behavioral explanation
**NPC motion-table loader, not a roster fetch.** It scans a signed-byte allowlist `DAT_00259258` (terminated
by `-1`) for the requested NPC id `param_1 & 0xff`. If the id is present (loop exited on a match, not on the
terminator), it builds the NPC motion path `data\rom\motion\npc\rn%02d_tbl.bin`, loads it, and decodes it into
the single NPC motion-handle grid at `0x502fa0` via FUN_001d09c0. Only whitelisted NPC ids are permitted to
load — an unlisted id silently loads nothing.

## Input / output
- `param_1` : `ulong` NPC id (low 8 bits used; also the `%02d` arg **[inferred]**).
- returns `void`.

## Side effects
- Writes the NPC motion grid at `0x502fa0` (2-byte dim header + handle table). Registers/releases motion
  handles (FUN_00188a30/ad0). No packets, no SM transition.

## Important branches
- Allowlist scan `while`: breaks when `DAT_00259258[i] == -1` (terminator) **or** `== (param_1&0xff)` (match).
- Post-loop gate `if (DAT_00259258[i] != -1)` → true only on a real match → do the load. If the loop stopped on
  the terminator, `[i] == -1` → skip (id not allowed).

## Constants & flags
- `DAT_00259258` = `-1`-terminated allowlist of permitted NPC ids (signed `char`). Sentinel `-1` (`0xff`).
- `0x20001` loader flags → buffer-returning loader (FUN_001a0e90).
- `0x24cd60` = motion path string (ELF read, Confirmed).

## Corrected reconstruction
```c
// data\rom\motion\npc\rn%02d_tbl.bin — NPC motion table, allowlist-gated
static const s8 g_npc_allow[] /* @0x259258 */ = { /* … ids … */, -1 };

void load_npc_motion_table_if_allowed(ulong npc_id /*param_1*/)
{
    u8 id = (u8)npc_id;
    int i = 0;
    while (g_npc_allow[i] != -1 && id != (u8)g_npc_allow[i])
        i++;

    if (g_npc_allow[i] == -1)          // fell through to terminator → not allowed
        return;

    char path[128];
    sprintf(path, "data\\rom\\motion\\npc\\rn%02d_tbl.bin" /*, id */);       // FUN_00109728
    void *blob = load_file(path, g_motion_work_base, 0x20001, 0);            // FUN_001cb360
    decode_motion_grid(g_motion_work_base, (void*)0x502fa0, blob, 0);        // FUN_001d09c0
}
```

## Evidence
- ELF string read at 0x24cd60 → `"data\rom\motion\npc\rn%02d_tbl.bin"` (Confirmed).
- Loop/gate structure matches a `-1`-terminated allowlist membership test. Runtime-unvalidated.

## Remaining uncertainty
- Contents of `DAT_00259258` (which NPC ids are permitted) not dumped here.
- Whether the matched index is used as the `%02d` arg vs `param_1` directly — varargs caveat.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d0c90.c`  — untouched decompiler output.
