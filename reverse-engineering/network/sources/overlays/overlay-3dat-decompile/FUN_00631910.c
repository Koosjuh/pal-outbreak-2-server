FUNCTION FUN_00631910 @ 0x00631910  size=288
CALLERS (4): FUN_00631cf0@0x00631cf0, FUN_00631ac0@0x00631ac0, FUN_00631bb0@0x00631bb0, FUN_00631c80@0x00631c80
CALLEES (1): FUN_00634470@0x00634470
----------------------------------------------------------------

void FUN_00631910(short param_1)

{
  char cVar1;
  
  cVar1 = *(char *)(iRam00715da8 + 0x2e);
  do {
    if (param_1 == 0) {
      if (*(byte *)(iRam00715da8 + 0x24) < 2) {
        *(char *)(iRam00715da8 + 0x24) = '\x14';
      }
      else {
        *(char *)(iRam00715da8 + 0x24) = *(byte *)(iRam00715da8 + 0x24) - 1;
      }
    }
    else if (param_1 == 1) {
      *(char *)(iRam00715da8 + 0x24) = *(char *)(iRam00715da8 + 0x24) + '\x01';
      if (0x14 < *(byte *)(iRam00715da8 + 0x24)) {
        *(undefined1 *)(iRam00715da8 + 0x24) = 1;
      }
    }
    if (param_1 == 2) {
      if (*(char *)(iRam00715da8 + 0x25) == '\0') {
        *(char *)(iRam00715da8 + 0x25) = '\0';
        break;
      }
      *(char *)(iRam00715da8 + 0x25) = *(char *)(iRam00715da8 + 0x25) + -1;
    }
    else if (param_1 == 3) {
      if (*(char *)(iRam00715da8 + 0x25) == '\x03') break;
      *(char *)(iRam00715da8 + 0x25) = *(char *)(iRam00715da8 + 0x25) + '\x01';
    }
    FUN_00634470();
  } while (cVar1 == *(char *)(iRam00715da8 + 0x2e));
  *(undefined4 *)(iRam00715da8 + 0x248) = 0;
  return;
}



================================================================