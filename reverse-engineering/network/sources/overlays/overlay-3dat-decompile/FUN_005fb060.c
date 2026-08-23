FUNCTION FUN_005fb060 @ 0x005fb060  size=528
CALLERS (1): FUN_005fa0b0@0x005fa0b0
CALLEES (6): FUN_005adc80@0x005adc80, FUN_005b9110@0x005b9110, FUN_005b14b0@0x005b14b0, FUN_005fb270@0x005fb270, FUN_005fb670@0x005fb670, FUN_005b8cf0@0x005b8cf0
----------------------------------------------------------------

void FUN_005fb060(undefined8 param_1)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  long lVar4;
  short sVar5;
  int iVar6;
  
  iVar6 = (int)param_1;
  cVar1 = *(char *)(iVar6 + 0x10);
  if (cVar1 == '\x03') {
    FUN_005fb270(param_1,0);
  }
  else if (cVar1 == '\x02') {
    cVar1 = *(char *)(iVar6 + 0x11);
    if (cVar1 == '\x02') {
      lVar4 = FUN_005b14b0(0x210);
      if (lVar4 != 0) {
        *(undefined1 *)(iVar6 + 0xe) = 1;
        *(undefined1 *)(iVar6 + 0xf) = 0;
        *(undefined1 *)(iVar6 + 0x10) = 0;
        *(undefined1 *)(iVar6 + 0x11) = 0;
        FUN_005b9110(0x4c);
        func_0x001b0140(1);
      }
    }
    else if (cVar1 == '\x01') {
      sVar5 = *(short *)(iVar6 + 0x16) + -1;
      *(short *)(iVar6 + 0x16) = sVar5;
      if (sVar5 < 0) {
        *(undefined2 *)(iVar6 + 0x16) = 0;
        *(char *)(iVar6 + 0x11) = *(char *)(iVar6 + 0x11) + '\x01';
      }
    }
    else if (cVar1 == '\0') {
      FUN_005b8cf0(0xffffffffffffffa1);
      *(undefined2 *)(iVar6 + 0x16) = 0x10;
      *(char *)(iVar6 + 0x11) = *(char *)(iVar6 + 0x11) + '\x01';
    }
  }
  else if (cVar1 == '\x01') {
    FUN_005fb270();
  }
  else if (cVar1 == '\0') {
    lVar4 = FUN_005fb670();
    if (lVar4 == 0) {
      iVar3 = FUN_005adc80(2);
      uVar2 = *(uint *)((iVar3 + -1) * 0x15c + 0x6c0774);
      if ((uVar2 & 0x10000) == 0) {
        if ((uVar2 & 0x20000) == 0) {
          *(undefined1 *)(iVar6 + 0xf) = 0;
          *(undefined1 *)(iVar6 + 0x10) = 0;
          *(undefined1 *)(iVar6 + 0x11) = 0;
        }
        else if (cRam00343571 == '\x02') {
          *(undefined1 *)(iVar6 + 0xf) = 0;
          *(undefined1 *)(iVar6 + 0x10) = 0;
          *(undefined1 *)(iVar6 + 0x11) = 0;
        }
        else if (cRam00343571 == '\0') {
          *(undefined1 *)(iVar6 + 0x10) = 2;
          *(undefined1 *)(iVar6 + 0x11) = 0;
        }
        else {
          *(undefined1 *)(iVar6 + 0x10) = 1;
          *(undefined1 *)(iVar6 + 0x11) = 0;
          *(undefined1 *)(iVar6 + 0x996) = 1;
        }
      }
      else if (cRam00343571 == '\x02') {
        *(undefined1 *)(iVar6 + 0x10) = 3;
        *(undefined1 *)(iVar6 + 0x11) = 0;
        *(undefined1 *)(iVar6 + 0x996) = 1;
      }
      else {
        *(undefined1 *)(iVar6 + 0xf) = 0;
        *(undefined1 *)(iVar6 + 0x10) = 0;
        *(undefined1 *)(iVar6 + 0x11) = 0;
      }
    }
    else {
      *(undefined1 *)(iVar6 + 0xf) = 4;
      *(undefined1 *)(iVar6 + 0x10) = 0;
      *(undefined1 *)(iVar6 + 0x11) = 0;
    }
  }
  return;
}



================================================================