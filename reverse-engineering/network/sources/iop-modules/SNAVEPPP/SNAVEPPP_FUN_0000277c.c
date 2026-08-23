FUNCTION FUN_0000277c @ 0x0000277c size=104
CALLERS (1): FUN_00002584@0x00002584
CALLEES (1): FUN_00010b4c@0x00010b4c

undefined4 FUN_0000277c(int param_1,short param_2)

{
  int iVar1;
  
  iVar1 = 0;
  if (0 < param_2) {
    do {
      FUN_00010b4c(param_1,0,0x18);
      iVar1 = iVar1 + 1;
      param_1 = param_1 + 0x18;
    } while (iVar1 < param_2);
  }
  return 0;
}


================================================================