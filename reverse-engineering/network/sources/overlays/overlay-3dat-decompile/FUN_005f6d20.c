FUNCTION FUN_005f6d20 @ 0x005f6d20  size=896
CALLERS (1): FUN_005f6aa0@0x005f6aa0
CALLEES (19): FUN_005af2f0@0x005af2f0, FUN_005f7270@0x005f7270, FUN_005af300@0x005af300, FUN_005b24c0@0x005b24c0, FUN_005af2c0@0x005af2c0, FUN_006235e0@0x006235e0, FUN_005af1e0@0x005af1e0, FUN_005f6a20@0x005f6a20, FUN_00606f10@0x00606f10, FUN_005af2e0@0x005af2e0, FUN_0062fea0@0x0062fea0, FUN_005af310@0x005af310, ...
----------------------------------------------------------------

void FUN_005f6d20(undefined8 param_1)

{
  char cVar1;
  int iVar2;
  undefined8 uVar3;
  long lVar4;
  short sVar5;
  int iVar6;
  
  iVar6 = (int)param_1;
  cVar1 = *(char *)(iVar6 + 0x11);
  switch(cVar1) {
  case '\0':
    *(char *)(iVar6 + 0x11) = cVar1 + '\x01';
    func_0x001a6910(0,0,0x10);
    thunk_EXT_FUN_001b3720();
    FUN_005af2f0(0,1);
    *(undefined1 *)(iVar6 + 0x11) = 4;
    break;
  case '\x01':
    *(char *)(iVar6 + 0x11) = cVar1 + '\x01';
    FUN_00618b60();
    func_0x003adb80();
    FUN_005b24c0();
    break;
  case '\x02':
    *(char *)(iVar6 + 0x11) = cVar1 + '\x01';
    *(undefined1 *)(iVar6 + 0x45a) = 0;
    break;
  case '\x03':
    *(undefined1 *)(iVar6 + 0x45a) = 1;
    *(char *)(iVar6 + 0x11) = *(char *)(iVar6 + 0x11) + '\x01';
    FUN_005af2f0(0);
    break;
  case '\x04':
    *(char *)(iVar6 + 0x11) = cVar1 + '\x01';
    FUN_005f70a0();
    break;
  case '\x05':
    *(char *)(iVar6 + 0x11) = cVar1 + '\x01';
    FUN_00618b60();
    *(undefined2 *)(iVar6 + 0x16) = 0x10;
    FUN_005f6a20(*(undefined1 *)(iVar6 + 0x97b));
    break;
  case '\x06':
    sVar5 = *(short *)(iVar6 + 0x16) + -1;
    *(short *)(iVar6 + 0x16) = sVar5;
    if (0 < sVar5) {
      return;
    }
    *(undefined1 *)(iVar6 + 0x11) = 7;
  case '\a':
    lVar4 = FUN_005f7270(param_1,*(undefined1 *)(iVar6 + 0x97b));
    if (lVar4 != 0) {
      if (*(char *)(iVar6 + 0x97b) == '\a') {
        *(undefined1 *)(iVar6 + 0x11) = 9;
        *(undefined2 *)(iVar6 + 0x16) = 0x5a;
      }
      else {
        *(char *)(iVar6 + 0x11) = *(char *)(iVar6 + 0x11) + '\x01';
      }
    }
    break;
  case '\b':
    lVar4 = FUN_005b14b0(0x10);
    if (lVar4 == 0) {
      if ((*(byte *)(iVar6 + 0x97b) - 3 < 3) || (*(byte *)(iVar6 + 0x97b) == 6)) {
        FUN_005af2c0(4);
        FUN_005af2e0(0x14);
        uVar3 = FUN_0062fea0(0xd);
        iVar2 = func_0x001ae3e0(uVar3);
        uVar3 = FUN_0062fea0(0xd);
        iVar6 = (int)((ulong)((long)(iVar2 * 5) << 0x21) >> 0x20);
        if (iVar2 * 10 < 0) {
          iVar6 = iVar2 * 10 + 1;
        }
        FUN_005af1e0(0x140 - (iVar6 >> 1),0x160,2,uVar3);
      }
    }
    else {
      *(undefined1 *)(iVar6 + 0x11) = 10;
      func_0x001b0140(1);
      FUN_005af300(0,10);
      func_0x001a7de0();
    }
    break;
  case '\t':
    sVar5 = *(short *)(iVar6 + 0x16) + -1;
    *(short *)(iVar6 + 0x16) = sVar5;
    if (sVar5 < 1) {
      *(char *)(iVar6 + 0x11) = *(char *)(iVar6 + 0x11) + '\x01';
      FUN_005af300(0,10);
      func_0x001a7de0();
    }
    break;
  case '\n':
    lVar4 = FUN_005af310();
    if (lVar4 != 0) {
      FUN_00618b60();
      FUN_005b9110(0x4c);
      *(char *)(iVar6 + 0x11) = *(char *)(iVar6 + 0x11) + '\x01';
      *(undefined2 *)(iVar6 + 0x16) = 4;
    }
    break;
  case '\v':
    sVar5 = *(short *)(iVar6 + 0x16) + -1;
    *(short *)(iVar6 + 0x16) = sVar5;
    if (sVar5 != 0) {
      return;
    }
    func_0x003adb80();
    *(undefined2 *)(iVar6 + 0x16) = 10;
    *(char *)(iVar6 + 0x11) = *(char *)(iVar6 + 0x11) + '\x01';
    FUN_005b24c0();
  case '\f':
    sVar5 = *(short *)(iVar6 + 0x16) + -1;
    *(short *)(iVar6 + 0x16) = sVar5;
    if (sVar5 < 1) {
      cVar1 = *(char *)(iVar6 + 0x97b);
      if (cVar1 == '\a') {
        FUN_00606f10();
        func_0x001a7de0();
        func_0x001a7e20(0x618c90);
      }
      else if (cVar1 == '\x03') {
        uRam003c8a80 = 0;
        FUN_005f4550();
      }
      else if (cVar1 == '\b') {
        FUN_006235e0();
      }
      else {
        uRam003c8a80 = 0;
        thunk_FUN_006235f0();
      }
    }
  }
  return;
}



================================================================