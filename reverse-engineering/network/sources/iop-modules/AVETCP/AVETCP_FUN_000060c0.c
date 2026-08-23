FUNCTION FUN_000060c0 @ 0x000060c0 size=880
CALLERS (1): FUN_00005f68@0x00005f68
CALLEES (11): FUN_000066a4@0x000066a4, FUN_0000139c@0x0000139c, FUN_000010c0@0x000010c0, FUN_00000fa0@0x00000fa0, FUN_00006c88@0x00006c88, FUN_00006430@0x00006430, FUN_00006a8c@0x00006a8c, FUN_00006784@0x00006784, FUN_00006978@0x00006978, FUN_00011d00@0x00011d00, FUN_00001760@0x00001760

int * FUN_000060c0(int param_1,int param_2,uint param_3,short param_4,ushort param_5,char param_6)

{
  ushort uVar1;
  short sVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  undefined1 auStack_28 [8];
  
  uVar8 = (uint)param_5;
  if (param_4 == 0) {
    *(short *)(param_1 + 8) = (short)param_3;
  }
  else {
    param_2 = param_2 + (param_3 & 0xffff);
  }
  iVar3 = FUN_000066a4();
  if (iVar3 == 0) {
    FUN_00006a8c(param_1);
    iVar3 = FUN_000066a4();
    if (iVar3 == 0) {
      return (int *)0x0;
    }
  }
  *(short *)(iVar3 + 8) = param_4;
  *(ushort *)(iVar3 + 10) = param_5;
  FUN_0000139c(auStack_28,param_2);
  if (param_4 == 0) {
    iVar5 = (int)((uVar8 + param_3) * 0x10000) >> 0x10;
    sVar2 = FUN_00006c88(iVar3,iVar5,2);
    if (sVar2 != 0) {
      FUN_00006a8c(param_1);
      sVar2 = FUN_00006c88(iVar3,iVar5,2);
      if (sVar2 != 0) {
        return (int *)0x0;
      }
    }
    uVar8 = uVar8 + (param_3 & 0xffff);
  }
  else {
    sVar2 = FUN_00006c88(iVar3,(int)(short)param_5,2);
    if (sVar2 != 0) {
      FUN_00006a8c(param_1);
      sVar2 = FUN_00006c88(iVar3,(int)(short)param_5,2);
      if (sVar2 != 0) {
        return (int *)0x0;
      }
    }
  }
  FUN_000010c0(iVar3,auStack_28,uVar8);
  *(undefined4 *)(iVar3 + 0xc) = 0;
  iVar5 = *(int *)(param_1 + 0x10);
  if (iVar5 == 0) {
    *(int *)(param_1 + 0x14) = iVar3;
    *(int *)(param_1 + 0x10) = iVar3;
  }
  else {
    uVar1 = *(ushort *)(iVar3 + 8);
    if (*(ushort *)(*(int *)(param_1 + 0x14) + 8) < uVar1) {
      *(int *)(*(int *)(param_1 + 0x14) + 0xc) = iVar3;
      *(int *)(param_1 + 0x14) = iVar3;
    }
    else if (uVar1 < *(ushort *)(iVar5 + 8)) {
      *(int *)(iVar3 + 0xc) = iVar5;
      *(int *)(param_1 + 0x10) = iVar3;
    }
    else {
      for (iVar6 = *(int *)(iVar5 + 0xc); iVar6 != 0; iVar6 = *(int *)(iVar6 + 0xc)) {
        if ((*(ushort *)(iVar5 + 8) < uVar1) && (uVar1 < *(ushort *)(iVar6 + 8))) {
          *(int *)(iVar3 + 0xc) = iVar6;
          *(int *)(iVar5 + 0xc) = iVar3;
          break;
        }
        if (*(ushort *)(iVar3 + 8) == *(ushort *)(iVar5 + 8)) {
          FUN_00001760(iVar3);
          FUN_00006784(iVar3);
          break;
        }
        iVar5 = *(int *)(iVar5 + 0xc);
      }
    }
  }
  if (*(char *)(param_1 + 0xb) == '\0') {
    if (param_6 != '\0') {
      return (int *)0x0;
    }
    *(undefined1 *)(param_1 + 0xb) = 1;
  }
  sVar2 = FUN_00006430(param_1);
  if (sVar2 != 0) {
    return (int *)0x0;
  }
  piVar4 = (int *)FUN_00000fa0();
  if (piVar4 == (int *)0x0) {
    FUN_00006978();
    return (int *)0x0;
  }
  *piVar4 = 0;
  piVar4[1] = 0;
  iVar3 = 0;
  if (*(int *)(param_1 + 0x10) != 0) {
    iVar6 = 0;
    iVar5 = *(int *)(param_1 + 0x10);
    do {
      iVar6 = iVar6 >> 0x10;
      *piVar4 = *piVar4 + 1;
      piVar4[1] = piVar4[1] + (uint)*(ushort *)(iVar5 + 10);
      *(undefined2 *)(piVar4 + iVar6 * 3 + 2) = *(undefined2 *)(iVar5 + 10);
      FUN_00011d00(piVar4 + iVar6 * 3 + 3,iVar5,8);
      if (iVar6 == 0) {
        piVar4[1] = piVar4[1] + (uint)*(ushort *)(param_1 + 8);
        *(short *)(piVar4 + 2) = (short)piVar4[2] + *(short *)(param_1 + 8);
      }
      iVar7 = *(int *)(iVar5 + 0xc);
      iVar3 = iVar3 + 1;
      FUN_00006784(iVar5);
      iVar6 = iVar3 * 0x10000;
      iVar5 = iVar7;
    } while (iVar7 != 0);
    return piVar4;
  }
  return piVar4;
}


================================================================