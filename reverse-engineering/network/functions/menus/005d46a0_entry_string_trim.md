# 0x005d46a0 entry_string_trim

| field | value |
|---|---|
| Original address | 0x005d46a0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d46a0 |
| Resolved name | section_room_entry_string_retrim |
| Subsystem | menus |
| Relevance | unrelated |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005d1e80 (on clicking a section header, kind 0x04)
**Callees:** —
**Referenced globals:** ui@0x701068 (entities[] +0x5ffc0)
**Referenced strings:** — (operates on per-entity packed name strings at +0x64)
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Invoked when a **section header** (entity kind 0x04) is clicked in the lobby list (FUN_005d1e80 sets the
header's `+5` expand flag, requests a redraw, then calls this with the header index). It first scans the
entity array to locate the clicked header while tracking the index of the most recent section separator
(kind 0x13). Once it reaches the clicked header (`iVar5 == param_1`), it walks forward from just after
that last separator and, for every **room entry** (kind 0x06/0x07) in the section, re-trims the entry's
packed display-string cursor at `+0x64`: it steps the `+0x64` char pointer back to the preceding NUL
boundary, writes a NUL there, and stores the adjusted pointer. The walk stops at the next 0x13
separator. Net effect: toggling the header re-slices which token of each room row's multi-field packed
string is shown (a display-only relabel of the section's rooms).

## Input / output
- Input: `param_1` = index of the clicked header entity (kind 0x04).
- Output: void.

## Side effects
- For each room entry in the section: mutates the packed name buffer (writes a NUL) and rewrites the
  entity's `+0x64` string-cursor pointer. No other state.

## Important branches
- Outer scan: track `last_sep` = index of most recent kind-0x13 entity; on the clicked header
  (`kind==0x04 && i==param_1`) → jump to the trim walk starting at `last_sep + 1`.
- Scan terminates (no match) on `i≥500` / NULL entry / empty (`byte0==0`).
- Trim walk: stop at `kind==0x13`; for `kind==0x06/0x07` with non-empty `+0x64` string → retrim; other
  kinds are skipped; NULL/empty terminates.

## Constants & flags
- Entity kinds: `0x04` section header (trigger), `0x06/0x07` room entries (retargeted), `0x13`
  section separator (boundary). `+0x64` = per-entity packed-string cursor (char*).

## Corrected reconstruction
```c
void section_room_entry_string_retrim(int header_idx)   // FUN_005d46a0
{
    int i = 0, last_sep = /*uninit -> effectively -1 until a 0x13 seen*/ 0;

    // locate the clicked header, remembering the last section separator
    for (;;) {
        Entity *e = (i < 500) ? (Entity*)ui->entities[i] : NULL;
        if (e == NULL || e->byte0 == 0) return;             // ran off the list, no header
        if (e->kind == 0x04) {
            if (i == header_idx) break;                     // found it -> trim from last_sep+1
            i++;                                            // (header does not move last_sep)
        } else if (e->kind == 0x13) {
            last_sep = i;                                   // section boundary
            i++;
        } else {
            i++;
        }
    }

    // retrim each room entry in this section
    for (int j = last_sep + 1; j < 500; j++) {
        Entity *e = (Entity*)ui->entities[j];
        if (e == NULL || e->byte0 == 0) return;
        if (e->kind == 0x13) return;                        // next section
        if (e->kind == 0x06 || e->kind == 0x07) {
            char *p = e->str_cursor;                        // +0x64
            if (*p != '\0') {
                char *q = p;
                do { p = q; q = p - 1; } while (p[-1] != '\0');  // back up to prior NUL
                *p = '\0';
                e->str_cursor = p;                          // advance +0x64 past the trimmed token
            }
        }
    }
}
```

## Evidence
- Raw: `sources/overlays/overlay-3dat-decompile/FUN_005d46a0.c` (size 324).
- Kinds 0x04/0x06/0x07/0x13 and the `+0x64` string field match FUN_005d1e80 (which calls this on a 0x04
  click) and FUN_005d19a0/FUN_005d2c20 (same entity layout, `+0x60`/`+0x64` string pointers).

## Remaining uncertainty
- The `in_t1_lo` register is uninitialized on the path where no separator precedes the header, so the
  precise starting index in that edge case is a decompiler artifact — treated here as 0/last_sep. The
  backward NUL-scan on `+0x64` is transcribed exactly but its intent ("re-slice packed multi-field
  string" vs "trim trailing token") is inferred; no runtime confirmation. Confidence **Medium**.
