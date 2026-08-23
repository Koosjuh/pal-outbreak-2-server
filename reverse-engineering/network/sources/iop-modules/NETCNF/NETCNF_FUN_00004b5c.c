FUNCTION FUN_00004b5c @ 0x00004b5c size=628
CALLERS (1): FUN_000058d0@0x000058d0
CALLEES (3): FUN_00004150@0x00004150, FUN_00009638@0x00009638, FUN_00004728@0x00004728

undefined4 FUN_00004b5c(undefined4 param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  
  if (param_3 < 3) {
    return 0;
  }
  iVar1 = FUN_00009638(&DAT_00009ba0,*(undefined4 *)(param_4 + 4));
  uVar5 = 3;
  if (iVar1 != 0) {
    iVar1 = FUN_00009638(&DAT_00009ba4,*(undefined4 *)(param_4 + 4));
    if (iVar1 != 0) {
      return 0;
    }
    uVar5 = 4;
  }
  puVar2 = (undefined4 *)FUN_00004150(param_1,0x60,2);
  iVar1 = param_3 + -2;
  if (puVar2 == (undefined4 *)0x0) {
    return 0xffffffff;
  }
  puVar6 = (undefined4 *)(param_4 + 8);
  puVar2[2] = uVar5;
  iVar3 = FUN_00009638(&DAT_00009ba8,*puVar6);
  if (iVar3 == 0) {
    uVar4 = puVar2[0x12] & 0xfffffffd;
  }
  else {
    iVar3 = FUN_00009638("-host",*puVar6);
    if (iVar3 != 0) goto LAB_00004c58;
    uVar4 = puVar2[0x12] | 2;
  }
  iVar1 = param_3 + -3;
  puVar6 = (undefined4 *)(param_4 + 0xc);
  puVar2[0x12] = uVar4;
LAB_00004c58:
  if (iVar1 < 1) {
    return 0;
  }
  iVar3 = FUN_00004728(param_1,0,puVar2 + 3);
  if (iVar3 != 0) {
    return 0xffffffff;
  }
  iVar3 = FUN_00004728(param_1,0,puVar2 + 8);
  if (iVar3 != 0) {
    return 0xffffffff;
  }
  iVar3 = FUN_00004728(param_1,0,puVar2 + 0xd);
  if (iVar3 == 0) {
    iVar3 = FUN_00009638("default",*puVar6);
    if ((iVar3 != 0) && (iVar3 = FUN_00004728(param_1,*puVar6,puVar2 + 3), iVar3 != 0)) {
      return 0xffffffff;
    }
    iVar1 = iVar1 + -1;
    puVar7 = puVar6 + 1;
    do {
      if (iVar1 < 2) {
        puVar6 = *(undefined4 **)(param_2 + 0x154);
        puVar2[1] = puVar6;
        if (puVar6 == (undefined4 *)0x0) {
          *(undefined4 **)(param_2 + 0x150) = puVar2;
        }
        else {
          *puVar6 = puVar2;
        }
        *puVar2 = 0;
        *(undefined4 **)(param_2 + 0x154) = puVar2;
        return 0;
      }
      puVar6 = puVar6 + 2;
      iVar3 = FUN_00009638(&DAT_00009bc0,*puVar7);
      if (iVar3 == 0) {
        iVar3 = FUN_00004728(param_1,*puVar6,puVar2 + 8);
        if (iVar3 != 0) {
          return 0xffffffff;
        }
        puVar2[0x12] = puVar2[0x12] | 4;
      }
      else {
        iVar3 = FUN_00009638("netmask",*puVar7);
        if ((iVar3 == 0) && (iVar3 = FUN_00004728(param_1,*puVar6,puVar2 + 0xd), iVar3 != 0)) {
          return 0xffffffff;
        }
      }
      iVar1 = iVar1 + -2;
      puVar7 = puVar7 + 2;
    } while( true );
  }
  return 0xffffffff;
}


================================================================