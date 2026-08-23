FUNCTION FUN_0000fd50 @ 0x0000fd50 size=144
CALLERS (1): FUN_00002900@0x00002900
CALLEES (4): FUN_00002b68@0x00002b68, FUN_00010aa4@0x00010aa4, FUN_00005070@0x00005070, FUN_00002d88@0x00002d88

int FUN_0000fd50(undefined4 param_1)

{
  short sVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = FUN_00002d88();
  iVar3 = -1;
  if (iVar2 != 0) {
    if ((*(short *)(iVar2 + 6) == 0) || (*(int *)(iVar2 + 0x44) == 0)) {
      DAT_00016ac0 = 0;
    }
    else {
      FUN_00010aa4(&DAT_00016ac0);
    }
    FUN_00002b68(0);
    sVar1 = FUN_00005070(0,param_1,0);
    iVar3 = (int)sVar1;
  }
  return iVar3;
}


================================================================