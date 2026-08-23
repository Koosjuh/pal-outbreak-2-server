# 0x001ebe64 lock_invoke

| field | value |
|---|---|
| Original address | 0x001ebe64 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ebe64 |
| Resolved name | list_lock_acquire |
| Subsystem | transport |
| Relevance | helper |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001eb4dc, FUN_001eb5ac, FUN_001eb688, FUN_001eb888, FUN_001eb8d0, FUN_001eb918
**Callees:** — (indirect: callback at container +0x8)
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** container +0x8 lock callback ptr; container +0x10 lock object

## Behavioral explanation
Acquire-side of an intrusive list's synchronization hook. The list container carries an optional
lock callback pointer at `+0x8` and the lock/mutex object inline at `+0x10`. If a callback is
registered, this invokes it as `cb(&container[+0x10], 1)` — `1` being the ACQUIRE/LOCK command —
and returns its result; if no callback is registered (`+0x8 == NULL`), it is a no-op returning 0.
This makes locking optional per list. Sibling wrappers at nearby addresses issue the RELEASE/other
commands (the record's earlier note that "callers pass 1/2/3" refers to those siblings; this
specific function hardcodes command `1`).

## Input / output
- `param_1` (`int` → `struct list_container *`): the list/container object.
- Returns `undefined4`: callback result, or `0` when no callback is set.

## Side effects
- Calls the registered lock callback (may block / take a mutex). No fields written by this fn.

## Important branches
- `if (*(container+0x8) != 0)` → invoke callback with cmd `1`; else return 0. The NULL-callback
  path is the "unlocked list" case.

## Constants & flags
- Lock command `1` = ACQUIRE (LOCK). Companion commands (2/3 = release/unlink/foreach) live in the
  sibling wrappers FUN_001eb4dc/5ac/688/888/8d0/918.

## Corrected reconstruction
```c
enum lock_cmd { LOCK_ACQUIRE = 1, LOCK_RELEASE = 2, LOCK_TRY = 3 /* [inferred] siblings */ };

// container layout (partial):  +0x8 lock_cb   +0x10 lock_obj
typedef u32 (*lock_cb_t)(void *lock_obj, int cmd);

u32 list_lock_acquire(struct list_container *c) {
    u32 rc = 0;
    if (c->lock_cb /* +0x8 */ != NULL)
        rc = ((lock_cb_t)c->lock_cb)(&c->lock_obj /* +0x10 */, LOCK_ACQUIRE);
    return rc;
}
```

## Evidence
- Raw: `FUN_001ebe64.c` — guarded indirect call `(*(code**)(p+8))(p+0x10, 1)`, else `0`.
- Six list-op sibling callers imply a shared cmd-dispatched lock hook.
- Confidence **High** on mechanics; the cmd `1` = "acquire" naming is **inferred**. Runtime pending.

## Remaining uncertainty
- The precise command numbering/semantics (acquire vs the sibling ops) is inferred from the
  caller set, not proven.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ebe64.c`  — untouched decompiler output.
