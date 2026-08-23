FUNCTION FUN_00009650 @ 0x00009650 size=92
CALLERS (2): FUN_0000a7ac@0x0000a7ac, FUN_0000a40c@0x0000a40c
CALLEES (2): FUN_00009044@0x00009044, FUN_00009024@0x00009024

int FUN_00009650(int param_1)

{
  short sVar1;
  int iVar2;
  
  if (*(char *)(param_1 + 3) == '\0') {
    iVar2 = -1;
  }
  else {
    *(char *)(param_1 + 3) = *(char *)(param_1 + 3) + -1;
    FUN_00009024();
    sVar1 = FUN_00009044(param_1,5,0,0);
    iVar2 = (int)sVar1;
  }
  return iVar2;
}


================================================================