FUNCTION FUN_005e8810 @ 0x005e8810  size=164
CALLERS (0): 
CALLEES (1): FUN_005ef0e0@0x005ef0e0
----------------------------------------------------------------

undefined8 FUN_005e8810(undefined8 param_1,undefined8 param_2)

{
  byte bVar1;
  int iVar2;
  
  FUN_005ef0e0(param_2);
  if (*(char *)(iRam007012a0 + 0xd892) == '\0') {
    bVar1 = *(byte *)(iRam007012a0 + 0x14);
    if ((bVar1 & 0xf) != 0) {
      *(byte *)(iRam007012a0 + 0x14) = bVar1 & 0xf0 | (bVar1 & 0xf) - 1;
    }
  }
  else {
    iVar2 = iRam007012a0 +
            ((uint)*(ushort *)(iRam007012a0 + 0xd894) * 0x18 -
            (uint)*(ushort *)(iRam007012a0 + 0xd894)) * 4;
    bVar1 = *(byte *)(iVar2 + 0x2531);
    if ((bVar1 & 0xf) != 0) {
      *(byte *)(iVar2 + 0x2531) = bVar1 & 0xf0 | (bVar1 & 0xf) - 1;
    }
  }
  return 0;
}



================================================================