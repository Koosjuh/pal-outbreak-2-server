
undefined4 FUN_001e332c(undefined4 param_1,undefined4 param_2,undefined2 param_3)

{
  short sVar1;
  undefined4 *puVar2;
  undefined2 *puVar3;
  undefined4 uVar4;
  
  puVar2 = (undefined4 *)FUN_00103de8();
  *puVar2 = 0;
  puVar3 = (undefined2 *)FUN_001e2a28(param_1);
  if (puVar3 == (undefined2 *)0x0) {
    puVar2 = (undefined4 *)FUN_00103de8();
    *puVar2 = 0xe;
    uVar4 = 0xffffffff;
  }
  else if (puVar3[1] == 1) {
    sVar1 = FUN_001e4bec(puVar3);
    if (sVar1 < 0) {
      puVar2 = (undefined4 *)FUN_00103de8();
      *puVar2 = 9;
      uVar4 = 0xffffffff;
    }
    else if ((puVar3[2] == 0xff4) || (puVar3[2] == 0x7f)) {
      sVar1 = FUN_001ef9a0(*puVar3,param_2,param_3);
      if (sVar1 == -1) {
        puVar3[2] = 0xff2;
      }
      else if (sVar1 < 0) {
        puVar2 = (undefined4 *)FUN_00103de8();
        *puVar2 = 0xe;
        return 0xffffffff;
      }
      uVar4 = 0;
    }
    else {
      puVar2 = (undefined4 *)FUN_00103de8();
      *puVar2 = 9;
      uVar4 = 0xffffffff;
    }
  }
  else {
    puVar2 = (undefined4 *)FUN_00103de8();
    *puVar2 = 0x6b;
    uVar4 = 0xffffffff;
  }
  return uVar4;
}

