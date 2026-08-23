FUNCTION FUN_00610580 @ 0x00610580  size=680
CALLERS (1): FUN_0060f910@0x0060f910
CALLEES (9): FUN_006153b0@0x006153b0, FUN_006101d0@0x006101d0, thunk_EXT_FUN_001b00e0@0x006187e0, FUN_006150b0@0x006150b0, FUN_0060f2c0@0x0060f2c0, FUN_0060e820@0x0060e820, thunk_EXT_FUN_001b00e0@0x006187b0, FUN_0060e9b0@0x0060e9b0, FUN_0060ef20@0x0060ef20
----------------------------------------------------------------

undefined8 FUN_00610580(void)

{
  long lVar1;
  char *pcVar2;
  int iVar3;
  
  pcVar2 = (char *)(iRam0070d1c0 + 0x20);
  switch(*(char *)(iRam0070d1c0 + 0x20)) {
  case '\0':
    *pcVar2 = *(char *)(iRam0070d1c0 + 0x20) + '\x01';
    *(undefined1 *)(iRam0070d1c0 + 0x26) = 0;
    *(undefined1 *)(iRam0070d1c0 + 0x2d) = 0;
  case '\x01':
    lVar1 = FUN_0060e9b0(iRam0070d1c0 + 0xed0,0x3ca2d0);
    if (lVar1 < 0) {
      return 0xfffffffffffffffc;
    }
    *(char *)(iRam0070d1c0 + 0x20) = *(char *)(iRam0070d1c0 + 0x20) + '\x01';
    *(undefined1 *)(iRam0070d1c0 + 0x2c) = 0;
    break;
  case '\x02':
    lVar1 = FUN_006101d0();
    if (lVar1 == 1) {
      lVar1 = FUN_0060e820(0x3c98b0,iRam0070d1c0 + 600,*(undefined1 *)(iRam0070d1c0 + 0x24));
      if (lVar1 < 0) {
LAB_00610720:
        lVar1 = FUN_0060ef20(iRam0070d1c0 + 0x1180);
        if (lVar1 != 0) {
          return 0xfffffffffffffffb;
        }
        *(undefined1 *)(iRam0070d1c0 + 0x20) = 0;
        *(undefined1 *)(iRam0070d1c0 + 0x4e) = 0;
        return 0xffffffffffffffff;
      }
      iVar3 = (int)lVar1 * 0x14;
      if (*(int *)(iVar3 + iRam0070d1c0 + 0x25c) < 0) {
        return 0xfffffffffffffffd;
      }
      lVar1 = FUN_0060f2c0();
      if (lVar1 < 0) {
        return 0xfffffffffffffffd;
      }
      FUN_006153b0(*(undefined4 *)(iVar3 + iRam0070d1c0 + 0x268));
      FUN_006150b0(*(undefined4 *)(iVar3 + iRam0070d1c0 + 0x268));
      *(undefined1 *)(iRam0070d1c0 + 0x20) = 5;
      *(undefined1 *)(iRam0070d1c0 + 0x4e) = 0x34;
      thunk_EXT_FUN_001b00e0();
      *(undefined4 *)(iRam0070d1c0 + 0x1aec4) = 0x3c;
    }
    else {
      if (lVar1 == -2) {
        return 0xfffffffffffffffe;
      }
      if (lVar1 != 0) goto LAB_00610720;
    }
    break;
  case '\x03':
    *pcVar2 = '\0';
    *(undefined1 *)(iRam0070d1c0 + 0x4e) = 0;
    return 0xffffffffffffffff;
  case '\x04':
    if (((uRam003433b0 & 0x10) != 0) || ((uRam003433b0 & 0x200) != 0)) {
      *pcVar2 = '\0';
      *(undefined1 *)(iRam0070d1c0 + 0x4e) = 0;
      thunk_EXT_FUN_001b00e0();
      return 1;
    }
    break;
  case '\x05':
    if (iRam00715474 != 0) {
      iVar3 = *(int *)(iRam0070d1c0 + 0x1aec4);
      if (iVar3 < 1) goto LAB_006107f0;
      *(int *)(iRam0070d1c0 + 0x1aec4) = iVar3 + -1;
    }
    if ((uRam003433b0 & 0x10) == 0) {
      return 0;
    }
LAB_006107f0:
    *(undefined1 *)(iRam0070d1c0 + 0x20) = 0;
    *(undefined1 *)(iRam0070d1c0 + 0x4e) = 0;
    thunk_EXT_FUN_001b00e0();
    return 1;
  }
  return 0;
}



================================================================