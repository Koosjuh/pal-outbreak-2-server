FUNCTION FUN_00001b0c @ 0x00001b0c size=344
CALLERS (2): FUN_000020bc@0x000020bc, FUN_00002284@0x00002284
CALLEES (1): FUN_00002734@0x00002734

undefined4 FUN_00001b0c(int param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  if (*(int *)(param_1 + 0x1c) == 0) {
    return 0;
  }
  if (*(int **)(param_1 + 0x18) == (int *)0x0) {
    iVar3 = FUN_00002734(param_1,0x2c,2);
    *(int *)(param_1 + 0x18) = iVar3;
    if (iVar3 == 0) {
      return 0xfffffffe;
    }
    *(undefined4 *)(iVar3 + 8) = 3;
    *(undefined4 *)(*(int *)(param_1 + 0x18) + 0x10) = 0xffffffff;
    *(undefined4 *)(*(int *)(param_1 + 0x18) + 0x14) = 0xffffffff;
    *(undefined4 *)(*(int *)(param_1 + 0x18) + 0x20) = 0xffffffff;
  }
  else {
    iVar3 = **(int **)(param_1 + 0x18);
    if (iVar3 != 0) {
      if (param_2 == 1) {
        *(int *)(iVar3 + 0x14) = *(int *)(param_1 + 0x1c);
      }
      if (param_2 == 2) {
        *(undefined4 *)(**(int **)(param_1 + 0x18) + 0x18) = *(undefined4 *)(param_1 + 0x1c);
        return 0;
      }
      return 0;
    }
  }
  puVar1 = (undefined4 *)FUN_00002734(param_1,0x28,2);
  if (puVar1 != (undefined4 *)0x0) {
    if (param_2 == 1) {
      puVar1[5] = *(undefined4 *)(param_1 + 0x1c);
    }
    if (param_2 == 2) {
      puVar1[6] = *(undefined4 *)(param_1 + 0x1c);
    }
    puVar2 = *(undefined4 **)(*(int *)(param_1 + 0x18) + 4);
    puVar1[1] = puVar2;
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = *(undefined4 **)(param_1 + 0x18);
    }
    *puVar2 = puVar1;
    *puVar1 = 0;
    *(undefined4 **)(*(int *)(param_1 + 0x18) + 4) = puVar1;
    return 0;
  }
  return 0xfffffffe;
}


================================================================