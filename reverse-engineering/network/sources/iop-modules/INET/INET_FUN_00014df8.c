FUNCTION FUN_00014df8 @ 0x00014df8 size=192
CALLERS (0): 
CALLEES (5): FUN_0001493c@0x0001493c, FUN_00016d00@0x00016d00, FUN_00013fd4@0x00013fd4, FUN_000142c8@0x000142c8, FUN_0001442c@0x0001442c

undefined4 FUN_00014df8(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  if ((*(byte *)(param_2 + 0xd) & 4) == 0) {
    if ((*(byte *)(param_2 + 0xd) & 2) == 0) {
      iVar1 = FUN_00013fd4(param_1,param_2);
      if (-1 < iVar1) {
        param_4 = FUN_0001442c(param_1,param_2,param_4);
        FUN_000142c8(param_1,param_2);
        if ((*(uint *)(param_1 + 0x2c) & 0x100) != 0) {
          *(undefined4 *)(param_1 + 0x28) = 7;
        }
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