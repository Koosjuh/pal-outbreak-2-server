FUNCTION FUN_005fede0 @ 0x005fede0  size=972
CALLERS (1): FUN_005fe730@0x005fe730
CALLEES (11): FUN_006018d0@0x006018d0, FUN_005c0f60@0x005c0f60, FUN_00600b60@0x00600b60, FUN_005ff1b0@0x005ff1b0, FUN_005c4580@0x005c4580, FUN_00601760@0x00601760, FUN_005f4b80@0x005f4b80, FUN_005b14b0@0x005b14b0, FUN_005f4be0@0x005f4be0, FUN_00602700@0x00602700, FUN_005b09b0@0x005b09b0
----------------------------------------------------------------

void FUN_005fede0(undefined8 param_1)

{
  long lVar1;
  int iVar2;
  
  iVar2 = (int)param_1;
  if (*(char *)(iVar2 + 0x97f) != '\0') {
    *(undefined1 *)(iVar2 + 0x97f) = 0;
    FUN_005c0f60(uRam006c4600,0x600ff0);
  }
  switch(*(char *)(iVar2 + 0x10)) {
  case '\0':
    *(char *)(iVar2 + 0x10) = *(char *)(iVar2 + 0x10) + '\x01';
    if (*(char *)(iVar2 + 0x11) == '\0') {
      FUN_00601760(param_1);
      *(undefined1 *)(iVar2 + 0x9cc) = 0;
    }
    else {
      FUN_006018d0(param_1);
      *(undefined1 *)(iVar2 + 0x9cc) = 0;
    }
    *(undefined1 *)(iVar2 + 0x908) = *(undefined1 *)(iVar2 + 0x44c);
    *(undefined2 *)(iVar2 + 0x16) = 10;
    FUN_00602700(param_1);
    func_0x001069a8(iRam003435d4 + 0xcf5c0,
                    iVar2 + (*(char *)(iVar2 + 0x908) * 0x3c - (int)*(char *)(iVar2 + 0x908)) * 0x10
                    + 0x30c0,0xd4);
    func_0x001069a8(iVar2 + 0x3cdc,
                    iVar2 + (*(char *)(iVar2 + 0x908) * 0x3c - (int)*(char *)(iVar2 + 0x908)) * 0x10
                    + 0x2e1c,0x3b0);
    break;
  case '\x01':
    *(short *)(iVar2 + 0x16) = *(short *)(iVar2 + 0x16) + -1;
    if (*(short *)(iVar2 + 0x16) < 0) {
      *(char *)(iVar2 + 0x10) = *(char *)(iVar2 + 0x10) + '\x01';
      *(undefined1 *)(iVar2 + 0x454) = 1;
    }
    FUN_00602700(param_1);
    func_0x001069a8(iRam003435d4 + 0xcf5c0,
                    iVar2 + (*(char *)(iVar2 + 0x908) * 0x3c - (int)*(char *)(iVar2 + 0x908)) * 0x10
                    + 0x30c0,0xd4);
    func_0x001069a8(iVar2 + 0x3cdc,
                    iVar2 + (*(char *)(iVar2 + 0x908) * 0x3c - (int)*(char *)(iVar2 + 0x908)) * 0x10
                    + 0x2e1c,0x3b0);
    break;
  case '\x02':
    if (*(char *)(iVar2 + 0x11) == '\0') {
      FUN_005f4b80();
      lVar1 = FUN_005f4be0();
      if (lVar1 == 0) {
        *(undefined1 *)(iVar2 + 0x992) = 1;
        FUN_005ff1b0(param_1);
      }
    }
    else {
      *(undefined1 *)(iVar2 + 0x992) = 1;
      lVar1 = FUN_00600b60(param_1);
      if (lVar1 == 0) {
        lVar1 = FUN_005b14b0(0x80);
        if (lVar1 == 0) {
          lVar1 = FUN_005b14b0(0x40);
          if (lVar1 == 0) {
            if (cRam006c553a < '\n') {
              FUN_005ff1b0(param_1);
            }
            else {
              lVar1 = FUN_005b09b0(iVar2 + 0x9cc,cRam006c553a + -9,2);
              if (lVar1 == 0) {
                FUN_005ff1b0(param_1);
              }
            }
          }
          else {
            *(char *)(iVar2 + 0x9ab) = *(char *)(iVar2 + 0x9ab) + -1;
            *(byte *)(iVar2 + 0x9ab) = *(byte *)(iVar2 + 0x9ab) & 3;
            *(undefined1 *)(iVar2 + 0x9cc) = 0;
          }
        }
        else {
          *(char *)(iVar2 + 0x9ab) = *(char *)(iVar2 + 0x9ab) + '\x01';
          *(byte *)(iVar2 + 0x9ab) = *(byte *)(iVar2 + 0x9ab) & 3;
          *(undefined1 *)(iVar2 + 0x9cc) = 0;
        }
      }
      else {
        func_0x001069a8(iVar2 + 0x3cdc,
                        iVar2 + (*(char *)(iVar2 + 0x908) * 0x3c - (int)*(char *)(iVar2 + 0x908)) *
                                0x10 + 0x2e1c,0x3b0);
        func_0x001069a8(iRam003435d4 + 0xcf5c0,
                        iVar2 + (*(char *)(iVar2 + 0x908) * 0x3c - (int)*(char *)(iVar2 + 0x908)) *
                                0x10 + 0x30c0,0xd4);
      }
      FUN_00602700(param_1);
    }
    break;
  case '\x03':
    *(short *)(iVar2 + 0x16) = *(short *)(iVar2 + 0x16) + -1;
    if (*(short *)(iVar2 + 0x16) < 0) {
      *(char *)(iVar2 + 0xf) = *(char *)(iVar2 + 0xf) + '\x01';
      *(undefined1 *)(iVar2 + 0x10) = 0;
      *(undefined1 *)(iVar2 + 0x443) = 2;
    }
    break;
  case '\x04':
    *(short *)(iVar2 + 0x16) = *(short *)(iVar2 + 0x16) + -1;
    if (*(short *)(iVar2 + 0x16) < 0) {
      *(char *)(iVar2 + 0x10) = *(char *)(iVar2 + 0x10) + '\x01';
      *(undefined1 *)(iVar2 + 0x443) = 1;
      *(undefined2 *)(iVar2 + 0x16) = 900;
      FUN_005c4580();
    }
    break;
  case '\x05':
    *(short *)(iVar2 + 0x16) = *(short *)(iVar2 + 0x16) + -1;
    if (*(short *)(iVar2 + 0x16) < 0) {
      *(undefined1 *)(iVar2 + 0x10) = 0;
    }
  }
  return;
}



================================================================