FUNCTION FUN_00007b40 @ 0x00007b40 size=348
CALLERS (1): FUN_00007c9c@0x00007c9c
CALLEES (6): FUN_0000789c@0x0000789c, FUN_00007658@0x00007658, FUN_00006f2c@0x00006f2c, FUN_00007974@0x00007974, FUN_00007910@0x00007910, FUN_00006f00@0x00006f00

void FUN_00007b40(int param_1,undefined4 param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  
  uVar1 = *(int *)(param_1 + 8) + 3U & 0xfffffffc;
  *(uint *)(param_1 + 8) = uVar1;
  *(uint *)(param_1 + 0xc) = uVar1;
  iVar2 = FUN_00006f00(param_1,&DAT_0000a9c4,"# <Sony Computer Entertainment Inc.>");
  if (-1 < iVar2) {
    if (param_3 == 0) {
      for (piVar4 = (int *)**(int **)(param_1 + 0x18); piVar4 != (int *)0x0; piVar4 = (int *)*piVar4
          ) {
        iVar2 = FUN_00006f00(param_1,"interface \"%S\" \"%S\" \"%S\"\n",piVar4[2],piVar4[3],
                             piVar4[4]);
        if (iVar2 < 0) {
          return;
        }
      }
      iVar2 = FUN_00006f2c(param_1,&DAT_0000ab80,*(undefined4 *)(param_1 + 0x18));
      if (iVar2 < 0) {
        return;
      }
      iVar2 = FUN_00007910(param_1,*(int *)(param_1 + 0x18) + 0x24);
      if (iVar2 < 0) {
        return;
      }
      uVar3 = 0;
    }
    else {
      iVar2 = FUN_00006f2c(param_1,&DAT_0000abd4,param_3);
      if (iVar2 < 0) {
        return;
      }
      iVar2 = FUN_0000789c(param_1,param_3);
      if (iVar2 < 0) {
        return;
      }
      iVar2 = FUN_00007658(param_1,param_3);
      if (iVar2 < 0) {
        return;
      }
      iVar2 = FUN_00007910(param_1,param_3 + 0x158);
      if (iVar2 < 0) {
        return;
      }
      uVar3 = 1;
    }
    FUN_00007974(param_1,param_2,uVar3);
  }
  return;
}


================================================================