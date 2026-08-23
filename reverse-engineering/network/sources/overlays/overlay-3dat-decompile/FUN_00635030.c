FUNCTION FUN_00635030 @ 0x00635030  size=656
CALLERS (1): FUN_00634ab0@0x00634ab0
CALLEES (5): FUN_00633930@0x00633930, FUN_00633ab0@0x00633ab0, FUN_00631ac0@0x00631ac0, FUN_00631bb0@0x00631bb0, FUN_00634470@0x00634470
----------------------------------------------------------------

void FUN_00635030(ulong param_1)

{
  char cVar1;
  
  cVar1 = *(char *)(iRam00715da8 + 0x2e);
  if (*(char *)(iRam00715da8 + 0x26) == '\0') {
    if (*(char *)(iRam00715da8 + 0x2f) != '\x01') {
      do {
        if ((param_1 & 4) == 0) {
          if ((param_1 & 8) != 0) {
            *(char *)(iRam00715da8 + 0x24) = *(char *)(iRam00715da8 + 0x24) + '\x01';
            if (0x14 < *(byte *)(iRam00715da8 + 0x24)) {
              *(undefined1 *)(iRam00715da8 + 0x24) = 0;
            }
          }
        }
        else if (*(char *)(iRam00715da8 + 0x24) == '\0') {
          *(char *)(iRam00715da8 + 0x24) = '\x14';
        }
        else {
          *(char *)(iRam00715da8 + 0x24) = *(char *)(iRam00715da8 + 0x24) + -1;
        }
        if ((param_1 & 1) == 0) {
          if ((param_1 & 2) != 0) {
            if (*(char *)(iRam00715da8 + 0x25) == '\x03') {
              *(undefined1 *)(iRam00715da8 + 0x26) = 1;
              *(undefined1 *)(iRam00715da8 + 0x28) = 0;
              return;
            }
            *(char *)(iRam00715da8 + 0x25) = *(char *)(iRam00715da8 + 0x25) + '\x01';
          }
        }
        else {
          if (*(char *)(iRam00715da8 + 0x25) == '\0') {
            *(undefined1 *)(iRam00715da8 + 0x26) = 1;
            *(undefined1 *)(iRam00715da8 + 0x28) = 0;
            return;
          }
          *(char *)(iRam00715da8 + 0x25) = *(char *)(iRam00715da8 + 0x25) + -1;
        }
        FUN_00634470();
      } while (cVar1 == *(char *)(iRam00715da8 + 0x2e));
      return;
    }
  }
  else if (*(char *)(iRam00715da8 + 0x2f) != '\x01') {
    if ((param_1 & 1) != 0) {
      *(undefined1 *)(iRam00715da8 + 0x25) = 3;
      *(undefined1 *)(iRam00715da8 + 0x26) = 0;
      FUN_00634470();
      return;
    }
    if ((param_1 & 2) != 0) {
      *(undefined1 *)(iRam00715da8 + 0x25) = 0;
      *(undefined1 *)(iRam00715da8 + 0x26) = 0;
      FUN_00634470();
      return;
    }
    if ((param_1 & 4) != 0) {
      FUN_00631bb0();
      return;
    }
    if ((param_1 & 8) == 0) {
      return;
    }
    FUN_00631ac0();
    return;
  }
  if ((param_1 & 8) == 0) {
    if ((param_1 & 4) == 0) {
      if ((param_1 & 1) == 0) {
        if ((param_1 & 2) != 0) {
          FUN_00633ab0();
        }
      }
      else {
        FUN_00633930();
      }
    }
    else {
      FUN_00631bb0();
    }
  }
  else {
    FUN_00631ac0();
  }
  return;
}



================================================================