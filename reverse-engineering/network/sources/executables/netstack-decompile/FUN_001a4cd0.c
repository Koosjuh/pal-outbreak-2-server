
long FUN_001a4cd0(undefined8 param_1,undefined8 param_2)

{
  long lVar1;
  long lVar2;
  
  FUN_0019ec60(0xffffffff8000000c,1);
  lVar1 = FUN_001a5550(param_1,param_2);
  if (-1 < lVar1) {
    FUN_001a2430();
    while (lVar2 = FUN_0019eb00(1), 0 < lVar2) {
      FUN_00111668(0);
    }
    while (lVar2 = FUN_0019ec60(0xffffffff8000000c,1), 0 < lVar2) {
      FUN_00111668(0);
    }
    FUN_001a2490();
  }
  return lVar1;
}

