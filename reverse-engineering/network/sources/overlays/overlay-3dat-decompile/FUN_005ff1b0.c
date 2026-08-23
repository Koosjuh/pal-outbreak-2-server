FUNCTION FUN_005ff1b0 @ 0x005ff1b0  size=1212
CALLERS (1): FUN_005fede0@0x005fede0
CALLEES (4): FUN_005adc80@0x005adc80, FUN_005b14b0@0x005b14b0, FUN_005f5ea0@0x005f5ea0, FUN_005b09b0@0x005b09b0
----------------------------------------------------------------

void FUN_005ff1b0(undefined8 param_1)

{
  char cVar1;
  int iVar2;
  long lVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = (int)param_1;
  if (*(char *)(iVar4 + 0x97e) == '\0') {
    iVar5 = 3;
    iVar2 = 2;
  }
  else {
    iVar5 = 4;
    iVar2 = 3;
  }
  if (*(char *)(iVar4 + 0x11) == '\0') {
    lVar3 = (long)*(char *)(iVar4 + 0x907);
    if ((lVar3 < 0) || (iVar2 <= lVar3)) {
      if ((lVar3 < iVar2 + 1) || (iVar5 < lVar3)) {
        lVar3 = FUN_005b14b0(0x40004);
        if (lVar3 == 0) {
          lVar3 = FUN_005b14b0(0x80008);
          if (lVar3 == 0) {
            lVar3 = FUN_005b14b0(0x10001);
            if (lVar3 == 0) {
              lVar3 = FUN_005b14b0(0x20002);
              if (lVar3 != 0) {
                *(char *)(iVar4 + 0x907) = (char)iVar2;
              }
            }
            else {
              *(char *)(iVar4 + 0x907) = *(char *)(iVar4 + 0x907) + '\x01';
              func_0x001b0140(0);
            }
          }
          else {
            *(char *)(iVar4 + 0x907) = (char)iVar2;
          }
        }
        else {
          *(char *)(iVar4 + 0x907) = *(char *)(iVar4 + 0x907) + -1;
          func_0x001b0140(0);
        }
      }
      else {
        lVar3 = FUN_005b14b0(0x10001);
        if (lVar3 == 0) {
          lVar3 = FUN_005b14b0(0x20002);
          if (lVar3 != 0) {
            *(char *)(iVar4 + 0x907) = *(char *)(iVar4 + 0x907) + -1;
            func_0x001b0140(0);
          }
        }
        else if ((long)*(char *)(iVar4 + 0x907) < (long)iVar5) {
          *(char *)(iVar4 + 0x907) = *(char *)(iVar4 + 0x907) + '\x01';
          func_0x001b0140(0);
        }
        else {
          *(char *)(iVar4 + 0x907) = (char)iVar5;
        }
      }
    }
    else {
      lVar3 = FUN_005b14b0(0x40004);
      if (lVar3 == 0) {
        lVar3 = FUN_005b14b0(0x80008);
        if (lVar3 != 0) {
          *(char *)(iVar4 + 0x907) = *(char *)(iVar4 + 0x907) + '\x01';
          func_0x001b0140(0);
        }
      }
      else if (*(char *)(iVar4 + 0x907) < '\x01') {
        *(undefined1 *)(iVar4 + 0x907) = 0;
      }
      else {
        *(char *)(iVar4 + 0x907) = *(char *)(iVar4 + 0x907) + -1;
        func_0x001b0140(0);
      }
    }
    cVar1 = *(char *)(iVar4 + 0x97e);
  }
  else {
    FUN_005b09b0(iVar4 + 0x907,(long)iVar2,3);
    cVar1 = *(char *)(iVar4 + 0x97e);
  }
  if (cVar1 == '\0') {
    lVar3 = FUN_005b14b0(0x10);
    if (lVar3 == 0) {
      lVar3 = FUN_005b14b0(0x200);
      if ((lVar3 != 0) && (*(char *)(iVar4 + 0x907) != '\x01')) {
        func_0x001b0140(2);
        *(undefined1 *)(iVar4 + 0x907) = 1;
        *(undefined1 *)(iVar4 + 0x992) = 0;
      }
    }
    else {
      cVar1 = *(char *)(iVar4 + 0x907);
      if (cVar1 == '\x03') {
        *(undefined1 *)(iVar4 + 0x909) = 3;
        FUN_005f5ea0(param_1);
        func_0x001b0140(1);
      }
      else if (cVar1 == '\x02') {
        *(undefined1 *)(iVar4 + 0x10) = 0;
        *(byte *)(iVar4 + 0x11) = *(byte *)(iVar4 + 0x11) ^ 1;
        *(undefined1 *)(iVar4 + 0x909) = *(undefined1 *)(iVar4 + 0x907);
        if (*(char *)((*(char *)(iVar4 + 0x908) * 0x3c - (int)*(char *)(iVar4 + 0x908)) * 0x10 +
                      iVar4 + 0x309c) == '\0') {
          *(undefined1 *)(iVar4 + 0x44c) = 0;
        }
        func_0x001b0140(1);
      }
      else if (cVar1 == '\x01') {
        *(char *)(iVar4 + 0x10) = *(char *)(iVar4 + 0x10) + '\x01';
        *(undefined1 *)(iVar4 + 0x454) = 0;
        func_0x001b0140();
        *(undefined2 *)(iVar4 + 0x16) = 1;
        *(undefined1 *)(iVar4 + 0x992) = 0;
      }
      else if (cVar1 == '\0') {
        func_0x001b0140(5);
      }
    }
  }
  else {
    lVar3 = FUN_005b14b0(0x10);
    if (lVar3 == 0) {
      lVar3 = FUN_005b14b0(0x200);
      if ((lVar3 != 0) && (*(char *)(iVar4 + 0x907) != '\x02')) {
        func_0x001b0140();
        *(undefined1 *)(iVar4 + 0x907) = 2;
        *(undefined1 *)(iVar4 + 0x992) = 0;
      }
    }
    else {
      cVar1 = *(char *)(iVar4 + 0x907);
      if (cVar1 == '\x04') {
        *(undefined1 *)(iVar4 + 0x909) = 4;
        FUN_005f5ea0(param_1);
      }
      else if (cVar1 == '\x03') {
        *(undefined1 *)(iVar4 + 0x10) = 0;
        *(byte *)(iVar4 + 0x11) = *(byte *)(iVar4 + 0x11) ^ 1;
        *(undefined1 *)(iVar4 + 0x909) = *(undefined1 *)(iVar4 + 0x907);
        *(undefined1 *)(iVar4 + 0x992) = 0;
        if (*(char *)((*(char *)(iVar4 + 0x908) * 0x3c - (int)*(char *)(iVar4 + 0x908)) * 0x10 +
                      iVar4 + 0x309c) == '\0') {
          *(undefined1 *)(iVar4 + 0x44c) = 0;
        }
      }
      else {
        if (cVar1 == '\x01') {
          return;
        }
        if (cVar1 == '\x02') {
          *(char *)(iVar4 + 0x10) = *(char *)(iVar4 + 0x10) + '\x01';
          *(undefined1 *)(iVar4 + 0x454) = 0;
          *(undefined1 *)(iVar4 + 0x992) = 0;
        }
        else if (cVar1 == '\0') {
          iVar2 = FUN_005adc80();
          if (*(ushort *)(iVar4 + 0x456) < *(ushort *)((iVar2 + -1) * 0x15c + 0x6c076a)) {
            func_0x001b0140(5);
            return;
          }
          *(undefined1 *)(iVar4 + 0x10) = 4;
          *(undefined1 *)(iVar4 + 0x992) = 0;
          *(undefined1 *)(iVar4 + 0x454) = 0;
          *(undefined1 *)(iVar4 + 0x992) = 0;
          *(undefined1 *)(iVar4 + 0x443) = 1;
        }
      }
      func_0x001b0140(1);
      *(undefined2 *)(iVar4 + 0x16) = 1;
    }
  }
  return;
}



================================================================