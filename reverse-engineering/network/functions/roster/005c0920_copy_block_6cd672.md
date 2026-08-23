# 0x005c0920 copy_block_6cd672

| field | value |
|---|---|
| Original address | 0x005c0920 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c0920 |
| Resolved name | copy_relay_record_0x6cd672 |
| Subsystem | roster |
| Relevance | support |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005b5ac0, FUN_005b5d20, FUN_005b6570
**Callees:** —
**Referenced globals:** 0x6cd672 — fixed 0x114-byte source record
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Fixed-length block copy of **0x114 bytes** (0x8a = 138 u16 words) from the global record at 0x6cd672
into the caller's buffer. **Correction to the prior "byte-swapped" note:** the loop does NOT swap —
it reads `hi = src[1]`, writes `dst[0] = src[0]`, then `dst[1] = hi`, i.e. a straight
low-then-high copy of each 2-byte pair (an unrolled `memcpy` emitted as a hand word loop). No endian
change occurs. 0x114 is exactly the **relayed member_record size** (see struct member_record), so
0x6cd672 is very likely the local/self member-relay record staged for a roster or op06-style send.

## Input / output
- `param_1` (u8*): destination buffer (must hold ≥0x114 bytes).
- Returns `0` (ignored).

## Side effects
Writes 0x114 bytes to `*param_1`. Reads (does not modify) 0x6cd672.

## Important branches
Single count-down loop, 0x8a iterations (`iVar2` 0x8a → 0, body runs each). No conditional paths.
Loop-trip proof: `iVar2=0x8a; do{ iVar2--; copy2bytes; } while(0<iVar2);` → 0x8a bodies × 2B = 0x114B.

## Constants & flags
- `0x8a` (138) — u16 word count.
- `0x114` (276) — total bytes = relayed member_record size.
- `0x6cd672` — source record base.

## Corrected reconstruction
```c
// Fixed 0x114-byte copy from the staged relay/member record at 0x6cd672.
// NOT a byte-swap — plain low/high pair copy (unrolled memcpy).
u64 copy_relay_record_0x6cd672(u8 *dst /*param_1*/) {
    const u8 *src = (const u8*)0x6cd672;
    for (int i = 0x8a; i > 0; i--) {   // 138 iterations
        u8 hi   = src[1];
        dst[0]  = src[0];
        dst[1]  = hi;
        src += 2;
        dst += 2;
    }
    return 0;                          // 0x8a * 2 = 0x114 bytes
}
```

## Evidence
- Raw: `FUN_005c0920.c` — `iVar2=0x8a; do{ iVar2--; uVar1=puVar3[1]; *param_1=*puVar3; puVar3+=2; param_1[1]=uVar1; param_1+=2; }while(0<iVar2);`.
- 0x114 == relayed member_record size (structures/structure-layouts/member_record.md).

## Remaining uncertainty
Semantic identity of 0x6cd672 (self member-relay record vs. a 0x114 template) not runtime-confirmed;
byte-count and non-swap behavior are certain from the decompile.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c0920.c`  — untouched decompiler output.
