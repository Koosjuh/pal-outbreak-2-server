FUNCTION FUN_00013744 @ 0x00013744 size=132
CALLERS (8): FUN_0001497c@0x0001497c, FUN_00015158@0x00015158, FUN_000149c8@0x000149c8, FUN_00014ad4@0x00014ad4, FUN_00015290@0x00015290, FUN_0001493c@0x0001493c, FUN_00013fd4@0x00013fd4, FUN_00014eb8@0x00014eb8
CALLEES (1): FUN_00013264@0x00013264

void FUN_00013744(undefined4 param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = 0;
  uVar1 = *(undefined4 *)(param_2 + 8);
  uVar3 = 0;
  if ((*(byte *)(param_2 + 0xd) & 4) == 0) {
    if ((*(byte *)(param_2 + 0xd) & 0x10) == 0) {
      iVar2 = *(int *)(param_2 + 4) + param_3;
      uVar3 = 0x10;
      uVar1 = 0;
    }
    FUN_00013264(param_1,uVar3 | 4,uVar1,iVar2,0);
  }
  return;
}


================================================================