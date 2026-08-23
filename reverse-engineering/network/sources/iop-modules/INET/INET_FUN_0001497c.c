FUNCTION FUN_0001497c @ 0x0001497c size=76
CALLERS (0): 
CALLEES (1): FUN_00013744@0x00013744

undefined4 FUN_0001497c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  if ((*(uint *)(param_1 + 0x2c) & 0x10000) == 0) {
    FUN_00013744();
  }
  *(undefined4 *)(param_1 + 0x28) = 0;
  return param_4;
}


================================================================