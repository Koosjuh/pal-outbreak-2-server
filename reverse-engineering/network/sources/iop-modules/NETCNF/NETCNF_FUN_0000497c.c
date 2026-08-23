FUNCTION FUN_0000497c @ 0x0000497c size=236
CALLERS (1): FUN_0000574c@0x0000574c
CALLEES (2): FUN_00004150@0x00004150, FUN_000045bc@0x000045bc

undefined4 FUN_0000497c(int param_1,undefined4 param_2,undefined4 param_3,char *param_4)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  
  puVar1 = (undefined4 *)FUN_00004150(param_1,0x28,2);
  if (puVar1 != (undefined4 *)0x0) {
    iVar2 = FUN_000045bc(param_1,param_2);
    puVar1[2] = iVar2;
    if (iVar2 != 0) {
      iVar2 = FUN_000045bc(param_1,param_3);
      puVar1[3] = iVar2;
      if (iVar2 != 0) {
        if ((param_4 != (char *)0x0) && (*param_4 != '\0')) {
          iVar2 = FUN_000045bc(param_1,param_4);
          puVar1[4] = iVar2;
          if (iVar2 == 0) {
            return 0xffffffff;
          }
        }
        puVar3 = *(undefined4 **)(*(int *)(param_1 + 0x18) + 4);
        puVar1[1] = puVar3;
        if (puVar3 == (undefined4 *)0x0) {
          puVar3 = *(undefined4 **)(param_1 + 0x18);
        }
        *puVar3 = puVar1;
        *puVar1 = 0;
        *(undefined4 **)(*(int *)(param_1 + 0x18) + 4) = puVar1;
        return 0;
      }
    }
  }
  return 0xffffffff;
}


================================================================