
undefined4 FUN_001d5288(int param_1,short param_2)

{
  int iVar1;
  long lVar2;
  undefined4 uStack_14;
  
  iVar1 = FUN_001ec1f8(*(undefined4 *)(param_1 + 0x520),&uStack_14,param_2 + 0x14,1,1);
  if ((iVar1 == 0) && (lVar2 = FUN_001ed2c0(uStack_14,0x10), lVar2 == 0)) {
    FUN_001ec9e0(*(undefined4 *)(param_1 + 0x520),uStack_14);
    uStack_14 = 0;
  }
  return uStack_14;
}

