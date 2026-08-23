# 0x006371d0 kbd_set_params_40_38

| field | value |
|---|---|
| Original address | 0x006371d0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006371d0 |
| Resolved name | kbd_configure_callback_and_mode |
| Subsystem | helpers |
| Relevance | helper |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005b45f0, FUN_005dc1e0, FUN_005dc2b0, FUN_005f4be0, FUN_005f97c0, FUN_005faa60, FUN_006149f0, FUN_00625190, FUN_0062adb0, FUN_0062d3d0
**Callees:** —
**Referenced globals:** 0x715da8 (soft-keyboard widget state base pointer)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x40 (u32 config word — pointer/callback/context); +0x38 (u16 mode/flags)

## Behavioral explanation
Pure two-field setter used at keyboard open/configure time by ~10 menu screens. It stores a 32-bit configuration word into `kbd+0x40` and a 16-bit mode/flags value into `kbd+0x38`. The 32-bit slot is passed opaquely by every caller (an `undefined4` — most consistent with a context pointer or callback handle), and the 16-bit slot is a small mode selector. No decoding is done here; the values are consumed later by the commit/render paths.

## Input / output
- `param_1` (u32): configuration word written to +0x40. [inferred] context/callback pointer or field id.
- `param_2` (u16): mode/flags written to +0x38.
- Returns: void.

## Side effects
- `kbd->cfg32(+0x40) = param_1; kbd->mode16(+0x38) = param_2;`. Nothing else.

## Important branches
- None (straight-line, no conditionals).

## Constants & flags
- None literal. +0x38 is a narrow mode field (16-bit); +0x40 is a full word.

## Corrected reconstruction
```c
void kbd_configure_callback_and_mode(uint32_t cfg /*param_1*/, uint16_t mode /*param_2*/)
{
    KbdState *kbd = *(KbdState **)0x715da8;
    kbd->cfg32 /*+0x40*/ = cfg;    /* [inferred] context/callback handle */
    kbd->mode16 /*+0x38*/ = mode;  /* mode / option flags */
}
```

## Evidence
- Raw decompile FUN_006371d0.c lines 9-10: `*(u32*)(base+0x40)=param_1; *(u16*)(base+0x38)=param_2;`.
- 10 callers across lobby/menu screens => shared configure helper.

## Remaining uncertainty
- Exact meaning of +0x40 (callback vs context vs field-id) and the enumeration of +0x38 modes require tracing the consumers (commit path 006378b0 reads +0x3a but not these; the render/open path in 006345e0/00634ab0 likely reads them). Names marked [inferred].
