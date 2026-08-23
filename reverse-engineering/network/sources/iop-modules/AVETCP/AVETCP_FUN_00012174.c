FUNCTION FUN_00012174 @ 0x00012174 size=68
CALLERS (0): 
CALLEES (2): FUN_00014f1c@0x00014f1c, FUN_00014f24@0x00014f24

int FUN_00012174(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_00014f1c();
  if (iVar1 == -100) {
    iVar1 = FUN_00014f24(param_1);
  }
  return iVar1;
}


================================================================