FUNCTION FUN_00000400 @ 0x00000400 size=60
CALLERS (1): FUN_00000a4c@0x00000a4c
CALLEES (1): FUN_0000018c@0x0000018c

undefined4 FUN_00000400(undefined4 param_1,undefined4 param_2,char param_3)

{
  undefined4 uVar1;
  char local_10 [8];
  
  if (param_3 == -1) {
    uVar1 = 0;
  }
  else {
    local_10[0] = param_3;
    uVar1 = FUN_0000018c(param_1,param_2,local_10,1);
  }
  return uVar1;
}


================================================================