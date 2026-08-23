
uint FUN_001c3880(int param_1)

{
  byte bVar1;
  uint uVar2;
  long lVar3;
  uint uVar4;
  
  lVar3 = FUN_001ee430(*(undefined4 *)(param_1 + 0x1c),0x35a714);
  if (lVar3 < 0) {
    uVar4 = 0xffffffff;
  }
  else {
    uVar4 = 0xffffffff;
    if (sRam0035a714 == 4) {
      if ((*(char *)(param_1 + 0x3c) == '\0') && (7 < uRam0035a71a)) {
        lVar3 = FUN_001ee560(*(undefined4 *)(param_1 + 0x1c),*(undefined4 *)(param_1 + 0x30),8);
        if (lVar3 != 8) {
          return 0xffffffff;
        }
        *(ushort *)(param_1 + 0x42) =
             **(ushort **)(param_1 + 0x30) << 8 | **(ushort **)(param_1 + 0x30) >> 8;
        if (*(short *)(param_1 + 0x42) == 0) {
          return 1;
        }
        *(undefined1 *)(param_1 + 0x3c) = 1;
        *(undefined2 *)(param_1 + 0x3e) = 0;
        *(undefined2 *)(param_1 + 0x40) = 0;
        *(undefined1 *)(param_1 + 0x44) = 1;
        uRam0035a71a = uRam0035a71a - 8;
      }
      uVar4 = 0;
      if (*(char *)(param_1 + 0x3c) != '\0') {
        if (1 < *(byte *)(param_1 + 0x44)) {
          *(undefined2 *)(param_1 + 0x3e) = 0;
        }
        uVar4 = (uint)*(ushort *)(param_1 + 0x42) - (uint)*(ushort *)(param_1 + 0x3e);
        if ((int)(uint)uRam0035a71a < (int)uVar4) {
          uVar4 = (uint)uRam0035a71a;
        }
        uVar2 = *(int *)(param_1 + 0x24) - (uint)*(ushort *)(param_1 + 0x3e);
        if ((int)uVar2 < (int)uVar4) {
          uVar4 = uVar2;
        }
        if (0 < (int)uVar4) {
          lVar3 = FUN_001ee560(*(undefined4 *)(param_1 + 0x1c),*(undefined4 *)(param_1 + 0x34),
                               (short)uVar4);
          if (lVar3 < 0) {
            return 0xffffffff;
          }
          *(short *)(param_1 + 0x3e) = *(short *)(param_1 + 0x3e) + (short)lVar3;
          if ((uint)*(ushort *)(param_1 + 0x42) == (uint)*(ushort *)(param_1 + 0x3e)) {
            *(undefined2 *)(param_1 + 0x42) = 0;
            *(undefined2 *)(param_1 + 0x40) = 0;
            *(undefined1 *)(param_1 + 0x3c) = 0;
            return 1;
          }
          if ((uint)*(ushort *)(param_1 + 0x3e) == *(uint *)(param_1 + 0x24)) {
            *(ushort *)(param_1 + 0x42) =
                 *(ushort *)(param_1 + 0x42) - (short)*(uint *)(param_1 + 0x24);
            *(undefined2 *)(param_1 + 0x40) = 0;
            bVar1 = *(char *)(param_1 + 0x44) + 1;
            *(byte *)(param_1 + 0x44) = bVar1;
            return (uint)bVar1;
          }
        }
        uVar4 = 0;
      }
    }
  }
  return uVar4;
}

