FUNCTION FUN_006296a0 @ 0x006296a0  size=928
CALLERS (1): FUN_00628e10@0x00628e10
CALLEES (13): FUN_005b1460@0x005b1460, FUN_005b0cd0@0x005b0cd0, FUN_005b1420@0x005b1420, FUN_005af3e0@0x005af3e0, FUN_005b8da0@0x005b8da0, FUN_005b8cf0@0x005b8cf0, FUN_0061ded0@0x0061ded0, FUN_00604860@0x00604860, FUN_006278e0@0x006278e0, FUN_005b9110@0x005b9110, FUN_005af400@0x005af400, FUN_006049b0@0x006049b0, ...
----------------------------------------------------------------

undefined4 FUN_006296a0(int param_1,undefined1 *param_2)

{
  char cVar1;
  short sVar2;
  long lVar3;
  
  cVar1 = param_2[1];
  switch(cVar1) {
  case '\0':
    param_2[1] = cVar1 + '\x01';
    lVar3 = FUN_00604860(0x694700,0x32,param_1 + 0xefb);
    if ((lVar3 != -1) &&
       (lVar3 = func_0x0010a338((int)lVar3 * 0x38 + 0x694710,param_1 + 0xf0b,0x10), lVar3 == 0)) {
      param_2[1] = 9;
      *(undefined2 *)(param_2 + 4) = 0x88;
      FUN_005b8cf0(5);
    }
    break;
  case '\x01':
    param_2[1] = cVar1 + '\x01';
    *(undefined1 *)(param_1 + 0x43c) = 1;
    *(undefined2 *)(param_2 + 4) = 0x10;
    FUN_005b8da0(0x20,param_1 + 0x43c);
    break;
  case '\x02':
    *(short *)(param_2 + 4) = *(short *)(param_2 + 4) + -1;
    if (*(short *)(param_2 + 4) == 0) {
      param_2[1] = param_2[1] + '\x01';
    }
    break;
  case '\x03':
    FUN_005b0cd0(param_1 + 0x43c,1,3);
    lVar3 = FUN_005b1420();
    if (lVar3 == 0) {
      lVar3 = FUN_005b1460();
      if (lVar3 != 0) {
        *param_2 = 2;
        param_2[1] = 0;
        func_0x001b0140();
        FUN_005b9110(0x20);
      }
    }
    else {
      param_2[1] = param_2[1] + '\x01';
      *(undefined1 *)(param_1 + 0x43f) = 1;
      *(undefined2 *)(param_2 + 4) = 8;
      func_0x001b0140();
    }
    break;
  case '\x04':
    *(short *)(param_2 + 4) = *(short *)(param_2 + 4) + -1;
    if (*(short *)(param_2 + 4) < 0) {
      FUN_005b9110(0x20);
      if (*(char *)(param_1 + 0x43c) == '\0') {
        param_2[1] = param_2[1] + '\x01';
        *(undefined2 *)(param_2 + 4) = 0x10;
      }
      else {
        *param_2 = 2;
        param_2[1] = 0;
      }
    }
    break;
  case '\x05':
    sVar2 = *(short *)(param_2 + 4);
    *(short *)(param_2 + 4) = sVar2 + -1;
    if ((short)(sVar2 + -1) < 1) {
      param_2[1] = param_2[1] + '\x01';
      lVar3 = FUN_006049b0(0x694700,param_1 + 0xefb,param_1 + 0xf0b);
      if (lVar3 == -1) {
        param_2[1] = 9;
        *(undefined2 *)(param_2 + 4) = 0x88;
        FUN_005b8cf0(0x16);
      }
    }
    break;
  case '\x06':
    param_2[1] = cVar1 + '\x01';
    param_2[2] = 0;
    FUN_005af3c0();
    break;
  case '\a':
    cVar1 = param_2[2];
    if (cVar1 == '\x02') {
      *param_2 = 2;
      param_2[1] = 0;
      param_2[2] = 0;
      *(undefined1 *)(param_1 + 0x45a) = 1;
      FUN_006278e0(0x694700);
    }
    else if (cVar1 == '\x01') {
      param_2[1] = 8;
      param_2[2] = 0;
      *(undefined1 *)(param_1 + 0x45a) = 1;
      FUN_006278e0(0x694700);
    }
    else if ((cVar1 == '\0') && (lVar3 = FUN_0061ded0(), lVar3 != 0)) {
      if (lVar3 < 0) {
        FUN_005af400();
        param_2[2] = 1;
      }
      else {
        FUN_005af3e0();
        param_2[2] = 2;
      }
    }
    break;
  case '\b':
    param_2[1] = cVar1 + '\x01';
    *(undefined2 *)(param_2 + 4) = 0x88;
    FUN_005b8cf0(0x15);
    break;
  case '\t':
    sVar2 = *(short *)(param_2 + 4);
    *(short *)(param_2 + 4) = sVar2 + -1;
    if ((short)(sVar2 + -1) < 1) {
      param_2[1] = param_2[1] + '\x01';
      param_2[2] = 0;
      *(undefined2 *)(param_2 + 4) = 0x10;
      FUN_005b9110(0x4c);
    }
    break;
  case '\n':
    sVar2 = *(short *)(param_2 + 4);
    *(short *)(param_2 + 4) = sVar2 + -1;
    if ((short)(sVar2 + -1) < 1) {
      *param_2 = 2;
      param_2[1] = 0;
      param_2[2] = 0;
      *(undefined1 *)(param_1 + 0x45a) = 1;
    }
  }
  return 0xffffffff;
}



================================================================