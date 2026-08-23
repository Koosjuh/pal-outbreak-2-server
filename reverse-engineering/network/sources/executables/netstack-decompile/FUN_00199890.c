
undefined4 FUN_00199890(undefined8 param_1)

{
  undefined4 uVar1;
  long lVar2;
  
  lVar2 = FUN_001999f0(param_1,0);
  if (lVar2 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(undefined4 *)((int)lVar2 + 4);
  }
  return uVar1;
}

