# 0x005c3370 roster_list_reply_cb

| field | value |
|---|---|
| Original address | 0x005c3370 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c3370 |
| Resolved name | scenario_member_scan_reply_cb |
| Subsystem | roster |
| Relevance | core |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** — (registered reply callback; feeds the scenario-detail SM via flag 0x6cba55)
**Callees:** FUN_005c7d00 (reply housekeeping)
**Referenced globals:** 0x6ca890 (member scan count, byte); 0x7005d0 (extracted 16-byte field); 0x6cba55 (SM reply flag)
**Referenced strings:** — (`'\''` error tag)
**Referenced opcodes:** 0x0a member-list (probable wire source)
**State vars:** 0x6ca890; 0x6cba55

## Behavioral explanation
Reply callback for a member/roster scan used by the scenario-detail state machine. On **success (0x00)** it
walks the reply's member entries (`count` at `param_2+8`, first entry at `param_2+0xc`, blob at `param_2+0x24`).
For each entry it copies the `0xf0`-byte charstats blob into a local buffer and inspects the flag byte at blob
offset `+0xdc`: if that flag is non-zero it extracts the following 16 bytes (blob `+0xdd`) into the global
`0x7005d0` (a single-entry destination — later entries overwrite it, so effectively it captures the last
flagged member's field). It increments the byte member-count `0x6ca890` per entry, advancing via the
variable-length `entry+0x14`. When the final page arrives (not a continuation) it sets the SM reply flag
`0x6cba55 = 1`; on **error (0x27)** it sets `0x6cba55 = 2`. The SM (scenario-detail) polls `0x6cba55` to
proceed. Unlike the roster-fill handlers, this does **not** write the drawn roster tables — it only extracts a
single flagged field and signals completion, so its role is a targeted scan rather than a full fill.

## Input / output
- `param_1` (char*): reply envelope. `[0]` status; `[1]`/`+2` continuation.
- `param_2` (int): reply body. `+8` entry count; entries from `+0xc`/`+0x24`, variable-length via `entry+0x14`.
- Returns: void.

## Side effects
- Per flagged entry: copies 16 bytes from `blob+0xdd` into `0x7005d0`.
- `0x6ca890` incremented per entry (byte).
- Completion: `0x6cba55 = 1` (ok, final) or `2` (error).

## Important branches
- `param_1[0] == 0x00`: run scan loop; then
  - final page (`param_1[1] != 1 || *(short*)(param_1+2) == 0`): `0x6cba55 = 1`.
  - continuation: leave `0x6cba55` unset (await next page).
- `param_1[0] == 0x27`: `0x6cba55 = 2`.
- Per entry: `blob[0xdc] != 0` → extract `blob[0xdd..0xdd+16]` into `0x7005d0`; else skip extract.

## Constants & flags
- Blob copy length `0xf0`; flag at blob `+0xdc`; extracted field at blob `+0xdd` (16 bytes = 4 words × 2 halfwords).
- SM flag `0x6cba55`: `1` = done-ok, `2` = error.
- Status `0x00`/`0x27`.

## Corrected reconstruction
```c
#define MEMBER_COUNT  0x6ca890   // u8
#define EXTRACT_DST   0x7005d0   // 16 bytes
#define SM_REPLY      0x6cba55   // 1 = ok, 2 = err

enum snap_reply_status { SNAP_OK = 0x00, SNAP_ERR = 0x27 };

void scenario_member_scan_reply_cb(char *env, int body)
{
    txn_housekeeping();                                   // FUN_005c7d00
    if (env[0] == SNAP_OK) {
        int  n    = *(int*)(body + 8);
        int  name = body + 0x0c;
        int  blob = body + 0x24;
        for (int i = 0; i < n; i++) {
            uint8_t local[0xf0];
            memcpy(local, (void*)blob, 0xf0);
            if (local[0xdc] != 0)
                memcpy((void*)EXTRACT_DST, &local[0xdd], 16);   // capture flagged field
            blob = name + *(int*)(name + 0x14);
            name = blob + 0x18;
            *(uint8_t*)MEMBER_COUNT += 1;
            blob += 0x30;
        }
        if (!(env[1] == 1 && *(int16_t*)(env + 2) != 0))
            *(uint8_t*)SM_REPLY = 1;
    } else if (env[0] == SNAP_ERR) {
        *(uint8_t*)SM_REPLY = 2;
    }
}
```

## Evidence
- Raw decompile `FUN_005c3370.c`: `memcpy(auStack_f0, param_2, 0xf0)`; the `0xdc`-byte stack buffer overflow
  puts blob `+0xdc` into `cStack_14` and `+0xdd` into `auStack_10`; conditional 16-byte copy to `0x7005d0`;
  `cRam006ca890++`; continuation test; `uRam006cba55 = 1/2`.
- Same variable-stride entry advance (`+0x14`,`+0x18`,`+0x30`) as the op0a fill handlers → shared member-list
  wire format.

## Remaining uncertainty
- The decompiler models the blob as a `0xdc`-byte stack array with the flag/field bleeding into adjacent
  locals; the real record likely has an explicit flag at `+0xdc` and a 16-byte field at `+0xdd`, but this is an
  inference from overflow layout, hence **Medium** confidence. What `0x7005d0` is consumed for (scenario host
  identity?) and which screen arms this callback are not traced — the name `scenario_member_scan_reply_cb` is a
  best-fit from the `0x6cba55` SM linkage noted in prior classification.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c3370.c`  — untouched decompiler output.
