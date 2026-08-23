FUNCTION FUN_006383e0 @ 0x006383e0  size=784
CALLERS (1): FUN_005dd960@0x005dd960
CALLEES (0): 
----------------------------------------------------------------

undefined4 FUN_006383e0(short *param_1)

{
  uint uVar1;
  ulong uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  float fVar8;
  
  if (iRam0028a324 == 0) {
    func_0x00180038(0x692500,0x70000000,3);
    uVar2 = func_0x0018f430(*(undefined4 *)(param_1 + 6),1);
    uVar1 = (uint)uVar2;
    DAT_70000028 = (long)(int)(uVar1 >> 0x18) << 0x18 |
                   (uVar2 & 0xff) << 0x10 |
                   (long)(int)(uVar1 >> 0x10) & 0xffU | ((long)(int)(uVar1 >> 8) & 0xffU) << 8 |
                   0x100000000;
    iVar3 = -iRam0028a458 + 0x1000;
    if (iVar3 < 0) {
      iVar3 = -iRam0028a458 + 0x1001;
    }
    iVar6 = (iVar3 >> 1) * 0x10;
    iVar3 = -iRam0028a450 + 0x1000;
    if (iVar3 < 0) {
      iVar3 = -iRam0028a450 + 0x1001;
    }
    iVar5 = (iVar3 >> 1) * 0x10;
    iVar7 = (int)param_1[1] << 4;
    iVar4 = (int)param_1[3] << 4;
    fVar8 = (float)iRam0028a458 / 640.0;
    iVar3 = (int)param_1[5] << 4;
    if (iRam00289f34 == 0) {
      iVar7 = iVar7 >> 1;
      iVar4 = iVar4 >> 1;
      iVar3 = iVar3 >> 1;
    }
    if (fRam00289f74 < 2.1474836e+09) {
      uVar2 = (ulong)(int)fRam00289f74;
    }
    else {
      uVar2 = (long)(int)(fRam00289f74 - 2.1474836e+09) | 0xffffffff80000000;
    }
    DAT_70000030 = uVar2 << 0x20 |
                   (long)((int)((float)(int)*param_1 * fVar8 * 16.0) + iVar6) |
                   (long)(iVar7 + iVar5) << 0x10;
    if (fRam00289f74 < 2.1474836e+09) {
      uVar2 = (ulong)(int)fRam00289f74;
    }
    else {
      uVar2 = (long)(int)(fRam00289f74 - 2.1474836e+09) | 0xffffffff80000000;
    }
    DAT_70000038 = uVar2 << 0x20 |
                   (long)((int)((float)(int)param_1[2] * fVar8 * 16.0) + iVar6) |
                   (long)(iVar4 + iVar5) << 0x10;
    if (fRam00289f74 < 2.1474836e+09) {
      uVar2 = (ulong)(int)fRam00289f74;
    }
    else {
      uVar2 = (long)(int)(fRam00289f74 - 2.1474836e+09) | 0xffffffff80000000;
    }
    DAT_70000040 = uVar2 << 0x20 |
                   (long)((int)((float)(int)param_1[4] * fVar8 * 16.0) + iVar6) |
                   (long)(iVar3 + iVar5) << 0x10;
    func_0x0018a650(0x70000000);
  }
  return 1;
}



================================================================