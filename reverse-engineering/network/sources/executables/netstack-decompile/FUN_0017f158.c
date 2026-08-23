
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0017f158(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  long lVar3;
  undefined1 *puVar4;
  int iVar5;
  
  uVar2 = 0;
  if (ram0x0022f590 != 0) {
    uRam0027b000 = *param_1;
    uRam0027b004 = param_1[1];
    iVar5 = 0;
    uRam0027b008 = param_1[2];
    uRam0027b00c = param_1[3];
    uRam0027b010 = param_1[4];
    uRam0027b028 = param_2;
    uRam0027b02c = param_3;
    do {
      iVar1 = iVar5 + 0x14;
      puVar4 = (undefined1 *)(iVar5 + 0x27b014);
      iVar5 = iVar5 + 1;
      *puVar4 = *(undefined1 *)((int)param_1 + iVar1);
    } while (iVar5 < 0x10);
    lVar3 = FUN_00115c68(0x27af88,0xffffffff80001301,0,0x27b000,0x280,0x27b000,0x280,0);
    uVar2 = uRam0027b024;
    if (lVar3 < 0) {
      FUN_0017fd00(0x258a78);
      uVar2 = 0;
    }
  }
  return uVar2;
}

