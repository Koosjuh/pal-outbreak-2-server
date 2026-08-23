FUNCTION FUN_00011a20 @ 0x00011a20 size=156
CALLERS (0): 
CALLEES (2): FUN_00019a38@0x00019a38, FUN_0000a60c@0x0000a60c

undefined4 FUN_00011a20(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  while (DAT_0001b2f8 == 0) {
    FUN_00019a38(100000);
  }
  if (DAT_0001b9e0 < DAT_0001b9d4) {
    uVar1 = FUN_0000a60c(param_2);
  }
  return uVar1;
}


================================================================