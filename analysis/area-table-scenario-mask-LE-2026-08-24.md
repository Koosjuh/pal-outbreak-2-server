# Scenario "(null)" root cause: mode-mask byte order (snap-re trace, 2026-08-24)

**Question asked:** why does the scenario ring read an EMPTY area-table buffer?
**Verdict: the premise is FALSIFIED — there is no buffer selector and the ring read the
POPULATED bank.** The real cause is **byte order**: v2 serializes `+0x14`/`+0x18` as BE32; the
EE (R5900) is little-endian and the whole TCP 0x6204 path is memcpy-verbatim, so served
`0x000007FF` is loaded as `0xFF070000` — every set bit lands outside the ring loop's tested
bits 0..10.

## 1. FUN_005bac60 takes a literal, not a selector (Confirmed)
`overlay-3dat-decompile/FUN_005bac60.c:9`: `return *(u32*)(param_1*4 + 0x6c5480);`
Every record accessor calls it with constant **0** (FUN_005bae80/+0x14, FUN_005baed0/+0x18,
FUN_005baf20/+0x03, FUN_005baf70/+0x04, FUN_005bafc0/+0x01, FUN_005bb010/+0x02,
FUN_005bb060/+0x34, FUN_005bae30/+0x00). Only the diff FUN_005bb0b0.c:16-18 passes 1
(current vs previous). Nothing passes 2 — bank 2 (0x8d6f00, all zero) is dead scratch; zero is
its normal state. `~0x6c5498` is unrelated (GLOBALS.md: FUN_005fd630's).

## 2. The three banks and their writers (Confirmed)
- Publisher FUN_00606ea0.c:13-22: zeroes the 0x8000 arena at uRam003435d4, then
  `0x6c5480[i] = base + i*(0x17bb & ~0x3f)`. Check vs slot-1: 0x8d4000 → 0x8d5780 → 0x8d6f00
  — exactly the observed pointers (and this arithmetic decodes ONLY under LE storage:
  runtime proof the EE stores words little-endian).
- Filler FUN_005aeb10.c:26-30 (from FUN_005ae8a0 state 3): memcpy(bank1, bank0, 0x177c)
  snapshot; memset(bank0,0,len); memcpy(bank0, src, len) — len=uRam00697020,
  src=uRam00697028 ← FUN_006188b0.c:50-58 memcpy of the downloaded 0x6204 blob
  (uRam00368474=0x361a70) ← downloader FUN_001c4960/FUN_001c4d40.c:47 writes chunks verbatim.
- **Every hop is memcpy. NO byteswap on the TCP 0x6204 path** (contrast: the UDP SN@P path
  DOES swap — snap-lobby-codec.js:350 / FUN_001d81a4 — why BE is right there, wrong here).

## 3. The arithmetic (Confirmed, reproduces all three observed values)
FUN_005fe1e0.c:19-31: `avail = ((savedata0x3424e8>>1) & rec+0x14) | rec+0x18`, tests bits
0..10. Served BE `00 00 07 FF` → native LE load `0xFF070000` → avail=0xFF070000 → no bit in
0..10 → count 0, ring stays memset 0xFFFF → cursor -1 → FUN_005bac80(-1) → func_0x001b6f50
NULL → sprintf "%s" prints "(null)". Slot-1: 0x6c4b96=0xFFFF ✓, "(null)" on-screen ✓,
savedata 0x1e ✓ (irrelevant: +0x18 is OR-ed savedata-free).

Why only scenario broke: +0x14/+0x18 are the blob's ONLY multi-byte scalar loads; rules
(+0x16c/+0x1a8), cast (+0x03/+0x04..), enable (+0x14c) are byte reads (OBAREA-V5 fixed those
tonight); +0x1c/+0x34/+0x4c are strings.

## 4. Fix (implemented, this commit)
`area-table.js`: the two `writeUInt32BE` → **`writeUInt32LE`** (wire bytes `FF 07 00 00`);
comment corrected (old comment's "big-endian EE" was the load-bearing wrong fact). Also fixes
the second consumer FUN_005f78c0.c:49-62 (6-slot strip at 0x70b410, raw +0x14, same LE load).

## 5. Corrections + hazards recorded
- **RULES-MASK-RE.md §5's ring-count address was wrong:** screen ctx base = 0x6c4b90 →
  count = base+0x53a = **0x6c50CA** (not 0x6c4fca = base+0x43a, uninformative); ring
  0x6c504A..0x6c5089; cursor 0x6c50CC. Falsifier from now on: 0x6c4b96 (id 1..11) + 0x6c50CA
  (count 11).
- **Bank overflow hazard (latent):** bank 0 usable size is 0x1780 but the client's chunk guard
  allows 0x2000 — a blob in (0x1780, 0x2000] silently scribbles bank 1 (option labels ON =
  0x1F5C would do it). `AREA_TABLE_TRANSFER.maximumChunkLength` tightened 0x2000 → 0x1780.

## 6. Needs fresh Ghidra (small, ranked)
1. func_0x001b6f50 (scenario id → title string; confirms 1-based ids / that 0x7FF is the
   right mask — affects which bits, not byte order). 2. FUN_005f8e20→FUN_005f9150 arg (pins
   ctx literal 0x6c4b90 by construction). 3. FUN_005fd630 (the 0x6c5498 reader).

## 7. Verification
Local: in-process serialize assert `readUInt32LE(0x14)===0x7ff` (test added; version bumped —
byte change is deliberate). PINE/savestate on the create screen: 0x8d4014 = `FF 07 00 00`;
0x6c4b96 ∈ 1..11 (not 0xFFFF); 0x6c50CA = 11; row 8 shows a scenario name and left/right
walks the ring.

Provenance: snap-re agent trace over overlay-3dat + main-EE decompiles (file list in the
session transcript); filed by the goal session because the agent's harness could not write
analysis/.
