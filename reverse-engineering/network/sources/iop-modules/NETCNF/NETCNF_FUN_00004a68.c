FUNCTION FUN_00004a68 @ 0x00004a68 size=244
CALLERS (1): FUN_000058d0@0x000058d0
CALLEES (3): FUN_00004150@0x00004150, FUN_00009638@0x00009638, FUN_00004728@0x00004728

undefined4 FUN_00004a68(undefined4 param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  
  if (param_3 < 3) {
LAB_00004ad0:
    uVar4 = 0;
  }
  else {
    iVar1 = FUN_00009638(&DAT_00009ba0,*(undefined4 *)(param_4 + 4));
    uVar4 = 1;
    if (iVar1 != 0) {
      iVar1 = FUN_00009638(&DAT_00009ba4,*(undefined4 *)(param_4 + 4));
      uVar4 = 2;
      if (iVar1 != 0) goto LAB_00004ad0;
    }
    puVar2 = (undefined4 *)FUN_00004150(param_1,0x20,2);
    if (puVar2 != (undefined4 *)0x0) {
      puVar2[2] = uVar4;
      iVar1 = FUN_00004728(param_1,*(undefined4 *)(param_4 + 8),puVar2 + 3);
      if (iVar1 == 0) {
        puVar3 = *(undefined4 **)(param_2 + 0x154);
        puVar2[1] = puVar3;
        if (puVar3 == (undefined4 *)0x0) {
          *(undefined4 **)(param_2 + 0x150) = puVar2;
        }
        else {
          *puVar3 = puVar2;
        }
        *puVar2 = 0;
        *(undefined4 **)(param_2 + 0x154) = puVar2;
        return 0;
      }
    }
    uVar4 = 0xffffffff;
  }
  return uVar4;
}


================================================================