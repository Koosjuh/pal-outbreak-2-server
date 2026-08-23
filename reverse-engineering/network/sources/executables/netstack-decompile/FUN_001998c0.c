
undefined4 FUN_001998c0(undefined8 param_1,uint param_2)

{
  long lVar1;
  
  lVar1 = FUN_001999f0(param_1,0);
  if (lVar1 != 0) {
    if (param_2 < *(uint *)((int)lVar1 + 4)) {
      return *(undefined4 *)(param_2 * 4 + (int)lVar1 + 0xc);
    }
  }
  return 0xffffffff;
}

