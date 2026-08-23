FUNCTION FUN_00628210 @ 0x00628210  size=1140
CALLERS (1): FUN_00627d60@0x00627d60
CALLEES (11): FUN_005b1460@0x005b1460, FUN_0061ded0@0x0061ded0, FUN_006278e0@0x006278e0, FUN_005b9110@0x005b9110, FUN_005b0cd0@0x005b0cd0, FUN_005b8e40@0x005b8e40, FUN_005b1420@0x005b1420, FUN_005af400@0x005af400, FUN_005af3e0@0x005af3e0, FUN_005af3c0@0x005af3c0, FUN_005b8cf0@0x005b8cf0
----------------------------------------------------------------

undefined4 FUN_00628210(int param_1,undefined1 *param_2)

{
  char cVar1;
  short sVar2;
  long lVar3;
  int iVar4;
  
  switch(param_2[1]) {
  case 0:
    param_2[1] = param_2[1] + '\x01';
    *(undefined1 *)(param_1 + 0x43c) = 1;
    *(undefined2 *)(param_2 + 4) = 0x10;
    FUN_005b8e40(0x3c,param_1 + 0x43c,
                 ((int)*(short *)(param_2 + 0xc) + (int)*(short *)(param_2 + 10)) * 0x38 + 0x694700)
    ;
    func_0x00106b60(param_1 + 0xefa,0,0xa5);
    func_0x0010a4f0(param_1 + 0xefb,
                    ((int)*(short *)(param_2 + 0xc) + (int)*(short *)(param_2 + 10)) * 0x38 +
                    0x694700,0x10);
    func_0x0010a4f0(param_1 + 0xf0b,
                    ((int)*(short *)(param_2 + 0xc) + (int)*(short *)(param_2 + 10)) * 0x38 +
                    0x694710,0x10);
    break;
  case 1:
    sVar2 = *(short *)(param_2 + 4);
    *(short *)(param_2 + 4) = sVar2 + -1;
    if ((short)(sVar2 + -1) < 1) {
      param_2[1] = param_2[1] + '\x01';
    }
    break;
  case 2:
    lVar3 = FUN_005b1460();
    if (lVar3 == 0) {
      lVar3 = FUN_005b1420(2);
      if (lVar3 == 0) {
        FUN_005b0cd0(param_1 + 0x43c,1,3);
      }
      else {
        param_2[1] = param_2[1] + '\x01';
        *(undefined1 *)(param_1 + 0x43f) = 1;
        *(undefined2 *)(param_2 + 4) = 8;
        func_0x001b0140();
      }
    }
    else {
      func_0x001b0140();
      *(undefined1 *)(param_1 + 0x45a) = 1;
      *param_2 = 1;
      param_2[1] = 0;
      *(undefined2 *)(param_2 + 4) = 6;
      FUN_005b9110(0x3c);
    }
    break;
  case 3:
    *(short *)(param_2 + 4) = *(short *)(param_2 + 4) + -1;
    if (*(short *)(param_2 + 4) < 0) {
      *(undefined2 *)(param_2 + 4) = 6;
      FUN_005b9110(0x3c);
      if (*(char *)(param_1 + 0x43c) == '\0') {
        param_2[1] = 4;
      }
      else {
        param_2[1] = 6;
        param_2[2] = 2;
        *(undefined1 *)(param_1 + 0x45a) = 1;
      }
    }
    break;
  case 4:
    iVar4 = (int)*(short *)(param_2 + 0xc) + (int)*(short *)(param_2 + 10) + 1;
    func_0x001069a8(((int)*(short *)(param_2 + 0xc) + (int)*(short *)(param_2 + 10)) * 0x38 +
                    0x694700,iVar4 * 0x38 + 0x694700,(0x32 - iVar4) * 0x38);
    func_0x00106b60(0x6951b8,0,0x38);
    param_2[1] = param_2[1] + '\x01';
    param_2[2] = 0;
    *(undefined1 *)(param_1 + 0x45a) = 0;
    FUN_005af3c0();
    break;
  case 5:
    lVar3 = FUN_0061ded0();
    if (lVar3 != 0) {
      if (lVar3 < 0) {
        param_2[2] = 10;
        FUN_005af400();
        *param_2 = 1;
        param_2[1] = 0;
        param_2[2] = 0;
        *(undefined1 *)(param_1 + 0x45a) = 1;
        FUN_006278e0(0x694700);
      }
      else {
        param_2[2] = 3;
        FUN_005af3e0();
        param_2[1] = 6;
        param_2[2] = 0;
        *(undefined1 *)(param_1 + 0x45a) = 1;
        FUN_006278e0(0x694700);
      }
    }
    break;
  case 6:
    cVar1 = param_2[2];
    if (cVar1 == '\x02') {
      sVar2 = *(short *)(param_2 + 4);
      *(short *)(param_2 + 4) = sVar2 + -1;
      if ((short)(sVar2 + -1) < 1) {
        *param_2 = 1;
        param_2[1] = 0;
      }
    }
    else if (cVar1 == '\x01') {
      sVar2 = *(short *)(param_2 + 4);
      *(short *)(param_2 + 4) = sVar2 + -1;
      if ((short)(sVar2 + -1) < 1) {
        param_2[2] = param_2[2] + '\x01';
        *(undefined2 *)(param_2 + 4) = 6;
        FUN_005b9110(0x4c);
      }
    }
    else if (cVar1 == '\0') {
      param_2[2] = 1;
      *(short *)(param_2 + 8) = *(short *)(param_2 + 8) + -1;
      if ((char)*(short *)(param_2 + 8) < '\x01') {
        *(undefined2 *)(param_2 + 8) = 0;
        *(undefined2 *)(param_2 + 0xc) = 0;
        *(undefined2 *)(param_2 + 10) = 0;
        *(undefined1 *)(param_1 + 0x443) = 1;
      }
      else {
        iVar4 = (int)*(short *)(param_2 + 10) + *(short *)(param_2 + 0xc) * 8;
        if (iVar4 < 8) {
          *(undefined2 *)(param_2 + 0xc) = 0;
          if (*(short *)(param_2 + 8) <= *(short *)(param_2 + 10)) {
            *(short *)(param_2 + 10) = *(short *)(param_2 + 8) + -1;
          }
        }
        else if ((*(short *)(param_2 + 8) + -8 < iVar4) &&
                (*(short *)(param_2 + 0xc) = *(short *)(param_2 + 0xc) + -1,
                (char)param_2[0xc] < '\0')) {
          *(undefined2 *)(param_2 + 0xc) = 0;
        }
      }
      *(undefined2 *)(param_2 + 4) = 0x4c;
      FUN_005b8cf0(0xffffffffffffff83);
    }
  }
  return 0xffffffff;
}



================================================================