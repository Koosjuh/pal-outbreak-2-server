FUNCTION FUN_0000051c @ 0x0000051c size=148
CALLERS (1): FUN_000005b0@0x000005b0
CALLEES (0): 

int FUN_0000051c(int param_1,undefined4 *param_2,ushort param_3)

{
  bool bVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  byte *pbVar5;
  byte *pbVar6;
  uint uVar7;
  
  uVar7 = 0;
  pbVar5 = (byte *)*param_2;
  if (*(ushort *)(param_2 + 1) < param_3) {
    param_3 = *(ushort *)(param_2 + 1);
  }
  bVar1 = (param_3 & 1) != 0;
  if (bVar1) {
    uVar7 = (uint)pbVar5[(short)param_3 + -1];
    param_3 = param_3 - 1;
  }
  iVar3 = (int)((uint)param_3 << 0x10) >> 0x11;
  iVar4 = iVar3;
  while (0 < iVar4) {
    bVar2 = *pbVar5;
    pbVar6 = pbVar5 + 1;
    pbVar5 = pbVar5 + 2;
    iVar3 = iVar3 + -1;
    param_1 = param_1 + (uint)bVar2 * 0x100 + (uint)*pbVar6;
    iVar4 = iVar3 * 0x10000;
  }
  if (bVar1) {
    param_1 = param_1 + uVar7 * 0x100;
  }
  return param_1;
}


================================================================