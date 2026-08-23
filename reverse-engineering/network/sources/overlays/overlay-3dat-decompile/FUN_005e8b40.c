FUNCTION FUN_005e8b40 @ 0x005e8b40  size=96
CALLERS (0): 
CALLEES (2): FUN_005ef040@0x005ef040, FUN_005ef0e0@0x005ef0e0
----------------------------------------------------------------

undefined8 FUN_005e8b40(undefined8 param_1,undefined8 param_2)

{
  *(undefined1 *)(iRam007012a0 + 0x18d) = 0;
  FUN_005ef0e0(param_2);
  if (*(short *)((uint)*(ushort *)(iRam007012a0 + 0x188) * 4 + iRam007012a0 + 0x153c) != 0) {
    FUN_005ef040(param_2);
  }
  return 0;
}



================================================================