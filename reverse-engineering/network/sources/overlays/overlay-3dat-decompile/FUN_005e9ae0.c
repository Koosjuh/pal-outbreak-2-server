FUNCTION FUN_005e9ae0 @ 0x005e9ae0  size=60
CALLERS (0): 
CALLEES (1): FUN_005ef0e0@0x005ef0e0
----------------------------------------------------------------

undefined8 FUN_005e9ae0(undefined8 param_1,undefined8 param_2)

{
  FUN_005ef0e0(param_2);
  *(undefined2 *)(iRam007012a0 + 0x8f2) = 4;
  *(undefined2 *)(iRam007012a0 + 0x8f4) = 0;
  return 0;
}



================================================================