FUNCTION FUN_00004314 @ 0x00004314 size=416
CALLERS (4): FUN_00002cb4@0x00002cb4, FUN_00002d9c@0x00002d9c, FUN_00002f1c@0x00002f1c, FUN_0000223c@0x0000223c
CALLEES (6): FUN_0000139c@0x0000139c, FUN_000042fc@0x000042fc, FUN_0000ea28@0x0000ea28, FUN_0000430c@0x0000430c, FUN_00011d00@0x00011d00, FUN_000010a8@0x000010a8

undefined4 FUN_00004314(int *param_1,undefined4 param_2,short param_3,short param_4)

{
  undefined2 uVar1;
  short sVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  
  iVar3 = FUN_000042fc();
  if (iVar3 == 0) {
    return 0xffffffff;
  }
  iVar5 = param_4 * 0x2c;
  if (*(short *)(&DAT_00022884 + iVar5) == 1) {
    FUN_00011d00(iVar3 + 6,iVar5 + 0x22888,(&DAT_00022886)[iVar5]);
    FUN_00011d00(iVar3,param_2,(&DAT_00022886)[iVar5]);
    if (param_3 == 4) {
      uVar4 = 0x806;
    }
    else {
      uVar4 = 0x800;
      if (param_3 != 0) goto LAB_00004484;
    }
    uVar1 = FUN_000010a8(uVar4);
    *(undefined2 *)(iVar3 + 0xc) = uVar1;
    iVar5 = *param_1;
    FUN_00011d00(&DAT_00016578,iVar3,6);
    FUN_00011d00(&DAT_0001657e,iVar3 + 6,6);
    FUN_00011d00(&DAT_00016584,iVar3 + 0xc,2);
    FUN_0000139c(param_1 + iVar5 * 3 + 3,&DAT_00016578);
    *(undefined2 *)(param_1 + iVar5 * 3 + 2) = 0xe;
    *param_1 = *param_1 + 1;
    sVar2 = FUN_0000ea28(param_1,(int)param_4);
    if (sVar2 == 0) {
      FUN_0000430c(iVar3);
      return 0;
    }
  }
LAB_00004484:
  FUN_0000430c(iVar3);
  return 0xffffffff;
}


================================================================