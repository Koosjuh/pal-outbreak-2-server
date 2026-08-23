# 0x005deb00 analog_input_to_pointer

| field | value |
|---|---|
| Original address | 0x005deb00 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005deb00 |
| Resolved name | analog_input_to_cursor |
| Subsystem | ui |
| Relevance | unrelated |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005c8810
**Callees:** —
**Referenced globals:** iRam0029a528 (processed pad/analog input struct); iRam00701068 + 0x4f8a0.. (browser cursor-input state); DAT_00692d28 (float speed-scale divisor)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** iRam00701068 + 0x4f8a0.. (cursor input block)

## Behavioral explanation
Per-frame input sampler for the browser overlay's on-screen cursor. It reads the processed pad/analog
struct at `iRam0029a528` and updates the 12-byte cursor-input state block at `context_base + 0x4f8a0`.
It does three things:
1. **Latches the pointer coordinates** — copies the current pointer X to a "previous X" slot (so
   downstream code can compute delta/edge), then writes the new X and two more coordinate/axis words
   from the pad struct.
2. **Quantizes two analog channels into 4-level direction zones.** For each of the two channels it
   takes the absolute magnitude and buckets it against thresholds `0x28/0x5a/0x7e` (40/90/126) into a
   zone `0..3` (0 = near-centre/dead, 3 = full deflection). This drives discrete cursor stepping /
   auto-repeat rather than free analog motion.
3. **Derives a per-channel speed nibble** from a float rate word: scale to fixed-point via
   `DAT_00692d28`, round, take the top nibble, and compute `4 - nibble` (so a larger scaled value →
   *smaller* delay → faster repeat). This is a repeat-rate/accel value, not a position.

Purely a controller→UI-cursor mapping; no network involvement.

## Input / output
- No parameters. Reads global `iRam0029a528` (pad) and writes global cursor block at `+0x4f8a0`.
- Returns: void.

## Side effects — cursor input block at `base + 0x4f8a0` (`base = iRam00701068`)
| offset | type | written from | meaning [inferred] |
|---|---|---|---|
| +0x4f8a0 | s16 | pad+0x08 (low 16) | pointer X (current) |
| +0x4f8a2 | s16 | previous +0x4f8a0 | pointer X (previous frame) |
| +0x4f8a4 | s16 | pad+0x10 (low 16) | pointer Y / axis word |
| +0x4f8a6 | s16 | pad+0x14 (low 16) | secondary axis word |
| +0x4f8a8 | u8  | zone of pad+0x20 | channel-A direction zone (0..3) |
| +0x4f8a9 | u8  | rate of pad+0x24 | channel-A speed nibble (0..4-ish) |
| +0x4f8aa | u8  | zone of pad+0x2c | channel-B direction zone (0..3) |
| +0x4f8ab | u8  | rate of pad+0x30 | channel-B speed nibble |

## Important branches
- Zone quantizer (per channel, seeded to 3 = full):
  `mag >= 0x7e` → zone 3; `0x5a <= mag < 0x7e` → 2; `0x28 <= mag < 0x5a` → 1; `mag < 0x28` → 0.
  Encoded as a short-circuit chain of side-effect assignments (`(z=2, mag<0x5a) && (z=1, mag<0x28)`
  then `z=0`), which is exactly the descending bucket ladder above. `mag` is `abs(short)`.
- No error/bounds paths; straight-line, two identical channel blocks.

## Constants & flags
- Zone thresholds `0x28` (40), `0x5a` (90), `0x7e` (126) — magnitude buckets; default seed `3`.
- Speed nibble: `4 - (((int)(rate * 65536.0 / DAT_00692d28 + 0.5) & 0xffff) >> 0xc) & 0xf`.
  `* 65536.0` = to 16.16 fixed; `/DAT_00692d28` = normalise by a max-range constant; `+0.5` = round;
  `& 0xffff` = keep low 16; `>> 0xc` = top nibble (0..15); `4 - n` = invert to a delay/step (larger
  rate → smaller value). Outer `& 0xf` clamps to a nibble.
- `DAT_00692d28` — float divisor / speed-scale constant (fixed data).

## Corrected reconstruction
```c
/* Per-frame: map the processed analog pad into the browser cursor-input state. */
struct cursor_input {            /* at context_base + 0x4f8a0 [inferred] */
    s16 x;                       /* +0x00 (0x4f8a0) current pointer X   */
    s16 x_prev;                  /* +0x02 (0x4f8a2) previous pointer X  */
    s16 axis_y;                  /* +0x04 (0x4f8a4)                     */
    s16 axis_2;                  /* +0x06 (0x4f8a6)                     */
    u8  zone_a;                  /* +0x08 (0x4f8a8) 0..3                */
    u8  speed_a;                 /* +0x09 (0x4f8a9)                     */
    u8  zone_b;                  /* +0x0a (0x4f8aa) 0..3                */
    u8  speed_b;                 /* +0x0b (0x4f8ab)                     */
};

static inline u8 zone_of(s16 v)  /* magnitude -> 4-level bucket */
{
    s16 m = v < 0 ? -v : v;      /* abs */
    if (m >= 0x7e) return 3;
    if (m >= 0x5a) return 2;
    if (m >= 0x28) return 1;
    return 0;
}

static inline u8 speed_of(float rate)   /* rate -> repeat/accel nibble */
{
    int f = (int)(rate * 65536.0f / DAT_00692d28 + 0.5f);   /* 16.16, rounded */
    return (u8)((4u - (u8)(((u32)f & 0xffff) >> 0xc)) & 0xf);
}

void analog_input_to_cursor(void)
{
    struct cursor_input *c = (void*)(iRam00701068 + 0x4f8a0);
    const u8 *pad = (const u8*)iRam0029a528;   /* processed pad/analog struct */

    c->x_prev = c->x;                                  /* latch previous X */
    c->x      = (s16)*(u32*)(pad + 0x08);
    c->axis_y = (s16)*(u32*)(pad + 0x10);
    c->axis_2 = (s16)*(u32*)(pad + 0x14);

    c->zone_a  = zone_of(*(s16*)(pad + 0x20));         /* channel A magnitude */
    c->speed_a = speed_of(*(float*)(pad + 0x24));      /* channel A rate      */

    c->zone_b  = zone_of(*(s16*)(pad + 0x2c));         /* channel B magnitude */
    c->speed_b = speed_of(*(float*)(pad + 0x30));      /* channel B rate      */
}
```
(The original writes `zone` as `3` first and narrows it via the short-circuit chain; the `zone_of`
ladder above is behaviourally identical.)

## Evidence
- Raw decompile FUN_005deb00.c: prev-X latch (11), pointer/axis stores from pad+8/+0x10/+0x14
  (12-14), zone seed `3` (15-16), channel-A abs + threshold ladder 0x7e/0x5a/0x28 (17-23), channel-A
  speed nibble from pad+0x24 float via `*65536.0 / DAT_00692d28 + 0.5`, `&0xffff`, `>>0xc`, `4 - n`
  (25-27), channel-B identical block from pad+0x2c/+0x30 (28-38).
- Single caller FUN_005c8810 (overlay per-frame update). Confidence **High** on structure/arithmetic;
  runtime-unvalidated.

## Remaining uncertainty
- The precise physical meaning of pad offsets (+0x08/+0x10/+0x14 as X/Y/secondary, +0x20/+0x2c vs
  +0x24/+0x30 as magnitude/rate pairs) is inferred from the store pattern, not from the pad-struct
  definition; likely two analog axes (or two sticks) each giving a magnitude + a rate.
- `DAT_00692d28` is a scale divisor whose exact value/units were not read.
- Field names in `struct cursor_input` are inferred; only the offsets and value flow are certain.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005deb00.c`  — untouched decompiler output.
