# 0x005f1a80 ui_column_minwidth_propagate

| field | value |
|---|---|
| Original address | 0x005f1a80 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f1a80 |
| Resolved name | ui_column_edge_reconcile |
| Subsystem | ui |
| Relevance | unrelated |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f1da0 (table column layout)
**Callees:** — (leaf)
**Referenced globals:** none (operates purely on the two edge arrays passed in)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Row-to-accumulator reconciliation used while building the table's column model. `param_1` is the running
**accumulator** edge array (the widest column model seen so far) and `param_2` is the **current row's**
edge array; both are cumulative `ColEdge` arrays (byte flags + u16 edge, stride 4). For each column it
compares the two cumulative edges and shifts the trailing edges of one array so both agree on the wider
column boundary — i.e. it merges a new row's column requirements into the accumulated maximum, honoring
a colspan flag (bit 0x1) that means "this edge is spanned, push the span rather than the single column"
and a no-shrink flag (bit 0x8) that forbids narrowing. The net effect is `acc[i] = max`-consistent
cumulative edges after every row is folded in.

## Input / output
- `param_1` — accumulator edge array (cumulative). Edges and flags updated in place.
- `param_2` — current row edge array (cumulative). Also adjusted in place to stay consistent.
- `param_3` — column count.
- Returns void.

## Important branches
- Iterate `i` over columns; `pbVar5 = &acc[i]`, `pbVar4 = &row[i]`.
- `acc[i].flags & 1 == 0` (acc column not spanned):
  - `row[i].flags & 1 == 0` (row not spanned): if `acc.edge < row.edge` push all *acc* trailing edges
    right by the diff (row is wider); else if `row.edge < acc.edge` and `row.flags&8==0` push all *row*
    trailing edges right (acc is wider, row may grow).
  - `row[i].flags & 1 != 0` (row column spanned): fold the span — widen acc/row trailing edges and copy
    the spanned flag; handles the sub-loop at `LAB_005f1c88` walking to the span end.
- `acc[i].flags & 1 != 0` (acc column spanned): symmetric handling — if row narrower, propagate the
  difference forward; if row wider and not no-shrink, grow row; copy flags at span boundaries.

## Constants & flags
- edge flag bit `0x1` = column is part of a colspan (spanned edge, not a real column boundary).
- edge flag bit `0x8` = no-shrink / fixed (do not widen this array to match).

## Corrected reconstruction
```c
// Merge one row's cumulative column edges (row) into the running accumulator (acc).
// Both are ColEdge{ u8 flags; u8 _; u16 edge; } cumulative arrays, stride 4.
void ui_column_edge_reconcile(ColEdge* acc /*p1*/, ColEdge* row /*p2*/, int ncol /*p3*/) {
    for (int i = 0; i < ncol; ) {
        ColEdge* a = &acc[i];
        ColEdge* r = &row[i];

        if ((a->flags & 1) == 0) {                       // acc column is a real boundary
            if ((r->flags & 1) == 0) {                   // row column also real
                u16 re = r->edge, ae = a->edge;
                if (ae < re)                             // row wider -> grow acc tail
                    for (int j=i; j<ncol; j++) acc[j].edge += (re-ae);
                else if (re < ae && (r->flags & 8)==0)   // acc wider -> grow row tail
                    for (int j=i; j<ncol; j++) row[j].edge += (ae-re);
                i++;
            } else {                                     // row column spanned
                u16 re=r->edge, ae=a->edge;
                if (ae < re) {                           // widen acc to the span, walk to span end
                    a->edge = re;
                    int j=i;
                    do { j++;
                         if (j<ncol) { ColEdge* p=&acc[j];
                             u16 pe0=acc[j-1].edge, pe=p->edge;
                             if (pe < pe0) {
                                 if ((p->flags & 1)==0) { p->edge = pe0; continue; }
                                 for (; j<ncol; j++) acc[j].edge += (pe0-pe);
                                 a->flags = r->flags; goto done;
                             }
                         }
                         a->flags = r->flags; done: ; 
                    } while (0);
                } else if (re < ae) {                    // acc wider: shrink row across the span
                    int j=i;
                    while (j<ncol && (row[j].flags & 1)==0) { j++; row[j-1].edge -= (ae-re); }
                    a->flags = r->flags;
                }
                i++;
            }
        } else {                                         // acc column is spanned
            u16 re=r->edge, ae=a->edge;
            if ((r->flags & 1)==0) {                      // row real vs acc span
                if (ae < re) { int j=i; while (j<ncol && (row[j].flags&1)==0){ j++; row[j-1].edge -= (re-ae);} }
                else if (re < ae && (r->flags & 8)==0)   for (int j=i;j<ncol;j++) row[j].edge += (ae-re);
                i++;
            } else {                                      // both spanned
                if (re <= ae) { if (re<ae && (r->flags&8)==0) for(int j=i;j<ncol;j++) row[j].edge += (ae-re); }
                else for (int j=i;j<ncol;j++) acc[j].edge += (re-ae);
                i++;
            }
        }
    }
}
```

## Evidence
- Raw: `FUN_005f1a80.c` (792 bytes). Only caller FUN_005f1da0 invokes it twice per row — once for the
  min-edge accumulator, once for the pref-edge accumulator (matching the two arrays 16b0 later consumes).
- Flag bits 0x1 (span) and 0x8 (no-shrink) match the values FUN_005f1da0 writes into `auStack_180`/
  `abStack_200` (0x1 for real cells, 0x8 for colspan-synthesized edges).

## Remaining uncertainty
- The spanned-column inner walk (`LAB_005f1c88`/`LAB_005f1c80`) is control-flow-preserved but its exact
  edge-copy corner cases are intricate; behavior kept verbatim. High confidence on the min/max
  reconciliation intent, no runtime trace, no network relevance.
