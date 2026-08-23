FUNCTION FUN_00000ce8 @ 0x00000ce8 size=68
CALLERS (0): 
CALLEES (1): FUN_0000143c@0x0000143c

undefined4 FUN_00000ce8(undefined2 *param_1)

{
  undefined2 uVar1;
  
  if (DAT_000096d4 == 0) {
    uVar1 = FUN_0000143c();
    *param_1 = uVar1;
  }
  else {
    *param_1 = 0;
  }
  return 0;
}


================================================================