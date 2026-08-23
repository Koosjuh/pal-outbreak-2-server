
void FUN_001ea804(undefined4 *param_1,undefined4 *param_2)

{
  long lVar1;
  undefined4 uStack_18;
  undefined4 *puStack_14;
  
  uStack_18 = 0;
  puStack_14 = param_1;
  do {
    lVar1 = FUN_001e5a00(param_2,0,&uStack_18,1);
  } while (lVar1 != 0);
  *puStack_14 = *param_2;
  puStack_14[1] = param_2[1];
  puStack_14[2] = param_2[2];
  puStack_14[3] = param_2[3];
  puStack_14[4] = param_2[4];
  FUN_001e5934(param_1,0x14);
  FUN_00106b60(param_2,0,4);
  return;
}

