FUNCTION FUN_00018db0 @ 0x00018db0 size=52
CALLERS (0): 
CALLEES (1): FUN_00017e68@0x00017e68

undefined4 FUN_00018db0(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0xfffffe04;
  if (*(int *)(param_1 + 0xc) == 2) {
    FUN_00017e68();
    uVar1 = 0;
  }
  return uVar1;
}


================================================================