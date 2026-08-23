# 0x006158b8 net_set_request_mode

| field | value |
|---|---|
| Original address | 0x006158b8 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006158b8 |
| Resolved name | net_set_request_mode |
| Subsystem | transport |
| Relevance | helper |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_0060e060
**Callees:** —
**Referenced globals:** ram0x00654200 (request mode word)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x654200

## Behavioral explanation
Trivial setter: stores `param_1` into the global request-mode word `ram0x00654200`. That word is later folded into a type-2 request as `uRam0070d244` by `net_request_issue_t2` (0x6159c0). So this pre-selects a mode/flag (e.g. lookup class or filter) that the next two-key query will carry. The Ghidra warning about overlapping `_` globals means `0x654200` is accessed at multiple widths; here it is written as a 32-bit word.

## Input / output
- `param_1` (undefined4) — request mode value.
- Return `undefined8` — always `0`.

## Side effects
- `ram0x00654200 = param_1`.

## Important branches
None (single store).

## Constants & flags
- `0x654200` — global request-mode word; consumer: `net_request_issue_t2` → `uRam0070d244`.

## Corrected reconstruction
```c
undefined8 net_set_request_mode(uint32_t mode /*param_1*/)
{
    g_req_mode /*ram0x00654200*/ = mode;   // consumed by issue_t2 as 0x70d244
    return 0;
}
```

## Evidence
- Single global store; the same global is read into `uRam0070d244` inside `net_request_issue_t2` (0x6159c0).
- **Runtime-unvalidated** (trivial). Confidence Medium only because the mode's meaning is unknown.

## Remaining uncertainty
Semantic meaning of the mode value (query class / filter / flags) is unproven; caller `0060e060` supplies it.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006158b8.c`  — untouched decompiler output.
