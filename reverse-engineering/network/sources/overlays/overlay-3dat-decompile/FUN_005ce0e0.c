FUNCTION FUN_005ce0e0 @ 0x005ce0e0  size=1012
CALLERS (0): 
CALLEES (6): FUN_005ce0a0@0x005ce0a0, FUN_0061e740@0x0061e740, FUN_0061e720@0x0061e720, FUN_0061e730@0x0061e730, FUN_005d5b60@0x005d5b60, FUN_005d0a40@0x005d0a40
----------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005ce0e0(void)

{
  char cVar1;
  ushort uVar2;
  short sVar3;
  ulong uVar4;
  uint uVar5;
  char cVar6;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_10 = (int)_DAT_00642db0;
  uStack_c = (int)((ulong)_DAT_00642db0 >> 0x20);
  uStack_8 = DAT_00642db8;
  uStack_4 = DAT_00642dbc;
  if (((*(ushort *)(iRam00701068 + 0x4f8a4) & 0x8000) != 0) ||
     (*(char *)(iRam00715da8 + 0x49c) == ')')) {
    FUN_0061e740();
    *(undefined1 *)(iRam00701068 + 0x68e83) = 0;
    *(undefined1 *)(iRam00701078 + 1) = 0;
    *(undefined1 *)(iRam00701068 + 0x68e86) = 1;
  }
  if (((*(ushort *)(iRam00701068 + 0x4f8a4) & 0x10) != 0) ||
     (*(char *)(iRam00715da8 + 0x49c) == '(')) {
    FUN_0061e730();
    if (*(char *)(iRam00701070 + 0x2e) == '\b') {
      return;
    }
    for (uVar5 = 0; uVar5 < 3; uVar5 = uVar5 + 1 & 0xff) {
      if (uVar5 == *(byte *)(iRam00701078 + 2) - 1) {
        if (uVar5 == 2) {
          FUN_005ce0a0();
          return;
        }
        if (uVar5 == 1) {
          uRam00701e18 = 0;
          FUN_005d5b60(0);
          return;
        }
        if (uVar5 == 0) {
          if (*(char *)(iRam00701070 + 0x38) != '\0') {
            return;
          }
          if (*(char *)(iRam00701070 + 0x3a) != '\0') {
            return;
          }
          FUN_005ce0a0();
          FUN_005d0a40();
          return;
        }
      }
    }
  }
  cVar6 = *(char *)(iRam00701078 + 2);
  if (*(char *)(iRam00701068 + 0x4f8a8) == '\0') {
    uVar2 = *(ushort *)(iRam00701068 + 0x4f8a4);
    if (((uVar2 & 1) == 0) && ((uVar2 & 2) == 0)) {
      cVar1 = *(char *)(iRam00715da8 + 0x49c);
      if ((cVar1 != 'R') && (cVar1 != 'Q')) {
        *(undefined1 *)(iRam00701068 + 0x68e7d) = 1;
        *(undefined2 *)(iRam00701078 + 0xe) = 0;
        return;
      }
      if (cVar1 == 'R') {
        cVar6 = cVar6 + -1;
      }
      if (cVar1 == 'Q') {
        cVar6 = cVar6 + '\x01';
      }
    }
    else {
      if ((uVar2 & 1) != 0) {
        cVar6 = cVar6 + -1;
      }
      if ((uVar2 & 2) != 0) {
        cVar6 = cVar6 + '\x01';
      }
    }
  }
  else {
    if (*(char *)(iRam00701068 + 0x68e7d) == '\x01') {
      *(undefined1 *)(iRam00701068 + 0x68e7c) = 1;
    }
    else {
      *(undefined1 *)(iRam00701068 + 0x68e7c) = 0;
    }
    *(undefined1 *)(iRam00701068 + 0x68e7d) = 0;
    if (1000 < *(short *)(iRam00701078 + 0xe)) {
      *(undefined2 *)(iRam00701078 + 0xe) = 0;
    }
    sVar3 = *(short *)(iRam00701078 + 0xe) + 1;
    *(short *)(iRam00701078 + 0xe) = sVar3;
    uVar4 = (long)sVar3 & 7;
    if (((long)sVar3 < 0) && (uVar4 != 0)) {
      uVar4 = (ulong)((int)uVar4 + -8);
    }
    if ((uVar4 != 0) && (*(char *)(iRam00701068 + 0x68e7c) == '\0')) {
      return;
    }
    cVar1 = *(char *)((int)&uStack_10 + (uint)*(byte *)(iRam00701068 + 0x4f8a9));
    *(undefined2 *)(iRam00701078 + 0xe) = 0;
    cVar6 = cVar6 + cVar1;
    *(char *)(iRam00701078 + 2) = cVar6;
  }
  if (cVar6 < '\x01') {
    cVar6 = '\x03';
  }
  if ('\x03' < cVar6) {
    cVar6 = '\x01';
  }
  FUN_0061e720();
  *(char *)(iRam00701078 + 2) = cVar6;
  return;
}



================================================================