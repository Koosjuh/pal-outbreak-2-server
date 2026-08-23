# 0x00627760 msg_task_init_op02

| field | value |
|---|---|
| Original address | 0x00627760 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00627760 |
| Resolved name | msg_task_init_state2 |
| Subsystem | rooms |
| Relevance | helper |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005b1a30, FUN_005f7f30
**Callees:** FUN_0062b9e0 (associated block reset)
**Referenced globals:** — (operates on the passed task descriptor)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** task+0x1 selector byte (=2); task+0xe/0xf/0x10/0x11 substate (=0)

## Behavioral explanation
Initializer for a message/task descriptor used by the room message-task dispatcher. It resets an
associated render/queue block (FUN_0062b9e0) and stamps the task's **selector byte** at `+0x1`
to `2`, then clears the four substate bytes (`+0xe..+0x11`) so the dispatcher restarts the task's
sub-state machine from step 0. The `2` selects which task-machine the dispatcher will run on
subsequent ticks (sibling `FUN_00627d40` stamps `9`, `FUN_00628690` stamps `5`). The selector is
a task-machine id, not a wire opcode — the "op02" in the old name is a task category, not a
transmitted SN@P opcode.

## Input / output
- **Params:** `param_1` — pointer to the task/message descriptor.
- **Return:** void.
- **Meaning:** arms the descriptor to run task-machine 2 from its first substate.

## Side effects
- `FUN_0062b9e0()` — resets the shared render/queue block (called with no args here).
- `task+0x1 = 2` — task-machine selector.
- `task+0xe = task+0xf = task+0x10 = task+0x11 = 0` — clears the substate quad.

## Important branches
- Straight-line; no conditionals.

## Constants & flags
- `2` = task-machine selector value (`+0x1`). Siblings: `5` (0x28690), `9` (0x27d40). [High]

## Corrected reconstruction
```c
void msg_task_init_state2(struct msg_task *t)   // [inferred struct]
{
    FUN_0062b9e0();       // reset associated render/queue block
    t->selector /*+0x1*/  = 2;   // run task-machine #2
    t->sub_e   /*+0xe*/   = 0;
    t->sub_f   /*+0xf*/   = 0;
    t->sub_10  /*+0x10*/  = 0;
    t->sub_11  /*+0x11*/  = 0;
}
```

## Evidence
- Raw decompile lines 9-14: `FUN_0062b9e0(); *(param_1+1)=2; *(param_1+0xe..0x11)=0`.
- Sibling FUN_00627d40 stamps 9 with identical substate clear; FUN_00628690 stamps 5.
- Runtime-unvalidated.

## Remaining uncertainty
- Exact task-machine that selector 2 maps to (which per-tick handler the dispatcher runs) is not
  decoded here; the +0x1 field is a machine id, confirmed by the sibling pattern but not traced.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00627760.c`  — untouched decompiler output.
