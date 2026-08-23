FUNCTION FUN_006381e0 @ 0x006381e0  size=512
CALLERS (6): FUN_00636890@0x00636890, FUN_00619170@0x00619170, FUN_006365d0@0x006365d0, FUN_00633c10@0x00633c10, FUN_006366a0@0x006366a0, FUN_00618e30@0x00618e30
CALLEES (0): 
----------------------------------------------------------------

void FUN_006381e0(short *param_1,long param_2)

{
  short sVar1;
  short sVar2;
  uint uVar3;
  ulong uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  float fVar9;
  
  if (iRam0028a324 == 0) {
    iVar5 = -iRam0028a458 + 0x1000;
    if (iVar5 < 0) {
      iVar5 = -iRam0028a458 + 0x1001;
    }
    iVar6 = (iVar5 >> 1) * 0x10;
    iVar5 = -iRam0028a450 + 0x1000;
    if (iVar5 < 0) {
      iVar5 = -iRam0028a450 + 0x1001;
    }
    iVar5 = (iVar5 >> 1) * 0x10;
    fVar9 = (float)iRam0028a458;
    sVar1 = *param_1;
    sVar2 = param_1[2];
    iVar8 = (int)param_1[1] << 4;
    iVar7 = (int)param_1[3] << 4;
    if (iRam00289f34 == 0) {
      iVar8 = iVar8 >> 1;
      iVar7 = iVar7 >> 1;
    }
    func_0x00180038(0x6924c0,0x70000000,3);
    uVar4 = func_0x0018f430(*(undefined4 *)(param_1 + 4),1);
    DAT_70000030 = param_2 << 0x20 |
                   (long)((int)((float)(int)sVar1 * (fVar9 / 640.0) * 16.0) + iVar6) |
                   (long)(iVar8 + iVar5) << 0x10;
    uVar3 = (uint)uVar4;
    DAT_70000038 = param_2 << 0x20 |
                   (long)((int)((float)(int)sVar2 * (fVar9 / 640.0) * 16.0) + iVar6) |
                   (long)(iVar7 + iVar5) << 0x10;
    DAT_70000028 = (long)(int)(uVar3 >> 0x18) << 0x18 |
                   (uVar4 & 0xff) << 0x10 |
                   (long)(int)(uVar3 >> 0x10) & 0xffU | ((long)(int)(uVar3 >> 8) & 0xffU) << 8 |
                   0x100000000;
    func_0x0018a650(0x70000000);
  }
  return;
}



================================================================