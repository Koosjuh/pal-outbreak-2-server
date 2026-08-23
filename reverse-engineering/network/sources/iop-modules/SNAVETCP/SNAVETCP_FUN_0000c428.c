FUNCTION FUN_0000c428 @ 0x0000c428 size=436
CALLERS (2): FUN_00007000@0x00007000, FUN_0000c088@0x0000c088
CALLEES (6): FUN_00010bc0@0x00010bc0, FUN_0000ad44@0x0000ad44, FUN_0000b3d4@0x0000b3d4, FUN_000105ec@0x000105ec, FUN_00014e24@0x00014e24, FUN_0001168c@0x0001168c

int FUN_0000c428(int param_1,short param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  short sVar4;
  int iVar5;
  
  iVar1 = param_1 - DAT_00016180;
  iVar5 = (uint)*(ushort *)(param_1 + 0xcc) +
          ((uint)*(ushort *)(param_1 + 0xfc) - (uint)*(ushort *)(param_1 + 0xf8));
  if (2 < *(short *)(param_1 + 0x13a)) {
    *(undefined2 *)(param_1 + 0x13a) = 0;
    FUN_0000b3d4(param_1);
  }
  *(char *)(param_1 + 0x142) = (char)param_2;
  sVar4 = (short)(iVar1 * -0x2b1da461 >> 2);
  if (param_2 == 4) {
    FUN_000105ec((int)sVar4,*(undefined4 *)(param_1 + 0xd0),0xfffffff5);
    FUN_00010bc0((int)sVar4,*(undefined4 *)(param_1 + 0xd4),0xfffffff5,iVar5 * 0x10000 >> 0x10);
    uVar2 = *(undefined4 *)(param_1 + 0x168);
    uVar3 = 0xb;
  }
  else {
    FUN_000105ec((int)sVar4,*(undefined4 *)(param_1 + 0xd0),0xfffffffa);
    FUN_00010bc0((int)sVar4,*(undefined4 *)(param_1 + 0xd4),0xfffffffa,iVar5 * 0x10000 >> 0x10);
    uVar2 = *(undefined4 *)(param_1 + 0x168);
    uVar3 = 10;
  }
  FUN_0001168c((int)sVar4,uVar2,3,uVar3);
  if (DAT_00016194 == 0) {
    if ((DAT_00016178 & 2) != 0) {
      FUN_00014e24("ave-tcp: delete tcp nh %d. (AT_TCP_Drop)\n",
                   (param_1 - DAT_00016180) * -0x2b1da461 >> 2);
    }
    *(byte *)(param_1 + 0x13f) = *(byte *)(param_1 + 0x13f) | 0x80;
  }
  iVar1 = FUN_0000ad44(param_1);
  if (iVar1 != 0) {
    *(undefined2 *)(param_1 + 0x13a) = 0xffff;
  }
  return iVar1;
}


================================================================