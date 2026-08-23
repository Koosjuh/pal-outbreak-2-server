FUNCTION FUN_000150c8 @ 0x000150c8 size=144
CALLERS (0): 
CALLEES (4): FUN_0001493c@0x0001493c, FUN_00016d00@0x00016d00, FUN_00013fd4@0x00013fd4, FUN_000142c8@0x000142c8

undefined4 FUN_000150c8(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  if ((*(byte *)(param_2 + 0xd) & 4) == 0) {
    if ((*(byte *)(param_2 + 0xd) & 2) == 0) {
      FUN_00013fd4(param_1,param_2);
      FUN_000142c8(param_1,param_2);
    }
    else {
      param_4 = FUN_0001493c(param_1,param_2,param_3,param_4);
    }
  }
  else {
    FUN_00016d00(param_1,0xfffffe02);
  }
  return param_4;
}


================================================================