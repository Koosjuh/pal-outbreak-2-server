FUNCTION FUN_0000056c @ 0x0000056c size=320
CALLERS (0): 
CALLEES (5): FUN_0000031c@0x0000031c, FUN_000080bc@0x000080bc, FUN_000080c4@0x000080c4, FUN_0000810c@0x0000810c, FUN_00000440@0x00000440

int FUN_0000056c(int param_1,uint param_2)

{
  int iVar1;
  short sVar2;
  int iVar3;
  undefined4 local_20 [2];
  
  if ((DAT_00009710 & 1) != 0) {
    FUN_0000810c(&PTR_DAT_000082d0);
    FUN_0000810c("DG_getDeviceInfo mdm %d eth %d\n",DAT_000096e4,DAT_000096f4);
  }
  FUN_000080bc(local_20);
  sVar2 = 0;
  iVar3 = 0;
  iVar1 = 0;
  do {
    if (*(int *)((int)&DAT_00009718 + iVar1) != 0) {
      if (param_2 < 0x30c) goto LAB_0000067c;
      FUN_0000031c(iVar3,param_1);
      sVar2 = sVar2 + 1;
      param_1 = param_1 + 0x30c;
      param_2 = param_2 - 0x30c;
    }
    iVar3 = iVar3 + 1;
    iVar1 = iVar3 * 4;
  } while (iVar3 < 2);
  iVar3 = 0;
  iVar1 = 0;
  do {
    if (*(int *)((int)&DAT_00009720 + iVar1) != 0) {
      if (param_2 < 0x30c) goto LAB_0000067c;
      FUN_00000440(iVar3,param_1);
      sVar2 = sVar2 + 1;
      param_1 = param_1 + 0x30c;
      param_2 = param_2 - 0x30c;
    }
    iVar3 = iVar3 + 1;
    iVar1 = iVar3 * 4;
  } while (iVar3 < 2);
  DAT_00009730 = 0;
LAB_0000067c:
  FUN_000080c4(local_20[0]);
  return (int)sVar2;
}


================================================================