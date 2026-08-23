FUNCTION FUN_0000b590 @ 0x0000b590 size=52
CALLERS (0): 
CALLEES (1): FUN_0000b198@0x0000b198

undefined4 FUN_0000b590(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0xfffffe04;
  if (*(int *)(param_1 + 0xc) == 1) {
    FUN_0000b198();
    uVar1 = 0;
  }
  return uVar1;
}


================================================================