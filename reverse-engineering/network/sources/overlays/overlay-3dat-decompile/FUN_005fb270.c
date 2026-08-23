FUNCTION FUN_005fb270 @ 0x005fb270  size=1004
CALLERS (1): FUN_005fb060@0x005fb060
CALLEES (8): FUN_005b1460@0x005b1460, FUN_005b2470@0x005b2470, FUN_005b9110@0x005b9110, FUN_005b14b0@0x005b14b0, FUN_005b1420@0x005b1420, FUN_005b8da0@0x005b8da0, FUN_005fb670@0x005fb670, FUN_005b8cf0@0x005b8cf0
----------------------------------------------------------------

void FUN_005fb270(int param_1,long param_2)

{
  char cVar1;
  long lVar2;
  short sVar3;
  
  lVar2 = FUN_005fb670();
  if (lVar2 == 0) {
    switch(*(undefined1 *)(param_1 + 0x11)) {
    case 0:
      *(undefined1 *)(param_1 + 0x43c) = 1;
      *(undefined1 *)(param_1 + 0x43f) = 0;
      *(char *)(param_1 + 0x11) = *(char *)(param_1 + 0x11) + '\x01';
      if (param_2 == 0) {
        FUN_005b8da0(0xffffffffffffffac,param_1 + 0x43c);
      }
      else {
        FUN_005b8da0(0xffffffffffffffab,param_1 + 0x43c);
      }
      break;
    case 1:
      lVar2 = FUN_005b14b0(0x40004);
      if (((lVar2 == 0) && (cRam006c462a != 'P')) &&
         ((cRam006c462a != '+' || ((bRam006c462b & 0x22) == 0)))) {
        lVar2 = FUN_005b14b0(0x80008);
        if (((lVar2 == 0) && (cRam006c462a != 'O')) && (cRam006c462a != '+')) {
          lVar2 = FUN_005b1420();
          if (lVar2 == 0) {
            lVar2 = FUN_005b1460();
            if (lVar2 != 0) {
              *(undefined1 *)(param_1 + 0xe) = 1;
              *(undefined1 *)(param_1 + 0xf) = 0;
              *(undefined1 *)(param_1 + 0x10) = 0;
              *(undefined1 *)(param_1 + 0x11) = 0;
              func_0x001b0140(2);
              FUN_005b9110(0x4c);
            }
          }
          else {
            if (*(char *)(param_1 + 0x43c) == '\0') {
              *(char *)(param_1 + 0x11) = *(char *)(param_1 + 0x11) + '\x01';
              *(undefined1 *)(param_1 + 0x43f) = 1;
              *(undefined2 *)(param_1 + 0x16) = 8;
              *(undefined1 *)(param_1 + 0x45a) = 0;
            }
            else {
              *(undefined1 *)(param_1 + 0xe) = 1;
              *(undefined1 *)(param_1 + 0xf) = 0;
              *(undefined1 *)(param_1 + 0x10) = 0;
              *(undefined1 *)(param_1 + 0x11) = 0;
              FUN_005b9110(0x4c);
            }
            func_0x001b0140(1);
          }
        }
        else {
          if (*(char *)(param_1 + 0x43c) == '\0') {
            func_0x001b0140(0);
          }
          *(undefined1 *)(param_1 + 0x43c) = 1;
        }
      }
      else {
        if (*(char *)(param_1 + 0x43c) != '\0') {
          func_0x001b0140(0);
        }
        *(undefined1 *)(param_1 + 0x43c) = 0;
      }
      break;
    case 2:
      sVar3 = *(short *)(param_1 + 0x16) + -1;
      *(short *)(param_1 + 0x16) = sVar3;
      if (sVar3 < 0) {
        *(char *)(param_1 + 0x11) = *(char *)(param_1 + 0x11) + '\x01';
        *(undefined1 *)(param_1 + 0x43f) = 0;
        FUN_005b9110(0x4c);
        func_0x001b4f40(param_2);
      }
      break;
    case 3:
      lVar2 = func_0x001b4f70();
      if (lVar2 == -1) {
        *(undefined1 *)(param_1 + 0x11) = 5;
        func_0x003adb70();
        FUN_005b2470(3);
        FUN_005b8cf0(0xffffffffffffffad);
        *(undefined2 *)(param_1 + 0x16) = 0x1e;
      }
      else if (lVar2 == 0) {
        *(undefined1 *)(param_1 + 0x996) = 1;
        func_0x003adb70();
        FUN_005b2470(3);
        if (param_2 == 0) {
          FUN_005b8cf0(0xffffffffffffffa3);
          cVar1 = *(char *)(param_1 + 0x11);
        }
        else {
          FUN_005b8cf0(0xffffffffffffffa4);
          cVar1 = *(char *)(param_1 + 0x11);
        }
        *(char *)(param_1 + 0x11) = cVar1 + '\x01';
        *(undefined2 *)(param_1 + 0x16) = 0x5a;
      }
      else if (lVar2 == 1) {
        *(undefined1 *)(param_1 + 0x996) = 0;
      }
      break;
    case 4:
      sVar3 = *(short *)(param_1 + 0x16) + -1;
      *(short *)(param_1 + 0x16) = sVar3;
      if (sVar3 < 0) {
        *(undefined1 *)(param_1 + 0xf) = 0;
        *(undefined1 *)(param_1 + 0x10) = 0;
        *(undefined1 *)(param_1 + 0x11) = 0;
        FUN_005b9110(0x4c);
        *(undefined1 *)(param_1 + 0x45a) = 1;
      }
      break;
    case 5:
      sVar3 = *(short *)(param_1 + 0x16) + -1;
      *(short *)(param_1 + 0x16) = sVar3;
      if (sVar3 < 0) {
        *(char *)(param_1 + 0x11) = *(char *)(param_1 + 0x11) + '\x01';
        *(undefined2 *)(param_1 + 0x16) = 0x5a;
      }
      break;
    case 6:
      *(short *)(param_1 + 0x16) = *(short *)(param_1 + 0x16) + -1;
      lVar2 = FUN_005b14b0(0x210);
      if ((lVar2 != 0) || (*(short *)(param_1 + 0x16) < 0)) {
        *(undefined1 *)(param_1 + 0xe) = 1;
        *(undefined1 *)(param_1 + 0xf) = 0;
        *(undefined1 *)(param_1 + 0x10) = 0;
        *(undefined1 *)(param_1 + 0x11) = 0;
        FUN_005b9110(0x4c);
        *(undefined1 *)(param_1 + 0x45a) = 1;
      }
    }
  }
  else {
    *(undefined1 *)(param_1 + 0xf) = 4;
    *(undefined1 *)(param_1 + 0x10) = 0;
    *(undefined1 *)(param_1 + 0x11) = 0;
    *(undefined1 *)(param_1 + 0x45a) = 1;
    if (*(char *)(param_1 + 0x996) == '\0') {
      func_0x003adb70();
      FUN_005b2470(3);
    }
  }
  return;
}



================================================================