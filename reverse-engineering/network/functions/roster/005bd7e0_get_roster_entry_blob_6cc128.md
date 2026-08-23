# 0x005bd7e0 get_roster_entry_charstats_6cc128

| field | value |
|---|---|
| Original address | 0x005bd7e0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bd7e0 |
| Resolved name | get_roster_entry_charstats_6cc128 |
| Subsystem | roster |
| Relevance | support |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005b3070 (roster query facade)
**Callees:** func_0x001069a8 (memcpy, fixed length)
**Referenced globals:** 0x6cc128 (roster-entry table, stride 0x114 — the charstats blob @+0x24)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Third sibling of the roster-entry getters (0x005bd740/0x005bd790): copies the **charstats** blob
(offset +0x24, fixed 0xf0 bytes) of roster entry `[index]` in the 0x114-stride table at 0x6cc104
(0x6cc128 = base + 0x24) into the caller buffer via a length-fixed memcpy (not strcpy — it is binary
character-stat data, may contain NULs). +0x24/0xf0 matches the op06 scratch charstats field
(0x6cd696) and `member_record.charstats[0xf0]`.

## Input / output
- `param_1` (uint) — entry index (`& 0xff`).
- `param_2` (void* out) — destination; receives 0xf0 bytes.
- Returns 0 (constant).

## Side effects
Writes 0xf0 bytes to the caller's `out`. No global mutation.

## Important branches
None. Only the `& 0xff` index truncation.

## Constants & flags
- `0x114` — roster-entry stride. `0x6cc128` = base 0x6cc104 + 0x24 (charstats). `0xf0` — copy length. `func_0x001069a8` = memcpy.

## Corrected reconstruction
```c
int get_roster_entry_charstats(uint index /*&0xff*/, void *out) {
    memcpy(out, roster_entry[index & 0xff].charstats, 0xf0);   // func_0x001069a8, 0x6cc104 + 0x24
    return 0;
}
```

## Evidence
- Raw decompile: `func_0x001069a8(param_2, (param_1&0xff)*0x114 + 0x6cc128, 0xf0)`.
- 0xf0-byte charstats at +0x24 matches member_record charstats and the op06 scratch (0x6cd696).
- Runtime-unvalidated (static only).

## Remaining uncertainty
- charstats internal layout (char-id @+0xc8 per member_record notes) not re-verified here.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bd7e0.c`  — untouched decompiler output.
