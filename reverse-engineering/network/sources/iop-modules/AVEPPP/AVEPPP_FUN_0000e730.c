FUNCTION FUN_0000e730 @ 0x0000e730 size=228
CALLERS (1): FUN_0000efbc@0x0000efbc
CALLEES (2): FUN_00001c68@0x00001c68, FUN_0000075c@0x0000075c

uint FUN_0000e730(int *param_1)

{
  short sVar1;
  byte *pbVar2;
  int iVar3;
  uint uVar4;
  
  if (((param_1 == (int *)0x0) || (iVar3 = *param_1, iVar3 == 0)) || (*(ushort *)(iVar3 + 4) < 2)) {
    sVar1 = FUN_0000075c(param_1,&DAT_00013794,1);
    uVar4 = 0xffffffff;
    if (sVar1 == 1) {
      uVar4 = (uint)DAT_00013794;
    }
  }
  else {
    *(ushort *)(iVar3 + 4) = *(ushort *)(iVar3 + 4) - 1;
    pbVar2 = *(byte **)*param_1;
    uVar4 = (uint)*pbVar2;
    *(byte **)*param_1 = pbVar2 + 1;
  }
  if (uVar4 == 0) {
    sVar1 = FUN_0000075c(param_1,&DAT_00013790,2);
    uVar4 = 0xffffffff;
    if (sVar1 == 2) {
      uVar4 = FUN_00001c68(&DAT_00013790);
      uVar4 = uVar4 & 0xffff;
    }
  }
  return uVar4;
}


================================================================