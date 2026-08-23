FUNCTION FUN_005e8580 @ 0x005e8580  size=120
CALLERS (0): 
CALLEES (2): FUN_005ec100@0x005ec100, FUN_005eef70@0x005eef70
----------------------------------------------------------------

undefined8 FUN_005e8580(undefined8 param_1,undefined8 param_2)

{
  FUN_005eef70(param_2);
  if (*(char *)(iRam007012a0 + 0xd892) == '\0') {
    *(undefined1 *)(iRam007012a0 + 0x17c) = 1;
  }
  else {
    *(undefined1 *)
     (((uint)*(ushort *)(iRam007012a0 + 0xd894) * 0x18 - (uint)*(ushort *)(iRam007012a0 + 0xd894)) *
      4 + iRam007012a0 + 0x252f) = 1;
  }
  FUN_005ec100(1);
  return 0;
}



================================================================