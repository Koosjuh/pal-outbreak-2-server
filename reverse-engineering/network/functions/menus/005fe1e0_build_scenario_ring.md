# 0x005fe1e0 build_scenario_ring

| field | value |
|---|---|
| Original address | 0x005fe1e0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005fe1e0 |
| Resolved name | build_available_scenario_ring |
| Subsystem | menus |
| Relevance | support |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f78c0, FUN_005f9280 (scenario-select screen enter/rebuild)
**Callees:** FUN_005bae80 (per-profile available-scenario mask A), FUN_005baed0 (per-profile forced/override mask B), func_0x00106b60 (memset)
**Referenced globals:** uRam003424e8 global scenario-unlock bitmask; bRam006c45f8 current profile/character index; ctx +0x4ba ring array (12×short); +0x53a valid count; +0x53c ring cursor; +6 current selection value; +4 sub-state
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x53c ring cursor; +4 sub-state

## Behavioral explanation
Builds the **selectable-scenario ring** for the scenario picker. It combines three bitmasks — the globally-unlocked scenarios (`uRam003424e8 >> 1`), the current profile's available set (`FUN_005bae80`), and a forced/override set (`FUN_005baed0`) — into an availability mask over scenarios 0..10, then writes the index of each available scenario into a ring array (`+0x4ba`, indexed 1..11) and counts them (`+0x53a`). Finally it positions the cursor (`+0x53c`) on the first valid entry and latches the current selection value (`+6`). Data-model builder; no network opcodes.

## Input / output
- **param_1** (`int`, screen_ctx*): scenario-select context; ring at +0x4ba, count +0x53a, cursor +0x53c, current-value +6, sub-state +4.
- **returns** `void`.

## Side effects
- `memset(+0x4ba, 0xFF, 0x40)` — clear ring to all -1 (empty).
- +0x53a = number of available scenarios.
- +0x4ba[k] = k for each available scenario k (1..11).
- +0x53c = first valid ring index (cursor).
- +6 = ring[cursor] (current selection); +4 = 0 (reset sub-state).

## Important branches
- **availability build (bits 0..10):** for `k = 1..11`, test bit `(k-1)` of `avail = ((uRam003424e8>>1) & maskA) | maskB`; if set → ring[k]=k, count++. (`maskA=FUN_005bae80(profile-1)`, `maskB=FUN_005baed0(profile-1)`, profile=`bRam006c45f8`.)
- **first-valid search:** starting at ring index 1, scan forward (byte offset `iVar5 = iVar6<<1`) up to 0x11 iterations; on first entry `>= 0` → jump to set cursor. The `if (iVar6 < 1) iVar6 = 0xb` wrap is effectively dead (iVar6 only increments). If none found in 0x11 steps, cursor falls back to 1.
- **finalize:** +0x53c = found index; +6 = ring[index]; +4 = 0.

## Constants & flags
- `0x40` = memset length (ring = 32 bytes / 16 shorts; slots 0..11 used).
- Ring maps **bit k → scenario slot k+1**; slot 0 stays empty (-1).
- `uRam003424e8 >> 1` = global unlock mask shifted (bit 0 dropped / 1-based) [inferred: skips a reserved bit].
- `0x11` (17) = max search iterations for first-valid.
- profile arg = `bRam006c45f8 - 1`.

## Corrected reconstruction
```c
// Build the ring of available scenarios and pick the initial cursor.
void build_available_scenario_ring(screen_ctx *s)   // param_1
{
    memset(&s->scen_ring, 0xFF, 0x40);               // +0x4ba, all -1
    s->scen_count = 0;                               // +0x53a

    u32 global   = uRam003424e8 >> 1;
    u32 maskA    = scenario_avail_mask(bRam006c45f8 - 1);   // FUN_005bae80
    u32 maskB    = scenario_force_mask(bRam006c45f8 - 1);   // FUN_005baed0
    u32 avail    = (global & maskA) | maskB;

    for (int k = 1; k < 12; k++) {                   // bit k-1 -> slot k
        if (avail & (1u << ((k - 1) & 0x1f))) {
            s->scen_ring[k] = (short)k;
            s->scen_count++;
        }
    }

    int idx = 1, tries = 0;
    while (s->scen_ring[idx] < 0) {                  // find first valid
        idx++;                                       // (wrap-to-0xb branch is dead)
        if (++tries >= 0x11) { idx = 1; break; }
    }
    s->scen_cursor = (short)idx;                     // +0x53c
    s->scen_current = s->scen_ring[idx];             // +6
    s->substate = 0;                                 // +4
}
```

## Evidence
- Raw decompile `FUN_005fe1e0.c` (mask combine, ring fill, first-valid search exact).
- `FUN_005bae80`/`FUN_005baed0` return per-profile scenario masks (callee naming from usage: ANDed vs ORed into availability).
- Consumed by the scenario nav helper (cursor at +0x53c) — cross-ref FUN_005f9f60 per prior classification.
- Runtime-unvalidated.

## Remaining uncertainty
- Why `uRam003424e8` is shifted right by 1 (reserved bit-0 vs. 1-based scenario numbering) is inferred, not confirmed.
- Distinction between mask A (ANDed) and mask B (ORed) — likely "unlocked-and-owned" vs "always-available/demo" — not traced into the callees.
- The dead wrap branch suggests the search was meant to be circular; harmless as compiled.
```
