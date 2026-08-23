FUNCTION FUN_00629330 @ 0x00629330  size=64
CALLERS (1): FUN_00628e10@0x00628e10
CALLEES (1): FUN_0062a5e0@0x0062a5e0
----------------------------------------------------------------

undefined4 FUN_00629330(undefined8 param_1,undefined1 *param_2)

{
  long lVar1;
  
  lVar1 = FUN_0062a5e0(param_1,0);
  if (lVar1 != 0) {
    *param_2 = 2;
    param_2[1] = 0;
  }
  return 0xffffffff;
}



================================================================