# 0x005df7b0 url_ext_to_mimetype

| field | value |
|---|---|
| Original address | 0x005df7b0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005df7b0 |
| Resolved name | url_ext_to_content_type |
| Subsystem | helpers |
| Relevance | support |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005d76b0, FUN_005d7a30
**Callees:** FUN_005dee60 (locate filename/last path segment [inferred]), FUN_005deee0 (find last '.' / extension start [inferred])
**Referenced globals:** —
**Referenced strings:** — (literal char compares, no string table)
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Content-type sniffer by file extension. It locates the URL's last path segment (FUN_005dee60) and then the extension boundary (FUN_005deee0), which yields a pointer `p` to the '.' (chars at `p+1..`) and an end pointer (`extraout_a3`). It then does exact-length, case-insensitive extension matches and returns a small type code. Length is enforced by requiring the char *after* the extension to equal the end pointer (`p+4==end` for a 3-char ext, `p+5==end` for 4-char, `p+7==end` for 6-char), so only whole-extension matches count.

Recognized extensions -> code:
- `png` -> 2
- `bmp` -> 3
- `htm` -> 1
- `html` -> 1
- `mmbbin` (chars M,M,B,B,I,N) -> 4
- anything else, or no extension -> 0

## Input / output
- **param_1** `const char *url`, **param_2** — buffer/context passed through to the segment/extension locators.
- **return** `undefined4` (int) — content-type code: `0` unknown, `1` HTML, `2` PNG, `3` BMP, `4` MMBBIN.

## Side effects
None on globals. Relies on the locators' register outputs (`extraout_a2` = ext pointer, `extraout_a3` = end pointer) — decompiler artifacts of the a-register calling convention.

## Important branches
- `FUN_005deee0(...) == 0` -> return 0 (no extension found).
- 3-char block: chars at `+1,+2,+3` non-NUL and `p+4==end` -> test PNG(2)/BMP(3)/HTM(1); fall through if none.
- 4-char block: `+1..+4` non-NUL and `p+5==end` and chars == H,T,M,L -> return 1.
- 6-char block: `+1..+6` non-NUL and `p+7==end`; first char must be M/m else return 0; then M,B,B,I,N -> return 4.
- All comparisons OR the upper/lower-case pair (e.g. `'P' || 'p'`), i.e. case-insensitive.
- Default -> return 0.

## Constants & flags
- Type codes: `0`=unknown, `1`=HTML/HTM, `2`=PNG, `3`=BMP, `4`=MMBBIN (custom Outbreak resource, matched as 6-char "mmbbin").

## Corrected reconstruction
```c
enum content_type { CT_UNKNOWN=0, CT_HTML=1, CT_PNG=2, CT_BMP=3, CT_MMBBIN=4 };

// Sniff content type from a URL's file extension (case-insensitive).
int url_ext_to_content_type(const char *url, void *ctx)          // FUN_005df7b0
{
    const char *seg = filename_of_url(url, ctx, url);            // FUN_005dee60
    const char *dot = ext_start(seg /*=extraout_a2*/, seg);      // FUN_005deee0
    if (dot == NULL) return CT_UNKNOWN;
    const char *end = /* extraout_a3 */ ext_end;

    char c1 = dot[1], c2, c3, c4, c5, c6;
    // --- 3-char extension ---
    if (c1 && (c2 = dot[2]) && (c3 = dot[3]) && dot + 4 == end) {
        if (eqi(c1,'P') && eqi(c2,'N') && eqi(c3,'G')) return CT_PNG;
        if (eqi(c1,'B') && eqi(c2,'M') && eqi(c3,'P')) return CT_BMP;
        if (eqi(c1,'H') && eqi(c2,'T') && eqi(c3,'M')) return CT_HTML;
    }
    // --- 4-char extension: HTML ---
    if (c1 && (c2 = dot[2]) && (c3 = dot[3]) && (c4 = dot[4]) && dot + 5 == end &&
        eqi(c1,'H') && eqi(c2,'T') && eqi(c3,'M') && eqi(c4,'L'))
        return CT_HTML;
    // --- 6-char extension: MMBBIN ---
    if (c1 && (c2=dot[2]) && (c3=dot[3]) && (c4=dot[4]) && (c5=dot[5]) &&
        (c6=dot[6]) && dot + 7 == end) {
        if (!eqi(c1,'M')) return CT_UNKNOWN;
        if (eqi(c2,'M') && eqi(c3,'B') && eqi(c4,'B') && eqi(c5,'I') && eqi(c6,'N'))
            return CT_MMBBIN;
    }
    return CT_UNKNOWN;
}
// eqi(a,LIT) == (a==LIT || a==LIT|0x20)  -- ASCII case-insensitive
```

## Evidence
- Raw: `FUN_005df7b0.c` — the three length-gated blocks with the OR'd upper/lower char pairs and the `iVar7+N == extraout_a3` end checks; return values 1/2/3/4 exactly as above.
- The 6-char branch compares positions +1..+6 to M,M,B,B,I,N → "MMBBIN" (note: not "MMBIN"; corrected from the prior classify note).
- Locator identities (FUN_005dee60/FUN_005deee0) inferred from usage (segment then extension pointer + end).

## Remaining uncertainty
- FUN_005dee60/FUN_005deee0 exact semantics inferred (segment vs extension); the `extraout_*` register wiring is a decompiler artifact. Runtime-unvalidated. "MMBBIN" is Outbreak-specific (likely a packed/binary resource) — name/purpose unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005df7b0.c`  — untouched decompiler output.
