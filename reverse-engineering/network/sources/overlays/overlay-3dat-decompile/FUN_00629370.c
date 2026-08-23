FUNCTION FUN_00629370 @ 0x00629370  size=56
CALLERS (1): FUN_00628e10@0x00628e10
CALLEES (1): FUN_0062ba70@0x0062ba70
----------------------------------------------------------------

undefined4 FUN_00629370(undefined8 param_1,undefined1 *param_2)

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