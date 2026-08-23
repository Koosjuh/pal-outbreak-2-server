FUNCTION FUN_005f7c80 @ 0x005f7c80  size=680
CALLERS (1): FUN_005f7800@0x005f7800
CALLEES (4): FUN_005f4b80@0x005f4b80, FUN_005b14b0@0x005b14b0, FUN_005f4be0@0x005f4be0, FUN_005f7690@0x005f7690
----------------------------------------------------------------

void FUN_005f7c80(undefined8 param_1)

{
  long lVar1;
  char cVar2;
  int iVar3;
  ulong uVar4;
  int iVar5;
  
  FUN_005f4b80();
  lVar1 = FUN_005f4be0();
  if (lVar1 == 0) {
    iVar5 = (int)param_1;
    *(undefined1 *)(iVar5 + 0x992) = 1;
    uVar4 = (ulong)uRam006c45fe;
    if (6 < uVar4) {
      uVar4 = 6;
    }
    lVar1 = FUN_005b14b0(0x10);
    if (lVar1 == 0) {
      lVar1 = FUN_005b14b0(0x200);
      if (lVar1 == 0) {
        lVar1 = (long)*(char *)(iVar5 + 0x907);
        iVar3 = (int)uVar4;
        if ((lVar1 < 0) || ((long)uVar4 <= lVar1)) {
          if ((lVar1 < iVar3 + 1) || (iVar3 + 3 < lVar1)) {
            lVar1 = FUN_005b14b0(0x40004);
            if (lVar1 == 0) {
              lVar1 = FUN_005b14b0(0x80008);
              cVar2 = (char)uVar4;
              if (lVar1 == 0) {
                lVar1 = FUN_005b14b0(0x10001);
                if (lVar1 == 0) {
                  lVar1 = FUN_005b14b0(0x20002);
                  if (lVar1 != 0) {
                    *(char *)(iVar5 + 0x907) = cVar2;
                  }
                }
                else {
                  *(char *)(iVar5 + 0x907) = cVar2 + '\x01';
                  func_0x001b0140(0);
                }
              }
              else {
                *(char *)(iVar5 + 0x907) = cVar2;
              }
            }
            else {
              *(char *)(iVar5 + 0x907) = *(char *)(iVar5 + 0x907) + -1;
              func_0x001b0140(0);
            }
          }
          else {
            lVar1 = FUN_005b14b0(0x10001);
            if (lVar1 == 0) {
              lVar1 = FUN_005b14b0(0x20002);
              if (lVar1 != 0) {
                *(char *)(iVar5 + 0x907) = *(char *)(iVar5 + 0x907) + -1;
                func_0x001b0140(0);
              }
            }
            else if ((long)*(char *)(iVar5 + 0x907) == (long)(iVar3 + 3)) {
              *(char *)(iVar5 + 0x907) = (char)(iVar3 + 3);
            }
            else {
              *(char *)(iVar5 + 0x907) = *(char *)(iVar5 + 0x907) + '\x01';
              func_0x001b0140(0);
            }
          }
        }
        else {
          lVar1 = FUN_005b14b0(0x40004);
          if (lVar1 == 0) {
            lVar1 = FUN_005b14b0(0x80008);
            if (lVar1 != 0) {
              *(char *)(iVar5 + 0x907) = *(char *)(iVar5 + 0x907) + '\x01';
              func_0x001b0140(0);
            }
          }
          else if (*(char *)(iVar5 + 0x907) == '\0') {
            *(undefined1 *)(iVar5 + 0x907) = 0;
          }
          else {
            *(char *)(iVar5 + 0x907) = *(char *)(iVar5 + 0x907) + -1;
            func_0x001b0140(0);
          }
        }
      }
      else {
        func_0x001b0140(2);
        FUN_005f7690(param_1,0);
      }
    }
    else {
      cVar2 = *(char *)(iVar5 + 0x907);
      if ((((long)cVar2 < 1) || ((long)uVar4 <= (long)cVar2)) ||
         ((*(char *)(cVar2 + 0x70b410) != -1 && (*(char *)(cVar2 + 0x70b410) != '\0')))) {
        *(undefined1 *)(iVar5 + 0xe) = 2;
        *(undefined1 *)(iVar5 + 0xf) = 0;
        *(undefined1 *)(iVar5 + 0x992) = 0;
        func_0x001b0140(1);
      }
      else {
        func_0x001b0140(5);
      }
    }
  }
  return;
}



================================================================