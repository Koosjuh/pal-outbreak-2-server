
void FUN_001ea8e8(undefined4 *param_1,int param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  undefined1 auStack_1c0 [368];
  undefined1 auStack_50 [32];
  undefined4 *puStack_30;
  uint uStack_2c;
  uint uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 auStack_1c [3];
  
  uStack_24 = FUN_00105dd8(0x1048);
  FUN_001e5854(auStack_1c0);
  FUN_001ea784(auStack_1c0,param_3,param_4);
  FUN_001ea784(auStack_1c0,param_5,param_6);
  FUN_001ea804(auStack_50,auStack_1c0);
  FUN_001e5234(uStack_24,auStack_50,0x14);
  uStack_2c = param_2 + 7U >> 3;
  puStack_30 = param_1;
  for (uStack_28 = uStack_2c; uStack_28 != 0; uStack_28 = uStack_28 - 1) {
    uStack_20 = *puStack_30;
    auStack_1c[0] = puStack_30[1];
    uStack_20 = FUN_001e2394(uStack_20);
    auStack_1c[0] = FUN_001e2394(auStack_1c[0]);
    FUN_001e5104(uStack_24,&uStack_20,auStack_1c);
    uStack_20 = FUN_001e2304(uStack_20);
    auStack_1c[0] = FUN_001e2304(auStack_1c[0]);
    *puStack_30 = uStack_20;
    puStack_30[1] = auStack_1c[0];
    puStack_30 = puStack_30 + 2;
  }
  FUN_00105e30(uStack_24);
  return;
}

