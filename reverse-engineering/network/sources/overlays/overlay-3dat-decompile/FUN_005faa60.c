FUNCTION FUN_005faa60 @ 0x005faa60  size=828
CALLERS (1): FUN_005fa0b0@0x005fa0b0
CALLEES (11): FUN_00637180@0x00637180, FUN_006345e0@0x006345e0, FUN_005adc80@0x005adc80, FUN_005b9110@0x005b9110, FUN_005b14b0@0x005b14b0, FUN_00634ab0@0x00634ab0, FUN_006371d0@0x006371d0, FUN_005b7fd0@0x005b7fd0, FUN_005b4c80@0x005b4c80, FUN_005fb670@0x005fb670, FUN_005b09b0@0x005b09b0
----------------------------------------------------------------

void FUN_005faa60(int param_1)

{
  char cVar1;
  int iVar2;
  long lVar3;
  
  lVar3 = FUN_005fb670();
  if (lVar3 == 0) {
    switch(*(undefined1 *)(param_1 + 0x10)) {
    case 0:
      iVar2 = FUN_005adc80(2);
      if (*(char *)((iVar2 + -1) * 0x15c + 0x6c076f) == '\0') {
        *(undefined1 *)(param_1 + 0x10) = 9;
      }
      else {
        *(char *)(param_1 + 0x10) = *(char *)(param_1 + 0x10) + '\x01';
        *(undefined2 *)(param_1 + 0x16) = 0x10;
        FUN_005b4c80(5);
      }
      break;
    case 1:
      *(short *)(param_1 + 0x16) = *(short *)(param_1 + 0x16) + -1;
      if (*(short *)(param_1 + 0x16) < 0) {
        *(char *)(param_1 + 0x10) = *(char *)(param_1 + 0x10) + '\x01';
        func_0x00106b60(0x6970a2,0,0x10);
        FUN_006371d0(0x42980000,0x118);
        FUN_006345e0(1,0,8,0x6970a2);
      }
      break;
    case 2:
      cVar1 = FUN_00634ab0(0x6970a2,uRam006c4610,uRam006c4618 | uRam006c4620);
      if ((cVar1 == -1) || (cVar1 == '\x01')) {
        *(char *)(param_1 + 0x10) = *(char *)(param_1 + 0x10) + '\x01';
        *(undefined2 *)(param_1 + 0x16) = 6;
        FUN_005b9110(0x4c);
        FUN_00637180();
      }
      break;
    case 3:
      *(short *)(param_1 + 0x16) = *(short *)(param_1 + 0x16) + -1;
      if (*(short *)(param_1 + 0x16) < 0) {
        *(char *)(param_1 + 0x10) = *(char *)(param_1 + 0x10) + '\x01';
        *(undefined2 *)(param_1 + 0x16) = 0x10;
        FUN_005b4c80(8);
      }
      break;
    case 4:
      *(short *)(param_1 + 0x16) = *(short *)(param_1 + 0x16) + -1;
      if (*(short *)(param_1 + 0x16) < 0) {
        *(char *)(param_1 + 0x10) = *(char *)(param_1 + 0x10) + '\x01';
        *(undefined1 *)(param_1 + 0x43c) = 0;
        FUN_005b7fd0(0x19,0,param_1 + 0x43c,0);
      }
      break;
    case 5:
      *(short *)(param_1 + 0x16) = *(short *)(param_1 + 0x16) + -1;
      if (*(short *)(param_1 + 0x16) < 0) {
        *(char *)(param_1 + 0x10) = *(char *)(param_1 + 0x10) + '\x01';
      }
      break;
    case 6:
      lVar3 = FUN_005b09b0(param_1 + 0x43c,1,3);
      if (lVar3 == 0) {
        lVar3 = FUN_005b14b0(0x10);
        if (lVar3 == 0) {
          lVar3 = FUN_005b14b0(0x200);
          if ((lVar3 != 0) && (*(char *)(param_1 + 0x43c) == '\0')) {
            func_0x001b0140(2);
            *(undefined1 *)(param_1 + 0x43c) = 1;
          }
        }
        else {
          *(char *)(param_1 + 0x10) = *(char *)(param_1 + 0x10) + '\x01';
          func_0x001b0140(1);
          *(undefined2 *)(param_1 + 0x16) = 8;
        }
      }
      break;
    case 7:
      *(short *)(param_1 + 0x16) = *(short *)(param_1 + 0x16) + -1;
      if (*(short *)(param_1 + 0x16) < 0) {
        *(undefined1 *)(param_1 + 0x443) = 1;
        FUN_005b9110(0x4c);
        if (*(char *)(param_1 + 0x43c) == '\x01') {
          *(char *)(param_1 + 0x10) = *(char *)(param_1 + 0x10) + '\x01';
        }
        else if (*(char *)(param_1 + 0x43c) == '\0') {
          *(undefined1 *)(param_1 + 0x10) = 9;
        }
      }
      break;
    case 8:
      *(undefined1 *)(param_1 + 0xf) = 1;
      *(undefined1 *)(param_1 + 0x10) = 0;
      break;
    case 9:
      *(undefined1 *)(param_1 + 0xf) = 3;
      *(undefined1 *)(param_1 + 0x10) = 0;
    }
  }
  else {
    *(undefined1 *)(param_1 + 0xf) = 4;
    *(undefined1 *)(param_1 + 0x10) = 0;
  }
  return;
}



================================================================