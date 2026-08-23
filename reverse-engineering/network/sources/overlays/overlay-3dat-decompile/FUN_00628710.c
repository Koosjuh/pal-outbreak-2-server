FUNCTION FUN_00628710 @ 0x00628710  size=56
CALLERS (1): FUN_00627d60@0x00627d60
CALLEES (1): FUN_0062ba70@0x0062ba70
----------------------------------------------------------------

undefined4 FUN_00628710(undefined8 param_1,undefined1 *param_2)

{
  long lVar1;
  
  lVar1 = FUN_0062ba70();
  if (lVar1 != 0) {
    *param_2 = 0;
    param_2[1] = 0;
  }
  return 0xffffffff;
}



================================================================