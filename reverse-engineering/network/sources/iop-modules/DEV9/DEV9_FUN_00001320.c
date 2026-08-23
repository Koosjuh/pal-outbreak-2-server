FUNCTION FUN_00001320 @ 0x00001320 size=312
CALLERS (1): FUN_00000204@0x00000204
CALLEES (2): FUN_00000fa8@0x00000fa8, FUN_00002164@0x00002164

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00001320(uint param_1)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  byte *pbVar4;
  
  FUN_00000fa8(2);
  _DAT_bf801418 = 0x1a00bb;
  pbVar2 = &DAT_b0000000;
  do {
    bVar1 = *pbVar2;
    pbVar3 = pbVar2 + 2;
    if (bVar1 != 0) {
      if (bVar1 == 0xff) break;
      pbVar4 = pbVar3;
      if (&DAT_b0001000 <= pbVar3) {
LAB_00001388:
        FUN_00002164("dev9: invalid tuples (off=0x%x)\n",pbVar4 + 0x50000000);
        return 0xffffffff;
      }
      pbVar4 = pbVar2 + 4;
      if (*pbVar3 == 0xff) break;
      pbVar3 = pbVar4 + (uint)*pbVar3 * 2;
      if (&DAT_b0001000 < pbVar3) goto LAB_00001388;
      if (bVar1 == 0x20) {
        if (pbVar2 + 0xc < (byte *)0xb0001001) {
          if (((uint)pbVar2[6] << 0x18 | (uint)*pbVar4 << 0x10 | (uint)pbVar2[10] << 8 |
              (uint)pbVar2[8]) == param_1) {
            _DAT_bf801418 = 0x1a00bb;
            return 0;
          }
          FUN_00002164("dev9: unexpected MANFID (0x%08x)\n");
          return 0xffffffff;
        }
        goto LAB_00001388;
      }
    }
    pbVar2 = pbVar3;
  } while (pbVar3 < &DAT_b0001000);
  FUN_00002164("dev9: MANFID not found\n");
  return 0xffffffff;
}


================================================================