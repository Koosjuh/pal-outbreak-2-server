
int FUN_001e2c7c(undefined4 param_1,undefined2 *param_2,undefined4 *param_3)

{
  short sVar1;
  undefined4 *puVar2;
  undefined2 *puVar3;
  undefined2 uStack_42;
  undefined4 uStack_40;
  ushort auStack_3c [2];
  int iStack_38;
  undefined2 *puStack_34;
  undefined2 *puStack_2c;
  undefined8 auStack_20 [2];
  
  auStack_20[0] = DAT_0025b7b8;
  puVar2 = (undefined4 *)FUN_00103de8();
  *puVar2 = 0;
  puStack_2c = param_2;
  puStack_34 = (undefined2 *)FUN_001e2a28(param_1);
  if (puStack_34 == (undefined2 *)0x0) {
    puVar2 = (undefined4 *)FUN_00103de8();
    *puVar2 = 0xe;
    iStack_38 = -1;
  }
  else {
    sVar1 = FUN_001e4bec(puStack_34);
    if (sVar1 < 0) {
      puVar2 = (undefined4 *)FUN_00103de8();
      *puVar2 = 0xe;
      iStack_38 = -1;
    }
    else if ((puStack_34[2] == 0xff5) || (puStack_34[2] == 0xff6)) {
      sVar1 = FUN_001ef710(*puStack_34);
      if ((sVar1 == -1) || (-1 < sVar1)) {
        while (sVar1 = FUN_001efcf0(*puStack_34,&uStack_42,&uStack_40,auStack_3c), sVar1 != 0) {
          if (sVar1 != -1) {
            puVar2 = (undefined4 *)FUN_00103de8();
            *puVar2 = 0xe;
            return -1;
          }
          FUN_001e20a0(auStack_20,0);
        }
        for (iStack_38 = 0; iStack_38 < 0x40; iStack_38 = iStack_38 + 1) {
          if (*(short *)(PTR_DAT_0025b798 + iStack_38 * 0x24 + 2) == 1) {
            FUN_001e4bec(PTR_DAT_0025b798 + iStack_38 * 0x24);
          }
          if (*(short *)(PTR_DAT_0025b798 + iStack_38 * 0x24 + 2) == -1) break;
        }
        if (iStack_38 < 0x40) {
          puVar3 = (undefined2 *)(PTR_DAT_0025b798 + iStack_38 * 0x24);
          *puVar3 = uStack_42;
          puVar3[1] = 1;
          puVar3[2] = 0x7f;
          *(uint *)(puVar3 + 0x10) = (uint)auStack_3c[0];
          *(undefined4 *)(puVar3 + 0xe) = uStack_40;
          *puStack_2c = 2;
          puStack_2c[1] = puVar3[0x10];
          *(undefined4 *)(puStack_2c + 2) = *(undefined4 *)(puVar3 + 0xe);
          *param_3 = 8;
        }
        else {
          puVar2 = (undefined4 *)FUN_00103de8();
          *puVar2 = 0x6c;
          iStack_38 = -1;
        }
      }
      else {
        puVar2 = (undefined4 *)FUN_00103de8();
        *puVar2 = 0xe;
        iStack_38 = -1;
      }
    }
    else {
      puVar2 = (undefined4 *)FUN_00103de8();
      *puVar2 = 0xe;
      iStack_38 = -1;
    }
  }
  return iStack_38;
}

