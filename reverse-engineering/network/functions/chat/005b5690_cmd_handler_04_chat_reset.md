# 0x005b5690 cmd_handler_04_chat_reset

| field | value |
|---|---|
| Original address | 0x005b5690 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b5690 |
| Resolved name | chat_cmd04_set_single_line |
| Subsystem | chat |
| Relevance | core |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** — (installed as command-selector 4 via FUN_005bdf70(4, 0x5b5690) from FUN_005b25c0)
**Callees:** FUN_005c3e80 (parse chat record → sender/name/text)
**Referenced globals:** 0x6c9d32(single-line message block, 0x31c bytes); 0x6c9d33(name field); 0x6c9d44(text field)
**Referenced strings:** —
**Referenced opcodes:** — (command-selector 4)

## Behavioral explanation
The **command-selector-4 handler**: unlike selector 3 (which appends to the 8-row scrollback), this
overwrites a **single-slot** message block at 0x6c9d32 (0x31c bytes). It clears the whole block,
parses the pending message with the same `FUN_005c3e80` record parser — discarding the sender field
to a stack scratch and writing name → 0x6c9d33 and text → 0x6c9d44 directly into the block — then
sets the block's ready flag (`*0x6c9d32 = 1`). This is the "current banner / system-line" message
(one live line replaced each time), the reset/replace counterpart to the appended scrollback.

## Input / output
- No parameters (reads pending message via `FUN_005c3e80`).
- Returns void.

## Side effects
- `memset(0x6c9d32, 0, 0x31c)` — clears the single-line block.
- Writes name into 0x6c9d33 and text into 0x6c9d44 (via the parser's out-pointers).
- Sets ready flag `*(u8*)0x6c9d32 = 1`.

## Important branches
- None — straight-line: clear → parse → mark ready.

## Constants & flags
- `0x31c` (796) — single-line block size.
- Ready flag byte at 0x6c9d32 (block base) = 1 after fill.
- Field offsets: name at +1 (0x6c9d33), text at +0x12 (0x6c9d44).

## Corrected reconstruction
```c
// Single live message line (banner / system line), replaced on each selector-4 command.
struct single_msg { u8 ready; char name[0x11]; char text[...]; }; // @0x6c9d32, block 0x31c

void chat_cmd04_set_single_line(void) {
    char sender_scratch[0x20];
    memset((void*)0x6c9d32, 0, 0x31c);                    // clear block
    parse_chat_record(sender_scratch, (void*)0x6c9d33, (void*)0x6c9d44); // FUN_005c3e80
    *(u8*)0x6c9d32 = 1;                                   // ready
}
```

## Evidence
- Raw: `func_0x00106b60(0x6c9d32,0,0x31c)` (memset), `FUN_005c3e80(auStack_20, 0x6c9d33, 0x6c9d44)`, `uRam006c9d32 = 1`.
- Same parser (0x5c3e80) as selector-3 handler ⇒ same on-wire chat record shape; the difference is single-slot replace vs. ring append.
- Installed as selector 4 (memory note: FUN_005bdf70(4, 0x5b5690)).
- Runtime-unvalidated.

## Remaining uncertainty
- Whether 0x6c9d32 is a system announcement banner vs. a "whisper"/private line; the parser's field widths (name vs text boundary at +0x12) are inferred from the destination offsets.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b5690.c`  — untouched decompiler output.
