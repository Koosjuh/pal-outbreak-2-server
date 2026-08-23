FUNCTION FUN_005f42c0 @ 0x005f42c0  size=384
CALLERS (2): FUN_00621ed0@0x00621ed0, FUN_005b2e40@0x005b2e40
CALLEES (1): FUN_005f4250@0x005f4250
----------------------------------------------------------------

void FUN_005f42c0(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  undefined4 uVar4;
  long lVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  undefined1 auStack_100 [256];
  
  iVar2 = iRam003435bc;
  uVar3 = uRam0034357a;
  iVar8 = 0x4000;
  iVar6 = iRam003435bc + 0x100000;
  uRam0034357a = 0xffff;
  func_0x00109eb8(auStack_100,0x649630);
  lVar5 = func_0x001cb360(auStack_100,iVar2,0x10001,0);
  piVar9 = (int *)(iVar2 + 8);
  if (lVar5 != 0) {
    iVar7 = 0;
    do {
      iVar1 = *piVar9;
      piVar9 = piVar9 + 2;
      func_0x001a79b0(iVar2 + iVar1,iVar6);
      lVar5 = func_0x001cbcb0(iVar8);
      if (lVar5 == 0) {
        func_0x001cb5f0(iVar8,iVar6);
        uVar4 = func_0x001cbcb0(iVar8);
        *param_1 = uVar4;
      }
      else {
        *param_1 = (int)lVar5;
      }
      param_1 = param_1 + 1;
      iVar7 = iVar7 + 1;
      iVar8 = iVar8 + 1;
    } while (iVar7 < 7);
    for (; iVar7 < 9; iVar7 = iVar7 + 1) {
      iVar1 = *piVar9;
      piVar9 = piVar9 + 2;
      func_0x001a79b0(iVar2 + iVar1,iVar6);
      lVar5 = func_0x001cbcb0(iVar8);
      if (lVar5 == 0) {
        func_0x001cb5f0(iVar8,iVar6);
        uVar4 = func_0x001cbcb0(iVar8);
        *param_2 = uVar4;
      }
      else {
        *param_2 = (int)lVar5;
      }
      param_2 = param_2 + 1;
      iVar8 = iVar8 + 1;
    }
    FUN_005f4250();
    uVar3 = uRam0034357a;
  }
  uRam0034357a = uVar3;
  return;
}



================================================================