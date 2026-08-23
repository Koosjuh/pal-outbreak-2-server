# 0x005adcd0 get_selected_room_field

| field | value |
|---|---|
| Original address | 0x005adcd0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005adcd0 |
| Resolved name | get_selected_room_field |
| Subsystem | rooms |
| Relevance | helper |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f4480
**Callees:** FUN_005fa820 (raw-id → display/room-number map)
**Referenced globals:** `0x6c4b98` u8 field-A; `0x6c4b99` u8 mode flag; `0x6c4b9c` s16 field-B (raw id/index)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** `cRam006c4b99` mode flag

## Behavioral explanation
Accessor over the currently-selected room's identity tuple in the lobby state block (`0x6c4b98..0x6c4b9c`),
selected by `param_1` (0/1/2). A mode flag at `0x6c4b99` switches between two interpretations of the same
tuple. Selector `0` returns the room's mapped number (via FUN_005fa820, with sentinel `999` normalized to 0)
when the flag is set, else the raw `0x6c4b9c` value; selector `1` returns `0x6c4b9c` only when the flag is set;
selector `2` returns the `0x6c4b98` byte only when the flag is clear. Any other selector returns 0. This is the
read-side of the "which room is currently selected" state used by the room-list UI.

## Input / output
- `param_1` : field selector — `0`=mapped/raw id, `1`=raw index (flag-set only), `2`=byte-A (flag-clear only).
- returns `long` : the requested field, or `0` when the mode flag gates it out / selector is out of range.

## Side effects
- None (pure read; FUN_005fa820 is a lookup).

## Important branches
- `param_1 == 2`: flag `0x6c4b99 == 0` → return `0x6c4b98`; else `0`.
- `param_1 == 1`: flag set → return `0x6c4b9c`; else `0`.
- `param_1 == 0`: flag clear → return `0x6c4b9c` raw; flag set → `FUN_005fa820(0x6c4b9c)`, mapping `999 → 0`.
- default → `0`.

## Constants & flags
- `0x6c4b99` mode flag: `0` = "direct" interpretation (byte-A valid, raw index for sel0); non-0 = "mapped"
  interpretation (index for sel1, mapped number for sel0).
- `999` = FUN_005fa820 not-found/invalid sentinel, normalized to `0`.

## Corrected reconstruction
```c
// Selected-room identity tuple in the lobby state block.
struct sel_room { /*0x6c4b98*/ u8  a; /*0x6c4b99*/ u8 mode; /*0x6c4b9a*/ u16 _pad; /*0x6c4b9c*/ s16 idx; };

long get_selected_room_field(int sel /*param_1*/)
{
    struct sel_room *r = (struct sel_room*)0x6c4b98;
    switch (sel) {
    case 2: return (r->mode == 0) ? r->a : 0;
    case 1: return (r->mode != 0) ? r->idx : 0;
    case 0:
        if (r->mode == 0) return r->idx;              // raw
        long n = map_room_number(r->idx);             // FUN_005fa820
        return (n == 999) ? 0 : n;                    // 999 = invalid
    default: return 0;
    }
}
```

## Evidence
- Raw if/else ladder on `param_1` over `cRam006c4b98`/`cRam006c4b99`/`sRam006c4b9c`; `FUN_005fa820` with the
  `999`→0 clamp. Caller FUN_005f4480 (paired with the u16 getter FUN_005add80). Runtime-unvalidated.

## Remaining uncertainty
- Exact meaning of byte-A (`0x6c4b98`) vs index (`0x6c4b9c`) and what FUN_005fa820 maps (list-index → server
  room number is the working hypothesis) not runtime-pinned.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005adcd0.c`  — untouched decompiler output.
