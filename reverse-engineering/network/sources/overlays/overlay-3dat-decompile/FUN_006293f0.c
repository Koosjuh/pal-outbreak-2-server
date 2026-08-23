FUNCTION FUN_006293f0 @ 0x006293f0  size=676
CALLERS (1): FUN_00628e10@0x00628e10
CALLEES (9): FUN_005b1460@0x005b1460, FUN_005af440@0x005af440, FUN_00604860@0x00604860, FUN_005b0cd0@0x005b0cd0, FUN_005b9110@0x005b9110, FUN_005b14b0@0x005b14b0, FUN_005b1420@0x005b1420, FUN_005b8da0@0x005b8da0, FUN_005b8cf0@0x005b8cf0
----------------------------------------------------------------

undefined4 FUN_006293f0(int param_1,undefined1 *param_2)

{
  char cVar1;
  long lVar2;
  
  cVar1 = param_2[1];
  switch(cVar1) {
  case '\0':
    param_2[1] = cVar1 + '\x01';
    lVar2 = FUN_00604860(0x870880,0x1e,param_1 + 0xefb);
    if (lVar2 != -1) {
      param_2[1] = 7;
      *(undefined2 *)(param_2 + 4) = 0x13c;
      FUN_005b8cf0(5);
    }
    break;
  case '\x01':
    param_2[1] = cVar1 + '\x01';
    *(undefined1 *)(param_1 + 0x90b) = 1;
    *(undefined2 *)(param_2 + 4) = 0x10;
    FUN_005b8da0(0x5d,param_1 + 0x90b);
    break;
  case '\x02':
    *(short *)(param_2 + 4) = *(short *)(param_2 + 4) + -1;
    if (*(short *)(param_2 + 4) < 0) {
      param_2[1] = param_2[1] + '\x01';
    }
    break;
  case '\x03':
    FUN_005b0cd0(param_1 + 0x90b,1,3);
    lVar2 = FUN_005b1420();
    if (lVar2 == 0) {
      lVar2 = FUN_005b1460();
      if (lVar2 != 0) {
        func_0x001b0140(2);
        *param_2 = 2;
        param_2[1] = 0;
        FUN_005b9110(0x5d);
      }
    }
    else {
      *(undefined1 *)(param_1 + 0x43f) = 1;
      param_2[1] = param_2[1] + '\x01';
      *(undefined2 *)(param_2 + 4) = 8;
      func_0x001b0140();
    }
    break;
  case '\x04':
    *(short *)(param_2 + 4) = *(short *)(param_2 + 4) + -1;
    if (*(short *)(param_2 + 4) < 0) {
      if (*(char *)(param_1 + 0x90b) == '\0') {
        param_2[1] = 5;
        *(undefined2 *)(param_2 + 4) = 6;
        FUN_005b9110(0x5d);
        lVar2 = FUN_005af440(0x870880,param_1 + 0xefb);
        if (lVar2 != 0) {
          param_2[1] = 6;
        }
      }
      else {
        *param_2 = 2;
        param_2[1] = 0;
        FUN_005b9110(0x5d);
      }
    }
    break;
  case '\x05':
    *(short *)(param_2 + 4) = *(short *)(param_2 + 4) + -1;
    if (*(short *)(param_2 + 4) == 0) {
      param_2[1] = 7;
      *(undefined2 *)(param_2 + 4) = 0x13c;
      FUN_005b8cf0(0x5e);
    }
    break;
  case '\x06':
    *(short *)(param_2 + 4) = *(short *)(param_2 + 4) + -1;
    if (*(short *)(param_2 + 4) == 0) {
      param_2[1] = param_2[1] + '\x01';
      *(undefined2 *)(param_2 + 4) = 0x13c;
      FUN_005b8cf0(99);
    }
    break;
  case '\a':
    *(short *)(param_2 + 4) = *(short *)(param_2 + 4) + -1;
    if ((*(short *)(param_2 + 4) < 0) ||
       ((*(short *)(param_2 + 4) < 0xb4 && (lVar2 = FUN_005b14b0(0x210), lVar2 != 0)))) {
      *param_2 = 2;
      param_2[1] = 0;
      *(undefined2 *)(param_2 + 4) = 1;
      FUN_005b9110(0x4c);
    }
  }
  return 0xffffffff;
}



================================================================