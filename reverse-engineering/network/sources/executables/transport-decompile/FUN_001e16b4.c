
int FUN_001e16b4(int param_1,int param_2,undefined4 param_3)

{
  long lVar1;
  undefined4 uStack_24;
  int iStack_20;
  
  uStack_24 = FUN_001ebd54(param_2 + 8);
  while ((lVar1 = FUN_001eb858(param_2 + 8,uStack_24), lVar1 == 0 &&
         (lVar1 = FUN_001ebb90(uStack_24,0x1000), lVar1 != 0))) {
    uStack_24 = FUN_001ebd7c(uStack_24);
  }
  lVar1 = FUN_001eb858(param_2 + 8,uStack_24);
  if (lVar1 != 0) {
    iStack_20 = FUN_001ec1f8(*(undefined4 *)(param_1 + 0x520),&uStack_24,0x10,1,0);
    if (iStack_20 != 0) {
      return iStack_20;
    }
    FUN_001eb3b8(param_2 + 8,uStack_24);
    FUN_001ebbd0(uStack_24,0x200);
  }
  FUN_001ebbd0(uStack_24,0x1000);
  FUN_001ed634(uStack_24,param_3);
  return 0;
}

