FUNCTION FUN_00610830 @ 0x00610830  size=6052
CALLERS (1): FUN_0060f910@0x0060f910
CALLEES (31): thunk_EXT_FUN_001b0100@0x006187a0, FUN_00612020@0x00612020, FUN_00618210@0x00618210, thunk_EXT_FUN_001b00e0@0x006187b0, FUN_0060f1b0@0x0060f1b0, FUN_00615430@0x00615430, FUN_0060e1c0@0x0060e1c0, FUN_00614ad0@0x00614ad0, FUN_00614990@0x00614990, thunk_EXT_FUN_001b0110@0x006187c0, FUN_00618600@0x00618600, FUN_0060ef20@0x0060ef20, ...
----------------------------------------------------------------

undefined4 FUN_00610830(void)

{
  ushort uVar1;
  undefined1 uVar2;
  char cVar3;
  char *pcVar4;
  uint uVar5;
  long lVar6;
  undefined8 uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  bool bVar12;
  int iVar13;
  ulong uVar14;
  
  cVar3 = *(char *)(iRam0070d1c0 + 0x20);
  if (((('\x05' < cVar3) && (cVar3 < '\t')) || (('\v' < cVar3 && (cVar3 < '\x0e')))) &&
     (lVar6 = FUN_00612020(), lVar6 != 0)) {
    *(undefined1 *)(iRam0070d1c0 + 0x20) = 0xf;
    *(undefined1 *)(iRam0070d1c0 + 0x4e) = 7;
    thunk_EXT_FUN_001b00e0();
  }
  cVar3 = *(char *)(iRam0070d1c0 + 0x20);
  pcVar4 = (char *)(iRam0070d1c0 + 0x20);
  switch(cVar3) {
  case '\0':
    iVar13 = 1;
    *pcVar4 = cVar3 + '\x01';
    do {
      *(undefined1 *)(iRam0070d1c0 + iVar13 + 0x10) = 0;
      iVar13 = iVar13 + 1;
    } while (iVar13 < 0x10);
    FUN_00618210(iRam0070d1c0 + 0x10d8);
    FUN_00615430();
  case '\x01':
    *(undefined1 *)(iRam0070d1c0 + 0x4a) = 1;
    uVar2 = 2;
    if ('\x01' < *(char *)(iRam0070d1c0 + 0x10)) {
      uVar2 = 4;
    }
    *(undefined1 *)(iRam0070d1c0 + 0x4b) = uVar2;
    *(undefined1 *)(iRam0070d1c0 + 0x4c) = 1;
    *(undefined1 *)(iRam0070d1c0 + 0x4d) = 1;
    *(undefined1 *)(iRam0070d1c0 + 0x4f) = 1;
    cVar3 = *(char *)(iRam0070d1c0 + 0x10);
    if ('\x01' < cVar3) {
      cVar3 = '\x02';
    }
    *(char *)(iRam0070d1c0 + 0x50) = cVar3;
    lVar6 = FUN_006120a0();
    if (lVar6 < 0) {
      return 0;
    }
    if (lVar6 != 0) {
      return 0xfffffffe;
    }
    if ((uRam003433b0 & 0x200) != 0) {
      return 0xffffffff;
    }
    if ((uRam003433b0 & 0x10) != 0) {
      if (*(char *)(iRam0070d1c0 + 0x10) == '\x01') {
        *(undefined1 *)(iRam0070d1c0 + 0x20) = 2;
      }
      else if (*(char *)(iRam0070d1c0 + 0x10) == '\0') {
        *(undefined1 *)(iRam0070d1c0 + 0x20) = 0x13;
        *(undefined1 *)(iRam0070d1c0 + 0x4e) = 0x37;
        *(undefined1 *)(iRam0070d1c0 + 0x1f) = 0;
      }
      else {
        *(undefined1 *)(iRam0070d1c0 + 0x20) = 0x12;
      }
      thunk_EXT_FUN_001b00e0();
      return 0;
    }
    if ((uRam003433b0 & 0x100) == 0) {
      if ((uRam003433b0 & 3) != 0) {
        if ('\x01' < *(char *)(iRam0070d1c0 + 0x10)) {
          if (('\0' < *(char *)(iRam0070d1c0 + 0x13)) && ((uRam003433b0 & 1) != 0)) {
            *(char *)(iRam0070d1c0 + 0x13) = *(char *)(iRam0070d1c0 + 0x13) + -1;
          }
          if (((long)*(char *)(iRam0070d1c0 + 0x13) < (long)(*(char *)(iRam0070d1c0 + 0x24) + -1))
             && ((uRam003433b0 & 2) != 0)) {
            *(char *)(iRam0070d1c0 + 0x13) = *(char *)(iRam0070d1c0 + 0x13) + '\x01';
          }
          cVar3 = *(char *)(iRam0070d1c0 + 0x14);
          if ((((int)*(char *)(iRam0070d1c0 + 0x13) - (int)cVar3 < 0) && ('\0' < cVar3)) &&
             ((uRam003433b0 & 1) != 0)) {
            *(char *)(iRam0070d1c0 + 0x14) = cVar3 + -1;
          }
          if ('\x01' < *(char *)(iRam0070d1c0 + 0x13)) {
            if (((long)*(char *)(iRam0070d1c0 + 0x14) < (long)(*(char *)(iRam0070d1c0 + 0x24) + -2))
               && ((uRam003433b0 & 2) != 0)) {
              *(char *)(iRam0070d1c0 + 0x14) = *(char *)(iRam0070d1c0 + 0x14) + '\x01';
            }
          }
        }
        if (('\0' < *(char *)(iRam0070d1c0 + 0x10)) && ((uRam003433b0 & 1) != 0)) {
          *(char *)(iRam0070d1c0 + 0x10) = *(char *)(iRam0070d1c0 + 0x10) + -1;
          thunk_EXT_FUN_001b0100();
        }
        if (((long)*(char *)(iRam0070d1c0 + 0x10) < (long)(*(char *)(iRam0070d1c0 + 0x24) + 1)) &&
           ((uRam003433b0 & 2) != 0)) {
          *(char *)(iRam0070d1c0 + 0x10) = *(char *)(iRam0070d1c0 + 0x10) + '\x01';
          thunk_EXT_FUN_001b0100();
        }
      }
    }
    else if ('\x01' < *(char *)(iRam0070d1c0 + 0x10)) {
      *(undefined1 *)(iRam0070d1c0 + 0x4b) = 2;
      *(undefined1 *)(iRam0070d1c0 + 0x21) = *(undefined1 *)(iRam0070d1c0 + 0x20);
      *(undefined1 *)(iRam0070d1c0 + 0x20) = 0xd;
      *(undefined1 *)(iRam0070d1c0 + 0x4e) = 0x19;
      thunk_EXT_FUN_001b00e0();
    }
    break;
  case '\x02':
    iVar13 = 0;
    *pcVar4 = cVar3 + '\x01';
    do {
      if (((iVar13 != 0) && (iVar13 != 3)) && (iVar13 != 4)) {
        *(undefined1 *)(iRam0070d1c0 + iVar13 + 0x10) = 0;
      }
      iVar13 = iVar13 + 1;
    } while (iVar13 < 0x10);
    *(undefined1 *)(iRam0070d1c0 + 0x4b) = 1;
    *(undefined1 *)(iRam0070d1c0 + 0x20) = 0xd;
    *(undefined1 *)(iRam0070d1c0 + 0x21) = 6;
    *(undefined1 *)(iRam0070d1c0 + 0x4e) = 0x17;
    FUN_00615430();
    break;
  case '\x03':
    *(undefined1 *)(iRam0070d1c0 + 0x4a) = 3;
    *(undefined1 *)(iRam0070d1c0 + 0x4b) = 2;
    *(undefined1 *)(iRam0070d1c0 + 0x4c) = 0x13;
    *(undefined1 *)(iRam0070d1c0 + 0x4d) = 0x15;
    *(undefined1 *)(iRam0070d1c0 + 0x4f) = 0x1e;
    *(undefined1 *)(iRam0070d1c0 + 0x50) = 0;
    lVar6 = FUN_00618230(iRam0070d1c0 + 0x10d8);
    if (-1 < lVar6) {
      *(byte *)(iRam0070d1c0 + 0x25) =
           *(byte *)(iRam0070d1c0 + 0x25) |
           (byte)((int)(uint)(*(byte *)(iRam0070d1c0 + 0x10da) | *(byte *)(iRam0070d1c0 + 0x10db))
                 >> 1) & 3;
      if (*(char *)(iRam0070d1c0 + 0x25) == '\0') {
        *(undefined1 *)(iRam0070d1c0 + 0x20) = 0xf;
        *(undefined1 *)(iRam0070d1c0 + 0x4e) = 6;
        thunk_EXT_FUN_001b00e0();
      }
      else {
        *(char *)(iRam0070d1c0 + 0x20) = *(char *)(iRam0070d1c0 + 0x20) + '\x01';
        for (uVar11 = 0;
            ((int)uVar11 < 2 && (((uint)*(byte *)(iRam0070d1c0 + 0x25) & 1 << (uVar11 & 0x1f)) == 0)
            ); uVar11 = uVar11 + 1) {
        }
        if (uVar11 == 2) {
          uVar11 = 0;
        }
        *(char *)(iRam0070d1c0 + 0x11) = (char)uVar11;
      }
    }
    break;
  case '\x04':
    if ((uRam003433b0 & 0x200) == 0) {
      if ((uRam003433b0 & 0x10) == 0) {
        if ((uRam003433b0 & 3) != 0) {
          uVar14 = (ulong)*(char *)(iRam0070d1c0 + 0x11);
          do {
            iVar13 = (int)uVar14;
            if ((uRam003433b0 & 1) != 0) {
              iVar13 = iVar13 + -1;
            }
            iVar10 = iVar13 + 2;
            if ((uRam003433b0 & 2) != 0) {
              iVar10 = iVar13 + 3;
            }
            uVar14 = (long)iVar10 & 1;
            if ((long)iVar10 < 0) {
              uVar11 = (uint)uVar14;
              if (uVar14 != 0) {
                uVar14 = (ulong)(int)(uVar11 - 2);
                goto LAB_00610e90;
              }
            }
            else {
LAB_00610e90:
              uVar11 = (uint)uVar14 & 0x1f;
            }
          } while ((((uint)*(byte *)(iRam0070d1c0 + 0x25) & 1 << uVar11) == 0) &&
                  (uVar14 != (long)*(char *)(iRam0070d1c0 + 0x11)));
          if ((long)*(char *)(iRam0070d1c0 + 0x11) != uVar14) {
            thunk_EXT_FUN_001b0100();
          }
          *(char *)(iRam0070d1c0 + 0x11) = (char)uVar14;
        }
      }
      else {
        *pcVar4 = cVar3 + '\x01';
        thunk_EXT_FUN_001b00e0();
        FUN_00618510(iRam0070d1c0 + 0x10d8,*(undefined1 *)(iRam0070d1c0 + 0x11));
        FUN_006185f0(iRam0070d1c0 + 0x10d8);
      }
    }
    else {
      FUN_00611fe0(0xe);
    }
    break;
  case '\x05':
    lVar6 = FUN_00618600(iRam0070d1c0 + 0x10d8);
    if (lVar6 != -2) {
      thunk_EXT_FUN_001b00e0();
      if (lVar6 == -5) {
        *(undefined1 *)(iRam0070d1c0 + 0x20) = 0x10;
        *(undefined1 *)(iRam0070d1c0 + 0x4e) = 10;
        *(undefined1 *)(iRam0070d1c0 + 0x1f) = 0;
        thunk_EXT_FUN_001b00e0();
      }
      else if (lVar6 == -7) {
        *(undefined1 *)(iRam0070d1c0 + 0x20) = 0xf;
        *(undefined1 *)(iRam0070d1c0 + 0x4e) = 0x2c;
      }
      else if (lVar6 == -1) {
        *(undefined1 *)(iRam0070d1c0 + 0x20) = 0xd;
        *(undefined1 *)(iRam0070d1c0 + 0x21) = 6;
        *(undefined1 *)(iRam0070d1c0 + 0x4e) = 0x17;
      }
      else {
        *(undefined1 *)(iRam0070d1c0 + 0x20) = 0xf;
        *(undefined1 *)(iRam0070d1c0 + 0x4e) = 0x22;
      }
    }
    break;
  case '\x06':
    *(undefined1 *)(iRam0070d1c0 + 0x4a) = 0xf;
    *(undefined1 *)(iRam0070d1c0 + 0x4b) = 2;
    *(undefined1 *)(iRam0070d1c0 + 0x4c) = 0x13;
    *(undefined1 *)(iRam0070d1c0 + 0x4d) = 0x16;
    *(undefined1 *)(iRam0070d1c0 + 0x4f) = 0x1f;
    *(undefined1 *)(iRam0070d1c0 + 0x50) = 0;
    if ((uRam003433b0 & 0x200) == 0) {
      if ((uRam003433b0 & 0x10) == 0) {
        if ((uRam003433b0 & 8) == 0) {
          if ((uRam003433b0 & 3) != 0) {
            if ((uRam003433b0 & 1) != 0) {
              *(char *)(iRam0070d1c0 + 0x15) = *(char *)(iRam0070d1c0 + 0x15) + -1;
            }
            if ((uRam003433b0 & 2) != 0) {
              *(char *)(iRam0070d1c0 + 0x15) = *(char *)(iRam0070d1c0 + 0x15) + '\x01';
            }
            uVar8 = (int)*(char *)(iRam0070d1c0 + 0x15) + 2;
            uVar11 = uVar8 & 1;
            cVar3 = (char)uVar11;
            if (((int)uVar8 < 0) && (uVar11 != 0)) {
              cVar3 = cVar3 + -2;
            }
            *(char *)(iRam0070d1c0 + 0x15) = cVar3;
            thunk_EXT_FUN_001b0100();
          }
        }
        else {
          thunk_EXT_FUN_001b0100();
          if (*(int *)(iRam0070d1c0 + 0xed0) == 0) {
            *(undefined1 *)(iRam0070d1c0 + 0x21) = *(undefined1 *)(iRam0070d1c0 + 0x20);
            *(undefined1 *)(iRam0070d1c0 + 0x20) = 8;
            *(undefined1 *)(iRam0070d1c0 + 0x4e) = 0x18;
          }
          else {
            *(undefined1 *)(iRam0070d1c0 + 0x20) = 7;
            *(undefined1 *)(iRam0070d1c0 + 0x21) = *(undefined1 *)(iRam0070d1c0 + 0x20);
          }
        }
      }
      else {
        *(int *)(iRam0070d1c0 + 0xed0) = 1 - *(char *)(iRam0070d1c0 + 0x15);
        thunk_EXT_FUN_001b00e0();
      }
    }
    else {
      FUN_00611fe0(0xe);
    }
    break;
  case '\a':
    *(undefined1 *)(iRam0070d1c0 + 0x4a) = 0x10;
    *(undefined1 *)(iRam0070d1c0 + 0x4b) = 2;
    *(undefined1 *)(iRam0070d1c0 + 0x4c) = 0x13;
    *(undefined1 *)(iRam0070d1c0 + 0x4d) = 0x17;
    *(undefined1 *)(iRam0070d1c0 + 0x4f) = 0x20;
    *(undefined1 *)(iRam0070d1c0 + 0x50) = *(undefined1 *)(iRam0070d1c0 + 0x16);
    if ((uRam003433b0 & 0x200) == 0) {
      if ((uRam003433b0 & 0x10) == 0) {
        if ((uRam003433b0 & 4) == 0) {
          if ((uRam003433b0 & 8) == 0) {
            if ((uRam003433b0 & 3) != 0) {
              if ((uRam003433b0 & 1) != 0) {
                *(char *)(iRam0070d1c0 + 0x16) = *(char *)(iRam0070d1c0 + 0x16) + -1;
              }
              if ((uRam003433b0 & 2) != 0) {
                *(char *)(iRam0070d1c0 + 0x16) = *(char *)(iRam0070d1c0 + 0x16) + '\x01';
              }
              uVar8 = (int)*(char *)(iRam0070d1c0 + 0x16) + 4;
              uVar11 = uVar8 & 3;
              cVar3 = (char)uVar11;
              if (((int)uVar8 < 0) && (uVar11 != 0)) {
                cVar3 = cVar3 + -4;
              }
              *(char *)(iRam0070d1c0 + 0x16) = cVar3;
              thunk_EXT_FUN_001b0100();
            }
          }
          else if ((*(char *)(iRam0070d1c0 + 0xed8) == '\0') ||
                  (*(short *)(iRam0070d1c0 + 0xed4) == 0)) {
            thunk_EXT_FUN_001b0110();
          }
          else {
            *(undefined1 *)(iRam0070d1c0 + 0x20) = 8;
            *(undefined1 *)(iRam0070d1c0 + 0x4e) = 0x18;
            thunk_EXT_FUN_001b0100();
          }
        }
        else {
          *(undefined1 *)(iRam0070d1c0 + 0x20) = 6;
          thunk_EXT_FUN_001b0100();
        }
      }
      else {
        thunk_EXT_FUN_001b00e0();
        cVar3 = *(char *)(iRam0070d1c0 + 0x16);
        if (cVar3 == '\x03') {
          *(undefined1 *)(iRam0070d1c0 + 0x20) = 0xc;
          FUN_00614990(iRam0070d1c0 + 0xed6);
        }
        else if (cVar3 == '\x02') {
          *(undefined1 *)(iRam0070d1c0 + 0x20) = 0xb;
          FUN_006149f0(1,iRam0070d1c0 + 0xfd8);
        }
        else if (cVar3 == '\x01') {
          *(undefined1 *)(iRam0070d1c0 + 0x20) = 0xc;
          FUN_00614990(iRam0070d1c0 + 0xed4);
        }
        else if (cVar3 == '\0') {
          *(undefined1 *)(iRam0070d1c0 + 0x20) = 0xb;
          FUN_006149f0(1,iRam0070d1c0 + 0xed8);
        }
      }
    }
    else {
      FUN_00611fe0(0xe);
    }
    break;
  case '\b':
    if ((uRam003433b0 & 0x200) == 0) {
      if ((uRam003433b0 & 0x10) == 0) {
        if ((uRam003433b0 & 3) != 0) {
          if ((uRam003433b0 & 1) != 0) {
            *(char *)(iRam0070d1c0 + 0x1f) = *(char *)(iRam0070d1c0 + 0x1f) + -1;
          }
          if ((uRam003433b0 & 2) != 0) {
            *(char *)(iRam0070d1c0 + 0x1f) = *(char *)(iRam0070d1c0 + 0x1f) + '\x01';
          }
          uVar8 = (int)*(char *)(iRam0070d1c0 + 0x1f) + 2;
          uVar11 = uVar8 & 1;
          cVar3 = (char)uVar11;
          if (((int)uVar8 < 0) && (uVar11 != 0)) {
            cVar3 = cVar3 + -2;
          }
          *(char *)(iRam0070d1c0 + 0x1f) = cVar3;
          thunk_EXT_FUN_001b0100();
        }
      }
      else if (*(char *)(iRam0070d1c0 + 0x1f) == '\0') {
        *pcVar4 = '\x06';
        *(undefined1 *)(iRam0070d1c0 + 0x4e) = 0;
        thunk_EXT_FUN_001b00f0();
      }
      else {
        *pcVar4 = cVar3 + '\x01';
        thunk_EXT_FUN_001b00e0();
        *(undefined1 *)(iRam0070d1c0 + 0x20) = 10;
        *(undefined1 *)(iRam0070d1c0 + 0x4e) = 0x32;
        FUN_00615470();
      }
    }
    else {
      *pcVar4 = '\x06';
      *(undefined1 *)(iRam0070d1c0 + 0x4e) = 0;
      thunk_EXT_FUN_001b00f0();
    }
    break;
  case '\t':
    lVar6 = FUN_006186d0(iRam0070d1c0 + 0x10d8);
    if (lVar6 != -2) {
      thunk_EXT_FUN_001b00e0();
      if (lVar6 == -5) {
        *(undefined1 *)(iRam0070d1c0 + 0x20) = 0xd;
        *(undefined1 *)(iRam0070d1c0 + 0x4e) = 9;
      }
      else if (lVar6 == -6) {
        *(undefined1 *)(iRam0070d1c0 + 0x20) = 0xd;
        *(undefined1 *)(iRam0070d1c0 + 0x4e) = 0x1f;
      }
      else if ((lVar6 == -7) || (lVar6 == -3)) {
        *(undefined1 *)(iRam0070d1c0 + 0x20) = 0xd;
        *(undefined1 *)(iRam0070d1c0 + 0x4e) = 0x14;
      }
      else if (lVar6 == -1) {
        *(undefined1 *)(iRam0070d1c0 + 0x20) = 10;
        *(undefined1 *)(iRam0070d1c0 + 0x4e) = 0x13;
      }
      else {
        *(undefined1 *)(iRam0070d1c0 + 0x20) = 0xd;
        *(undefined1 *)(iRam0070d1c0 + 0x4e) = 0x22;
      }
    }
    break;
  case '\n':
    if (((uRam003433b0 & 0x10) != 0) || ((uRam003433b0 & 0x200) != 0)) {
      *pcVar4 = '\0';
      *(undefined1 *)(iRam0070d1c0 + 0x4e) = 0;
      thunk_EXT_FUN_001b00e0();
      return 0xfffffffe;
    }
    break;
  case '\v':
    lVar6 = FUN_00614ad0();
    if (lVar6 != 0) {
      *(undefined1 *)(iRam0070d1c0 + 0x20) = *(undefined1 *)(iRam0070d1c0 + 0x21);
    }
    break;
  case '\f':
    *(undefined1 *)(iRam0070d1c0 + 0x41) = 2;
    if ((uRam003433b0 & 0x200) == 0) {
      if ((uRam003433b0 & 0x10) == 0) {
        if ((uRam003433b0 & 0xc) == 0) {
          uVar11 = uRam003433b0 | *(uint *)(iRam0070d1c0 + 0x30);
          if ((uVar11 & 3) != 0) {
            uVar1 = *(ushort *)(iRam0070d1c0 + 0x48);
            uVar9 = (uint)**(ushort **)(iRam0070d1c0 + 0x44);
            uVar8 = (uVar9 / uVar1) % 10;
            iVar13 = uVar1 * uVar8;
            do {
              if ((uVar11 & 2) != 0) {
                uVar8 = (int)(uVar8 + 9) % 10;
              }
              if ((uVar11 & 1) != 0) {
                uVar8 = (int)(uVar8 + 0xb) % 10;
              }
              uVar5 = (uVar9 - iVar13) + uVar8 * uVar1;
            } while (0xffff < uVar5);
            **(ushort **)(iRam0070d1c0 + 0x44) = (ushort)uVar5;
            thunk_EXT_FUN_001b0100();
          }
        }
        else {
          if ((uRam003433b0 & 4) != 0) {
            if (*(short *)(iRam0070d1c0 + 0x48) != 10000) {
              *(short *)(iRam0070d1c0 + 0x48) = *(short *)(iRam0070d1c0 + 0x48) * 10;
              *(char *)(iRam0070d1c0 + 0x40) = *(char *)(iRam0070d1c0 + 0x40) + '\x01';
            }
          }
          if ((uRam003433b0 & 8) != 0) {
            if (*(ushort *)(iRam0070d1c0 + 0x48) != 1) {
              *(ushort *)(iRam0070d1c0 + 0x48) = *(ushort *)(iRam0070d1c0 + 0x48) / 10;
              *(char *)(iRam0070d1c0 + 0x40) = *(char *)(iRam0070d1c0 + 0x40) + -1;
            }
          }
          thunk_EXT_FUN_001b0100();
        }
      }
      else {
        *(undefined1 *)(iRam0070d1c0 + 0x20) = *(undefined1 *)(iRam0070d1c0 + 0x21);
        *(undefined1 *)(iRam0070d1c0 + 0x40) = 0;
        thunk_EXT_FUN_001b00e0();
      }
    }
    else {
      *(undefined1 *)(iRam0070d1c0 + 0x20) = *(undefined1 *)(iRam0070d1c0 + 0x21);
      **(undefined2 **)(iRam0070d1c0 + 0x44) = *(undefined2 *)(iRam0070d1c0 + 0x42);
      *(undefined1 *)(iRam0070d1c0 + 0x40) = 0;
      thunk_EXT_FUN_001b00f0();
    }
    break;
  case '\r':
    bVar12 = false;
    if (*(char *)(iRam0070d1c0 + 0x4b) == '\x01') {
      if ((uRam003433b0 & 0x10) != 0) {
        bVar12 = true;
      }
    }
    else if (((uRam003433b0 & 0x10) != 0) || ((uRam003433b0 & 0x200) != 0)) {
      bVar12 = true;
    }
    if (bVar12) {
      *pcVar4 = *(char *)(iRam0070d1c0 + 0x21);
      *(undefined1 *)(iRam0070d1c0 + 0x4e) = 0;
      thunk_EXT_FUN_001b00e0();
    }
    break;
  case '\x0e':
    if ((uRam003433b0 & 0x200) == 0) {
      if ((uRam003433b0 & 0x10) == 0) {
        if ((uRam003433b0 & 3) != 0) {
          if ((uRam003433b0 & 1) != 0) {
            *(char *)(iRam0070d1c0 + 0x1f) = *(char *)(iRam0070d1c0 + 0x1f) + -1;
          }
          if ((uRam003433b0 & 2) != 0) {
            *(char *)(iRam0070d1c0 + 0x1f) = *(char *)(iRam0070d1c0 + 0x1f) + '\x01';
          }
          uVar8 = (int)*(char *)(iRam0070d1c0 + 0x1f) + 2;
          uVar11 = uVar8 & 1;
          cVar3 = (char)uVar11;
          if (((int)uVar8 < 0) && (uVar11 != 0)) {
            cVar3 = cVar3 + -2;
          }
          *(char *)(iRam0070d1c0 + 0x1f) = cVar3;
          thunk_EXT_FUN_001b0100();
        }
      }
      else {
        if (*(char *)(iRam0070d1c0 + 0x1f) != '\0') {
          *pcVar4 = '\0';
          thunk_EXT_FUN_001b00e0();
          *(undefined1 *)(iRam0070d1c0 + 0x4e) = 0;
          return 0xfffffffe;
        }
        *pcVar4 = *(char *)(iRam0070d1c0 + 0x21);
        *(undefined1 *)(iRam0070d1c0 + 0x4e) = 0;
        thunk_EXT_FUN_001b00f0();
      }
    }
    else {
      *pcVar4 = *(char *)(iRam0070d1c0 + 0x21);
      *(undefined1 *)(iRam0070d1c0 + 0x4e) = 0;
      thunk_EXT_FUN_001b00f0();
    }
    break;
  case '\x0f':
    *(undefined1 *)(iRam0070d1c0 + 0x4b) = 2;
    if (((uRam003433b0 & 0x10) != 0) || ((uRam003433b0 & 0x200) != 0)) {
      *(undefined1 *)(iRam0070d1c0 + 0x20) = 0;
      *(undefined1 *)(iRam0070d1c0 + 0x4e) = 0;
      thunk_EXT_FUN_001b00e0();
      return 0xfffffffe;
    }
    break;
  case '\x10':
    if ((uRam003433b0 & 0x200) == 0) {
      if ((uRam003433b0 & 0x10) == 0) {
        if ((uRam003433b0 & 3) != 0) {
          if ((uRam003433b0 & 1) != 0) {
            *(char *)(iRam0070d1c0 + 0x1f) = *(char *)(iRam0070d1c0 + 0x1f) + -1;
          }
          if ((uRam003433b0 & 2) != 0) {
            *(char *)(iRam0070d1c0 + 0x1f) = *(char *)(iRam0070d1c0 + 0x1f) + '\x01';
          }
          uVar8 = (int)*(char *)(iRam0070d1c0 + 0x1f) + 2;
          uVar11 = uVar8 & 1;
          cVar3 = (char)uVar11;
          if (((int)uVar8 < 0) && (uVar11 != 0)) {
            cVar3 = cVar3 + -2;
          }
          *(char *)(iRam0070d1c0 + 0x1f) = cVar3;
          thunk_EXT_FUN_001b0100();
        }
      }
      else if (*(char *)(iRam0070d1c0 + 0x1f) == '\0') {
        *pcVar4 = '\x02';
        *(undefined1 *)(iRam0070d1c0 + 0x4e) = 0;
        thunk_EXT_FUN_001b00f0();
      }
      else {
        *pcVar4 = '\x11';
        *(undefined1 *)(iRam0070d1c0 + 0x4e) = 0xb;
        thunk_EXT_FUN_001b00e0();
        FUN_00618210(iRam0070d1c0 + 0x10d8);
      }
    }
    else {
      *pcVar4 = '\x02';
      *(undefined1 *)(iRam0070d1c0 + 0x4e) = 0;
      thunk_EXT_FUN_001b00f0();
    }
    break;
  case '\x11':
    lVar6 = FUN_00618460(iRam0070d1c0 + 0x10d8);
    if (lVar6 == -1) {
      *(undefined1 *)(iRam0070d1c0 + 0x20) = 0xd;
      *(undefined1 *)(iRam0070d1c0 + 0x21) = 5;
      *(undefined1 *)(iRam0070d1c0 + 0x4e) = 0xc;
      FUN_00618210(iRam0070d1c0 + 0x10d8);
      thunk_EXT_FUN_001b00e0();
    }
    else if (lVar6 != -2) {
      *(undefined1 *)(iRam0070d1c0 + 0x20) = 0xd;
      *(undefined1 *)(iRam0070d1c0 + 0x21) = 2;
      *(undefined1 *)(iRam0070d1c0 + 0x4e) = 0xd;
      FUN_00618210(iRam0070d1c0 + 0x10d8);
      thunk_EXT_FUN_001b00e0();
    }
    break;
  case '\x12':
    uVar7 = FUN_0060e1c0(iRam0070d1c0 + 0x1180,
                         iRam0070d1c0 + *(char *)(iRam0070d1c0 + 0x13) * 0x1340 + 0xaf00);
    FUN_00614960(iRam0070d1c0 + 0x1acb4,uVar7);
    if (((char *)(iRam0070d1c0 + 0x1acb4) == (char *)0x0) ||
       (*(char *)(iRam0070d1c0 + 0x1acb4) == '\0')) {
      *(undefined1 *)(iRam0070d1c0 + 0x20) = 0xd;
      *(undefined1 *)(iRam0070d1c0 + 0x21) = 1;
      *(undefined1 *)(iRam0070d1c0 + 0x4e) = 0x1e;
      thunk_EXT_FUN_001b00e0();
    }
    else {
      lVar6 = FUN_0060ef20(iRam0070d1c0 + 0x1180);
      if (lVar6 == 0) {
        lVar6 = FUN_0060ee80(iRam0070d1c0 + 0x1180);
        if (lVar6 == 0) {
          lVar6 = FUN_0060f1b0(iRam0070d1c0 + *(char *)(iRam0070d1c0 + 0x13) * 0x14 + 600);
          if (lVar6 == 0) {
            *(undefined1 *)(iRam0070d1c0 + 0x20) = 1;
            thunk_EXT_FUN_001b0110();
          }
          else {
            iVar13 = *(char *)(iRam0070d1c0 + 0x13) * 0x14;
            if ((((*(int *)(iVar13 + iRam0070d1c0 + 600) == 1) &&
                 (iVar10 = *(char *)(iRam0070d1c0 + 0x13) * 0x1340 + iRam0070d1c0,
                 *(char *)(iVar10 + 0xb700) != '\0')) && (*(int *)(iVar10 + 0xc200) == 2)) &&
               (*(char *)(iVar10 + 0xc225) == -1)) {
              *(undefined1 *)(iRam0070d1c0 + 0x20) = 0xf;
              *(undefined1 *)(iRam0070d1c0 + 0x4e) = 0x1b;
              thunk_EXT_FUN_001b00e0();
            }
            else if (*(int *)(iVar13 + iRam0070d1c0 + 0x25c) < 0) {
              *(undefined1 *)(iRam0070d1c0 + 0x20) = 0xd;
              *(undefined1 *)(iRam0070d1c0 + 0x21) = 1;
              *(undefined1 *)(iRam0070d1c0 + 0x4e) = 5;
              thunk_EXT_FUN_001b00e0();
            }
            else {
              lVar6 = FUN_0060f2c0();
              if (-1 < lVar6) {
                lVar6 = FUN_0060e9b0(iRam0070d1c0 + 0xed0,0x3ca2d0);
                if (lVar6 < 0) {
                  *(undefined1 *)(iRam0070d1c0 + 0x2e) = 1;
                }
                lVar6 = FUN_0060e820(0x3c98b0,iRam0070d1c0 + *(char *)(iRam0070d1c0 + 0x13) * 0x14 +
                                              600,1);
                if (lVar6 < 0) {
                  *(undefined1 *)(iRam0070d1c0 + 0x2e) = 1;
                }
                FUN_006153b0(*(undefined4 *)
                              (*(char *)(iRam0070d1c0 + 0x13) * 0x14 + iRam0070d1c0 + 0x268));
                FUN_006150b0(*(undefined4 *)
                              (*(char *)(iRam0070d1c0 + 0x13) * 0x14 + iRam0070d1c0 + 0x268));
                return 1;
              }
              *(undefined1 *)(iRam0070d1c0 + 0x20) = 0xd;
              *(undefined1 *)(iRam0070d1c0 + 0x21) = 1;
              *(undefined1 *)(iRam0070d1c0 + 0x4e) = 5;
              thunk_EXT_FUN_001b00e0();
            }
          }
        }
        else {
          *(undefined1 *)(iRam0070d1c0 + 0x20) = 0xf;
          *(undefined1 *)(iRam0070d1c0 + 0x4e) = 0x1e;
          thunk_EXT_FUN_001b00e0();
        }
      }
      else {
        *(undefined1 *)(iRam0070d1c0 + 0x20) = 0xf;
        *(undefined1 *)(iRam0070d1c0 + 0x4e) = 0x1d;
        thunk_EXT_FUN_001b00e0();
      }
    }
    break;
  case '\x13':
    if ((uRam003433b0 & 0x200) == 0) {
      if ((uRam003433b0 & 0x10) == 0) {
        if ((uRam003433b0 & 3) != 0) {
          if ((uRam003433b0 & 1) != 0) {
            *(char *)(iRam0070d1c0 + 0x1f) = *(char *)(iRam0070d1c0 + 0x1f) + -1;
          }
          if ((uRam003433b0 & 2) != 0) {
            *(char *)(iRam0070d1c0 + 0x1f) = *(char *)(iRam0070d1c0 + 0x1f) + '\x01';
          }
          uVar8 = (int)*(char *)(iRam0070d1c0 + 0x1f) + 2;
          uVar11 = uVar8 & 1;
          cVar3 = (char)uVar11;
          if (((int)uVar8 < 0) && (uVar11 != 0)) {
            cVar3 = cVar3 + -2;
          }
          *(char *)(iRam0070d1c0 + 0x1f) = cVar3;
          thunk_EXT_FUN_001b0100();
        }
      }
      else {
        if (*(char *)(iRam0070d1c0 + 0x1f) != '\0') {
          *pcVar4 = '\0';
          *(undefined1 *)(iRam0070d1c0 + 0x4e) = 0;
          thunk_EXT_FUN_001b00e0();
          return 2;
        }
        *pcVar4 = '\x01';
        *(undefined1 *)(iRam0070d1c0 + 0x4e) = 0;
        thunk_EXT_FUN_001b00f0();
      }
    }
    else {
      *pcVar4 = '\x01';
      *(undefined1 *)(iRam0070d1c0 + 0x4e) = 0;
      thunk_EXT_FUN_001b00f0();
    }
  }
  return 0;
}



================================================================