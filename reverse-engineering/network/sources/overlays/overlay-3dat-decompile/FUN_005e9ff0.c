FUNCTION FUN_005e9ff0 @ 0x005e9ff0  size=156
CALLERS (0): 
CALLEES (1): FUN_005ef040@0x005ef040
----------------------------------------------------------------

undefined8 FUN_005e9ff0(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  
  FUN_005ef040(param_2);
  if (*(char *)(iRam007012a0 + 0xd892) == '\0') {
    *(byte *)(iRam007012a0 + 0x18b) = *(byte *)(iRam007012a0 + 0x18b) | 1;
  }
  else {
    iVar1 = ((uint)*(ushort *)(iRam007012a0 + 0xd894) * 0x18 -
            (uint)*(ushort *)(iRam007012a0 + 0xd894)) * 4 + iRam007012a0;
    *(byte *)(iVar1 + 0x2530) = *(byte *)(iVar1 + 0x2530) | 1;
  }
  *(undefined1 *)(iRam007012a0 + 0x18c) = 1;
  FUN_005ef040(param_2);
  return 0;
}



================================================================