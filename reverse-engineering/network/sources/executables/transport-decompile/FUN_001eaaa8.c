
undefined4 FUN_001eaaa8(int param_1,short param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  short sStack_24;
  short sStack_22;
  undefined4 uStack_20;
  int iStack_1c;
  
  iStack_1c = param_1;
  FUN_001069a8(&sStack_24,param_1,2);
  iStack_1c = iStack_1c + 2;
  do {
    if (sStack_24 < 1) {
LAB_001eab7c:
      if (sStack_22 == param_2) {
        *param_3 = uStack_20;
        uVar2 = 0;
      }
      else {
        uVar2 = 0xffffffff;
      }
      return uVar2;
    }
    FUN_001069a8(&sStack_22,iStack_1c,2);
    iVar1 = iStack_1c + 2;
    if (sStack_22 == param_2) {
      iStack_1c = iVar1;
      FUN_001069a8(&uStack_20,iVar1,4);
      goto LAB_001eab7c;
    }
    iStack_1c = iStack_1c + 6;
    sStack_24 = sStack_24 + -1;
  } while( true );
}

