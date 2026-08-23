FUNCTION FUN_00637f90 @ 0x00637f90  size=588
CALLERS (3): FUN_00636890@0x00636890, FUN_00614e60@0x00614e60, FUN_00618e30@0x00618e30
CALLEES (0): 
----------------------------------------------------------------

void FUN_00637f90(short *param_1,long param_2)

{
  short sVar1;
  uint uVar2;
  ulong uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  float fVar7;
  
  if (iRam0028a324 == 0) {
    sVar1 = param_1[2];
    iVar5 = (int)param_1[1] << 4;
    fVar7 = (float)iRam0028a458;
    iVar4 = (int)param_1[3] << 4;
    if (iRam00289f34 == 0) {
      iVar5 = iVar5 >> 1;
      iVar4 = iVar4 >> 1;
    }
    iVar6 = (int)((float)(int)*param_1 * (fVar7 / 640.0) * 16.0) + iRam0028a2d4 * 0x10;
    iVar5 = iVar5 + iRam0028a2d8 * 0x10;
    func_0x00180038(0x692470,0x70000000,3);
    DAT_70000018 = 0x535310;
    uVar3 = func_0x0018f430(*(undefined4 *)(param_1 + 4),0);
    DAT_70000038 = param_2 << 0x20 | (long)iVar6 | (long)iVar5 << 0x10;
    uVar2 = (uint)uVar3;
    DAT_70000048 = param_2 << 0x20 |
                   (long)(iVar6 + (int)((float)(int)sVar1 * (fVar7 / 640.0) * 16.0)) |
                   (long)(iVar5 + iVar4) << 0x10;
    DAT_70000028 = (long)(int)(uVar2 >> 0x18) << 0x18 |
                   (uVar3 & 0xff) << 0x10 |
                   (long)(int)(uVar2 >> 0x10) & 0xffU | ((long)(int)(uVar2 >> 8) & 0xffU) << 8 |
                   0x100000000;
    DAT_70000030 = (long)(param_1[6] * 0x10 + 8) | (long)(param_1[7] * 0x10 + 8) << 0x10;
    DAT_70000040 = (long)(param_1[8] * 0x10 + 8) | (long)(param_1[9] * 0x10 + 8) << 0x10;
    func_0x0018a650(0x70000000);
  }
  return;
}



================================================================