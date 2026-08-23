FUNCTION FUN_005d0af0 @ 0x005d0af0  size=1184
CALLERS (0): 
CALLEES (1): FUN_005d5db0@0x005d5db0
----------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005d0af0(void)

{
  char cVar1;
  char cVar2;
  ushort uVar3;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_10 = (int)_DAT_00642de0;
  uStack_c = (int)((ulong)_DAT_00642de0 >> 0x20);
  uStack_8 = DAT_00642de8;
  uStack_4 = DAT_00642dec;
  uStack_20 = (int)_DAT_00642df0;
  uStack_1c = (int)((ulong)_DAT_00642df0 >> 0x20);
  uStack_18 = DAT_00642df8;
  uStack_14 = DAT_00642dfc;
  if ((int)(*(ushort *)(iRam00701070 + 0x18) & 2) >> 1 != 0) {
    if (*(char *)(iRam00701068 + 0x4f8a8) != '\0') {
      if (*(short *)(iRam00701078 + 0x10) <= *(short *)(iRam00701070 + 0x1e)) {
        FUN_005d5db0(0xffffffffffffffec,0);
      }
      if ((long)(0x27c - *(short *)(iRam00701070 + 0x20)) <= (long)*(short *)(iRam00701078 + 0x10))
      {
        FUN_005d5db0(0x14,0);
      }
      if (*(short *)(iRam00701078 + 0x12) <= *(short *)(iRam00701070 + 0x1a)) {
        FUN_005d5db0(0,0xffffffffffffffec);
      }
      if ((long)(0x1bc - *(short *)(iRam00701070 + 0x1c)) <= (long)*(short *)(iRam00701078 + 0x12))
      {
        FUN_005d5db0(0,0x14);
      }
    }
    uVar3 = *(ushort *)(iRam00701068 + 0x4f8a0);
    if (((((uVar3 & 1) != 0) || ((uVar3 & 2) != 0)) || ((uVar3 & 4) != 0)) ||
       (((uVar3 & 8) != 0 || ((0x4e < uRam0036d6dc && (uRam0036d6dc < 0x53)))))) {
      if (*(short *)(iRam00701078 + 0x10) < *(short *)(iRam00701070 + 0x1e)) {
        FUN_005d5db0(0xffffffffffffffec,0);
      }
      if ((long)(0x278 - *(short *)(iRam00701070 + 0x20)) < (long)*(short *)(iRam00701078 + 0x10)) {
        FUN_005d5db0(0x14,0);
      }
      if (*(short *)(iRam00701078 + 0x12) < *(short *)(iRam00701070 + 0x1a)) {
        FUN_005d5db0(0,0xffffffffffffffec);
      }
      if ((long)(0x1b8 - *(short *)(iRam00701070 + 0x1c)) < (long)*(short *)(iRam00701078 + 0x12)) {
        FUN_005d5db0(0,0x14);
      }
    }
    if (*(char *)(iRam00701068 + 0x4f8aa) != '\0') {
      cVar1 = *(char *)((int)&uStack_10 + (uint)*(byte *)(iRam00701068 + 0x4f8ab));
      cVar2 = *(char *)((int)&uStack_20 + (uint)*(byte *)(iRam00701068 + 0x4f8ab));
      if (*(char *)(iRam00701068 + 0x4f8aa) == '\x03') {
        *(int *)(iRam00701070 + 4) = *(int *)(iRam00701070 + 4) + cVar1 * 4;
        *(int *)(iRam00701070 + 8) = *(int *)(iRam00701070 + 8) + cVar2 * 4;
      }
      else {
        *(int *)(iRam00701070 + 4) = *(int *)(iRam00701070 + 4) + cVar1 * 2;
        *(int *)(iRam00701070 + 8) = *(int *)(iRam00701070 + 8) + cVar2 * 2;
      }
    }
    if ((*(ushort *)(iRam00701068 + 0x4f8a0) & 0x800) != 0) {
      FUN_005d5db0(0,0xffffffffffffffec);
    }
    if ((*(ushort *)(iRam00701068 + 0x4f8a0) & 0x400) != 0) {
      FUN_005d5db0(0,0x14);
    }
    if ((*(ushort *)(iRam00701068 + 0x4f8a0) & 0x80) != 0) {
      FUN_005d5db0(0xffffffffffffffec,0);
    }
    if ((*(ushort *)(iRam00701068 + 0x4f8a0) & 0x40) != 0) {
      FUN_005d5db0(0x14,0);
    }
    if (*(char *)(iRam00715da8 + 0x49c) == 'K') {
      FUN_005d5db0(0,0xfffffffffffffe98);
    }
    if (*(char *)(iRam00715da8 + 0x49c) == 'N') {
      FUN_005d5db0(0,0x168);
    }
    if (*(char *)(iRam00715da8 + 0x49c) == 'J') {
      FUN_005d5db0(0,-*(int *)(iRam00701070 + 0x10));
    }
    if (*(char *)(iRam00715da8 + 0x49c) == 'M') {
      FUN_005d5db0(0,*(undefined4 *)(iRam00701070 + 0x10));
    }
  }
  return;
}



================================================================