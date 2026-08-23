FUNCTION FUN_000151ec @ 0x000151ec size=164
CALLERS (0): 
CALLEES (4): FUN_0001493c@0x0001493c, FUN_00012c60@0x00012c60, FUN_00016d00@0x00016d00, FUN_00013fd4@0x00013fd4

undefined4 FUN_000151ec(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  if ((*(byte *)(param_2 + 0xd) & 4) == 0) {
    if ((*(byte *)(param_2 + 0xd) & 2) == 0) {
      FUN_00013fd4(param_1);
      if (((*(uint *)(param_1 + 0x2c) & 0x40) != 0) &&
         (*(undefined4 *)(param_1 + 0x28) = 0, (*(uint *)(param_1 + 0x2c) & 0x2000000) != 0)) {
        FUN_00012c60(param_1);
      }
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