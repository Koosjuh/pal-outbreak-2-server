FUNCTION FUN_005fa490 @ 0x005fa490  size=612
CALLERS (1): FUN_005fa0b0@0x005fa0b0
CALLEES (7): FUN_005fc850@0x005fc850, FUN_005fa700@0x005fa700, FUN_005b14b0@0x005b14b0, FUN_005fba80@0x005fba80, FUN_005fa990@0x005fa990, FUN_005fb670@0x005fb670, FUN_005b09b0@0x005b09b0
----------------------------------------------------------------

void FUN_005fa490(undefined8 param_1)

{
  char cVar1;
  long lVar2;
  int iVar3;
  
  iVar3 = (int)param_1;
  cVar1 = *(char *)(iVar3 + 0x10);
  if (cVar1 == '\x02') {
    lVar2 = FUN_005fb670();
    if (lVar2 == 0) {
      lVar2 = FUN_005b14b0(0x220);
      if (lVar2 != 0) {
        *(undefined1 *)(iVar3 + 0x10) = 0;
        *(undefined1 *)(iVar3 + 0x11) = 0;
        func_0x001b0140(1);
      }
    }
    else {
      *(undefined1 *)(iVar3 + 0xf) = 4;
      *(undefined1 *)(iVar3 + 0x10) = 0;
    }
  }
  else if (cVar1 == '\x01') {
    lVar2 = FUN_005fb670();
    if (lVar2 == 0) {
      lVar2 = FUN_005b09b0(iVar3 + 0x909,1,2);
      if (lVar2 == 0) {
        lVar2 = FUN_005b14b0(0x200);
        if (lVar2 == 0) {
          lVar2 = FUN_005b14b0(0x800);
          if ((lVar2 == 0) && (lVar2 = FUN_005b14b0(0x400), lVar2 == 0)) {
            lVar2 = FUN_005b14b0(0x20);
            if (lVar2 == 0) {
              if (*(char *)(iVar3 + 0x909) == '\0') {
                lVar2 = FUN_005b09b0(iVar3 + 4,(int)*(short *)(iVar3 + 10) - 1U & 0xff,1);
                if (lVar2 == 0) {
                  lVar2 = FUN_005b14b0(0x20);
                  if (lVar2 != 0) {
                    *(char *)(iVar3 + 0x10) = *(char *)(iVar3 + 0x10) + '\x01';
                    *(undefined1 *)(iVar3 + 0x11) = 0;
                    FUN_005fc850(3);
                    func_0x001b0140(1);
                  }
                }
                else {
                  FUN_005fa990(param_1);
                }
              }
              else {
                lVar2 = FUN_005b14b0(0x10);
                if (lVar2 != 0) {
                  *(char *)(iVar3 + 0xf) = *(char *)(iVar3 + 0xf) + '\x01';
                  *(undefined1 *)(iVar3 + 0x10) = 0;
                  *(undefined1 *)(iVar3 + 0x11) = 0;
                  func_0x001b0140(1);
                }
              }
            }
            else {
              *(char *)(iVar3 + 0x10) = *(char *)(iVar3 + 0x10) + '\x01';
              *(undefined1 *)(iVar3 + 0x11) = 0;
              FUN_005fc850(3);
              func_0x001b0140(1);
            }
          }
          else {
            *(byte *)(iVar3 + 0x11) = *(byte *)(iVar3 + 0x11) ^ 1;
            FUN_005fc850(*(undefined1 *)(iVar3 + 0x11));
          }
        }
        else {
          *(undefined1 *)(iVar3 + 0xe) = 1;
          *(undefined1 *)(iVar3 + 0xf) = 0;
          *(undefined1 *)(iVar3 + 0x10) = 0;
          *(undefined1 *)(iVar3 + 0x11) = 0;
          *(undefined1 *)(iVar3 + 0x448) = 0;
          *(undefined1 *)(iVar3 + 0x449) = 0;
          *(undefined1 *)(iVar3 + 0x97c) = 1;
          FUN_005fba80();
        }
      }
    }
    else {
      *(undefined1 *)(iVar3 + 0xf) = 4;
      *(undefined1 *)(iVar3 + 0x10) = 0;
    }
  }
  else if (cVar1 == '\0') {
    *(undefined1 *)(iVar3 + 0x10) = 1;
    *(undefined1 *)(iVar3 + 0x11) = 1;
    *(undefined1 *)(iVar3 + 0x428) = 0;
    FUN_005fc850(*(undefined1 *)(iVar3 + 0x11));
    *(undefined1 *)(iVar3 + 0x909) = 0;
    lVar2 = FUN_005fa700(param_1,*(undefined2 *)(iVar3 + 4));
    if (lVar2 == 0) {
      FUN_005fa990(param_1);
    }
    else {
      *(undefined1 *)(iVar3 + 0xf) = 8;
      *(undefined1 *)(iVar3 + 0x10) = 0;
    }
  }
  return;
}



================================================================