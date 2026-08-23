
undefined4 * FUN_001e5538(undefined4 *param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  int iStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 *puStack_28;
  undefined4 *puStack_24;
  int iStack_20;
  
  uVar1 = FUN_00105dd8(0x1048);
  FUN_001e5234(uVar1,param_2,param_4);
  iStack_20 = param_3 + 7;
  if (iStack_20 < 0) {
    iStack_20 = param_3 + 0xe;
  }
  iVar2 = iStack_20 >> 3;
  puStack_28 = param_1;
  puStack_24 = param_1;
  for (iStack_34 = 0; iStack_34 < iVar2; iStack_34 = iStack_34 + 1) {
    uStack_30 = *puStack_28;
    uStack_2c = puStack_28[1];
    uStack_30 = FUN_001e2394(uStack_30);
    uStack_2c = FUN_001e2394(uStack_2c);
    FUN_001e5104(uVar1,&uStack_30,&uStack_2c);
    uStack_30 = FUN_001e2304(uStack_30);
    uStack_2c = FUN_001e2304(uStack_2c);
    *puStack_24 = uStack_30;
    puStack_24[1] = uStack_2c;
    puStack_28 = puStack_28 + 2;
    puStack_24 = puStack_24 + 2;
  }
  FUN_00105e30(uVar1);
  return param_1;
}

