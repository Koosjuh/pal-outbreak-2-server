FUNCTION FUN_005e8600 @ 0x005e8600  size=136
CALLERS (0): 
CALLEES (2): FUN_005ec100@0x005ec100, FUN_005eef70@0x005eef70
----------------------------------------------------------------

undefined8 FUN_005e8600(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  
  FUN_005eef70(param_2);
  if (*(char *)(iRam007012a0 + 0xd892) == '\0') {
    *(undefined1 *)(iRam007012a0 + 0x17c) = 0;
  }
  else {
    iVar1 = ((uint)*(ushort *)(iRam007012a0 + 0xd894) * 0x18 -
            (uint)*(ushort *)(iRam007012a0 + 0xd894)) * 4 + iRam007012a0;
    if (*(char *)(iVar1 + 0x24fb) == '\x03') {
      return 0;
    }
    *(undefined1 *)(iVar1 + 0x252f) = 0;
  }
  FUN_005ec100(0);
  return 0;
}



================================================================