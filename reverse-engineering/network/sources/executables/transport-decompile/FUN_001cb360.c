
undefined8 FUN_001cb360(undefined8 param_1,undefined8 param_2,ulong param_3)

{
  undefined8 uVar1;
  
  if ((param_3 & 0x10000) == 0) {
    uVar1 = 0;
    if ((param_3 & 0xffff) != 0) {
      uVar1 = FUN_001a0e90();
    }
  }
  else {
    uVar1 = FUN_001a0df0();
  }
  return uVar1;
}

