FUNCTION FUN_00001c6c @ 0x00001c6c size=312
CALLERS (1): FUN_00001da4@0x00001da4
CALLEES (5): FUN_0000018c@0x0000018c, FUN_000004dc@0x000004dc, FUN_00001b80@0x00001b80, FUN_00000530@0x00000530, FUN_0000059c@0x0000059c

int FUN_00001c6c(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  uint local_20 [2];
  
  if (param_2 != 0) {
    iVar3 = *(int *)(param_2 + 0x24);
    if (iVar3 == 0) {
      return 0;
    }
    if (*(int *)(iVar3 + 8) != 0) {
      return 0;
    }
    puVar2 = *(undefined4 **)(iVar3 + 4);
    if (puVar2 == (undefined4 *)0x0) {
      return 0;
    }
    iVar1 = FUN_0000018c(param_3,8,local_20,4);
    if (iVar1 != 0) {
      return 0;
    }
    iVar1 = FUN_0000018c(param_3,0,iVar3 + 0x14,9);
    if (iVar1 != 0) {
      return 0;
    }
    iVar1 = FUN_000004dc(*puVar2,local_20[0]);
    if (iVar1 != 0) {
      return 0;
    }
    iVar1 = FUN_00000530(puVar2[1],param_3,2);
    if (iVar1 != 0) {
      return 0;
    }
    iVar1 = FUN_00000530(puVar2[2],param_3,3);
    if (iVar1 != 0) {
      return 0;
    }
    iVar1 = FUN_0000059c(puVar2[3],param_3);
    if (iVar1 == 0) {
      *(undefined4 *)(iVar3 + 8) = param_3;
      if ((local_20[0] & 0x10) == 0) {
        return param_2;
      }
      FUN_00001b80(param_1,param_3);
      return param_2;
    }
  }
  return 0;
}


================================================================