FUNCTION FUN_005deb00 @ 0x005deb00  size=688
CALLERS (1): FUN_005c8810@0x005c8810
CALLEES (0): 
----------------------------------------------------------------

void FUN_005deb00(void)

{
  short sVar1;
  
  *(undefined2 *)(iRam00701068 + 0x4f8a2) = *(undefined2 *)(iRam00701068 + 0x4f8a0);
  *(short *)(iRam00701068 + 0x4f8a0) = (short)*(undefined4 *)(iRam0029a528 + 8);
  *(short *)(iRam00701068 + 0x4f8a4) = (short)*(undefined4 *)(iRam0029a528 + 0x10);
  *(short *)(iRam00701068 + 0x4f8a6) = (short)*(undefined4 *)(iRam0029a528 + 0x14);
  *(undefined1 *)(iRam00701068 + 0x4f8a8) = 3;
  *(undefined1 *)(iRam00701068 + 0x4f8aa) = 3;
  sVar1 = *(short *)(iRam0029a528 + 0x20);
  if (sVar1 < 0) {
    sVar1 = -sVar1;
  }
  if (((sVar1 < 0x7e) && (*(undefined1 *)(iRam00701068 + 0x4f8a8) = 2, sVar1 < 0x5a)) &&
     (*(undefined1 *)(iRam00701068 + 0x4f8a8) = 1, sVar1 < 0x28)) {
    *(undefined1 *)(iRam00701068 + 0x4f8a8) = 0;
  }
  *(byte *)(iRam00701068 + 0x4f8a9) =
       4U - (char)(((int)((*(float *)(iRam0029a528 + 0x24) * 65536.0) / DAT_00692d28 + 0.5) &
                   0xffffU) >> 0xc) & 0xf;
  sVar1 = *(short *)(iRam0029a528 + 0x2c);
  if (sVar1 < 0) {
    sVar1 = -sVar1;
  }
  if (((sVar1 < 0x7e) && (*(undefined1 *)(iRam00701068 + 0x4f8aa) = 2, sVar1 < 0x5a)) &&
     (*(undefined1 *)(iRam00701068 + 0x4f8aa) = 1, sVar1 < 0x28)) {
    *(undefined1 *)(iRam00701068 + 0x4f8aa) = 0;
  }
  *(byte *)(iRam00701068 + 0x4f8ab) =
       4U - (char)(((int)((*(float *)(iRam0029a528 + 0x30) * 65536.0) / DAT_00692d28 + 0.5) &
                   0xffffU) >> 0xc) & 0xf;
  return;
}



================================================================