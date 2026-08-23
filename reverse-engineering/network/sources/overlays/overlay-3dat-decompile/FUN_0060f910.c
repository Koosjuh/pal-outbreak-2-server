FUNCTION FUN_0060f910 @ 0x0060f910  size=2192
CALLERS (1): FUN_00623090@0x00623090
CALLEES (28): FUN_00610580@0x00610580, FUN_00614790@0x00614790, FUN_00610830@0x00610830, thunk_EXT_FUN_001b0100@0x006187a0, FUN_006149d0@0x006149d0, FUN_00612d10@0x00612d10, FUN_00614b80@0x00614b80, thunk_EXT_FUN_001b00e0@0x006187b0, FUN_00634550@0x00634550, FUN_00615430@0x00615430, thunk_EXT_FUN_001af020@0x00614780, thunk_EXT_FUN_001af0a0@0x00614770, ...
----------------------------------------------------------------

int FUN_0060f910(void)

{
  char cVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  uint uVar4;
  long lVar5;
  uint uVar6;
  
  FUN_00614b80();
  switch(iRam0070d1d8) {
  case 0:
    FUN_006187f0();
    if (iRam0035b9e0 != -1) {
      func_0x001d4de0();
      func_0x001ca780();
      iRam0035b9e0 = -1;
    }
    FUN_0060f170();
    iRam0070d1c0 = iRam003435bc;
    func_0x00106b60(iRam003435bc,0,0x1af00);
    FUN_0060e060(iRam0070d1c0 + 0x1180);
    *(undefined4 *)(iRam0070d1c0 + 8) = uRam00715430;
    *(undefined4 *)(iRam0070d1c0 + 0xc) = uRam00715434;
    FUN_00615430();
    if (iRam0070d1d0 == 0) {
      func_0x001a7b70(0x14,0xffffffffff000000);
      iRam0070d1d8 = 1;
    }
    else {
      iRam0070d1d8 = 2;
    }
    FUN_00634550(uRam0034359d);
    *(undefined1 *)(iRam0070d1c0 + 0x4e) = 0x38;
    break;
  case 1:
    *(char *)(iRam0070d1c0 + 0x29) = *(char *)(iRam0070d1c0 + 0x29) + '\x01';
    lVar5 = FUN_006101d0();
    if (lVar5 == -3) {
      iRam0070d1d8 = 9;
      *(undefined1 *)(iRam0070d1c0 + 0x2c) = 0;
      *(undefined1 *)(iRam0070d1c0 + 0x10) = 0;
      *(undefined1 *)(iRam0070d1c0 + 0x1f) = 0;
      *(undefined1 *)(iRam0070d1c0 + 0x4e) = 0x1d;
      thunk_EXT_FUN_001b00e0();
      *(undefined1 *)(iRam0070d1c0 + 0x4a) = 1;
      *(undefined1 *)(iRam0070d1c0 + 0x4b) = 2;
      *(undefined1 *)(iRam0070d1c0 + 0x4c) = 1;
      *(undefined1 *)(iRam0070d1c0 + 0x4d) = 1;
      *(undefined1 *)(iRam0070d1c0 + 0x4f) = 1;
      *(undefined1 *)(iRam0070d1c0 + 0x50) = 0;
    }
    else if (lVar5 == -2) {
      iRam0070d1d8 = 8;
      *(undefined1 *)(iRam0070d1c0 + 0x4e) = 6;
      *(undefined1 *)(iRam0070d1c0 + 0x1f) = 0;
      *(undefined1 *)(iRam0070d1c0 + 0x4a) = 1;
      *(undefined1 *)(iRam0070d1c0 + 0x4b) = 2;
      *(undefined1 *)(iRam0070d1c0 + 0x4c) = 1;
      *(undefined1 *)(iRam0070d1c0 + 0x4d) = 1;
      *(undefined1 *)(iRam0070d1c0 + 0x4f) = 1;
      *(undefined1 *)(iRam0070d1c0 + 0x50) = 0;
      thunk_EXT_FUN_001b00e0();
    }
    else if (lVar5 == -1) {
      iRam0070d1d8 = 5;
      *(undefined1 *)(iRam0070d1c0 + 0x2c) = 0;
      *(undefined1 *)(iRam0070d1c0 + 0x10) = 0;
      *(undefined1 *)(iRam0070d1c0 + 0x4e) = 0;
    }
    else if (lVar5 == 1) {
      iRam0070d1d8 = 5;
      *(undefined1 *)(iRam0070d1c0 + 0x2c) = 0;
      *(undefined1 *)(iRam0070d1c0 + 0x10) = 0;
      *(undefined1 *)(iRam0070d1c0 + 0x4e) = 0;
    }
    break;
  case 2:
    *(char *)(iRam0070d1c0 + 0x29) = *(char *)(iRam0070d1c0 + 0x29) + '\x01';
    uVar3 = FUN_00610580();
    switch(uVar3) {
    case 1:
      iRam0070d1d8 = 6;
      *(undefined1 *)(iRam0070d1c0 + 0x20) = 0;
      *(undefined1 *)(iRam0070d1c0 + 0x4a) = 0;
      *(undefined1 *)(iRam0070d1c0 + 0x4b) = 0;
      *(undefined1 *)(iRam0070d1c0 + 0x4c) = 0;
      *(undefined1 *)(iRam0070d1c0 + 0x4d) = 0;
      *(undefined1 *)(iRam0070d1c0 + 0x4f) = 0;
      *(undefined1 *)(iRam0070d1c0 + 0x50) = 0;
      break;
    case 0xfffffffb:
      iRam0070d1d8 = 8;
      *(undefined1 *)(iRam0070d1c0 + 0x4e) = 0x1d;
      thunk_EXT_FUN_001b00e0();
      break;
    case 0xfffffffc:
      iRam0070d1d8 = 8;
      *(undefined1 *)(iRam0070d1c0 + 0x4e) = 0x2b;
      thunk_EXT_FUN_001b00e0();
      break;
    case 0xfffffffd:
      iRam0070d1d8 = 8;
      *(undefined1 *)(iRam0070d1c0 + 0x4e) = 5;
      thunk_EXT_FUN_001b00e0();
      break;
    case 0xfffffffe:
      iRam0070d1d8 = 8;
      *(undefined1 *)(iRam0070d1c0 + 0x4e) = 6;
      thunk_EXT_FUN_001b00e0();
      break;
    case 0xffffffff:
      iRam0070d1d8 = 8;
      *(undefined1 *)(iRam0070d1c0 + 0x4e) = 0x2b;
      thunk_EXT_FUN_001b00e0();
    }
    break;
  case 3:
    FUN_006154b0();
    break;
  case 5:
    *(char *)(iRam0070d1c0 + 0x29) = *(char *)(iRam0070d1c0 + 0x29) + '\x01';
    *(undefined1 *)(iRam0070d1c0 + 0x41) = 0;
    FUN_006149d0(0x3433b0);
    lVar5 = FUN_00610830();
    if (lVar5 == -2) {
      iRam0070d1d8 = 1;
      *(undefined1 *)(iRam0070d1c0 + 0x20) = 0;
    }
    else if (lVar5 == -1) {
      iRam0070d1d8 = 7;
      *(undefined1 *)(iRam0070d1c0 + 0x20) = 0;
      *(undefined1 *)(iRam0070d1c0 + 0x4e) = 0x1a;
      *(undefined1 *)(iRam0070d1c0 + 0x10) = 0;
      *(undefined1 *)(iRam0070d1c0 + 0x1f) = 0;
      thunk_EXT_FUN_001b00e0();
    }
    else if (lVar5 == 2) {
      iRam0070d1d8 = 3;
      *(undefined1 *)(iRam0070d1c0 + 0x20) = 0;
      *(undefined1 *)(iRam0070d1c0 + 0x10) = 0;
      *(undefined1 *)(iRam0070d1c0 + 0x4e) = 0x1a;
      *(undefined1 *)(iRam0070d1c0 + 0x1f) = 0;
      thunk_EXT_FUN_001b00e0();
    }
    else if (lVar5 == 1) {
      iRam0070d1d8 = 6;
      *(undefined1 *)(iRam0070d1c0 + 0x20) = 0;
      *(undefined1 *)(iRam0070d1c0 + 0x4a) = 0;
      *(undefined1 *)(iRam0070d1c0 + 0x4b) = 0;
      *(undefined1 *)(iRam0070d1c0 + 0x4c) = 0;
      *(undefined1 *)(iRam0070d1c0 + 0x4d) = 0;
      *(undefined1 *)(iRam0070d1c0 + 0x4f) = 0;
      *(undefined1 *)(iRam0070d1c0 + 0x50) = 0;
    }
    break;
  case 6:
    FUN_006101a0();
    return *(byte *)(iRam0070d1c0 + 0x2e) + 1;
  case 7:
    *(undefined1 *)(iRam0070d1c0 + 0x4b) = 2;
    *(char *)(iRam0070d1c0 + 0x29) = *(char *)(iRam0070d1c0 + 0x29) + '\x01';
    if ((uRam003433b0 & 0x200) == 0) {
      if ((uRam003433b0 & 0x10) == 0) {
        if ((uRam003433b0 & 3) != 0) {
          if ((uRam003433b0 & 1) != 0) {
            *(char *)(iRam0070d1c0 + 0x1f) = *(char *)(iRam0070d1c0 + 0x1f) + -1;
          }
          if ((uRam003433b0 & 2) != 0) {
            *(char *)(iRam0070d1c0 + 0x1f) = *(char *)(iRam0070d1c0 + 0x1f) + '\x01';
          }
          uVar6 = (int)*(char *)(iRam0070d1c0 + 0x1f) + 2;
          uVar4 = uVar6 & 1;
          cVar1 = (char)uVar4;
          if (((int)uVar6 < 0) && (uVar4 != 0)) {
            cVar1 = cVar1 + -2;
          }
          *(char *)(iRam0070d1c0 + 0x1f) = cVar1;
          thunk_EXT_FUN_001b0100();
        }
      }
      else {
        if (*(char *)(iRam0070d1c0 + 0x1f) != '\0') {
          thunk_EXT_FUN_001b00e0();
          FUN_006101a0();
          return -1;
        }
        *(undefined1 *)(iRam0070d1c0 + 0x4e) = 0;
        thunk_EXT_FUN_001b00f0();
        iRam0070d1d8 = 5;
      }
    }
    else {
      *(undefined1 *)(iRam0070d1c0 + 0x4e) = 0;
      thunk_EXT_FUN_001b00f0();
      iRam0070d1d8 = 5;
    }
    break;
  case 8:
    *(char *)(iRam0070d1c0 + 0x29) = *(char *)(iRam0070d1c0 + 0x29) + '\x01';
    if (((uRam003433b0 & 0x10) != 0) || ((uRam003433b0 & 0x200) != 0)) {
      thunk_EXT_FUN_001b00e0();
      FUN_006101a0();
      uRam007152e8 = 0;
      return -1;
    }
    break;
  case 9:
    if (((uRam003433b0 & 0x10) != 0) || ((uRam003433b0 & 0x200) != 0)) {
      iRam0070d1d8 = 5;
      *(undefined1 *)(iRam0070d1c0 + 0x4e) = 0;
      thunk_EXT_FUN_001b00e0();
    }
  }
  if (iRam0070d1d8 != 3) {
    uVar2 = FUN_00614790();
    *(undefined1 *)(iRam0070d1c0 + 0x22) = uVar2;
    thunk_EXT_FUN_001af020(1);
    FUN_00614720(0xffffffff80808080);
    FUN_00614750(0x16,0x16);
    thunk_EXT_FUN_001af0a0(0xffffffffffffffe0);
    FUN_00612ca0();
    FUN_00612d10();
    FUN_00612b70();
    FUN_00613c30();
    FUN_00614600();
    FUN_00614b90();
    if (iRam0070d1c8 != 0) {
      FUN_00636890(0);
    }
    thunk_EXT_FUN_001af020(*(undefined1 *)(iRam0070d1c0 + 0x22));
  }
  return 0;
}



================================================================