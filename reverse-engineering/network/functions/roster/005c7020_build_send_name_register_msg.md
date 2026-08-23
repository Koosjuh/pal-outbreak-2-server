# 0x005c7020 build_send_name_register_msg

| field | value |
|---|---|
| Original address | 0x005c7020 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c7020 |
| Resolved name | build_send_op48_name_query |
| Subsystem | roster |
| Relevance | core |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005af1a0
**Callees:** FUN_005c4f40 (get_local_name_a), FUN_005c4fd0 (get_local_name_b), func_0x00109eb8 (strncpy), func_0x00106b60 (memset), func_0x001e094c (op48 name-query send), FUN_005c3e50 (register reply cb)
**Referenced globals:** 0x6febac SN@P connection handle; 0x700638 reply context; 0x700fb0 name scratch (via callees)
**Referenced strings:** NAME (0x4e414d45)
**Referenced opcodes:** transport op0x48 (name query)
**State vars:** —

## Behavioral explanation
Builds and sends an **op48 name-query** (the `0x48` name-query opcode) carrying two `'NAME'` field descriptors, then registers `name_reply_populate_roster` (0x005c70e0) as the reply callback. It fetches two locally-formatted name strings (from FUN_005c4f40 / FUN_005c4fd0 — both derive a name from the user record at `0x365d20` indexed by `uRam0086f800`, then append a suffix string `0x6405b0` / `0x6405b8`), copies each into a 0x10 stack buffer, and assembles a TLV descriptor array `{tag='NAME', field=0x44, ptr=name_a}, {tag='NAME', field=0x46, ptr=name_b}` which it hands to the op48 send primitive `func_0x001e094c`. The send handle is passed to FUN_005c3e50 to bind the reply handler + context `0x700638`.

## Input / output
- no parameters (`void`), reads globals.
- returns `0` (constant).

## Side effects
- Transmits an op48 name-query on connection `0x6febac`.
- Registers reply callback `0x005c70e0` with context `0x700638` (via FUN_005c3e50).
- Writes name scratch at `0x700fb0` (inside FUN_005c4f40/4fd0).

## Important branches
None — straight-line build+send.

## Constants & flags
- `TAG_NAME = 0x4e414d45` ("NAME").
- descriptor field words `0x44` (name_a) and `0x46` (name_b) — field selector/length [inferred].
- descriptor stride 0xc: `{u32 tag, u32 field, void* ptr}`; two entries in a 0x3c zeroed area (zero-terminated).
- `func_0x001e094c` arg3 = `0xa`, arg4 = template/format `0x5c3cf0` [inferred].

## Corrected reconstruction
```c
struct name_tlv { u32 tag; u32 field; void *ptr; };   // stride 0xc

int build_send_op48_name_query(void)
{
    char name_a[0x10], name_b[0x10];
    struct name_tlv desc[5];                 // 0x3c zeroed; only [0],[1] used
    memset(desc, 0, 0x3c);

    strncpy(name_a, get_local_name_a(), 0x10);   // FUN_005c4f40 -> 0x700fb0
    strncpy(name_b, get_local_name_b(), 0x10);   // FUN_005c4fd0 -> 0x700fb0

    desc[0] = (struct name_tlv){ .tag = TAG_NAME, .field = 0x44, .ptr = name_a };
    desc[1] = (struct name_tlv){ .tag = TAG_NAME, .field = 0x46, .ptr = name_b };

    void *h = snap_send_op48_name_query(uRam006febac, desc, 0xa, /*tmpl*/0x5c3cf0); // func_0x001e094c
    register_reply_cb(h, name_reply_populate_roster /*0x5c70e0*/, 0x700638);         // FUN_005c3e50
    return 0;
}
```

## Evidence
- Raw: `FUN_005c7020.c` — two 'NAME' tags (0x4e414d45), fields 0x44/0x46, ptrs to the two 0x10 name buffers, `func_0x001e094c(uRam006febac,&desc,10,0x5c3cf0)`, `FUN_005c3e50(h,0x5c70e0,0x700638)`.
- `func_0x001e094c` is an opcode-0x48 builder (PACKET_INDEX 0x48: `0x001e094c 0x005bca90`); task brief: op48 = name-query.
- FUN_005c4f40 / FUN_005c4fd0 read the user record `0x365d20` (index `uRam0086f800`) and append `0x6405b0`/`0x6405b8`.
- Reply handler wiring proven by FUN_005c70e0 being the registered cb address.

## Remaining uncertainty
Meaning of the `0x44`/`0x46` descriptor field words (length vs field-type selector) and the `0xa` / `0x5c3cf0` args to `func_0x001e094c` are inferred. The two "names" appear to be a login handle + a secondary tag (suffixes 0x6405b0/0x6405b8 differ).
