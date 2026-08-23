FUNCTION FUN_00006f00 @ 0x00006f00 size=44
CALLERS (5): FUN_00007658@0x00007658, FUN_0000789c@0x0000789c, FUN_00007b40@0x00007b40, FUN_00006f2c@0x00006f2c, FUN_00007910@0x00007910
CALLEES (1): FUN_00006960@0x00006960

void FUN_00006f00(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 local_res8;
  undefined4 local_resc;
  
  local_res8 = param_3;
  local_resc = param_4;
  FUN_00006960(param_1,param_2,&local_res8);
  return;
}


================================================================