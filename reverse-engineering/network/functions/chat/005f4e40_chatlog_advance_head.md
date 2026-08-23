# 0x005f4e40 chatlog_advance_head

| field | value |
|---|---|
| Original address | 0x005f4e40 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f4e40 |
| Resolved name | chatlog_ring_advance_head |
| Subsystem | chat |
| Relevance | support |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f50d0 (chatlog_push_msg)
**Callees:** —
**Referenced globals:** iRam003435d4 (chat-block base); base+0xc9358 head; base+0xc935c view/scroll; base+0xc9360 tail; cRam006c50fb (log-mode flag)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** head +0xc9358, tail +0xc9360, view +0xc935c

## Behavioral explanation
Commits one just-written slot into the 50-entry chat ring by advancing the head (write) cursor,
and — when the ring is full — dropping the oldest entry by advancing the tail. In scroll/history
mode (`cRam006c50fb != 0`) it keeps the manual view anchor pinned to the oldest visible entry so
that dropping the oldest slot doesn't leave the view pointing at reclaimed data. Called once per
log line committed by `chatlog_push_msg` (0x5f50d0), after that fn has filled the slot at the
current head.

Ring geometry: 50 slots (`0x32`), indices wrap by subtracting `0x32`. `head` = next write slot,
`tail` = oldest live slot, `view` = top-of-window anchor used by the renderer (0x5f54d0).

## Input / output
- No parameters, no return (`void`). Operates entirely on the global ring cursors.

## Side effects
- `head = (head + 1) mod 50`.
- If the incremented `head == tail` (ring wrapped onto oldest): `tail = (tail + 1) mod 50` (evict oldest).
  - And if `cRam006c50fb != 0` AND the pre-increment `tail == view`: `view = tail` (re-pin view to new oldest).

## Important branches
- `if (head > 0x31) head -= 0x32;` — head wrap. (post-increment normalize)
- `if (head == tail)` — ring became full; evict oldest by advancing tail (with its own `> 0x31 -> -0x32` wrap).
- Nested: `if (cRam006c50fb != 0 && old_tail == view)` — only in history/scroll mode, and only when the
  view was sitting on the entry being evicted, re-anchor `view = tail`. In live mode (`==0`) the view is
  recomputed each frame by the renderer, so no re-pin is needed.

## Constants & flags
- `0x32` (50) — ring capacity / wrap modulus.
- `0x31` (49) — last valid index (wrap threshold).
- `cRam006c50fb` — log-mode flag: `0` = live/auto-follow (renderer recomputes view), `!=0` = scroll/history
  (view is a persistent manual anchor that must be maintained here). [inferred semantics, consistent across 0x5f4e40/0x5f5300/0x5f54d0]

## Corrected reconstruction
```c
#define CHAT_RING_CAP 0x32   // 50 slots

typedef struct {             // fields at iRam003435d4 + ...
    // ... slot arrays at +0xc8000 (see chatlog_push_msg) ...
    int head;   // +0xc9358  next write slot
    int view;   // +0xc935c  renderer top-of-window anchor
    int tail;   // +0xc9360  oldest live slot
} ChatRing;  // [inferred layout]

void chatlog_ring_advance_head(void)
{
    ChatRing *r = (ChatRing *)iRam003435d4;   // via +0xc9358 etc.

    if (++r->head > CHAT_RING_CAP - 1)
        r->head -= CHAT_RING_CAP;             // wrap

    int old_tail = r->tail;
    if (r->head == old_tail) {                // ring full -> evict oldest
        if (++r->tail > CHAT_RING_CAP - 1)
            r->tail -= CHAT_RING_CAP;
        if (cRam006c50fb != 0 && old_tail == r->view)
            r->view = r->tail;                // keep scroll anchor valid
    }
}
```

## Evidence
- Raw: `FUN_005f4e40.c` — head `+0xc9358` incremented then `if (0x31 < ...) -= 0x32`; full-check
  `head == *(+0xc9360)`; tail advance + wrap; guarded `cRam006c50fb != '\0' && iVar1 == *(+0xc935c)`
  re-pin `+0xc935c = +0xc9360`.
- Sole caller `FUN_005f50d0` calls it right after populating the head slot => "commit" semantics.
- Same three cursors are consumed by the renderer `FUN_005f54d0`, confirming head/view/tail roles.

## Remaining uncertainty
- Direction convention (whether "head" is newest vs the array is filled ascending) is inferred from
  the caller/renderer; the arithmetic itself is unambiguous. No runtime trace (High, not Confirmed).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f4e40.c`  — untouched decompiler output.
