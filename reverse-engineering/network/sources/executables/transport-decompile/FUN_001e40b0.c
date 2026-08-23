
undefined4 FUN_001e40b0(undefined4 param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 uStack_1c;
  
  uStack_1c = 0;
  iVar1 = FUN_001e2a28(param_1);
  if (iVar1 == 0) {
    puVar2 = (undefined4 *)FUN_00103de8();
    *puVar2 = 0x6c;
    uVar3 = 0xffffffff;
  }
  else if (*(short *)(iVar1 + 4) == 0x7f) {
    if (param_2 == 0x71045ead) {
      iVar1 = FUN_001ebd54(iVar1 + 8);
      if (iVar1 != 0) {
        uStack_1c = FUN_001ebca8(iVar1);
      }
      *param_3 = uStack_1c;
      uVar3 = 0;
    }
    else {
      puVar2 = (undefined4 *)FUN_00103de8();
      *puVar2 = 0x16;
      uVar3 = 0xffffffff;
    }
  }
  else {
    puVar2 = (undefined4 *)FUN_00103de8();
    *puVar2 = 9;
    uVar3 = 0xffffffff;
  }
  return uVar3;
}

