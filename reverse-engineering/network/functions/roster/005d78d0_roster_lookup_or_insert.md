# 0x005d78d0 roster_lookup_or_insert

| field | value |
|---|---|
| Original address | 0x005d78d0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d78d0 |
| Resolved name | session_node_lookup_or_insert |
| Subsystem | roster |
| Relevance | core |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005d7f80
**Callees:** FUN_005d6a70 (find active node by key), FUN_005d6c10 (find/reserve node slot by key), FUN_005d6b40 (pick eviction victim), FUN_005d6ce0 (release node)
**Referenced globals:** iRam00701068+0x4f47c session-node pool head; cRam00701000 request mode
**Referenced strings:** —
**Referenced opcodes:** — (enter/create/member txn commit)
**State vars:** cRam00701000 mode; node+0x104 state; node+0x108 who-byte

## Behavioral explanation
Look-up-or-insert against the session-node pool (`+0x4f47c`), keyed by `param_1`. Two outcomes:
1. **Not found active** (FUN_005d6a70 → 0): reserve a slot for the key (FUN_005d6c10); if the pool is full, evict a victim (FUN_005d6b40 → FUN_005d6ce0) and retry the reserve; set the (new) node's state (`+0x104`) to **3** (in-progress) and return it.
2. **Found active**: only usable if its state is **5** (idle/waiting). In mode `cRam00701000==5` with a who-byte mismatch (`node+0x108 != *param_3`) it releases the node and returns 0 (conflict — a different owner holds the key); otherwise it reactivates the node to state **2** and returns it. A found node in any state other than 5 → return 0 (busy/wrong phase).

This is the commit gate for the enter/create/member transaction: it hands the caller a node in state 3 (fresh) or 2 (reactivated), or 0 to reject.

## Input / output
- `param_1` — `key` : session/room key (opaque, passed to the pool find/reserve helpers).
- `param_2` — unused here (forwarded elsewhere by the caller).
- `param_3` — `char *` : who-byte to compare against `node+0x108` in the mode-5 conflict check.
- returns `node *` (long) or `0` on reject.

## Side effects
- May allocate a pool node (reserve) or evict+release the oldest (FUN_005d6ce0).
- Sets `node+0x104` (state) to 3 (new) or 2 (reactivated).
- Releases a conflicting node (mode-5 who-byte mismatch).

## Important branches
- `FUN_005d6a70(pool,key) == 0` (no active node):
  - `FUN_005d6c10(pool,key) == 0` (no free slot) → `FUN_005d6ce0(FUN_005d6b40(pool))` (evict oldest), then `node = FUN_005d6c10(pool,key)` (retry).
  - `node+0x104 = 3`; return node.
- active node found:
  - `node+0x104 == 5`:
    - `cRam00701000 == 5 && node+0x108 != *param_3` → `FUN_005d6ce0(node)`, return 0.
    - else → `node+0x104 = 2`, return node.
  - else → return 0.

## Constants & flags
- Node state (`+0x104`): 2 = reactivated/committed, 3 = in-progress (new), 5 = idle/waiting (joinable).
- `cRam00701000 == 5` = request mode "enter/create" (matches PACKET_INDEX session_enter_dispatch subtype 5).
- `node+0x108` = who-byte (roster ownership tag).

## Corrected reconstruction
```c
// pool head @ iRam00701068 + 0x4f47c ; node+0x104=state, node+0x108=whobyte
long session_node_lookup_or_insert(key_t key, void *unused, char *whobyte)
{
    node_t *n = FUN_005d6a70(POOL, key);          // active node by key?
    if (n == 0) {                                  // insert path
        n = FUN_005d6c10(POOL, key);               // reserve slot
        if (n == 0) {
            FUN_005d6ce0(FUN_005d6b40(POOL));      // evict oldest
            n = FUN_005d6c10(POOL, key);           // retry (now succeeds)
        }
        n->state = 3;                              // in-progress
        return (long)n;
    }
    // found active
    if (n->state == 5) {
        if (cRam00701000 == 5 && n->whobyte != *whobyte) {
            FUN_005d6ce0(n);                       // conflicting owner -> reject
            return 0;
        }
        n->state = 2;                              // reactivate
        return (long)n;
    }
    return 0;                                       // wrong phase -> reject
}
```

## Evidence
- Raw: `FUN_005d78d0.c` — the `0x4f47c` pool, FUN_005d6a70/6c10/6b40/6ce0 call structure, `+0x104` states 3/2/5, `cRam00701000=='\x05'`, `+0x108 != *param_3` conflict release.
- GLOBALS.md: `0x004f47c` = "roster pool head"; `0x00701000` = "pending-req kind/mode".
- Mirrors PACKET_INDEX session_enter_dispatch (0x005d7760): find/create pool node (0x4f370 family), evict oldest, set state 3.

## Remaining uncertainty
The pool-helper semantics (FUN_005d6a70 active-find vs FUN_005d6c10 reserve-by-key) are inferred from the retry-after-evict pattern; not independently decompiled here. `param_2` is unused in this function but the caller (FUN_005d7f80) forwards it — role unknown. State value meanings (2/3/5) are consistent with the session-node model but runtime-unvalidated.
