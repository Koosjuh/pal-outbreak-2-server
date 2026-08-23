FUNCTION FUN_00004558 @ 0x00004558 size=100
CALLERS (2): FUN_00005ee4@0x00005ee4, FUN_000045bc@0x000045bc
CALLEES (3): FUN_00004150@0x00004150, FUN_00009650@0x00009650, FUN_00009640@0x00009640

int FUN_00004558(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_00009650(param_2);
  iVar1 = FUN_00004150(param_1,iVar1 + 1,0);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    FUN_00009640(iVar1,param_2);
  }
  return iVar1;
}


================================================================