FUNCTION FUN_00014eb8 @ 0x00014eb8 size=288
CALLERS (0): 
CALLEES (7): FUN_0001493c@0x0001493c, FUN_00013744@0x00013744, FUN_00016d00@0x00016d00, FUN_00013fd4@0x00013fd4, FUN_000142c8@0x000142c8, FUN_000130cc@0x000130cc, FUN_0001442c@0x0001442c

undefined4 FUN_00014eb8(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 uVar4;
  
  if ((*(byte *)(param_2 + 0xd) & 4) == 0) {
    if ((*(byte *)(param_2 + 0xd) & 2) == 0) {
      iVar1 = FUN_00013fd4(param_1,param_2,param_3);
      if (iVar1 < 0) {
        return param_4;
      }
      uVar2 = FUN_0001442c(param_1,param_2,param_4);
      if (((*(uint *)(param_1 + 0x2c) & 0x200000) != 0) && (*(int *)(param_1 + 0x98) != 0)) {
        uVar2 = FUN_0001493c(param_1,param_2,param_3,uVar2);
        return uVar2;
      }
      FUN_000142c8(param_1,param_2);
      uVar3 = *(uint *)(param_1 + 0x2c) & 0x40;
      if ((*(uint *)(param_1 + 0x2c) & 0x100) == 0) {
        uVar4 = 6;
        if (uVar3 == 0) {
          return uVar2;
        }
      }
      else {
        uVar4 = 8;
        if (uVar3 != 0) {
          FUN_000130cc(param_1);
          return uVar2;
        }
      }
      *(undefined4 *)(param_1 + 0x28) = uVar4;
      return uVar2;
    }
    FUN_00013744(param_1,param_2,param_3);
  }
  FUN_00016d00(param_1,0xfffffe02);
  return param_4;
}


================================================================