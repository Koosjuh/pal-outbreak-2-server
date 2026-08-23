
undefined8 FUN_001caa30(undefined8 param_1,undefined8 param_2)

{
  if ((iRam003688d0 == 0) && (iRam003688d8 == 0)) {
    FUN_001cac50();
    iRam003688d8 = FUN_001df1d8(uRam0035b9e0,0x8000,param_1,param_2);
    FUN_001cac60();
    if (iRam003688d8 != 0) {
      param_2 = FUN_001ca9d0();
    }
  }
  else {
    param_2 = 0xfffffffffffffff0;
  }
  return param_2;
}

