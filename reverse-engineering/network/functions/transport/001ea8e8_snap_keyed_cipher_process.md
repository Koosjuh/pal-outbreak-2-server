# 0x001ea8e8 snap_keyed_cipher_process

| field | value |
|---|---|
| Original address | 0x001ea8e8 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ea8e8 |
| Resolved name | snap_keyed_cipher_process (blowfish_ecb_hashed_key) |
| Subsystem | transport |
| Relevance | core |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d9b6c
**Callees:** FUN_00105dd8 (alloc), FUN_00105e30 (free), FUN_001e5854 (hash init), FUN_001ea784 (hash update), FUN_001ea804 (hash final), FUN_001e5234 (cipher key-schedule init), FUN_001e5104 (cipher block round), FUN_001e2394 / FUN_001e2304 (endian swaps)
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** — (used by the reliable-msg path FUN_001d9b6c, op0x3d/0x41)
**State vars:** —

## Behavioral explanation
The SN@P payload block-cipher. It derives a session key by hashing two caller-supplied byte spans
(`(ptr3,len4)` then `(ptr5,len6)`) into a 20-byte digest, loads that digest as the key schedule of a
64-bit block cipher, and transforms `param_1` in place in 8-byte (two-word) blocks. Each block is
endian-normalised, run through one cipher call (`FUN_001e5104`), then endian-restored. The 0x1048-byte
context (`FUN_00105dd8(0x1048)`) is exactly a **Blowfish** key schedule (P-array 18×4 = 72 bytes +
4 S-boxes × 256 × 4 = 4096 → 4168 = 0x1048), and the 20-byte key is a **SHA-1** digest — so this is
Blowfish-ECB keyed by SHA-1(input_a ‖ input_b). Because the ctx allocation, hashing, and cipher all
reuse `uStack_24`, key-derivation and encryption share the one scratch object.

## Input / output
- **param_1** (u32*): in/out data buffer, transformed in place.
- **param_2** (int): data length in bytes; processed as `ceil(param_2/8)` 8-byte blocks.
- **param_3, param_4**: first key-material span (ptr, len) fed to the hash.
- **param_5, param_6**: second key-material span (ptr, len) fed to the hash.
- **Returns:** void (in-place).

## Side effects
- Allocates a 0x1048 scratch/key-schedule ctx and frees it before return (no persistent state).
- Overwrites `param_1[0 .. blocks*2)` with the cipher output.

## Important branches
- Single count-down loop over `blocks = (param_2 + 7) >> 3`. No error paths; a zero length processes
  zero blocks. The final block is processed whole even if `param_2` is not a multiple of 8 (reads/writes
  a full 8 bytes — caller must guarantee the buffer is block-padded).

## Constants & flags
- `0x1048` = Blowfish key-schedule context size (18 P-entries + 4×256 S-box words).
- `0x14` (20) = SHA-1 digest length used as the cipher key.
- `FUN_001e2394` / `FUN_001e2304` = word byte-swaps (ntohl-before / htonl-after) so the cipher core
  always sees big-endian-normalised words on the little-endian EE.

## Corrected reconstruction
```c
// Blowfish-ECB over param_1, key = SHA1(span_a || span_b). In place.
void snap_keyed_cipher_process(u32 *data, int len,
                               const void *key_a, u32 key_a_len,
                               const void *key_b, u32 key_b_len)
{
    sha1_ctx    hash;                       // auStack_1c0 (368 bytes)
    u8          digest[20];                 // auStack_50 (32-byte slot, 20 used)
    blowfish_ctx *cipher = alloc(0x1048);   // FUN_00105dd8 — reused as key schedule

    sha1_init(&hash);                       // FUN_001e5854
    sha1_update(&hash, key_a, key_a_len);   // FUN_001ea784
    sha1_update(&hash, key_b, key_b_len);   // FUN_001ea784
    sha1_final(digest, &hash);              // FUN_001ea804

    blowfish_set_key(cipher, digest, 20);   // FUN_001e5234

    u32 blocks = (u32)(len + 7) >> 3;       // ceil(len/8) 64-bit blocks
    u32 *p = data;
    for (u32 n = blocks; n != 0; n--) {
        u32 L = bswap32(p[0]);              // FUN_001e2394
        u32 R = bswap32(p[1]);
        blowfish_process_block(cipher, &L, &R);   // FUN_001e5104
        p[0] = bswap32(L);                  // FUN_001e2304
        p[1] = bswap32(R);
        p += 2;
    }
    free(cipher);                           // FUN_00105e30
}
```

## Evidence
- `FUN_00105dd8(0x1048)` = 4168-byte ctx == Blowfish key schedule footprint (P[18]+S[4][256], 4-byte words).
- 20-byte key (`0x14`) sourced from a 3-call init/update/update/final sequence over a 368-byte ctx = SHA-1.
- Two-word (8-byte) block loop with symmetric pre/post byte-swaps = 64-bit block cipher (Feistel/Blowfish).
- Called only from `FUN_001d9b6c` (reliable app-message crypto on op0x3d/0x41 path).
- Confidence **High** on the algorithm identification; **Runtime validated: no** — a known-answer test
  against a captured encrypted body would confirm Blowfish vs another 64-bit Feistel.

## Remaining uncertainty
Encrypt vs decrypt direction is set inside `FUN_001e5104` (not in this set) — the same wrapper likely
serves both by the round-key order. Whether the two hashed spans are (client-key, server-nonce) or
(peer-id, session-salt) depends on `FUN_001d9b6c`'s callers.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ea8e8.c`  — untouched decompiler output.
