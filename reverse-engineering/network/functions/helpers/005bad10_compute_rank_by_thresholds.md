# 0x005bad10 compute_rank_by_thresholds

| field | value |
|---|---|
| Original address | 0x005bad10 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bad10 |
| Resolved name | compute_min_rank_over_records |
| Subsystem | helpers |
| Relevance | unrelated |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_00616d30, FUN_006173c0
**Callees:** — (`func_0x00106b60`=memset, `func_0x001069a8`=memcpy)
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Computes a rank/grade (0..3) for one stat column across `count` game records, returning the **minimum**
(worst) rank found. For each record it copies a 0xD4-byte stat block (from `record + 0x2a4`) to a
local buffer, reads the `idx`-th `u16` element of that block, and grades it against three ascending
byte thresholds at `thresholds + 0x12e8`: the grade is the number of thresholds the value meets/exceeds
(0,1,2, or 3). The function keeps the smallest grade seen over all records. This is a
stats/difficulty grading calc over the local save/session record array — no network involvement.

## Input / output
- `int param_1` — pointer to the first game record (stride `0x3b0`); the stat block is at `+0x2a4`.
- `int param_2` — pointer to the threshold table (three bytes at `+0x12e8`, `+0x12e9`, `+0x12ea`).
- `char param_3` — record count to scan.
- `char param_4` — column selector; only the low nibble (`& 0xf`, sign-adjusted) is used as the u16
  index into the copied stat block.
- Returns `char` — worst (minimum) rank over all scanned records, initialized to `3`.

## Side effects
None persistent — only a 0xD4-byte stack scratch buffer (`auStack_e0` / `auStack_a4` alias).

## Important branches
- `param_4 < 0 && (param_4 & 0xf) != 0` → `idx -= 0x10` (sign fix-up for the nibble). In practice
  callers pass small non-negative selectors, so `idx = param_4 & 0xf`.
- Outer loop `row = 0 .. param_3-1` — one grade per record; `param_1 += 0x3b0` each iteration.
- Inner loop `j = 0..2`: `if (thresholds[0x12e8 + j] <= stat[idx]) rank = j + 1;` — because thresholds
  are ascending, `rank` ends as the count of thresholds cleared (0..3).
- `if (rank < best) best = rank;` — accumulate the minimum. `best` starts at `3` (cap).

## Constants & flags
- `0x3b0` — game-record stride.
- `0x2a4` — offset of the stat block within a record.
- `0xd4` — stat-block size copied (contains a `u16[82]` array, `auStack_a4`).
- `0x12e8` — base offset of the 3-byte threshold triple within the threshold struct.
- `3` — max/initial rank; grades are 0..3.
- `0xf` — column-index mask (low nibble).

## Corrected reconstruction
```c
// Grades one stat column across `count` records; returns the worst (min) grade 0..3.
char compute_min_rank_over_records(GameRecord *rec, const RankTable *rt,
                                   char count, char col_sel) {
    int idx = col_sel & 0xf;                 // u16 column index
    if (col_sel < 0 && idx != 0) idx -= 0x10; // preserved sign fix-up
    char best = 3;

    for (int row = 0; row < count; row++) {
        u16 stats[0x6a];                     // 0xd4-byte block as u16[82]
        memset(stats, 0, 0xd4);              // func_0x00106b60
        memcpy(stats, (u8*)rec + 0x2a4, 0xd4); // func_0x001069a8

        char rank = 0;
        for (int j = 0; j < 3; j++) {
            // thresholds ascending -> rank = count of thresholds cleared
            if ((u8)rt->thr[j] /* *(char*)(param_2 + 0x12e8 + j) */ <= stats[idx])
                rank = (char)(j + 1);
        }
        if (rank < best) best = rank;

        rec = (GameRecord*)((u8*)rec + 0x3b0); // next record
    }
    return best;
}
```
Note: the inner compare uses a **signed char** load of the threshold widened to long and compared
against the zero-extended `u16` stat — preserved above via the `(u8)`/`<=` shape; exact signedness of
the threshold byte is a minor uncertainty.

## Evidence
- Raw decompile: outer `for (; lVar6 < param_3; ...)` with `param_1 += 0x3b0`; per-row memset/memcpy of
  0xD4 from `param_1 + 0x2a4`; inner `do { if ((long)*(char*)(iVar2+0x12e8) <= (ulong)auStack_a4[iVar1])
  cVar5 = iVar4 + 1; } while (iVar4 < 3)`; `if (cVar5 < cVar7) cVar7 = cVar5;` with `cVar7` init `3`.
- Callers `FUN_00616d30`, `FUN_006173c0` (stats/results screens, not deep-read). Runtime-unvalidated.

## Remaining uncertainty
Domain meaning (which stat column, what the 0..3 rank denotes — e.g. clear-rank / medal) not resolved;
signedness of the threshold byte load. Control flow itself is certain → Medium confidence.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bad10.c`  — untouched decompiler output.
