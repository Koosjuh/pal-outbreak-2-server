# 0x005c5780 set_status_label_from_index

| field | value |
|---|---|
| Original address | 0x005c5780 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c5780 |
| Resolved name | append_status_label_from_index |
| Subsystem | ui |
| Relevance | helper |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005c5810 (build_room_status_text)
**Callees:** FUN_005c7ff0 (string-id -> string resolver [inferred]), strcat@0x00109ab0 [inferred]
**Referenced globals:** 0x6fbe58 (room/connection status text buffer)
**Referenced strings:** localized strings 0xb..0x10 (via resolver)
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Maps a small room-state index (0..5) to a localized string id (0xb..0x10), resolves the id to a string via FUN_005c7ff0, and **appends** it to the status text buffer 0x6fbe58. Out-of-range indices are silently ignored (no append). Called by `build_room_status_text` to emit each phase label as it walks the room-state globals.

## Input / output
- `param_1` (byte): status index 0..5. Any other value = no-op.
- returns void.

## Side effects
- On a valid index: appends the resolved string to buffer 0x6fbe58 (strcat).

## Important branches
- `param_1` in 0..5 -> `id = 0xb + param_1`, resolve, strcat.
- default -> `goto` skip; nothing written.

## Constants & flags
Index -> string-id table (contiguous):
- 0 -> 0xb
- 1 -> 0xc
- 2 -> 0xd
- 3 -> 0xe
- 4 -> 0xf
- 5 -> 0x10

(Semantic per caller: 0=idle/no-room, 1=busy/full-flag path, 2/3=joining phases w/ host name, 4/5=ready/waiting — see build_room_status_text.)

## Corrected reconstruction
```c
extern const char *resolve_string(int id);   // FUN_005c7ff0 [inferred]
extern char *strcat_(char *d, const char *s); // 0x00109ab0 [inferred]
#define STATUS_BUF 0x006fbe58

// Append the localized label for room-state index (0..5) to the status buffer.
void append_status_label_from_index(unsigned char idx)
{
    int strid;
    switch (idx) {
        case 0: strid = 0x0b; break;
        case 1: strid = 0x0c; break;
        case 2: strid = 0x0d; break;
        case 3: strid = 0x0e; break;
        case 4: strid = 0x0f; break;
        case 5: strid = 0x10; break;
        default: return;                 // out of range: no-op
    }
    strcat_((char *)STATUS_BUF, resolve_string(strid));
}
```

## Evidence
- Raw decompile: 6-case switch producing 0xb..0x10, `FUN_005c7ff0(uVar1)`, then `f_109ab0(0x6fbe58, ...)`; default `goto` to return.
- Sole caller build_room_status_text @0x005c5810 supplies indices 0,1,2,3,4,5.
- Confidence **High** on control flow; string-ids' exact text pending a string-table dump.

## Remaining uncertainty
- FUN_005c7ff0 assumed to be the localized-string resolver (id->ptr); the id-to-text mapping (0xb..0x10) is not dumped here. Renamed set_->append_ to reflect strcat (not overwrite) semantics.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c5780.c`  — untouched decompiler output.
