FUNCTION FUN_000061d8 @ 0x000061d8 size=136
CALLERS (1): FUN_00005070@0x00005070
CALLEES (1): FUN_00010be8@0x00010be8

undefined4 FUN_000061d8(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  short sVar4;
  undefined4 uVar5;
  undefined1 auStack_10 [8];
  
  iVar3 = DAT_00014a2c;
  *param_1 = *(undefined4 *)(DAT_00014a2c + 0xc);
  uVar2 = DAT_00012ef4;
  uVar1 = DAT_00012ecc;
  uVar5 = *(undefined4 *)(iVar3 + 8);
  *(short *)((int)param_1 + 0x12) = (short)DAT_00012edc;
  *(short *)(param_1 + 2) = (short)uVar1;
  param_1[3] = uVar2;
  param_1[1] = uVar5;
  sVar4 = FUN_00010be8(auStack_10);
  if (sVar4 == 0) {
    *(undefined2 *)((int)param_1 + 0x12) = 9;
  }
  *(short *)(param_1 + 4) = (short)DAT_00012ed4;
  return 0;
}


================================================================