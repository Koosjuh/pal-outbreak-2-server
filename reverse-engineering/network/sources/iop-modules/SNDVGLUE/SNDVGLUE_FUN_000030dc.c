FUNCTION FUN_000030dc @ 0x000030dc size=188
CALLERS (1): FUN_00003d48@0x00003d48
CALLEES (3): FUN_0000823c@0x0000823c, FUN_00008140@0x00008140, FUN_00008244@0x00008244

undefined4 FUN_000030dc(short param_1)

{
  undefined4 uVar1;
  short sVar2;
  int iVar3;
  int *piVar4;
  
  FUN_00008244(DAT_0000de78);
  piVar4 = &DAT_0000de38;
  iVar3 = 0;
  do {
    sVar2 = (short)iVar3;
    if ((*piVar4 != 0) && ((short)piVar4[1] == param_1)) break;
    iVar3 = iVar3 + 1;
    sVar2 = (short)iVar3;
    piVar4 = piVar4 + 4;
  } while (iVar3 * 0x10000 >> 0x10 < 4);
  if (sVar2 < 4) {
    FUN_00008140(piVar4,0,0x10);
    FUN_0000823c(DAT_0000de78);
    uVar1 = 0;
  }
  else {
    FUN_0000823c(DAT_0000de78,0);
    uVar1 = 0xffffffff;
  }
  return uVar1;
}


================================================================