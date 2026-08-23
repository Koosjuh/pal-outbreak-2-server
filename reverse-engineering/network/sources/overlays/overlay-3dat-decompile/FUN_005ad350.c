FUNCTION FUN_005ad350 @ 0x005ad350  size=476
CALLERS (2): FUN_005ad030@0x005ad030, FUN_005ad680@0x005ad680
CALLEES (5): FUN_005bb010@0x005bb010, FUN_005bafc0@0x005bafc0, FUN_005b9110@0x005b9110, FUN_005b14b0@0x005b14b0, FUN_005b8cf0@0x005b8cf0
----------------------------------------------------------------

undefined4 FUN_005ad350(int param_1,uint param_2)

{
  char cVar1;
  undefined1 uVar2;
  short sVar3;
  long lVar4;
  
  cVar1 = *(char *)(param_1 + 0x10);
  if (cVar1 == '\x04') {
    *(undefined1 *)(param_1 + 0x10) = 3;
    *(undefined1 *)(param_1 + 0x11) = 1;
    FUN_005b8cf0(0xffffffffffffffb5);
    *(undefined2 *)(param_1 + 0x16) = 0x10;
  }
  else {
    if (cVar1 != '\x03') {
      if ((cVar1 != '\x02') && (cVar1 != '\x01')) {
        if (cVar1 != '\0') {
          return 0;
        }
        if (*(char *)(param_2 * 0x15c + 0x6c386e) != '\x03') {
          return 0xffffffff;
        }
        cVar1 = FUN_005bafc0(param_2 & 0xffff);
        *(undefined1 *)(param_1 + 0x8ec) = 0;
        *(undefined1 *)(param_1 + 0x8ed) = 0;
        if (cVar1 != '\0') {
          if (cVar1 == cRam00342f30) {
            if (cRam00342f31 == '\0') {
              *(undefined1 *)(param_1 + 0x10) = 4;
              *(undefined1 *)(param_1 + 0x11) = 0;
              return 0;
            }
            *(char *)(param_1 + 0x8ec) = cRam00342f30;
            *(char *)(param_1 + 0x8ed) = cRam00342f31;
          }
          else {
            *(char *)(param_1 + 0x8ec) = cVar1;
            uVar2 = FUN_005bb010(param_2 & 0xffff);
            *(undefined1 *)(param_1 + 0x8ed) = uVar2;
          }
        }
      }
      *(undefined1 *)(param_1 + 0x992) = 0;
      *(undefined1 *)(param_1 + 0x992) = 0;
      cRam006c45f8 = (char)param_2 + '\x01';
      return 1;
    }
    cVar1 = *(char *)(param_1 + 0x11);
    if (cVar1 == '\x02') {
      lVar4 = FUN_005b14b0(0x210);
      if (lVar4 != 0) {
        FUN_005b9110(0x4c);
        func_0x001b0140(1);
        return 0xffffffff;
      }
    }
    else if (cVar1 == '\x01') {
      sVar3 = *(short *)(param_1 + 0x16) + -1;
      *(short *)(param_1 + 0x16) = sVar3;
      if (sVar3 < 0) {
        *(undefined2 *)(param_1 + 0x16) = 0;
        *(char *)(param_1 + 0x11) = *(char *)(param_1 + 0x11) + '\x01';
      }
    }
    else if (cVar1 == '\0') {
      FUN_005b8cf0(0xffffffffffffffb1);
      *(undefined2 *)(param_1 + 0x16) = 0x10;
      *(char *)(param_1 + 0x11) = *(char *)(param_1 + 0x11) + '\x01';
    }
  }
  return 0;
}



================================================================