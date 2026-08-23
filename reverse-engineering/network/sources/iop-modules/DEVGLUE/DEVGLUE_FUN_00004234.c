FUNCTION FUN_00004234 @ 0x00004234 size=48
CALLERS (0): 
CALLEES (1): FUN_0000804c@0x0000804c

undefined4 FUN_00004234(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (*(int *)(param_1 + 0x1a0) == 2) {
    uVar1 = FUN_0000804c(param_1,param_2,1);
  }
  return uVar1;
}


================================================================