# 0x005ed630 map_control_char

| field | value |
|---|---|
| Original address | 0x005ed630 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ed630 |
| Resolved name | map_delimiter_break_code |
| Subsystem | ui |
| Relevance | helper |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ed6e0, FUN_005ee220, FUN_005ee470
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Classifies the leading byte of a text fragment into a small break/indent "type code", then consumes that byte by NUL-terminating it (`*param_1 = 0`). It recognizes a fixed set of punctuation and control characters (used as break-opportunity / tab-stop markers when laying out justified or tabbed text) and maps each to a code; unrecognized bytes yield code 0 (and are still NUL-terminated, except the unrecognized-default path returns 0 immediately after NUL). Tab (`\t`) is explicitly recognized but maps to code 0 (a no-cost break). This is the per-fragment delimiter classifier feeding the wrap/justify logic in `FUN_005ed6e0` and the run scanners.

## Input / output
- `param_1` — `char *` fragment; only the first byte is read, then overwritten with 0.
- returns `undefined8` (code) — break/indent type code (see table).

## Side effects
- Always writes `*param_1 = 0` (consumes/terminates the leading byte) before returning — on every path including the unrecognized default.

## Important branches (delimiter -> code)
| first byte | code | note |
|---|---|---|
| `'/'` (0x2f) | `0x11` | strong break / path-style separator |
| `'.'` (0x2e) | `3` | |
| `'-'` (0x2d) | `2` | hyphen break |
| `','` (0x2c) | `1` | |
| `'('` (0x28) | `4` | |
| `'\n'` (0x0a) | `1` | newline |
| `'\t'` (0x09) | `0` | recognized, zero-cost |
| `'\v'` (0x0b) | `2` | |
| `'\b'` (0x08) | `3` | |
| anything else | `0` | early-return default (still NUL-terminates) |

- Control flow is an if/else-if chain; `'\t'` is distinguished from the default only in that it skips the early `return 0` and falls through to the shared `*param_1 = 0; return code` tail with `code == 0`. Functionally `'\t'` and the default both yield 0.

## Constants & flags
- Code values `0x11,4,3,2,1,0` are break/indent class ids consumed downstream; `0x11` (17) is the distinct "hard/path break" for `'/'`.

## Corrected reconstruction
```c
// Classify a leading delimiter into a break/indent code and consume it.
u64 map_delimiter_break_code(char *frag)
{
    char c = *frag;
    u64 code = 0;
    switch (c) {
        case '/':  code = 0x11; break;
        case '.':  code = 3;    break;
        case '-':  code = 2;    break;
        case ',':  code = 1;    break;
        case '(':  code = 4;    break;
        case '\n': code = 1;    break;
        case '\t': code = 0;    break;   // recognized, zero cost
        case '\v': code = 2;    break;
        case '\b': code = 3;    break;
        default:
            *frag = '\0';                // unrecognized: consume, code 0
            return 0;
    }
    *frag = '\0';                        // consume the delimiter
    return code;
}
```

## Evidence
- Raw decompile: exact if/else-if ladder on `*param_1` with the codes above; `'\t'` handled by the `cVar1 != '\t'` guard (falls through with 0); default `*param_1 = '\0'; return 0;`; shared tail `*param_1 = '\0'; return uVar2;`.

## Remaining uncertainty
The downstream meaning of each code (which break/indent class) is inferred from the caller family (justify/tab layout); not individually decoded. The reconstruction preserves the observed behavior exactly (a `switch` here is equivalent to the decompiled ladder). Runtime-unvalidated.
