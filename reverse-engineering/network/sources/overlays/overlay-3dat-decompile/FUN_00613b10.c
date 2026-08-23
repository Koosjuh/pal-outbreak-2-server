FUNCTION FUN_00613b10 @ 0x00613b10  size=284
CALLERS (1): FUN_00614b90@0x00614b90
CALLEES (1): FUN_00614c80@0x00614c80
----------------------------------------------------------------

void FUN_00613b10(void)

{
  switch(*(undefined1 *)(iRam0070d1c0 + 0x4e)) {
  case 1:
  case 3:
  case 4:
  case 10:
  case 0x18:
  case 0x1a:
  case 0x30:
  case 0x31:
  case 0x35:
  case 0x37:
    FUN_00614c80(0x1b,0,0);
    FUN_00614c80(0x1a,0,*(char *)(iRam0070d1c0 + 0x1f) * -0x1e);
    break;
  case 2:
  case 5:
  case 6:
  case 7:
  case 8:
  case 9:
  case 0xb:
  case 0xc:
  case 0xd:
  case 0xe:
  case 0xf:
  case 0x13:
  case 0x14:
  case 0x15:
  case 0x16:
  case 0x17:
  case 0x19:
  case 0x1b:
  case 0x1c:
  case 0x1d:
  case 0x1e:
  case 0x1f:
  case 0x20:
  case 0x21:
  case 0x22:
  case 0x24:
  case 0x2a:
  case 0x2b:
  case 0x2c:
  case 0x2d:
  case 0x2e:
  case 0x2f:
  case 0x32:
  case 0x33:
  case 0x34:
  case 0x36:
  case 0x38:
    FUN_00614c80(0x1b,0,0);
    return;
  case 0x10:
  case 0x11:
  case 0x12:
  case 0x25:
  case 0x26:
  case 0x27:
  case 0x28:
  case 0x29:
    FUN_00614c80(0x1b,0,0);
    if (*(char *)(iRam0070d1c0 + 0x23) != '\x03') {
      FUN_00614c80(0x1a,0,*(char *)(iRam0070d1c0 + 0x1f) * -0x1e);
    }
    break;
  case 0x23:
    FUN_00614c80(0x1b,0,0);
    FUN_00614c80(0x1e,0,0x24);
  }
  return;
}



================================================================