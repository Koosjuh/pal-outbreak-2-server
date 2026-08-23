
undefined4 FUN_001e3f98(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined2 *puVar2;
  undefined4 uVar3;
  
  puVar1 = (undefined4 *)FUN_00103de8();
  *puVar1 = 0;
  puVar2 = (undefined2 *)FUN_001e2a28(param_1);
  if (puVar2 == (undefined2 *)0x0) {
    puVar1 = (undefined4 *)FUN_00103de8();
    *puVar1 = 0x6c;
    uVar3 = 0xffffffff;
  }
  else {
    if (puVar2[1] == 1) {
      FUN_001ef770(*puVar2);
      puVar2[2] = 0xff3;
    }
    else if (puVar2[1] == 2) {
      FUN_001e3a3c();
      FUN_001e3a3c();
      FUN_001e3a3c();
      FUN_001f0230(*puVar2);
      puVar2[1] = 0xffff;
      puVar2[2] = 0xffff;
    }
    FUN_001e2654(puVar2);
    uVar3 = 0;
  }
  return uVar3;
}

