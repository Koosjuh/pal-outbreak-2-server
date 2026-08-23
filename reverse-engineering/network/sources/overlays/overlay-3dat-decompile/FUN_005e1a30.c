FUNCTION FUN_005e1a30 @ 0x005e1a30  size=112
CALLERS (2): FUN_005e2fa0@0x005e2fa0, FUN_005e2760@0x005e2760
CALLEES (2): FUN_005dda30@0x005dda30, FUN_005e1f30@0x005e1f30
----------------------------------------------------------------

void FUN_005e1a30(undefined4 param_1,undefined4 param_2,undefined4 param_3,float param_4,
                 undefined8 param_5)

{
  long lVar1;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  float fStack_4;
  
  uStack_10 = param_1;
  uStack_c = param_2;
  uStack_8 = param_3;
  fStack_4 = param_4;
  lVar1 = FUN_005e1f30(&uStack_10,&uStack_c,&uStack_8,&fStack_4);
  if (lVar1 != 0) {
    FUN_005dda30(uStack_10,uStack_c,uStack_8,fStack_4 + 1.0,param_5);
  }
  return;
}



================================================================