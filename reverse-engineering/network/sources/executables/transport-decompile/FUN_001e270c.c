
int FUN_001e270c(int param_1,int param_2)

{
  undefined4 *puVar1;
  undefined2 *puVar2;
  undefined2 uStack_30;
  int iStack_2c;
  
  puVar1 = (undefined4 *)FUN_00103de8();
  *puVar1 = 0;
  if (param_1 == 2) {
    if (param_2 == 1) {
      uStack_30 = 1;
    }
    else {
      if (param_2 != 2) {
        puVar1 = (undefined4 *)FUN_00103de8();
        *puVar1 = 0x6d;
        return -1;
      }
      uStack_30 = 2;
    }
    for (iStack_2c = 0; iStack_2c < 0x40; iStack_2c = iStack_2c + 1) {
      if (*(short *)(PTR_DAT_0025b798 + iStack_2c * 0x24 + 2) == 1) {
        FUN_001e4bec(PTR_DAT_0025b798 + iStack_2c * 0x24);
      }
      if (*(short *)(PTR_DAT_0025b798 + iStack_2c * 0x24 + 2) == -1) break;
    }
    if (iStack_2c < 0x40) {
      puVar2 = (undefined2 *)(PTR_DAT_0025b798 + iStack_2c * 0x24);
      puVar2[1] = uStack_30;
      *puVar2 = 0xffff;
      puVar2[2] = 0xffff;
      FUN_001e2654(puVar2);
    }
    else {
      puVar1 = (undefined4 *)FUN_00103de8();
      *puVar1 = 0x6c;
      iStack_2c = -1;
    }
  }
  else {
    puVar1 = (undefined4 *)FUN_00103de8();
    *puVar1 = 0x60;
    iStack_2c = -1;
  }
  return iStack_2c;
}

