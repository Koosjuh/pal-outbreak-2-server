
short FUN_001e366c(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  short sVar1;
  undefined4 *puVar2;
  undefined2 *puVar3;
  int *piVar4;
  undefined2 uStack_28;
  short sStack_1c;
  undefined4 uStack_18;
  uint uStack_14;
  
  puVar2 = (undefined4 *)FUN_00103de8();
  *puVar2 = 0;
  puVar3 = (undefined2 *)FUN_001e2a28(param_1);
  if (puVar3 == (undefined2 *)0x0) {
    puVar2 = (undefined4 *)FUN_00103de8();
    *puVar2 = 0x6c;
    sStack_1c = -1;
  }
  else if (puVar3[2] == -1) {
    puVar2 = (undefined4 *)FUN_00103de8();
    *puVar2 = 0xe;
    sStack_1c = -1;
  }
  else {
    uStack_14 = (uint)(ushort)puVar3[1];
    if (uStack_14 == 1) {
      sStack_1c = FUN_001e4bec(puVar3);
      if ((sStack_1c == 0) && ((puVar3[2] == 0x7f || (puVar3[2] == 0xff4)))) {
        uStack_28 = (undefined2)param_3;
        sStack_1c = FUN_001efb80(*puVar3,param_2,uStack_28);
      }
    }
    else if (uStack_14 == 2) {
      sVar1 = FUN_001eb434(puVar3 + 4,&uStack_18);
      if (sVar1 == -0x1b56) {
        sStack_1c = 0;
      }
      else if (sVar1 == 0) {
        sStack_1c = FUN_001ed7e0(uStack_18,param_2,param_3);
        FUN_001ec9e0(DAT_0025b79c,uStack_18);
      }
      else {
        piVar4 = (int *)FUN_00103de8();
        *piVar4 = (int)sVar1;
        sStack_1c = -1;
      }
    }
    else {
      puVar2 = (undefined4 *)FUN_00103de8();
      *puVar2 = 0x6b;
      sStack_1c = -1;
    }
  }
  return sStack_1c;
}

