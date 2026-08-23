# 0x005c5eb0 send_op08_leave

| field | value |
|---|---|
| Original address | 0x005c5eb0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c5eb0 |
| Resolved name | send_op08 |
| Subsystem | roster |
| Relevance | core |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005c6500 (room_roster_sync_sm, phase 12/13 — finalize)
**Callees:** func_0x00106b60 (memset), func_0x001df380 (op10 transport multicast send)
**Referenced globals:** 0x6febac SN@P connection handle
**Referenced strings:** —
**Referenced opcodes:** inner app-op 0x08, transport op0x10
**State vars:** —

## Behavioral explanation
Host→member relay of app-opcode **0x08**, body-less (same shape as send_op03/09). Zeroes 0x304 scratch, byte0 = 8, reliable op10 multicast to recipient `param_1`, declared length 4. Emitted in the finalize phase of the roster-sync SM (FUN_005c6500 state '\f'→'\r'): after the charstats (op07) chunks are delivered, the host sends op08 to each member `1..bRam00700708` (a sync-complete / commit marker). Immediately after this loop the SM copies each member's name/charstats into the persistent arrays `0x700710/0x700720/0x700734`.

## Input / output
- `param_1` — `connID` : recipient member id (from FUN_005c5120 on `0x700b60 + i*0x114`).
- returns `void`.

## Side effects
- Transmits reliable op10 frame to `param_1`, payload `{08,00,00,00}`.

## Important branches
None.

## Constants & flags
- inner opcode `0x08`; len `4`; count `1`; who `0x8000`.

## Corrected reconstruction
```c
void send_op08(connID target)
{
    u8 buf[0x304];
    memset(buf, 0, 0x304);
    buf[0] = 0x08;
    snap_send_op10_multi(uRam006febac, 0x8000, buf, 4, 1, target);
}
```

## Evidence
- Raw: `FUN_005c5eb0.c` — memset 0x304, buf[0]=8, `func_0x001df380(uRam006febac,0x8000,buf,4,1,param_1)`.
- Caller `FUN_005c6500.c` phase '\f' (12): `for i in 1..bRam00700708: FUN_005c5120(...); send_op08(id)` then persists name/charstats to 0x700710/0x700720/0x700734.

## Remaining uncertainty
"leave" label retained loosely; in this SM context op08 reads as a sync-complete/commit marker per member rather than a departure. No wire trace to confirm the body is empty.
