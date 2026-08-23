FUNCTION FUN_000005b0 @ 0x000005b0 size=112
CALLERS (2): FUN_0000f710@0x0000f710, FUN_00000090@0x00000090
CALLEES (1): FUN_0000051c@0x0000051c

uint FUN_000005b0(byte *param_1,undefined4 param_2,undefined2 param_3)

{
  byte bVar1;
  uint uVar2;
  byte *pbVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = 0;
  if (param_1 != (byte *)0x0) {
    iVar5 = 6;
    do {
      bVar1 = *param_1;
      pbVar3 = param_1 + 1;
      param_1 = param_1 + 2;
      iVar5 = iVar5 + -1;
      iVar4 = iVar4 + (uint)bVar1 * 0x100 + (uint)*pbVar3;
    } while (0 < iVar5);
  }
  uVar2 = FUN_0000051c(iVar4,param_2,param_3);
  uVar2 = (uVar2 >> 0x10) + (uVar2 & 0xffff);
  return ~(uVar2 + (uVar2 >> 0x10)) & 0xffff;
}


================================================================