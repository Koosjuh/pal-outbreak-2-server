FUNCTION FUN_00607cf0 @ 0x00607cf0  size=204
CALLERS (1): FUN_00607a10@0x00607a10
CALLEES (3): FUN_005b9110@0x005b9110, FUN_005b14b0@0x005b14b0, FUN_005b8cf0@0x005b8cf0
----------------------------------------------------------------

undefined4 FUN_00607cf0(undefined8 param_1,undefined1 *param_2)

{
  long lVar1;
  
  if (param_2[1] == '\x01') {
    *(int *)(param_2 + 0x18) = *(int *)(param_2 + 0x18) + -1;
    if ((*(int *)(param_2 + 0x18) < 0x11e) && (lVar1 = FUN_005b14b0(0x10), lVar1 != 0)) {
      func_0x001b0140(1);
      *param_2 = 2;
      param_2[1] = 0;
      FUN_005b9110(0x4c);
    }
    else if (*(int *)(param_2 + 0x18) < 0) {
      *param_2 = 2;
      param_2[1] = 0;
      FUN_005b9110(0x4c);
    }
  }
  else if (param_2[1] == '\0') {
    param_2[1] = 1;
    *(undefined4 *)(param_2 + 0x18) = 0x13c;
    FUN_005b8cf0(0xffffffffffffff9b);
  }
  return 0xffffffff;
}



================================================================