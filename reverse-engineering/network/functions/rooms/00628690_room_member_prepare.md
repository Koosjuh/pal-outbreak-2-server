# 0x00628690 room_member_prepare

| field | value |
|---|---|
| Original address | 0x00628690 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00628690 |
| Resolved name | member_action_prepare |
| Subsystem | rooms |
| Relevance | support |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00627d60 (member/action task machine)
**Callees:** FUN_0062b9e0 (render/queue reset); `func_0x0010a4f0` (bounded string copy, 0x10), `func_0x00106b60` (memset)
**Referenced globals:** — (operates on the passed room object + task descriptor)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** obj+0x443 flag (=1); task+0x0 selector (=5); task+0x1 (=0); obj+0xefb/+0xf0b source name/id; obj+0x1045/+0x1055 staged name/id; obj+0x1069/+0x108e text buffers

## Behavioral explanation
Substep that stages a room-member action (the "act on this member" flow — e.g. kick/message
target). It marks the room object busy (`obj+0x443 = 1`), sets the task descriptor's selector to
5 (the member-action task-machine, cf. the msg_task_init siblings) with substate 0, resets the
shared render/queue block, then **copies the currently-selected member's name and id** from the
object's live selection fields (`obj+0xefb` name, `obj+0xf0b` id — each 0x10 bytes) into the
staging/action fields (`obj+0x1045` name, `obj+0x1055` id). Finally it zeroes two 0x25-byte text
buffers (`obj+0x1069`, `obj+0x108e`) — the message/chat text fields the action screen will use.
Returns -1 (0xffffffff), the task-machine "stay/continue" sentinel used across these substeps.

## Input / output
- **Params:** `param_1` — room object pointer; `param_2` — task descriptor pointer.
- **Return:** `0xffffffff` (-1) — "continue" sentinel for the task dispatcher.
- **Meaning:** prepares the staged action buffers so the following substeps can render/confirm
  and send the member action.

## Side effects
- `obj+0x443 = 1` — busy/mode flag (same field room_scene_object_init set to 2).
- `task+0x0 = 5`, `task+0x1 = 0` — arm member-action machine, substate 0.
- `FUN_0062b9e0()` — reset render/queue block.
- `strncpy(obj+0x1045, obj+0xefb, 0x10)` — staged name ← selected member name.
- `strncpy(obj+0x1055, obj+0xf0b, 0x10)` — staged id ← selected member id.
- `memset(obj+0x1069, 0, 0x25)`, `memset(obj+0x108e, 0, 0x25)` — clear two text buffers.

## Important branches
- Straight-line; no conditionals. (The -1 return is unconditional.)

## Constants & flags
- `1` = obj+0x443 busy flag value. [inferred]
- `5` = task selector for the member-action machine (matches msg_task_init family). [High]
- `0x10` = name/id field width (matches member_record.name / roster row). [Confirmed cross-struct]
- `0x25` = text buffer size (message/chat field). [High]
- Offsets: `+0xefb`/`+0xf0b` = live selected member name/id; `+0x1045`/`+0x1055` = staged
  name/id; `+0x1069`/`+0x108e` = two text buffers. [High]

## Corrected reconstruction
```c
// Stage the selected member's name/id into the action buffers; arm the action task-machine.
u32 member_action_prepare(struct room_scene *obj, struct msg_task *t)
{
    obj->busy_443 /*+0x443*/ = 1;

    t->selector /*+0x0*/ = 5;    // member-action machine
    t->sub1     /*+0x1*/ = 0;
    FUN_0062b9e0();              // reset render/queue block

    strncpy(obj->act_name  /*+0x1045*/, obj->sel_name /*+0xefb*/, 0x10);
    strncpy(obj->act_id    /*+0x1055*/, obj->sel_id   /*+0xf0b*/, 0x10);
    memset(obj->text_a /*+0x1069*/, 0, 0x25);
    memset(obj->text_b /*+0x108e*/, 0, 0x25);

    return 0xffffffff;           // "continue" sentinel
}
```

## Evidence
- Raw decompile lines 9-17: `*(param_1+0x443)=1; *param_2=5; param_2[1]=0; FUN_0062b9e0();
  func_0x0010a4f0(param_1+0x1045,param_1+0xefb,0x10); func_0x0010a4f0(param_1+0x1055,
  param_1+0xf0b,0x10); func_0x00106b60(param_1+0x1069,0,0x25); func_0x00106b60(param_1+0x108e,
  0,0x25); return 0xffffffff`.
- 0x10 name width matches member_record.name; 0x443 field matches room_scene_object_init.
- Runtime-unvalidated.

## Remaining uncertainty
- The exact member action (kick vs message vs invite) is not decoded — inferred "action on
  selected member" from the name/id staging + text buffers.
- func_0x0010a4f0 assumed strncpy-style bounded copy (0x10); could be memcpy — behavior
  identical for fixed 0x10 fields.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00628690.c`  — untouched decompiler output.
