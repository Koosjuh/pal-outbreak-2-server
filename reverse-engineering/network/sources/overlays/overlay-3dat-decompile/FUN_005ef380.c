FUNCTION FUN_005ef380 @ 0x005ef380  size=108
CALLERS (2): FUN_005e9d20@0x005e9d20, FUN_005e8960@0x005e8960
CALLEES (1): FUN_005ec100@0x005ec100
----------------------------------------------------------------

void FUN_005ef380(void)

{
  undefined1 uVar1;
  
  if (*(char *)(iRam007012a0 + 0xd892) == '\0') {
    uVar1 = *(undefined1 *)(iRam007012a0 + 0x17c);
  }
  else {
    uVar1 = *(undefined1 *)
             (((uint)*(ushort *)(iRam007012a0 + 0xd894) * 0x18 -
              (uint)*(ushort *)(iRam007012a0 + 0xd894)) * 4 + iRam007012a0 + 0x252f);
  }
  if (*(short *)(iRam007012a0 + 0x124) < 1) {
    *(short *)(iRam007012a0 + 0x124) = 0;
  }
  else {
    *(short *)(iRam007012a0 + 0x124) = *(short *)(iRam007012a0 + 0x124) + -1;
  }
  FUN_005ec100(uVar1);
  return;
}



================================================================