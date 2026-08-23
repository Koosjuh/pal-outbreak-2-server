FUNCTION FUN_000007f0 @ 0x000007f0 size=128
CALLERS (0): 
CALLEES (2): FUN_0000057c@0x0000057c, FUN_000006c0@0x000006c0

undefined4 FUN_000007f0(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if (param_1 < 0) {
    uVar1 = FUN_000006c0(-param_1,param_2);
  }
  else {
    uVar1 = FUN_0000057c(param_1,param_2);
  }
  return uVar1;
}


================================================================