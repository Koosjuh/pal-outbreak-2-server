FUNCTION FUN_00613c30 @ 0x00613c30  size=368
CALLERS (1): FUN_0060f910@0x0060f910
CALLEES (6): FUN_006140d0@0x006140d0, thunk_EXT_FUN_001af0a0@0x00614770, FUN_00613e70@0x00613e70, FUN_00613f40@0x00613f40, FUN_00613da0@0x00613da0, FUN_00613fb0@0x00613fb0
----------------------------------------------------------------

void FUN_00613c30(void)

{
  thunk_EXT_FUN_001af0a0(0xfffffffffffffff0);
  switch(*(undefined1 *)(iRam0070d1c0 + 0x4e)) {
  case 1:
  case 2:
  case 3:
  case 4:
  case 5:
  case 6:
  case 7:
  case 0xc:
  case 0xd:
  case 0xe:
  case 0xf:
  case 0x13:
  case 0x14:
  case 0x15:
  case 0x16:
  case 0x17:
  case 0x18:
  case 0x1a:
  case 0x1b:
  case 0x1e:
  case 0x23:
  case 0x2b:
  case 0x2c:
  case 0x2d:
  case 0x2f:
  case 0x30:
  case 0x31:
  case 0x32:
  case 0x35:
  case 0x36:
  case 0x37:
  case 0x38:
    FUN_00613da0();
    goto LAB_00613d8c;
  case 8:
  case 0x1f:
  case 0x2e:
    FUN_00613fb0(3);
    break;
  case 9:
  case 10:
    FUN_00613fb0(0);
    break;
  case 0xb:
    FUN_00613fb0(2);
    break;
  case 0x10:
  case 0x11:
  case 0x12:
  case 0x25:
  case 0x26:
  case 0x27:
  case 0x28:
  case 0x29:
    if (*(char *)(iRam0070d1c0 + 0x23) == '\x03') {
      FUN_00613e70();
    }
    else {
      FUN_00613da0();
    }
    break;
  case 0x19:
    FUN_00613da0();
    FUN_006140d0();
    break;
  case 0x1c:
  case 0x33:
    FUN_00613fb0(1);
    break;
  case 0x1d:
    FUN_00613fb0(2);
    break;
  case 0x20:
    FUN_00613fb0(1);
    break;
  case 0x21:
    FUN_00613fb0(1);
    break;
  case 0x22:
    FUN_00613fb0(1);
    break;
  case 0x24:
  case 0x2a:
    FUN_00613f40(0);
    FUN_00613f40(1);
    if ((*(byte *)(iRam0070d1c0 + 0x29) & 0x20) != 0) {
      FUN_00613f40(2);
    }
    break;
  case 0x34:
    FUN_00613fb0(2);
  }
LAB_00613d8c:
  thunk_EXT_FUN_001af0a0(0xffffffffffffffe0);
  return;
}



================================================================