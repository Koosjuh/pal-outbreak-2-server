FUNCTION FUN_005f54d0 @ 0x005f54d0  size=984
CALLERS (4): FUN_005fec30@0x005fec30, FUN_005f84c0@0x005f84c0, FUN_00602340@0x00602340, FUN_00601d50@0x00601d50
CALLEES (6): FUN_005af2e0@0x005af2e0, FUN_005f4fd0@0x005f4fd0, FUN_005f4ed0@0x005f4ed0, FUN_005af2c0@0x005af2c0, FUN_005af1e0@0x005af1e0, FUN_005f5300@0x005f5300
----------------------------------------------------------------

void FUN_005f54d0(int param_1)

{
  short sVar1;
  long lVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int unaff_s5_lo;
  int iVar7;
  float fVar8;
  float fVar9;
  float in_f23;
  float fVar10;
  float fVar11;
  
  iVar3 = iRam003435d4;
  iVar6 = iRam003435d4 + 0xc8000;
  FUN_005af2e0(0x12);
  fVar10 = 18.0 - DAT_00692ec8;
  if (param_1 == 2) {
    unaff_s5_lo = 0xb;
    in_f23 = 100.0;
  }
  else if (param_1 == 1) {
    in_f23 = 96.0;
    unaff_s5_lo = 5;
  }
  else if (param_1 == 0) {
    unaff_s5_lo = 10;
    in_f23 = 84.0;
  }
  if (cRam006c50fb == '\0') {
    iVar7 = *(int *)(iVar3 + 0xc9358) - *(int *)(iVar3 + 0xc9360);
    if (iVar7 < 0) {
      iVar7 = iVar7 + 0x32;
    }
    if (iVar7 < unaff_s5_lo) {
      *(int *)(iVar3 + 0xc935c) = *(int *)(iVar3 + 0xc9360);
    }
    else {
      iVar7 = *(int *)(iVar3 + 0xc9358) - unaff_s5_lo;
      if (iVar7 < 0) {
        iVar7 = iVar7 + 0x32;
      }
      *(int *)(iVar3 + 0xc935c) = iVar7;
    }
    iVar3 = *(int *)(iVar3 + 0xc935c);
  }
  else {
    sVar1 = FUN_005f4ed0();
    if (sVar1 == 0) {
      sVar1 = FUN_005f4fd0();
      if (sVar1 != 0) {
        for (lVar2 = 0; lVar2 < sVar1; lVar2 = (long)((int)lVar2 + 1)) {
          iVar7 = *(int *)(iVar3 + 0xc9358) - *(int *)(iVar3 + 0xc935c);
          if (iVar7 < 0) {
            iVar7 = iVar7 + 0x32;
          }
          if ((unaff_s5_lo < iVar7) &&
             (*(int *)(iVar3 + 0xc935c) = *(int *)(iVar3 + 0xc935c) + 1,
             *(int *)(iVar3 + 0xc935c) == 0x32)) {
            *(undefined4 *)(iVar3 + 0xc935c) = 0;
          }
        }
      }
      iVar3 = *(int *)(iVar3 + 0xc935c);
    }
    else {
      for (lVar2 = 0; lVar2 < sVar1; lVar2 = (long)((int)lVar2 + 1)) {
        iVar7 = *(int *)(iVar3 + 0xc935c);
        if (*(int *)(iVar3 + 0xc9360) != iVar7) {
          iVar4 = iVar7 + -1;
          if (iVar4 < 0) {
            iVar4 = iVar7 + 0x31;
          }
          *(int *)(iVar3 + 0xc935c) = iVar4;
        }
      }
      iVar3 = *(int *)(iVar3 + 0xc935c);
    }
  }
  iVar7 = 0;
  if (0 < unaff_s5_lo) {
    for (; iVar7 < unaff_s5_lo; iVar7 = iVar7 + 1) {
      fVar11 = 64.0;
      *(undefined1 *)(iVar7 + 0x6c54d0) = 0;
      iVar4 = iVar6 + iVar3 * 0x11;
      fVar9 = (float)iVar7 * 20.0;
      if (*(char *)(iVar4 + 800) != '\0') {
        FUN_005f5300(iVar3,1);
        fVar8 = in_f23 + fVar9;
        iVar4 = iVar4 + 800;
        FUN_005af1e0(0x40,(int)fVar8,0,iVar4);
        iVar4 = func_0x001ae3e0(iVar4);
        fVar11 = ((float)iVar4 / 2.0) * fVar10 + 64.0;
        *(short *)(iVar7 * 2 + 0x6c54e0) = (short)(int)fVar11;
        FUN_005af2c0(0);
        FUN_005af1e0((int)fVar11,(int)fVar8,0,0x649718);
        fVar11 = fVar11 + fVar10 * 2.0;
        *(undefined1 *)(iVar7 + 0x6c54d0) = *(undefined1 *)(iVar6 + iVar3 + 0x1364);
      }
      iVar4 = iVar6 + iVar3 * 0x42;
      iVar5 = iVar4 + 0x672;
      *(undefined1 *)(iVar4 + 0x6b3) = 0;
      if (iVar5 != 0) {
        FUN_005f5300(iVar3,2);
        FUN_005af1e0((int)fVar11,(int)(in_f23 + fVar9),0,iVar5);
      }
      iVar3 = iVar3 + 1;
      if (0x31 < iVar3) {
        iVar3 = 0;
      }
    }
  }
  return;
}



================================================================