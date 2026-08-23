FUNCTION FUN_00007e7c @ 0x00007e7c size=312
CALLERS (1): FUN_00007660@0x00007660
CALLEES (1): FUN_00010aa4@0x00010aa4

void FUN_00007e7c(int param_1,int param_2,byte *param_3,int *param_4,int *param_5)

{
  byte bVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = *(int *)(&DAT_00011d14 + param_2 * 4 + param_1 * 0x14);
  if (iVar5 == 0) {
    iVar4 = *param_4;
    iVar3 = iVar4 * 0x200 + 0x14bb8;
    FUN_00010aa4(iVar3,param_3);
    (&DAT_00014ba8)[param_2] = iVar3;
    *param_4 = iVar4 + 1;
  }
  if (iVar5 == 1) {
    iVar5 = *param_5;
    sVar2 = 0;
    bVar1 = *param_3;
    while (bVar1 != 0) {
      bVar1 = *param_3;
      param_3 = param_3 + 1;
      sVar2 = sVar2 * 10 + -0x30 + (ushort)bVar1;
      bVar1 = *param_3;
    }
    iVar3 = iVar5 * 2;
    *(short *)(&DAT_000153b8 + iVar3) = sVar2;
    (&DAT_00014ba8)[param_2] = &DAT_000153b8 + iVar3;
    *param_5 = iVar5 + 1;
  }
  return;
}


================================================================