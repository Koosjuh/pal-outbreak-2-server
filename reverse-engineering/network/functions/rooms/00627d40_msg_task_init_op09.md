# 0x00627d40 msg_task_init_op09

| field | value |
|---|---|
| Original address | 0x00627d40 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00627d40 |
| Resolved name | msg_task_init_state9 |
| Subsystem | rooms |
| Relevance | helper |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f7f30
**Callees:** —
**Referenced globals:** — (operates on the passed task descriptor)
**Referenced strings:** —
**Referenced opcodes:** 0x09 (task-machine selector, not a transmitted opcode)
**State vars:** task+0x1 selector byte (=9); task+0xe/0xf/0x10/0x11 substate (=0)

## Behavioral explanation
Sibling of `FUN_00627760`: initializes a message/task descriptor by stamping the **selector
byte** `+0x1` to `9` and clearing the four substate bytes (`+0xe..+0x11`). Unlike the state-2
initializer it does **not** call FUN_0062b9e0 (no render/queue reset), so this variant just
re-targets an already-live descriptor to task-machine 9 and rewinds its substate. Task-machine 9
is the descriptor category the FUN_005f7f30 caller then services on subsequent ticks (the "op09"
in the old name is the local task category; the register-family SN@P op 0x09 is handled elsewhere,
so this is not itself the wire register).

## Input / output
- **Params:** `param_1` — pointer to the task/message descriptor.
- **Return:** void.
- **Meaning:** arms the descriptor to run task-machine 9 from substate 0.

## Side effects
- `task+0x1 = 9` — task-machine selector.
- `task+0xe = task+0xf = task+0x10 = task+0x11 = 0` — clears the substate quad.

## Important branches
- Straight-line; no conditionals, no callees.

## Constants & flags
- `9` = task-machine selector value (`+0x1`). Siblings: `2` (0x27760), `5` (0x28690). [High]

## Corrected reconstruction
```c
void msg_task_init_state9(struct msg_task *t)   // [inferred struct]
{
    t->selector /*+0x1*/ = 9;    // run task-machine #9
    t->sub_e   /*+0xe*/  = 0;
    t->sub_f   /*+0xf*/  = 0;
    t->sub_10  /*+0x10*/ = 0;
    t->sub_11  /*+0x11*/ = 0;
}
```

## Evidence
- Raw decompile lines 9-13: `*(param_1+1)=9; *(param_1+0xe..0x11)=0`. No callees (header).
- Sibling FUN_00627760 stamps 2 (and additionally calls FUN_0062b9e0).
- Runtime-unvalidated.

## Remaining uncertainty
- Which per-tick handler selector 9 dispatches to, and why this variant omits the FUN_0062b9e0
  reset (likely because the descriptor's render block is already valid), is not decoded.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00627d40.c`  — untouched decompiler output.
