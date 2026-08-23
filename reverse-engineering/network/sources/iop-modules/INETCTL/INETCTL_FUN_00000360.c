FUNCTION FUN_00000360 @ 0x00000360 size=80
CALLERS (1): FUN_00000a4c@0x00000a4c
CALLEES (1): FUN_0000018c@0x0000018c

undefined4 FUN_00000360(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  int local_res8 [2];
  
  if (param_3 == -1) {
    uVar1 = 0;
  }
  else {
    local_res8[0] = param_3 * 1000;
    uVar1 = FUN_0000018c(param_1,param_2,local_res8,4);
  }
  return uVar1;
}


================================================================