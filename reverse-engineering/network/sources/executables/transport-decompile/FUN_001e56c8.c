
int FUN_001e56c8(undefined4 *param_1,undefined4 *param_2,int param_3,undefined4 param_4,
                undefined4 param_5)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puStack_3c;
  int iStack_28;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 *puStack_18;
  int iStack_14;
  
  uVar1 = FUN_00105dd8(0x1048);
  FUN_001e5234(uVar1,param_4,param_5);
  iStack_14 = param_3 + 7;
  if (iStack_14 < 0) {
    iStack_14 = param_3 + 0xe;
  }
  iVar2 = iStack_14 >> 3;
  puStack_3c = param_2;
  puStack_18 = param_1;
  for (iStack_28 = 0; iStack_28 < iVar2; iStack_28 = iStack_28 + 1) {
    uStack_20 = *puStack_3c;
    uStack_1c = puStack_3c[1];
    uStack_20 = FUN_001e2394(uStack_20);
    uStack_1c = FUN_001e2394(uStack_1c);
    FUN_001e4fd8(uVar1,&uStack_20,&uStack_1c);
    uStack_20 = FUN_001e2304(uStack_20);
    uStack_1c = FUN_001e2304(uStack_1c);
    *puStack_18 = uStack_20;
    puStack_18[1] = uStack_1c;
    puStack_3c = puStack_3c + 2;
    puStack_18 = puStack_18 + 2;
  }
  FUN_00105e30(uVar1);
  return iVar2 << 3;
}

