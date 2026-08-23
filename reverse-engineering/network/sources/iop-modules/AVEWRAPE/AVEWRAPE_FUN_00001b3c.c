FUNCTION FUN_00001b3c @ 0x00001b3c size=144
CALLERS (2): FUN_0000131c@0x0000131c, FUN_00000ea4@0x00000ea4
CALLEES (1): FUN_00002850@0x00002850

undefined4 FUN_00001b3c(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 local_10 [2];
  
  switch(param_1) {
  case 0:
    local_10[0] = 0xcf;
    break;
  case 1:
    local_10[0] = 1;
    break;
  case 2:
    local_10[0] = 2;
    break;
  case 3:
    local_10[0] = 4;
    break;
  case 4:
    local_10[0] = 8;
    break;
  default:
    return 0xffffffff;
  }
  uVar1 = FUN_00002850(9,local_10,4);
  return uVar1;
}


================================================================