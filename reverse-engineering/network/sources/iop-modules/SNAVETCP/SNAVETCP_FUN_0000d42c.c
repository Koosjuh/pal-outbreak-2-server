FUNCTION FUN_0000d42c @ 0x0000d42c size=520
CALLERS (3): FUN_00007000@0x00007000, FUN_0000d39c@0x0000d39c, FUN_0000d634@0x0000d634
CALLEES (3): FUN_0000ad44@0x0000ad44, FUN_0000b3d4@0x0000b3d4, FUN_00014e24@0x00014e24

undefined4 FUN_0000d42c(short param_1)

{
  byte *pbVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  iVar3 = DAT_00016180 + param_1 * 0x17c;
  switch((int)((*(ushort *)(iVar3 + 0x13a) + 1) * 0x10000) >> 0x10) {
  case 0:
    *(byte *)(iVar3 + 0x13f) = *(byte *)(iVar3 + 0x13f) | 0x80;
    uVar4 = DAT_00016178 & 2;
    *(undefined2 *)(iVar3 + 0x13a) = 0;
    if (uVar4 != 0) {
      FUN_00014e24("ave-tcp: delete tcp nh %d. (AT_TCP_CloseSub FATAL)\n",
                   (int)((iVar3 - DAT_00016180) * -0x2b1da461) >> 2);
    }
    FUN_0000ad44(iVar3);
    return 0;
  case 2:
    uVar4 = DAT_00016180 + (uint)DAT_0001619b * 0x17c;
    if (DAT_00016180 < uVar4) {
      pbVar1 = (byte *)(DAT_00016180 + 0x13f);
      uVar2 = DAT_00016180;
      do {
        if ((*(short *)(pbVar1 + -7) != 0) && (param_1 == *(short *)(pbVar1 + -3))) {
          if ((DAT_00016178 & 2) != 0) {
            FUN_00014e24("ave-tcp: delete tcp nh %d. (AT_TCP_CloseSub LISTEN)\n",
                         (int)((uVar2 - DAT_00016180) * -0x2b1da461) >> 2);
          }
          *pbVar1 = *pbVar1 | 0x80;
          FUN_0000ad44(uVar2);
        }
        uVar2 = uVar2 + 0x17c;
        pbVar1 = pbVar1 + 0x17c;
      } while (uVar2 < uVar4);
    }
  case 1:
  case 3:
  case 4:
    *(undefined2 *)(iVar3 + 0x13a) = 0;
    FUN_0000ad44(iVar3);
    return 0;
  case 5:
    *(undefined2 *)(iVar3 + 0x13a) = 6;
    break;
  case 6:
    *(undefined2 *)(iVar3 + 0x13a) = 8;
  }
  FUN_0000b3d4(iVar3);
  return 0;
}


================================================================