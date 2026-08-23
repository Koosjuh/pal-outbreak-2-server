FUNCTION FUN_005e9a90 @ 0x005e9a90  size=68
CALLERS (0): 
CALLEES (2): FUN_005ed1f0@0x005ed1f0, FUN_005ef0e0@0x005ef0e0
----------------------------------------------------------------

undefined8 FUN_005e9a90(undefined8 param_1,undefined8 param_2)

{
  FUN_005ef0e0(param_2);
  *(undefined2 *)(iRam007012a0 + 0x8f2) = 4;
  *(undefined2 *)(iRam007012a0 + 0x8f4) = 0;
  FUN_005ed1f0(0);
  return 0;
}



================================================================