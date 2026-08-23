FUNCTION FUN_00612120 @ 0x00612120  size=2496
CALLERS (1): FUN_00614b90@0x00614b90
CALLEES (2): FUN_0060ea60@0x0060ea60, FUN_00614c80@0x00614c80
----------------------------------------------------------------

void FUN_00612120(void)

{
  char cVar1;
  long lVar2;
  int iVar3;
  
  switch(*(undefined1 *)(iRam0070d1c0 + 0x4a)) {
  case 0:
    return;
  case 1:
    FUN_00614c80(5,0,0);
    if ('\x02' < *(char *)(iRam0070d1c0 + 0x24)) {
      FUN_00614c80(0x1f,0,0);
    }
    cVar1 = *(char *)(iRam0070d1c0 + 0x10);
    if (cVar1 < '\x02') {
      FUN_00614c80(7,0,(cVar1 * 0xc + (short)cVar1) * 2);
    }
    else {
      FUN_00614c80(7,0,((short)*(char *)(iRam0070d1c0 + 0x13) -
                       (short)*(char *)(iRam0070d1c0 + 0x14)) * 0x1a + 0x3f);
    }
    break;
  case 2:
    FUN_00614c80(0x21,0,0);
    FUN_00614c80(8,0,*(char *)(iRam0070d1c0 + 0x10) * 0x28);
    break;
  case 3:
    FUN_00614c80(10,0,0);
    FUN_00614c80(0xb,0,0);
    FUN_00614c80(9,0,*(char *)(iRam0070d1c0 + 0x11) * 0x38);
    break;
  case 4:
    FUN_00614c80(0xb,0,0);
    FUN_00614c80(0x12,0,((short)*(char *)(iRam0070d1c0 + 0x12) -
                        (short)*(char *)(iRam0070d1c0 + 0x1d)) * 0x1c);
    break;
  case 5:
    FUN_00614c80(0xb,0,0);
    FUN_00614c80(0xd,0,0);
    FUN_00614c80(0x13,0,(ushort)*(byte *)(iRam0070d1c0 + 0x4b5) * 0x38);
    FUN_00614c80(0x14,0,*(char *)(iRam0070d1c0 + 0x13) * 0x38);
    break;
  case 6:
    FUN_00614c80(0xb,0,0);
    FUN_00614c80(0xc,0,0);
    if ((*(char *)(iRam0070d1c0 + 0x4bc) != '\0') && (*(char *)(iRam0070d1c0 + 0x6bc) != '\0')) {
      FUN_00614c80(0xd,0,0);
    }
    FUN_00614c80(0x12,0,*(char *)(iRam0070d1c0 + 0x14) * 0x38);
    break;
  case 7:
    FUN_00614c80(0xb,0,0);
    FUN_00614c80(0xc,0,0);
    FUN_00614c80(0xd,0,0);
    FUN_00614c80(0x18,0,(ushort)*(byte *)(iRam0070d1c0 + 0x4b6) * 0x38);
    FUN_00614c80(0x19,0,*(char *)(iRam0070d1c0 + 0x15) * 0x38);
    break;
  case 8:
    FUN_00614c80(0xb,0,0);
    FUN_00614c80(0xc,0,0);
    lVar2 = FUN_0060ea60(iRam0070d1c0 + 0xabc);
    if (((lVar2 != 0) && (lVar2 = FUN_0060ea60(iRam0070d1c0 + 0xac0), lVar2 != 0)) &&
       (lVar2 = FUN_0060ea60(iRam0070d1c0 + 0xac4), lVar2 != 0)) {
      FUN_00614c80(0xd,0,0);
    }
    if (*(char *)(iRam0070d1c0 + 0x41) == '\0') {
      FUN_00614c80(0x12,0,*(char *)(iRam0070d1c0 + 0x16) * 0x1c);
    }
    else {
      FUN_00614c80(0x17,*(char *)(iRam0070d1c0 + 0x40) * 0x38 -
                        (short)*(char *)(iRam0070d1c0 + 0x40),*(char *)(iRam0070d1c0 + 0x16) * 0x1c)
      ;
    }
    break;
  case 9:
    FUN_00614c80(0xb,0,0);
    FUN_00614c80(0xc,0,0);
    FUN_00614c80(0xd,0,0);
    FUN_00614c80(0x18,0,(ushort)*(byte *)(iRam0070d1c0 + 0x4b7) * 0x38);
    FUN_00614c80(0x19,0,*(char *)(iRam0070d1c0 + 0x17) * 0x38);
    break;
  case 10:
    FUN_00614c80(0xb,0,0);
    FUN_00614c80(0xc,0,0);
    lVar2 = FUN_0060ea60(iRam0070d1c0 + 0xac8);
    if (lVar2 != 0) {
      FUN_00614c80(0xd,0,0);
    }
    if (*(char *)(iRam0070d1c0 + 0x41) == '\0') {
      FUN_00614c80(0x12,0,*(char *)(iRam0070d1c0 + 0x18) * 0x38);
    }
    else {
      FUN_00614c80(0x17,*(char *)(iRam0070d1c0 + 0x40) * 0x38 -
                        (short)*(char *)(iRam0070d1c0 + 0x40),*(char *)(iRam0070d1c0 + 0x18) * 0x38)
      ;
    }
    break;
  case 0xb:
    FUN_00614c80(0xb,0,0);
    FUN_00614c80(0xc,0,0);
    if (*(char *)(iRam0070d1c0 + 0xad0) != '\0') {
      FUN_00614c80(0xd,0,0);
    }
    FUN_00614c80(0x12,0,0x1c);
    break;
  case 0xc:
    FUN_00614c80(10,0,0);
    break;
  case 0xd:
    FUN_00614c80(0xb,0,0);
    if ('\x03' < *(char *)(iRam0070d1c0 + 0x24)) {
      FUN_00614c80(0xe,0,0);
      FUN_00614c80(0xf,0,0);
    }
    FUN_00614c80(0x12,0,((short)*(char *)(iRam0070d1c0 + 0x19) -
                        (short)*(char *)(iRam0070d1c0 + 0x1e)) * 0x1c);
    break;
  case 0xe:
    FUN_00614c80(0xb,0,0);
    FUN_00614c80(0xc,0,0);
    FUN_00614c80(0xd,0,0);
    FUN_00614c80(0x12,0,0x1c);
    break;
  case 0xf:
    FUN_00614c80(0xb,0,0);
    FUN_00614c80(0xd,0,0);
    FUN_00614c80(0x13,0,(1 - (short)*(undefined4 *)(iRam0070d1c0 + 0xed0)) * 0x38);
    FUN_00614c80(0x14,0,*(char *)(iRam0070d1c0 + 0x15) * 0x38);
    break;
  case 0x10:
    FUN_00614c80(0xb,0,0);
    FUN_00614c80(0xc,0,0);
    if ((*(char *)(iRam0070d1c0 + 0xed8) != '\0') && (*(short *)(iRam0070d1c0 + 0xed4) != 0)) {
      FUN_00614c80(0xd,0,0);
    }
    cVar1 = *(char *)(iRam0070d1c0 + 0x41);
    if (cVar1 == '\x02') {
      FUN_00614c80(0x1c,0x60,*(char *)(iRam0070d1c0 + 0x16) * 0x18 + -0x18);
      FUN_00614c80(0x1d,0x76 - (*(char *)(iRam0070d1c0 + 0x40) * 10 +
                               (short)*(char *)(iRam0070d1c0 + 0x40)),
                   *(char *)(iRam0070d1c0 + 0x16) * 0x18 + -0x18);
    }
    else if ((cVar1 == '\x01') || (cVar1 == '\0')) {
      FUN_00614c80(0x12,0,*(char *)(iRam0070d1c0 + 0x16) * 0x18 + -10);
    }
    break;
  case 0x11:
    FUN_00614c80(0xb,0,0);
    FUN_00614c80(0xd,0,0);
    FUN_00614c80(0xe,0,0);
    FUN_00614c80(0xf,0,0);
    iVar3 = (uint)*(byte *)(iRam0070d1c0 + 0x4b8) - (int)*(char *)(iRam0070d1c0 + 0x1c);
    if ((-1 < iVar3) && (iVar3 < 3)) {
      FUN_00614c80(0x10,0,(short)iVar3 * 0x1c);
    }
    FUN_00614c80(0x11,0,((short)*(char *)(iRam0070d1c0 + 0x1a) -
                        (short)*(char *)(iRam0070d1c0 + 0x1c)) * 0x1c);
    break;
  default:
    goto switchD_00612154_default;
  }
  FUN_00614c80(4,0,0);
  FUN_00614c80(6,0,0);
switchD_00612154_default:
  return;
}



================================================================