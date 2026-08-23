FUNCTION FUN_005ea190 @ 0x005ea190  size=328
CALLERS (0): 
CALLEES (3): FUN_005ec920@0x005ec920, FUN_005ec1b0@0x005ec1b0, FUN_005ef780@0x005ef780
----------------------------------------------------------------

undefined8 FUN_005ea190(undefined8 param_1)

{
  undefined1 uVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  undefined1 auStack_110 [272];
  
  FUN_005ec1b0(param_1,auStack_110,0x100);
  iVar4 = iRam007012a0;
  if (*(byte *)(iRam007012a0 + 0xe96c) < 0x11) {
    uVar1 = FUN_005ec920(auStack_110,0x648320,0x20);
    *(undefined1 *)((uint)*(byte *)(iVar4 + 0xe96c) + iVar4 + 0xe96c) = uVar1;
    if (*(char *)((uint)*(byte *)(iRam007012a0 + 0xe96c) + iRam007012a0 + 0xe96c) == '\x02') {
      if (*(char *)(iRam007012a0 + 0xd892) == '\0') {
        bVar3 = *(byte *)(iRam007012a0 + 0x14) & 0xf0;
        if (bVar3 != 0xf0) {
          *(byte *)(iRam007012a0 + 0x14) = *(byte *)(iRam007012a0 + 0x14) & 0xf | bVar3 + 0x10;
        }
      }
      else {
        iVar4 = iRam007012a0 +
                ((uint)*(ushort *)(iRam007012a0 + 0xd894) * 0x18 -
                (uint)*(ushort *)(iRam007012a0 + 0xd894)) * 4;
        bVar3 = *(byte *)(iVar4 + 0x2531);
        bVar2 = bVar3 & 0xf0;
        if (bVar2 != 0xf0) {
          *(byte *)(iVar4 + 0x2531) = bVar3 & 0xf | bVar2 + 0x10;
        }
        FUN_005ef780();
      }
    }
  }
  return 0;
}



================================================================