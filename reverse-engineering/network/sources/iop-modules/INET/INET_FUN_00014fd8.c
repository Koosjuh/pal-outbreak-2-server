FUNCTION FUN_00014fd8 @ 0x00014fd8 size=240
CALLERS (0): 
CALLEES (5): FUN_0001493c@0x0001493c, FUN_00016d00@0x00016d00, FUN_00013fd4@0x00013fd4, FUN_000130cc@0x000130cc, FUN_0001442c@0x0001442c

undefined4 FUN_00014fd8(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((*(byte *)(param_2 + 0xd) & 4) == 0) {
    if ((*(byte *)(param_2 + 0xd) & 2) != 0) goto LAB_00015074;
    iVar1 = FUN_00013fd4(param_1,param_2,param_3);
    if (-1 < iVar1) {
      param_4 = FUN_0001442c(param_1,param_2,param_4);
    }
  }
  else {
    FUN_00016d00(param_1,0xfffffe02);
  }
  if (((*(uint *)(param_1 + 0x2c) & 0x200000) == 0) || (*(int *)(param_1 + 0x98) == 0)) {
    if ((*(uint *)(param_1 + 0x2c) & 0x100) == 0) {
      return param_4;
    }
    FUN_000130cc(param_1);
    return param_4;
  }
LAB_00015074:
  uVar2 = FUN_0001493c(param_1,param_2,param_3,param_4);
  return uVar2;
}


================================================================