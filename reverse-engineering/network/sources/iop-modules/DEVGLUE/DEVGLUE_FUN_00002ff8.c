FUNCTION FUN_00002ff8 @ 0x00002ff8 size=228
CALLERS (1): FUN_00003c90@0x00003c90
CALLEES (2): FUN_0000823c@0x0000823c, FUN_00008244@0x00008244

undefined4 FUN_00002ff8(short param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int *piVar2;
  short sVar3;
  int iVar4;
  
  FUN_00008244(DAT_0000de78);
  piVar2 = &DAT_0000de38;
  iVar4 = 0;
  do {
    sVar3 = (short)iVar4;
    if (*piVar2 == 0) break;
    iVar4 = iVar4 + 1;
    sVar3 = (short)iVar4;
    if ((short)piVar2[1] == param_1) goto LAB_000030b0;
    piVar2 = piVar2 + 4;
  } while (iVar4 * 0x10000 >> 0x10 < 4);
  if (sVar3 < 4) {
    *(short *)(piVar2 + 1) = param_1;
    piVar2[2] = param_2;
    piVar2[3] = param_3;
    *piVar2 = *piVar2 + 1;
    FUN_0000823c(DAT_0000de78);
    uVar1 = 0;
  }
  else {
LAB_000030b0:
    FUN_0000823c(DAT_0000de78);
    uVar1 = 0xffffffff;
  }
  return uVar1;
}


================================================================