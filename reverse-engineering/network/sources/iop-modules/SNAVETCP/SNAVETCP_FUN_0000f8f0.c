FUNCTION FUN_0000f8f0 @ 0x0000f8f0 size=336
CALLERS (1): FUN_000003a0@0x000003a0
CALLEES (3): FUN_0000f4fc@0x0000f4fc, FUN_00001080@0x00001080, FUN_000046d4@0x000046d4

undefined4 FUN_0000f8f0(short *param_1)

{
  short sVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  DAT_0001616c = 0;
  if (*(int *)(param_1 + 2) == 0) {
    if (*(int *)(param_1 + 4) != 0) {
      DAT_0001616c = 0;
      return 0xfffffff0;
    }
    if (*(int *)(param_1 + 6) != -1) {
      DAT_0001616c = 0;
      return 0xfffffff0;
    }
    DAT_0001616c = 1;
  }
  if (*param_1 != 0) {
    return 0xfffffff0;
  }
  DAT_00017e10 = *(uint *)(param_1 + 2);
  DAT_00017e14 = *(uint *)(param_1 + 4);
  DAT_00017e14 = FUN_0000f4fc();
  DAT_00017e18 = *(uint *)(param_1 + 6);
  iVar6 = (int)*param_1;
  if (iVar6 == 0) {
    if (((DAT_00017e10 != DAT_00017e18) && (DAT_00017e10 != 0xffffffff)) &&
       ((uVar3 = DAT_00017e10 & ~DAT_00017e14, uVar3 != 0 || (DAT_00017e10 == 0)))) {
      if (uVar3 == ~DAT_00017e14) {
        return 0xfffffff0;
      }
      uVar3 = FUN_00001080();
      if ((uVar3 & 0xff000000) != 0x7f000000) {
        iVar6 = (int)*param_1;
        uVar3 = DAT_00017e10;
        uVar4 = DAT_00017e14;
        uVar5 = DAT_00017e18;
        goto LAB_0000fa10;
      }
    }
    uVar2 = 0xfffffff0;
  }
  else {
    uVar3 = *(uint *)(param_1 + 2);
    uVar4 = *(uint *)(param_1 + 4);
    uVar5 = *(uint *)(param_1 + 6);
LAB_0000fa10:
    sVar1 = FUN_000046d4(uVar3,uVar4,uVar5,iVar6);
    uVar2 = 0;
    if (sVar1 != 0) {
      uVar2 = 0xfffffff0;
    }
  }
  return uVar2;
}


================================================================