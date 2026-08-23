# 0x005c6210 roster_sm_init

| field | value |
|---|---|
| Original address | 0x005c6210 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c6210 |
| Resolved name | roster_sync_sm_init |
| Subsystem | rooms |
| Relevance | core |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00616d30, FUN_006173c0
**Callees:** — (memset `func_0x00106b60`; memcpy `func_0x001069a8`)
**Referenced globals:** 0x6ff2bd candidate table (4 × 0x114); 0x6cbb94 sm-active flag; 0x6cbb70 pump
fn-ptr; 0x6cbb90 sm-phase; 0x6cbb74 done-callback
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006cbb94 sm-active

## Behavioral explanation
Arms the **room roster-sync state machine** (the pump is `room_roster_sync_sm` at 0x005c6500). It first
copies the caller's 48-byte member/argument block (`param_1`, 12 words) onto the stack, then — **only if
the SM is not already active** (`0x6cbb94 == 0`) — clears the 0x450-byte candidate table at 0x6ff2bd
(4 entries × 0x114 stride) and seeds each of the 4 candidate slots with a member's name(0x10) /
id-or-name2(0x10) / char-stats(0xf0) from the staged block. It then latches the SM live: sets active=1,
installs `FUN_005c6500` as the pump function pointer (0x6cbb70), zeroes the phase (0x6cbb90 = 0 → the SM
starts at phase 0), and stores `param_2` as the completion callback (0x6cbb74). Returns 0 on a successful
arm, **-1 if the SM was already active** (idempotent guard — a second create/enter can't restart it
mid-flight).

## Input / output
- `param_1` (u32*): source block of member candidates (read as 12 words; the seeding loop reads
  name/name2/stats per slot).
- `param_2` (u32): completion callback token stored at 0x6cbb74 and invoked when the SM reaches its
  final phase.
- Returns `0` = armed, `0xffffffff` = already active (no-op).

## Side effects (only when arming)
- memset(0x6ff2bd, 0, 0x450) — clear the 4-slot candidate table.
- For i in 0..3: candidate[i].name(0x10), candidate[i].name2/id(0x10), candidate[i].stats(0xf0) seeded.
- `sm_active` (0x6cbb94) := 1; `pump_fn` (0x6cbb70) := &room_roster_sync_sm; `sm_phase` (0x6cbb90) := 0;
  `done_cb` (0x6cbb74) := param_2.

## Important branches
- `cRam006cbb94 == 0` (SM idle) → seed table, arm SM, return 0.
- else (SM already active) → skip everything, return -1.

## Constants & flags
- `0x114` — candidate/member record stride (matches member_record relayed size). `0x450` = 4 × 0x114.
- Candidate field offsets within a 0x114 record: +0x00 name[0x10], +0x10 name2/id[0x10], +0x24 stats[0xf0]
  (0x6ff2e1 − 0x6ff2bd = 0x24).

## Corrected reconstruction
```c
// candidate record (0x114) — mirrors member_record relayed form
typedef struct { char name[0x10]; char name2[0x10]; u8 _pad[4]; u8 stats[0xf0]; } candidate_rec; // 0x114
extern candidate_rec g_candidates[4];      // 0x6ff2bd, 4 × 0x114 = 0x450
extern u8    g_roster_sm_active;           // 0x6cbb94
extern void  (*g_roster_pump)(void);       // 0x6cbb70
extern u8    g_roster_sm_phase;            // 0x6cbb90
extern u32   g_roster_done_cb;             // 0x6cbb74
extern void  room_roster_sync_sm(void);    // 0x005c6500

u32 roster_sync_sm_init(u32 *members /*param_1*/, u32 done_cb /*param_2*/)
{
    u32 staged[12];
    for (int i = 0; i < 6; i++) { staged[i*2] = members[i*2]; staged[i*2+1] = members[i*2+1]; }

    u32 rc = 0xffffffff;
    if (g_roster_sm_active == 0) {
        memset(g_candidates, 0, 0x450);
        for (int i = 0; i < 4; i++) {                 // seed 4 candidate slots
            memcpy(g_candidates[i].name,  (u8*)staged + i*4 + 0x00, 0x10); // [inferred] src stride
            memcpy(g_candidates[i].name2, (u8*)staged + i*4 + 0x10, 0x10);
            memcpy(g_candidates[i].stats, (u8*)staged + i*4 + 0x20, 0xf0);
        }
        g_roster_sm_active = 1;
        g_roster_pump      = room_roster_sync_sm;     // pump installed
        rc                 = 0;
        g_roster_sm_phase  = 0;                        // start at phase 0
        g_roster_done_cb   = done_cb;
    }
    return rc;
}
```

## Evidence
- Raw: single-shot guard `cRam006cbb94`; `pcRam006cbb70 = FUN_005c6500`; phase/cb latches; return -1/0.
- Candidate table 0x6ff2bd stride 0x114 × 4 = 0x450 matches the phase-0 consumer in `room_roster_sync_sm`
  which reads 0x6ff2bd occupied-slots and compacts them into the member table 0x6ff70d.
- Callers `FUN_00616d30`/`FUN_006173c0` are the create/enter entry points. Runtime-unvalidated.

## Remaining uncertainty
The per-slot **source** addressing in the seeding loop (`staged + i*4 + {0,0x10,0x20}`, reading 0xf0
bytes) over-runs the 48-byte staged buffer as decompiled — a Ghidra artifact of the copy prologue; the
true source is a caller-owned member array. The name2/id field semantics (0x10 bytes) vs member_record's
4-byte id are unresolved.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c6210.c`  — untouched decompiler output.
