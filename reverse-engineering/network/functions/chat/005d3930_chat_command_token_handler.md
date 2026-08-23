# 0x005d3930 menu_link_token_dispatch

| field | value |
|---|---|
| Original address | 0x005d3930 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d3930 |
| Resolved name | menu_link_token_dispatch (was chat_command_token_handler) |
| Subsystem | chat |
| Relevance | support |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005d1e80
**Callees:** FUN_005cf5f0, FUN_005d09d0, FUN_005d59f0, FUN_005d5a40, FUN_005d5b60, FUN_005d5c20, FUN_005d5cc0, FUN_005d74a0, FUN_005d7540, FUN_005dedf0
**Referenced globals:** `iRam00701068` (widget/link array base; `+0x5ffc0` = 500× ptr, stride 4); `iRam00701070` (view state: +0x2e screen mode, +0x38/+0x3a busy/err, +4/+8 cursor xy, +0x30/+0x34 flags, +0x3b/+0x43b scratch, +0x55d name); `iRam00701078` (action-request block: +1/+2 pending, +0x20); `iRam00701080` (compose/profile state); `pcRam00701088` (0x1d0 profile buffer); `0x870f10` (profile save slot, 0x1d0); counters `+0x60dc9`/`+0x60dc7/8`/`+0x60dce`, next-action `+0x68e85`; page-dir `uRam00701e18`; `uRam00700fe8`
**Referenced strings:** command tokens str@0x642e30/e40/e50/e60/e80/ec0/ee0/f00/f20/f40/d80/f60; anchor/url marker str@0x642f78; field-key str@0x642c20/c28; status str@0x642ea0 (all `str@`-only in the index — text unresolved)
**Referenced opcodes:** —
**State vars:** `iRam00701070+0x2e` (screen mode: 8 = compose/edit, 0x0a = board/view, 1 = other)

## Behavioral explanation
Handler for a **selected UI "link" widget** on the online message-board / mail (BBS) screens. Given a
selection index, it fetches the widget pointer from the 500-slot array at `701068+0x5ffc0` and reads the
widget's associated **command string** at `widget+0x60`. If non-empty, it matches that string against a
cascade of literal command **tokens** (each `0x642exx`) via `strncmp`, and drives the corresponding
navigation/action. The active behavior for each token depends on the current **screen mode** at
`701070+0x2e` (8 = compose/edit, 0x0a = board/view). Effects fall into families:
- **page navigation** — set page-direction `701e18` (1 = prev, 2 = next) and call `FUN_005d5b60(0)`, or in
  compose mode call `FUN_005d5c20(0xb/0xc)`.
- **next-screen request** — write `701068+0x68e85` (7/8/9/10) plus `701078+1`/`+2` (a pending-op tuple),
  gated by a "profile complete?" check over `pcRam00701088` bytes.
- **field extraction** — for the `#`-prefixed anchor and delimited tokens, copy a sub-field of the command
  string in-place / into scratch (`701070+0x3b`), or parse a decimal page number into `701068+0x60dc9`.
- **submit/save** — snapshot the profile buffer to/from `0x870f10` (0x1d0 bytes), stage field keys via
  `FUN_005d7540`, then refresh via `FUN_005d59f0`/`FUN_005d5a40`.
- **anchor resolve** — if the string starts with `#`, scan all 500 widgets for a matching named anchor
  (type byte `+2 == 0x0e`) and move the view cursor (`701070+4/+8`) to that widget's float xy (`+0x34/+0x38`),
  clamped to the screen.

The whole body is gated at entry by "not busy / no error" (`701070+0x38 == 0 && +0x3a == 0`).

## Input / output
- `param_1` (int) — selection index into the widget array (used as `param_1*4`).
- Returns `void` (several branches `return` early).

## Widget object (element of `701068+0x5ffc0`, ptr array of 500)
| off | type | meaning |
|---|---|---|
| +0x00 | u8 | live flag (non-zero = present) |
| +0x02 | u8 | type (`0x0e` = named anchor) |
| +0x34 | float | anchor X |
| +0x38 | float | anchor Y |
| +0x60 | char* | command/link string (the token dispatched on) |

## Side effects
- In-place edits to the widget command string (field extraction / `#`-truncation).
- `uRam00701e18` = 1/2 (page direction); `701068+0x60dc9` = parsed page number.
- `701068+0x68e85` = 7/8/9/10, `701078+1` = 5/6/8, `701078+2` = 1 (pending next-screen tuple).
- `memcpy(0x870f10 ⇄ 701088, 0x1d0)` — profile save/restore.
- `FUN_005d7540(key,val)` — stage field key/values (`0x642c20`,`0x642c28`).
- View cursor `701070+4/+8` repositioned to a resolved anchor; misc flags `701070+0x30/0x34`, `701068+0x60dc7/8`, `700fe8`, `701078+0x20`.
- Redraw/refresh via `FUN_005d59f0`, `FUN_005d5a40`, `FUN_005d5cc0` (set status text), `FUN_005dedf0` (open link/url).

## Important branches
- **Entry gate:** `701070+0x38 != 0 || +0x3a != 0` → no-op.
- **Empty string:** `strlen(widget+0x60) == 0` → no-op.
- **Token cascade** (first `strncmp==0` wins; each further gated by screen mode `+0x2e`):
  - `e30`: mode `0x0a` → `FUN_005d09d0()`.
  - `e40`: mode 8 → `FUN_005d5c20(0xb)`; else `701e18=1, FUN_005d5b60(0)`  (prev page).
  - `e50`: mode 8 → `FUN_005d5c20(0xc)`; else `701e18=2, FUN_005d5b60(0)`  (next page).
  - `e60`: mode 8 → return; else extract the Nth `;`-delimited field (N = `701068+0x4f8b9`) into the string, then fall to `e80` group.
  - `e80`: mode != 8 → `FUN_005d5cc0(str@e a0); FUN_005d59f0()` (set status + refresh).
  - `ec0`: mode `0x0a` → profile-complete check over `pcRam00701088[{0,0x41,0x4c,0xcd,0x14e,0x14f}]`; all set → `68e85=7,(701078+1)=5`; any clear → `68e85=8,(701078+1)=6`; `(701078+2)=1`.
  - `ee0`: mode `0x0a` → `68e85=9,(701078+1)=8,(701078+2)=1`.
  - `f00`: mode `0x0a` → `68e85=10,(701078+1)=8,(701078+2)=1`.
  - `f20`: mode != 8 → parse decimal digits (after token) into `701068+0x60dc9` (`acc = acc*10 + digit`), `701e18=1, FUN_005d5b60(0)`.
  - `f40`: `memcpy(0x870f10, 701088, 0x1d0)` (save profile); mode 8 → `FUN_005d5c20(0xb)`; else `701e18=1, FUN_005d5b60(0)`.
  - `d80`: `memcpy(701088, 0x870f10, 0x1d0)` (restore profile); mode 8 → `FUN_005d5c20(0xc)`; else `701e18=2, FUN_005d5b60(0)`.
  - `f60`: submit — if `701080+0x11d` and `701080+0x11` non-empty: set status, `FUN_005cf5f0()`, stage keys `642c20`/`642c28` via `FUN_005d7540`, set submit flags, then mode 8 → `FUN_005d5c20(9)`; else `FUN_005d74a0(701068+0x4f97c); 700fe8=1; FUN_005d5a40()`.
  - **`#`-prefix** (no token matched, first char `#`): scan 500 widgets; match `[0]!=0 && [2]==0x0e && strcmp(widget[i]+0x60, str)==0` → move view cursor `701070+4/+8` to `widget[i]` float xy (`+0x34/+0x38`), clamped `[0, view-extent]`; return.
  - **default** (no token, not `#`): `701068+0x60dce=1`; `strstr(str, str@0x642f78)` → if absent `FUN_005d5cc0(str)` (show as status); else split at `#` into scratch `701070+0x3b`, copy tail (`642f78` match) into `701070+0x43b`, and `FUN_005dedf0(701068+0x4f97c, 701070+0x3b)` (open link/url); then `(701078+0x20)=0`; mode 8 → `FUN_005d5c20()`; else `FUN_005d59f0()`.

## Constants & flags
- Screen modes (`701070+0x2e`): `8` = compose/edit, `0x0a` = board/view, `1` = other (each token acts only in specific modes).
- Page direction `701e18`: `1` = prev, `2` = next.
- Next-screen tuple `68e85`: `7/8/9/10`; paired `701078+1`: `5/6/8`.
- Anchor type `widget+2 == 0x0e`.
- Profile buffer size `0x1d0`; save slot `0x870f10`.
- Widget array size **500**, stride 4 (pointers).

## Corrected reconstruction
```c
// BBS/mail link-token dispatcher. Tokens 0x642exx are literal command keywords
// (text unresolved in the string index — names below are [inferred]).
void menu_link_token_dispatch(int sel /*param_1*/)
{
    view_state *V = (view_state*)iRam00701070;
    if (V->busy /*+0x38*/ != 0 || V->err /*+0x3a*/ != 0) return;

    widget **arr = (widget**)(iRam00701068 + 0x5ffc0);
    char *s = arr[sel]->cmd /*+0x60*/;
    if (strlen(s) == 0) return;
    u8 mode = V->screen_mode /*+0x2e*/;   // 8=compose, 0x0a=board

    if      (MATCH(s, TOK_E30)) { if (mode==0x0a) FUN_005d09d0(); }
    else if (MATCH(s, TOK_E40)) { if (mode==8) FUN_005d5c20(0xb); else { page_dir=1; FUN_005d5b60(0);} } // prev
    else if (MATCH(s, TOK_E50)) { if (mode==8) FUN_005d5c20(0xc); else { page_dir=2; FUN_005d5b60(0);} } // next
    else if (MATCH(s, TOK_E60)) {
        if (mode==8) return;
        extract_semicolon_field(arr[sel], /*idx=*/*(u8*)(iRam00701068+0x4f8b9));  // in-place
        goto status_group;
    }
    else {
      status_group:
        if      (MATCH(s, TOK_E80)) { if (mode!=8){ set_status(TOK_EA0); FUN_005d59f0(); } }
        else if (MATCH(s, TOK_EC0)) { if (mode==0x0a) request_next(profile_complete()?7:8, profile_complete()?5:6); }
        else if (MATCH(s, TOK_EE0)) { if (mode==0x0a) request_next(9, 8); }
        else if (MATCH(s, TOK_F00)) { if (mode==0x0a) request_next(10, 8); }
        else if (MATCH(s, TOK_F20)) { if (mode!=8){ page_num = parse_dec(s+strlen(TOK_F20)); page_dir=1; FUN_005d5b60(0);} }
        else if (MATCH(s, TOK_F40)) { memcpy((void*)0x870f10, (void*)0x701088, 0x1d0);         // save profile
                                      if (mode==8) FUN_005d5c20(0xb); else { page_dir=1; FUN_005d5b60(0);} }
        else if (MATCH(s, TOK_D80)) { memcpy((void*)0x701088, (void*)0x870f10, 0x1d0);         // restore profile
                                      if (mode==8) FUN_005d5c20(0xc); else { page_dir=2; FUN_005d5b60(0);} }
        else if (MATCH(s, TOK_F60)) { submit_compose(); }                                       // stage keys + send
        else if (s[0]=='#')         { resolve_anchor(s); }                                       // move cursor to anchor
        else                        { open_link_or_status(s); }                                  // url via FUN_005dedf0 or status
    }
}
```

## Evidence
- Raw: `sources/overlays/overlay-3dat-decompile/FUN_005d3930.c` (size 3396; 1 caller, 10 callees). Full token cascade, mode gates, profile memcpy (0x1d0 @0x870f10), 500-widget anchor scan, and float-xy cursor move all read directly.
- Helper identities: `func_0x0010a050`=strlen, `func_0x00106910`=strncmp, `func_0x0010a700`=strstr, `func_0x00109d70`=strcmp, `func_0x001069a8`=memcpy, `func_0x00106b60`=memset, `func_0x00109eb8`=strcpy.
- `str@0x642c20` tagged "field-key" in strings index (supports the submit-stage interpretation).
- Confidence **Medium**: control flow & structural offsets are certain; the *keyword text* of each token (e30…f60) is unresolved, so per-token names are inferred from their side effects.

## Remaining uncertainty
- The literal text of every `0x642exx` token (index carries `str@`-only placeholders) — the strongest single lever for promoting this to High; a data dump of 0x642e30.. would name them.
- Exact meaning of the `68e85`/`701078+1,+2` next-screen tuple values (7/8/9/10 ↔ 5/6/8).
- Whether screen mode `8` is "compose" vs. "preview" (inferred from FUN_005d5c20 usage), and mode `0x0a` = board vs. thread view.
- `FUN_005dedf0` treated as "open link/url"; unproven.
