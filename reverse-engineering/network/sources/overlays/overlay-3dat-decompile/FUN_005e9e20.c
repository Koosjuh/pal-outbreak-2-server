FUNCTION FUN_005e9e20 @ 0x005e9e20  size=68
CALLERS (0): 
CALLEES (2): FUN_005e9790@0x005e9790, FUN_005ee010@0x005ee010
----------------------------------------------------------------

undefined8 FUN_005e9e20(undefined8 param_1,undefined8 param_2)

{
  FUN_005e9790(param_2);
  FUN_005ee010();
  *(undefined4 *)(iRam007012a0 + 4) = 0;
  *(undefined1 *)param_2 = 0;
  return 0;
}



================================================================