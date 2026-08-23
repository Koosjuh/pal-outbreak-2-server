FUNCTION FUN_005ef3f0 @ 0x005ef3f0  size=256
CALLERS (1): FUN_005e9360@0x005e9360
CALLEES (4): FUN_005ec100@0x005ec100, FUN_005d8a70@0x005d8a70, FUN_005d95f0@0x005d95f0, FUN_005ec4f0@0x005ec4f0
----------------------------------------------------------------

void FUN_005ef3f0(void)

{
  undefined1 uVar1;
  long lVar2;
  
  uVar1 = *(undefined1 *)(iRam007012a0 + 0x17c);
  *(undefined2 *)(iRam007012a0 + 0x124) = 0;
  *(undefined1 *)(*(short *)(iRam007012a0 + 0x124) + iRam007012a0 + 0x168) = 3;
  lVar2 = FUN_005ec4f0(iRam007012a0 + 0x2a3);
  if (-1 < lVar2) {
    *(int *)(*(short *)(iRam007012a0 + 0x124) * 4 + iRam007012a0 + 0x128) = (int)lVar2;
  }
  lVar2 = FUN_005ec4f0(iRam007012a0 + 0x193);
  if (-1 < lVar2) {
    *(int *)(iRam007012a0 + 0x120) = (int)lVar2;
  }
  lVar2 = FUN_005ec4f0(iRam007012a0 + 0x2b3);
  if (-1 < lVar2) {
    *(int *)(iRam007012a0 + 0x178) = (int)lVar2;
  }
  FUN_005ec100(uVar1);
  if ((*(char *)(iRam007012a0 + 0x186) == '\0') && (*(char *)(iRam007012a0 + 0xe96b) == '\0')) {
    FUN_005d8a70(*(undefined4 *)(iRam007012a0 + 0x120));
    FUN_005d95f0(iRam007012a0 + 0x1a3);
  }
  return;
}



================================================================