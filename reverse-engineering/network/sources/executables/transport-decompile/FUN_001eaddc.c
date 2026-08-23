
undefined8 FUN_001eaddc(int param_1)

{
  int iStack_2c;
  short sStack_28;
  undefined2 uStack_26;
  undefined4 uStack_24;
  int iStack_20;
  
  FUN_001069a8(&sStack_28,param_1,2);
  iStack_20 = (int)sStack_28;
  sStack_28 = FUN_001e234c(sStack_28);
  FUN_001069a8(param_1,&sStack_28,2);
  iStack_2c = param_1 + 2;
  for (; 0 < iStack_20; iStack_20 = iStack_20 + -1) {
    FUN_001069a8(&uStack_26,iStack_2c,2);
    uStack_26 = FUN_001e234c(uStack_26);
    FUN_001069a8(iStack_2c,&uStack_26,2);
    FUN_001069a8(&uStack_24,iStack_2c + 2,4);
    uStack_24 = FUN_001e2304(uStack_24);
    FUN_001069a8(iStack_2c + 2,&uStack_24,4);
    iStack_2c = iStack_2c + 6;
  }
  return 0;
}

