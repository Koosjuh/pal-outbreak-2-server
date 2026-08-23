FUNCTION FUN_005ef220 @ 0x005ef220  size=348
CALLERS (5): FUN_005ea4a0@0x005ea4a0, FUN_005e9d00@0x005e9d00, FUN_005e88c0@0x005e88c0, FUN_005e9c30@0x005e9c30, FUN_005ea420@0x005ea420
CALLEES (3): FUN_005ec100@0x005ec100, FUN_005ec4f0@0x005ec4f0, FUN_005ec800@0x005ec800
----------------------------------------------------------------

void FUN_005ef220(void)

{
  undefined1 uVar1;
  undefined1 uVar2;
  long lVar3;
  int iVar4;
  
  if (*(char *)(iRam007012a0 + 0xd892) == '\0') {
    uVar1 = *(undefined1 *)(iRam007012a0 + 0x17c);
  }
  else {
    uVar1 = *(undefined1 *)
             (((uint)*(ushort *)(iRam007012a0 + 0xd894) * 0x18 -
              (uint)*(ushort *)(iRam007012a0 + 0xd894)) * 4 + iRam007012a0 + 0x252f);
  }
  if (0xe < *(short *)(iRam007012a0 + 0x124)) {
    *(undefined2 *)(iRam007012a0 + 0x124) = 0xe;
  }
  if (*(char *)(iRam007012a0 + 0x2c3) == '\0') {
    iVar4 = *(short *)(iRam007012a0 + 0x124) * 4 + iRam007012a0;
    *(undefined4 *)(iVar4 + 300) = *(undefined4 *)(iVar4 + 0x128);
  }
  else {
    lVar3 = FUN_005ec4f0(iRam007012a0 + 0x2c3);
    if (lVar3 < 0) {
      iVar4 = *(short *)(iRam007012a0 + 0x124) * 4 + iRam007012a0;
      *(undefined4 *)(iVar4 + 300) = *(undefined4 *)(iVar4 + 0x128);
    }
    else {
      *(int *)(*(short *)(iRam007012a0 + 0x124) * 4 + iRam007012a0 + 300) = (int)lVar3;
    }
  }
  iVar4 = iRam007012a0;
  if (*(char *)(iRam007012a0 + 0x2d3) == '\0') {
    iVar4 = *(short *)(iRam007012a0 + 0x124) + iRam007012a0;
    *(undefined1 *)(iVar4 + 0x169) = *(undefined1 *)(iVar4 + 0x168);
  }
  else {
    uVar2 = FUN_005ec800(iRam007012a0 + 0x2d3);
    *(undefined1 *)(*(short *)(iVar4 + 0x124) + iVar4 + 0x169) = uVar2;
  }
  if (*(short *)(iRam007012a0 + 0x124) < 0xe) {
    *(short *)(iRam007012a0 + 0x124) = *(short *)(iRam007012a0 + 0x124) + 1;
  }
  FUN_005ec100(uVar1);
  return;
}



================================================================