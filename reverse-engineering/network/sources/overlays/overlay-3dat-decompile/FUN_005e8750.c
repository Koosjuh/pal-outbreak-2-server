FUNCTION FUN_005e8750 @ 0x005e8750  size=192
CALLERS (0): 
CALLEES (2): FUN_005ef780@0x005ef780, FUN_005ef0e0@0x005ef0e0
----------------------------------------------------------------

undefined8 FUN_005e8750(undefined8 param_1,undefined8 param_2)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  
  FUN_005ef0e0(param_2);
  if (*(char *)(iRam007012a0 + 0xd892) == '\0') {
    bVar2 = *(byte *)(iRam007012a0 + 0x14) & 0xf;
    if (bVar2 != 0xf) {
      *(byte *)(iRam007012a0 + 0x14) = *(byte *)(iRam007012a0 + 0x14) & 0xf0 | bVar2 + 1;
    }
  }
  else {
    iVar3 = iRam007012a0 +
            ((uint)*(ushort *)(iRam007012a0 + 0xd894) * 0x18 -
            (uint)*(ushort *)(iRam007012a0 + 0xd894)) * 4;
    bVar2 = *(byte *)(iVar3 + 0x2531);
    bVar1 = bVar2 & 0xf;
    if (bVar1 != 0xf) {
      *(byte *)(iVar3 + 0x2531) = bVar2 & 0xf0 | bVar1 + 1;
    }
    FUN_005ef780();
  }
  return 0;
}



================================================================