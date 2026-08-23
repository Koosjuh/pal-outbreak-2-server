FUNCTION FUN_005e9b20 @ 0x005e9b20  size=76
CALLERS (0): 
CALLEES (2): FUN_005ed1f0@0x005ed1f0, FUN_005ef0e0@0x005ef0e0
----------------------------------------------------------------

undefined8 FUN_005e9b20(undefined8 param_1,undefined8 param_2)

{
  FUN_005ef0e0(param_2);
  if (*(short *)(iRam007012a0 + 0x8f4) == 0) {
    FUN_005ed1f0(0);
  }
  else {
    FUN_005ed1f0(1);
  }
  return 0;
}



================================================================