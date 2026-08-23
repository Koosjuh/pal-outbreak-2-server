FUNCTION FUN_0000236c @ 0x0000236c size=444
CALLERS (1): FUN_00008cb4@0x00008cb4
CALLEES (0): 

undefined4 FUN_0000236c(int param_1)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  iVar4 = 3;
  if (DAT_000149fc != '\x05') {
    return 0xfffffff0;
  }
  iVar2 = *(int *)(DAT_00014a2c + 8);
  iVar5 = *(int *)(DAT_00014a2c + 0xc);
  iVar8 = *(int *)(DAT_00014a2c + 0x18);
  iVar7 = *(int *)(DAT_00014a2c + 0x1c);
  iVar6 = *(int *)(DAT_00014a2c + 100);
  iVar3 = *(int *)(DAT_00014a2c + 0x68);
  do {
    *(char *)(param_1 + (short)iVar4) = (char)iVar2;
    iVar4 = iVar4 + -1;
    iVar2 = iVar2 >> 8;
  } while (-1 < iVar4 * 0x10000);
  iVar4 = 3;
  do {
    *(char *)(param_1 + (short)iVar4 + 4) = (char)iVar5;
    iVar4 = iVar4 + -1;
    iVar5 = iVar5 >> 8;
  } while (-1 < iVar4 * 0x10000);
  iVar4 = 3;
  do {
    iVar2 = param_1 + (short)iVar4;
    *(char *)(iVar2 + 8) = (char)iVar8;
    iVar8 = iVar8 >> 8;
    *(char *)(iVar2 + 0xc) = (char)iVar7;
    iVar7 = iVar7 >> 8;
    *(char *)(iVar2 + 0x10) = (char)iVar6;
    iVar6 = iVar6 >> 8;
    *(char *)(iVar2 + 0x14) = (char)iVar3;
    iVar4 = iVar4 + -1;
    iVar3 = iVar3 >> 8;
  } while (-1 < iVar4 * 0x10000);
  *(undefined4 *)(param_1 + 0x18) = DAT_00014a6c;
  iVar4 = 0;
  *(undefined4 *)(param_1 + 0x1c) = DAT_00014a70;
  do {
    sVar1 = (short)iVar4;
    iVar4 = iVar4 + 1;
    *(int *)(param_1 + sVar1 * 4 + 0x20) = (int)(short)(&DAT_00014a74)[sVar1];
  } while (iVar4 * 0x10000 >> 0x10 < 4);
  *(int *)(param_1 + 0x30) = (int)DAT_00014a7c;
  *(undefined2 *)(param_1 + 0x34) = DAT_00014a7e;
  *(undefined4 *)(param_1 + 0x38) = DAT_00014a80;
  iVar4 = 0;
  *(undefined4 *)(param_1 + 0x3c) = DAT_00014a84;
  do {
    iVar2 = iVar4 << 0x10;
    iVar4 = iVar4 + 1;
    iVar2 = iVar2 >> 0xf;
    *(undefined2 *)(param_1 + iVar2 + 0x40) = *(undefined2 *)((int)&DAT_00014a88 + iVar2);
  } while (iVar4 * 0x10000 >> 0x10 < 4);
  *(undefined2 *)(param_1 + 0x48) = DAT_00014a90;
  *(undefined2 *)(param_1 + 0x4a) = DAT_00014a92;
  *(undefined2 *)(param_1 + 0x4c) = DAT_00014a94;
  *(undefined2 *)(param_1 + 0x4e) = DAT_00014a96;
  *(undefined2 *)(param_1 + 0x50) = DAT_00014a98;
  return 0;
}


================================================================