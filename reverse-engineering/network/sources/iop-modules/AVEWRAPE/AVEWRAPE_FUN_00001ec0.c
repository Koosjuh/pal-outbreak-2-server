FUNCTION FUN_00001ec0 @ 0x00001ec0 size=368
CALLERS (1): FUN_00002098@0x00002098
CALLEES (2): FUN_00002840@0x00002840, FUN_00002838@0x00002838

void FUN_00001ec0(uint *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  uVar5 = *param_1;
  uVar6 = 0xffffffff;
  if ((3 < uVar5) || (uVar6 = FUN_00002840(uVar5), uVar6 != 0)) goto LAB_00002014;
  iVar1 = FUN_00002838(&DAT_00003df0,0xc30);
  iVar3 = 0;
  if (0 < iVar1) {
    iVar4 = 0;
    do {
      if (*(uint *)((int)&DAT_00003df0 + iVar4) == uVar5) break;
      iVar3 = iVar3 + 1;
      iVar4 = iVar4 + 0x30c;
    } while (iVar3 < iVar1);
  }
  if (iVar1 == iVar3) {
    param_1[6] = 0xffffffff;
    return;
  }
  iVar3 = iVar3 * 0x30c;
  if (*(int *)(&DAT_00003df8 + iVar3) == 0) {
    iVar1 = *(int *)(&DAT_00003df4 + iVar3);
    if (iVar1 == 1) {
      DAT_00002c64 = iVar1;
      param_1[6] = 0;
      return;
    }
    if (1 < iVar1) goto LAB_00002014;
    uVar2 = 4;
joined_r0x00001fb8:
    if (iVar1 != 0) goto LAB_00002014;
  }
  else {
    if (*(int *)(&DAT_00003df8 + iVar3) != 1) {
      param_1[6] = 0;
      return;
    }
    iVar1 = *(int *)(&DAT_00003df4 + iVar3);
    if (iVar1 != 1) {
      if (1 < iVar1) goto LAB_00002014;
      uVar2 = 5;
      goto joined_r0x00001fb8;
    }
    uVar2 = 2;
  }
  DAT_00002c64 = uVar2;
LAB_00002014:
  param_1[6] = uVar6;
  return;
}


================================================================