FUNCTION FUN_005dd660 @ 0x005dd660  size=700
CALLERS (0): 
CALLEES (8): FUN_005e5200@0x005e5200, FUN_005e5650@0x005e5650, FUN_005dfee0@0x005dfee0, FUN_005ddc20@0x005ddc20, FUN_005e4af0@0x005e4af0, FUN_005de330@0x005de330, FUN_005e4f10@0x005e4f10, FUN_005e4b00@0x005e4b00
----------------------------------------------------------------

void FUN_005dd660(int param_1)

{
  char cVar1;
  short sVar2;
  undefined8 uVar3;
  
  cVar1 = *(char *)(param_1 + 6);
  if ((((cVar1 == '\a') || (cVar1 == '\x06')) || (cVar1 == '\x05')) ||
     ((cVar1 == '\x04' || (cVar1 == '\x03')))) {
    if (*(char *)(param_1 + 7) == '\x02') {
      if (*(short *)(param_1 + 0xc) < 1) {
        *(undefined1 *)(param_1 + 7) = 1;
      }
      else {
        *(short *)(param_1 + 0xc) = *(short *)(param_1 + 0xc) + -0xf;
      }
    }
    else if (*(char *)(param_1 + 7) == '\x01') {
      if (*(short *)(param_1 + 0xc) < 0xff) {
        *(short *)(param_1 + 0xc) = *(short *)(param_1 + 0xc) + 0xf;
      }
      else {
        *(undefined1 *)(param_1 + 7) = 2;
      }
    }
    cVar1 = *(char *)(param_1 + 6);
  }
  else {
    cVar1 = *(char *)(param_1 + 6);
  }
  if (cVar1 == 'c') {
    FUN_005dfee0();
    *(char *)(iRam00701068 + 0x60dc4) = *(char *)(iRam00701068 + 0x60dc4) + '\x01';
  }
  else if (cVar1 == '\a') {
    FUN_005e5650();
  }
  else if (cVar1 == '\x06') {
    FUN_005e5200();
  }
  else if (cVar1 == '\x05') {
    FUN_005e4f10();
  }
  else if (cVar1 == '\x04') {
    FUN_005e4b00();
  }
  else if (cVar1 == '\x03') {
    FUN_005e4af0();
  }
  else if ((cVar1 == '\x02') || (cVar1 == '\x01')) {
    sVar2 = *(short *)(param_1 + 10);
    *(short *)(param_1 + 10) = sVar2 + 1;
    if (600 < sVar2) {
      *(undefined2 *)(param_1 + 10) = 0;
    }
    if (-1 < *(short *)(param_1 + 10)) {
      if (*(char *)(param_1 + 7) == '\x02') {
        if (*(short *)(param_1 + 0xc) < 1) {
          *(undefined1 *)(param_1 + 7) = 1;
        }
        else {
          *(short *)(param_1 + 0xc) = *(short *)(param_1 + 0xc) + -0xf;
        }
      }
      else if (*(char *)(param_1 + 7) == '\x01') {
        if (*(short *)(param_1 + 0xc) < 0xff) {
          *(short *)(param_1 + 0xc) = *(short *)(param_1 + 0xc) + 0xf;
        }
        else {
          *(undefined1 *)(param_1 + 7) = 2;
        }
      }
      uVar3 = FUN_005de330(9,1);
      FUN_005ddc20(0x43a90000,0x43b60000,0xe,0xffffffffff000001,0,0x28,uVar3);
      uVar3 = FUN_005de330(9,1);
      FUN_005ddc20(0x43a80000,0x43b50000,0xd,0xffffffffffffffff,0,0x28,uVar3);
    }
  }
  else if (cVar1 == '\0') {
    *(undefined2 *)(param_1 + 10) = 0;
  }
  return;
}



================================================================