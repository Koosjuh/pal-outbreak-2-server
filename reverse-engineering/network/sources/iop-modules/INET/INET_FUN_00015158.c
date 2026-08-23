FUNCTION FUN_00015158 @ 0x00015158 size=148
CALLERS (0): 
CALLEES (3): FUN_00013744@0x00013744, FUN_00013fd4@0x00013fd4, FUN_000130cc@0x000130cc

undefined4 FUN_00015158(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  if ((*(byte *)(param_2 + 0xd) & 4) == 0) {
    if ((*(byte *)(param_2 + 0xd) & 2) == 0) {
      FUN_00013fd4(param_1,param_2);
      if ((*(byte *)(param_2 + 0xd) & 1) == 0) {
        FUN_000130cc(param_1);
      }
    }
    else {
      FUN_00013744(param_1,param_2);
      *(undefined4 *)(param_1 + 0x28) = 0;
    }
  }
  else {
    *(undefined4 *)(param_1 + 0x28) = 0;
  }
  return param_4;
}


================================================================