# 0x005f5300 chatlog_set_text_color

| field | value |
|---|---|
| Original address | 0x005f5300 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f5300 |
| Resolved name | chatlog_set_line_color |
| Subsystem | chat |
| Relevance | support |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f54d0 (chatlog_render)
**Callees:** FUN_005af2c0 (set text palette index)
**Referenced globals:** chatBase = iRam003435d4+0xc8000; 0x649710 (8-entry player-slot color LUT); 0x24eba9 (char-class table, bit 0x04); cRam006c50fb (log-mode flag); 0x6c69cc (a name string to compare against, via caller path)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006c50fb

## Behavioral explanation
Chooses and sets the text palette index for one of the three rendered fields of a chat slot,
based on that slot's attribute byte. The attribute byte is interpreted as a character: if it is a
digit `'0'`..`'7'` (detected via char-class table bit `0x04`), the line is a per-player message and
gets that player's slot color from an 8-entry LUT (`0x649710`, indexed `(attr-'0') & 7`). Otherwise
it is a system/default line and gets a fixed palette index that differs per field and per log-mode
(`cRam006c50fb`). Called three times per visible row by the renderer (field 0/1/2).

`field` selector (`param_2`):
- `0` -> uses attr E (chatBase + slot + 0x1396)
- `1` -> uses attr F (chatBase + slot + 0x13c8); the name-string branch additionally compares the
  slot's display name (`chatBase + slot*0x11 + 800`) against global `0x6c69cc` (a special/self name)
- `2` -> uses attr G (chatBase + slot + 0x13fa)

## Input / output
- `param_1` (int) — slot index into the ring.
- `param_2` (char) — which field's color to set: `0`, `1`, or `2`.
- returns `void`; effect is the call to `FUN_005af2c0(palette_index)`.

## Side effects
- Calls `FUN_005af2c0(idx)` setting the current text palette index. No ring/state writes.

## Important branches
- **field 2** (`param_2==2`): `attr=G`. If `attr!=0 && (charclass[attr]&4)!=0 && cRam006c50fb==0`
  is FALSE... actually: if `attr==0` OR `(charclass[attr]&4)==0` OR `cRam006c50fb!=0` -> default:
  `cRam006c50fb==0 ? FUN_005af2c0(0) : FUN_005af2c0(0x14)`. Else (digit tag, live mode) ->
  `FUN_005af2c0(LUT[(attr-'0') & 7])` player color.
- **field 1** (`param_2==1`): `attr=F`. If `attr==0 || (charclass[attr]&4)==0` -> compare name string
  vs `0x6c69cc`: match(strcmp==0) -> `0x11`, else -> `0x15`. Else (digit tag) -> `LUT[(attr-'0')&7]`.
- **field 0** (`param_2==0`): `attr=E`. If `attr==0 || (charclass[attr]&4)==0` -> `0x10`.
  Else (digit tag) -> `LUT[(attr-'0')&7]`.

## Constants & flags
- `0x649710` — 8-entry `u8` player-slot color LUT, indexed `(attr - '0') & 7`.
- `0x24eba9` — char-class table; bit `0x04` = "is a slot digit `'0'`..`'7'`" for this fn's purpose.
- Default palette indices: field0 `0x10`; field1 `0x11` (self/special-name match) / `0x15` (other);
  field2 `0` (live) / `0x14` (history mode); tag='0'..'7' -> per-slot LUT color.
- `cRam006c50fb` — log-mode flag; `!=0` (history/scroll) forces the field-2 default to `0x14` (dimmed).
- `'0'` = 0x30 (subtracted before LUT index).
- `0x6c69cc` — a reference name string (likely the local player / a system sender) used to pick self-color `0x11`.

## Corrected reconstruction
```c
enum {                       // FUN_005af2c0 palette indices
    PAL_FIELD0_DEFAULT = 0x10,
    PAL_NAME_SELF      = 0x11,
    PAL_MSG_DIM        = 0x14,   // history mode
    PAL_NAME_OTHER     = 0x15,
    PAL_MSG_LIVE       = 0x00,
};
#define IS_SLOT_DIGIT(c) ((c) != 0 && (*(u8*)((c) + 0x24eba9) & 4))
#define SLOT_COLOR(c)    (*(u8*)(((c) - '0' & 7) + 0x649710))

void chatlog_set_line_color(int slot, char field)
{
    u8 *chat = (u8 *)(iRam003435d4 + 0xc8000);

    if (field == 2) {                         // message row
        u8 g = chat[slot + 0x13fa];
        if (IS_SLOT_DIGIT(g) && cRam006c50fb == 0)
            FUN_005af2c0(SLOT_COLOR(g));
        else
            FUN_005af2c0(cRam006c50fb == 0 ? PAL_MSG_LIVE : PAL_MSG_DIM);
    }
    else if (field == 1) {                    // name row
        u8 f = chat[slot + 0x13c8];
        if (!IS_SLOT_DIGIT(f)) {
            int self = (strcmp((char*)(chat + slot*0x11 + 800), (char*)0x6c69cc) == 0);
            FUN_005af2c0(self ? PAL_NAME_SELF : PAL_NAME_OTHER);
        } else {
            FUN_005af2c0(SLOT_COLOR(f));
        }
    }
    else if (field == 0) {
        u8 e = chat[slot + 0x1396];
        if (!IS_SLOT_DIGIT(e)) FUN_005af2c0(PAL_FIELD0_DEFAULT);
        else                   FUN_005af2c0(SLOT_COLOR(e));
    }
}
```

## Evidence
- Raw: `FUN_005f5300.c` — three `param_2` arms reading `+0x13fa`/`+0x13c8`/`+0x1396`; digit test
  `(*(byte*)(bVar1+0x24eba9) & 4)`; LUT `*(u8*)((bVar1-0x30 & 7)+0x649710)`; defaults `0/0x14/0x11/0x15/0x10`;
  name compare via `func_0x00109d70(iVar3 + param_1*0x11 + 800, 0x6c69cc)` (strcmp).
- Field/attr mapping matches `chatlog_push_msg` (0x5f50d0) attr writes and renderer field-1/field-2 draw order.

## Remaining uncertainty
- Identity of the `0x6c69cc` comparison string (local player name vs. a reserved system sender) not confirmed.
- Exact color values in the `0x649710` LUT (raw palette bytes) not dumped. Bit-0x04 char-class semantics
  inferred from the `-'0' & 7` usage. No runtime trace (High).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f5300.c`  — untouched decompiler output.
