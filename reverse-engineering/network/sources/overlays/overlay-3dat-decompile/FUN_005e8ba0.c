FUNCTION FUN_005e8ba0 @ 0x005e8ba0  size=104
CALLERS (0): 
CALLEES (1): FUN_005ef040@0x005ef040
----------------------------------------------------------------

undefined8 FUN_005e8ba0(undefined8 param_1,undefined8 param_2)

{
  FUN_005ef040(param_2);
  if (*(char *)(iRam007012a0 + 0xd892) == '\0') {
    *(undefined2 *)(iRam007012a0 + 0x12) = 0;
  }
  else {
    *(undefined2 *)
     (((uint)*(ushort *)(iRam007012a0 + 0xd894) * 0x18 - (uint)*(ushort *)(iRam007012a0 + 0xd894)) *
      4 + iRam007012a0 + 0x251e) = 0;
  }
  return 0;
}



================================================================