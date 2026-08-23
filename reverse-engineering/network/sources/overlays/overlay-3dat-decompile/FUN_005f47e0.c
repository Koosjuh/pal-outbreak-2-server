FUNCTION FUN_005f47e0 @ 0x005f47e0  size=820
CALLERS (1): FUN_00621fe0@0x00621fe0
CALLEES (0): 
----------------------------------------------------------------

void FUN_005f47e0(float param_1,short *param_2)

{
  short sVar1;
  uint uVar2;
  ulong uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  float fVar8;
  
  if (iRam0028a324 == 0) {
    iVar4 = -iRam0028a458 + 0x1000;
    if (iVar4 < 0) {
      iVar4 = -iRam0028a458 + 0x1001;
    }
    iVar5 = -iRam0028a450 + 0x1000;
    if (iVar5 < 0) {
      iVar5 = -iRam0028a450 + 0x1001;
    }
    fVar8 = (float)iRam0028a458;
    sVar1 = param_2[2];
    iVar7 = (int)param_2[1] << 4;
    iVar6 = (int)param_2[3] << 4;
    if (iRam00289f34 == 0) {
      iVar7 = iVar7 >> 1;
      iVar6 = iVar6 >> 1;
    }
    iVar4 = (int)((float)(int)*param_2 * (fVar8 / 640.0) * 16.0) + (iVar4 >> 1) * 0x10;
    iVar7 = iVar7 + (iVar5 >> 1) * 0x10;
    func_0x00180038(0x6496c0,0x70000000,3);
    uVar3 = func_0x0018f430(*(undefined4 *)(param_2 + 4),0);
    uVar2 = (uint)uVar3;
    DAT_70000028 = (long)(int)(uVar2 >> 0x18) << 0x18 |
                   (uVar3 & 0xff) << 0x10 |
                   (long)(int)(uVar2 >> 0x10) & 0xffU | ((long)(int)(uVar2 >> 8) & 0xffU) << 8 |
                   0x100000000;
    DAT_70000030 = (long)((int)(param_1 * 16.0) + 8) | (long)(param_2[7] * 0x10 + 8) << 0x10;
    if (fRam00289f74 < 2.1474836e+09) {
      uVar3 = (ulong)(int)fRam00289f74;
    }
    else {
      uVar3 = (long)(int)(fRam00289f74 - 2.1474836e+09) | 0xffffffff80000000;
    }
    DAT_70000038 = uVar3 << 0x20 | (long)iVar4 | (long)iVar7 << 0x10;
    DAT_70000040 = (long)((int)((param_1 + 511.0) * 16.0) + 8) |
                   (long)(param_2[9] * 0x10 + 8) << 0x10;
    if (fRam00289f74 < 2.1474836e+09) {
      uVar3 = (ulong)(int)fRam00289f74;
    }
    else {
      uVar3 = (long)(int)(fRam00289f74 - 2.1474836e+09) | 0xffffffff80000000;
    }
    DAT_70000048 = uVar3 << 0x20 |
                   (long)(iVar4 + (int)((float)(int)sVar1 * (fVar8 / 640.0) * 16.0)) |
                   (long)(iVar7 + iVar6) << 0x10;
    func_0x0018a650(0x70000000);
  }
  return;
}



================================================================