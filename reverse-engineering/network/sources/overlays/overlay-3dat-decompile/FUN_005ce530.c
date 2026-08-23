FUNCTION FUN_005ce530 @ 0x005ce530  size=1620
CALLERS (0): 
CALLEES (6): FUN_005d5c20@0x005d5c20, FUN_005ce4e0@0x005ce4e0, FUN_005d09d0@0x005d09d0, FUN_0061e740@0x0061e740, FUN_0061e720@0x0061e720, FUN_0061e730@0x0061e730
----------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005ce530(void)

{
  char cVar1;
  ushort uVar2;
  short sVar3;
  ulong uVar4;
  char cVar5;
  char cVar6;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_10 = (int)_DAT_00642dc0;
  uStack_c = (int)((ulong)_DAT_00642dc0 >> 0x20);
  uStack_8 = DAT_00642dc8;
  uStack_4 = DAT_00642dcc;
  cVar6 = *(char *)(iRam00701068 + 0x68e85);
  if (cVar6 == '\x06') {
    cVar6 = '\x02';
  }
  else if (cVar6 == '\x05') {
    cVar6 = '\x02';
  }
  else if (cVar6 == '\x04') {
    cVar6 = '\x03';
  }
  else {
    cVar6 = '\x02';
  }
  *(undefined1 *)(iRam00701068 + 0x68e7a) = 0;
  cVar5 = *(char *)(iRam00701068 + 0x68e85);
  if (cVar5 == '\x06') {
    if (((*(ushort *)(iRam00701068 + 0x4f8a4) & 0x10) != 0) ||
       (*(char *)(iRam00715da8 + 0x49c) == '(')) {
      FUN_0061e730();
      if (*(char *)(iRam00701078 + 2) == '\x02') {
        *(undefined1 *)(iRam00701068 + 0x68e7a) = 0x50;
        FUN_005ce4e0();
        return;
      }
      if (*(char *)(iRam00701078 + 2) != '\x01') {
        return;
      }
      *(undefined1 *)(iRam00701068 + 0x68e7a) = 0x52;
      *(undefined1 *)(iRam00701068 + 0x68e87) = 0;
      *(undefined1 *)(iRam00701078 + 1) = 4;
      *(undefined1 *)(iRam00701068 + 0x68e7b) = 0;
      return;
    }
  }
  else {
    if (cVar5 == '\x05') {
      if ((*(ushort *)(iRam00701068 + 0x4f8a4) & 0x10) == 0) {
        if (*(char *)(iRam00715da8 + 0x49c) != '(') {
          if (((*(ushort *)(iRam00701068 + 0x4f8a4) & 0x200) != 0) ||
             (*(char *)(iRam00715da8 + 0x49c) == ')')) {
            FUN_0061e740();
            FUN_005ce4e0();
            if (*(char *)(iRam00701070 + 0x2e) == '\b') {
              *(undefined1 *)(iRam00701070 + 0x38) = 0;
              FUN_005d5c20(7);
              *(undefined1 *)(iRam00701070 + 0x2c) = 1;
              return;
            }
            *(undefined1 *)(iRam00701068 + 0x68e7a) = 0x3c;
            FUN_005d09d0();
            return;
          }
          goto LAB_005ce964;
        }
      }
      FUN_0061e730();
      FUN_005ce4e0();
      if (*(char *)(iRam00701078 + 2) == '\x02') {
        if (*(char *)(iRam00701070 + 0x2e) != '\b') {
          *(undefined1 *)(iRam00701068 + 0x68e7a) = 0x3c;
          FUN_005d09d0();
          return;
        }
        *(undefined1 *)(iRam00701070 + 0x38) = 0;
        FUN_005d5c20(7);
        *(undefined1 *)(iRam00701070 + 0x2c) = 1;
        return;
      }
      if (*(char *)(iRam00701078 + 2) != '\x01') {
        return;
      }
      *(undefined1 *)(iRam00701068 + 0x68e7a) = 0x3d;
      return;
    }
    if ((cVar5 == '\x04') &&
       (((*(ushort *)(iRam00701068 + 0x4f8a4) & 0x10) != 0 ||
        (*(char *)(iRam00715da8 + 0x49c) == '(')))) {
      FUN_0061e730();
      cVar6 = *(char *)(iRam00701078 + 2);
      if (cVar6 != '\x03') {
        if (cVar6 == '\x02') {
          *(undefined1 *)(iRam00701068 + 0x68e7a) = 1;
        }
        else if (cVar6 == '\x01') {
          *(undefined1 *)(iRam00701068 + 0x68e7a) = 2;
        }
        *(char *)(iRam00701068 + 0x68e7a) =
             *(char *)(iRam00701068 + 0x68e7a) + *(char *)(iRam00701070 + 0x35) * '\n';
        *(undefined1 *)(iRam00701068 + 0x68e87) = 0;
        FUN_005ce4e0();
        return;
      }
      *(undefined1 *)(iRam00701068 + 0x68e7a) = 0;
      FUN_005ce4e0();
      return;
    }
  }
LAB_005ce964:
  cVar5 = *(char *)(iRam00701078 + 2);
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
        cVar5 = cVar5 + -1;
      }
      if (cVar1 == 'Q') {
        cVar5 = cVar5 + '\x01';
      }
    }
    else {
      if ((uVar2 & 1) != 0) {
        cVar5 = cVar5 + -1;
      }
      if ((uVar2 & 2) != 0) {
        cVar5 = cVar5 + '\x01';
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
    cVar5 = cVar5 + cVar1;
  }
  if (cVar5 < '\x01') {
    cVar6 = '\x01';
  }
  else if (cVar5 <= cVar6) {
    FUN_0061e720();
    cVar6 = cVar5;
  }
  *(char *)(iRam00701078 + 2) = cVar6;
  return;
}



================================================================