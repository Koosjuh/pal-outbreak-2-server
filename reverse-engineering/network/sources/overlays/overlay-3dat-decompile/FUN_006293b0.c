FUNCTION FUN_006293b0 @ 0x006293b0  size=60
CALLERS (1): FUN_00628e10@0x00628e10
CALLEES (1): FUN_0062a5e0@0x0062a5e0
----------------------------------------------------------------

undefined4 FUN_006293b0(undefined8 param_1,undefined1 *param_2)

{
  long lVar1;
  
  lVar1 = FUN_0062a5e0(param_1,0);
  if (lVar1 != 0) {
    *param_2 = 0;
    param_2[1] = 0;
  }
  return 0xffffffff;
}



================================================================