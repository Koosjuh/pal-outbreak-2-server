
int FUN_001e3880(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined8 param_4,
                undefined4 param_5)

{
  undefined4 *puVar1;
  int *piVar2;
  undefined1 auStack_30 [2];
  undefined2 uStack_2e;
  undefined4 uStack_2c;
  int iStack_20;
  int iStack_1c;
  undefined4 auStack_18 [2];
  
  puVar1 = (undefined4 *)FUN_00103de8();
  *puVar1 = 0;
  iStack_20 = FUN_001e2a28(param_1);
  if (iStack_20 == 0) {
    puVar1 = (undefined4 *)FUN_00103de8();
    *puVar1 = 0x6c;
    iStack_1c = 0xffffffff;
  }
  else if (*(short *)(iStack_20 + 4) == -1) {
    puVar1 = (undefined4 *)FUN_00103de8();
    *puVar1 = 0xe;
    iStack_1c = 0xffffffff;
  }
  else if (*(short *)(iStack_20 + 2) == 2) {
    iStack_1c = FUN_001eb434(iStack_20 + 8,auStack_18);
    if (iStack_1c == -0x1b56) {
      iStack_1c = 0;
    }
    else if (iStack_1c == 0) {
      iStack_1c = FUN_001ed7e0(auStack_18[0],param_2,param_3);
      uStack_2c = FUN_001ed3f4(auStack_18[0]);
      uStack_2e = FUN_001ed4fc(auStack_18[0]);
      FUN_001069a8(param_5,auStack_30,0x10);
      FUN_001ec9e0(DAT_0025b79c,auStack_18[0]);
    }
    else {
      piVar2 = (int *)FUN_00103de8();
      *piVar2 = iStack_1c;
      iStack_1c = 0xffffffff;
    }
  }
  else {
    puVar1 = (undefined4 *)FUN_00103de8();
    *puVar1 = 0x6b;
    iStack_1c = 0xffffffff;
  }
  return iStack_1c;
}

