FUNCTION FUN_00002ae8 @ 0x00002ae8 size=460
CALLERS (1): FUN_000114dc@0x000114dc
CALLEES (3): FUN_00001454@0x00001454, FUN_0000139c@0x0000139c, FUN_000010c0@0x000010c0

short FUN_00002ae8(ushort param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  short sVar5;
  undefined4 local_38;
  undefined1 local_34;
  undefined1 local_33;
  undefined1 local_32;
  undefined1 local_31;
  undefined1 local_30;
  undefined1 local_2f;
  undefined1 local_2e;
  byte local_2d;
  undefined1 auStack_28 [8];
  
  sVar5 = 0;
  iVar4 = 0;
  if (0xb < param_1) {
    iVar1 = 0;
    do {
      uVar3 = (uint)DAT_0001618c;
      if ((int)uVar3 <= iVar1 >> 0x10) {
        return sVar5;
      }
      iVar2 = iVar4 << 0x10;
      if ((&DAT_000187a0)[(iVar1 >> 0x10) * 0x20] == '\0') {
        iVar4 = iVar4 + 1;
        iVar1 = iVar4 * 0x10000 >> 0x10;
        if ((int)uVar3 <= iVar1) {
          return sVar5;
        }
        iVar2 = iVar4 * 0x10000;
        if ((&DAT_000187a0)[iVar1 * 0x20] == '\0') {
          do {
            iVar4 = iVar4 + 1;
            iVar1 = iVar4 * 0x10000 >> 0x10;
            if ((int)uVar3 <= iVar1) {
              return sVar5;
            }
          } while ((&DAT_000187a0)[iVar1 * 0x20] == '\0');
          iVar2 = iVar4 * 0x10000;
        }
      }
      iVar2 = iVar2 >> 0x10;
      iVar1 = iVar2 * 0x20;
      if ((int)(uint)DAT_0001618c <= iVar2) {
        return sVar5;
      }
      local_38 = (&DAT_000187b4)[iVar2 * 8];
      local_34 = (&DAT_000187b8)[iVar1];
      local_33 = *(undefined1 *)(iVar1 + 0x187b9);
      local_32 = *(undefined1 *)(iVar1 + 0x187ba);
      local_31 = *(undefined1 *)(iVar1 + 0x187bb);
      local_30 = *(undefined1 *)(iVar1 + 0x187bc);
      local_2f = *(undefined1 *)(iVar1 + 0x187bd);
      sVar5 = sVar5 + 1;
      local_2e = (&DAT_000187b0)[iVar1];
      iVar4 = iVar4 + 1;
      param_1 = param_1 - 0xc;
      local_2d = (&DAT_000187a0)[iVar1] | 1;
      FUN_0000139c(auStack_28,&local_38);
      FUN_000010c0(param_2,auStack_28,0xc);
      FUN_00001454(param_2,0xc);
      iVar1 = iVar4 * 0x10000;
    } while (0xb < param_1);
  }
  return sVar5;
}


================================================================