
undefined8 FUN_001f27c8(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined8 uVar2;
  long lVar3;
  
  uVar2 = 0xffffffffffffffff;
  if (DAT_0024e430 != -1) {
    if (param_1 == 0) {
      WaitSema();
      uVar1 = FUN_001f2878();
      *param_2 = uVar1;
      SignalSema(DAT_0024e430);
      uVar2 = 0;
    }
    else {
      uVar2 = 0xfffffffffffffff5;
      if (param_1 == 1) {
        lVar3 = FUN_00115e60(0x37e9e0);
        if (lVar3 == 0) {
          uVar1 = FUN_001f2878();
          *param_2 = uVar1;
          uVar2 = 0;
        }
        else {
          uVar2 = 1;
        }
      }
    }
  }
  return uVar2;
}

