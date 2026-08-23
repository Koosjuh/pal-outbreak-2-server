FUNCTION FUN_005f6b00 @ 0x005f6b00  size=536
CALLERS (1): FUN_005f6aa0@0x005f6aa0
CALLEES (12): FUN_005af310@0x005af310, FUN_005af2f0@0x005af2f0, FUN_005f4550@0x005f4550, FUN_005f7270@0x005f7270, FUN_005af300@0x005af300, FUN_005b9110@0x005b9110, FUN_00618b60@0x00618b60, FUN_005af340@0x005af340, FUN_005b24c0@0x005b24c0, FUN_005f70a0@0x005f70a0, FUN_005f6a20@0x005f6a20, FUN_00606f10@0x00606f10, ...
----------------------------------------------------------------

void FUN_005f6b00(undefined8 param_1)

{
  char cVar1;
  long lVar2;
  short sVar3;
  int iVar4;
  
  iVar4 = (int)param_1;
  cVar1 = *(char *)(iVar4 + 0x11);
  switch(cVar1) {
  case '\0':
    if (*(char *)(iVar4 + 0x97b) == '\0') {
      *(undefined1 *)(iVar4 + 0x11) = 2;
      func_0x001a6910(0,0,0x10);
      func_0x003adb80();
    }
    else {
      *(char *)(iVar4 + 0x11) = cVar1 + '\x01';
      func_0x001a6910(0,0,0x10);
      lVar2 = FUN_005af340();
      if (lVar2 == 0) {
        FUN_005af300(0,10);
      }
    }
    break;
  case '\x01':
    lVar2 = FUN_005af310();
    if (lVar2 != 0) {
      func_0x003adb80();
      FUN_005b24c0();
      *(undefined1 *)(iVar4 + 0x11) = 2;
    }
    break;
  case '\x02':
    *(undefined1 *)(iVar4 + 0x11) = 3;
    FUN_00618b60();
    FUN_005f70a0(param_1);
    if (*(char *)(iVar4 + 0x97b) == '\x01') {
      *(undefined2 *)(iVar4 + 0x16) = 0x10;
      FUN_005f6a20(*(undefined1 *)(iVar4 + 0x97b));
      FUN_005af2f0(0,1);
    }
    else {
      *(undefined2 *)(iVar4 + 0x16) = 1;
    }
    break;
  case '\x03':
    sVar3 = *(short *)(iVar4 + 0x16) + -1;
    *(short *)(iVar4 + 0x16) = sVar3;
    if (0 < sVar3) {
      return;
    }
    *(undefined1 *)(iVar4 + 0x11) = 4;
  case '\x04':
    lVar2 = FUN_005f7270(param_1,*(undefined1 *)(iVar4 + 0x97b));
    if (lVar2 != 0) {
      *(char *)(iVar4 + 0x11) = *(char *)(iVar4 + 0x11) + '\x01';
    }
    break;
  case '\x05':
    *(char *)(iVar4 + 0x11) = cVar1 + '\x01';
    lVar2 = FUN_005af340();
    if (lVar2 == 0) {
      FUN_005af300(0,10);
    }
    func_0x001a7de0();
    break;
  case '\x06':
    lVar2 = FUN_005af310();
    if (lVar2 != 0) {
      FUN_00618b60();
      FUN_005b9110(0x4c);
      func_0x003adb80();
      FUN_005b24c0();
      *(char *)(iVar4 + 0x11) = *(char *)(iVar4 + 0x11) + '\x01';
    }
    break;
  case '\a':
    cVar1 = *(char *)(iVar4 + 0x97b);
    if ((cVar1 == '\0') || (cVar1 == '\x02')) {
      FUN_00606f10();
    }
    else if (cVar1 == '\x01') {
      uRam003c8a80 = 0;
      FUN_005f4550();
    }
  }
  return;
}



================================================================