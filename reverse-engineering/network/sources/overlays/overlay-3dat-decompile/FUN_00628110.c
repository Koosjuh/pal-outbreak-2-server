FUNCTION FUN_00628110 @ 0x00628110  size=256
CALLERS (1): FUN_00627d60@0x00627d60
CALLEES (2): FUN_005b14b0@0x005b14b0, FUN_005b7fd0@0x005b7fd0
----------------------------------------------------------------

undefined4 FUN_00628110(int param_1,undefined1 *param_2)

{
  char cVar1;
  long lVar2;
  
  cVar1 = param_2[1];
  if (cVar1 == '\x02') {
    *(short *)(param_2 + 4) = *(short *)(param_2 + 4) + -1;
    if (*(short *)(param_2 + 4) < 0) {
      *param_2 = 4;
      param_2[1] = 0;
    }
  }
  else if (cVar1 == '\x01') {
    lVar2 = FUN_005b14b0(0x10);
    if (lVar2 == 0) {
      lVar2 = FUN_005b14b0(0x200);
      if (lVar2 != 0) {
        *param_2 = 0;
        param_2[1] = 0;
        *(undefined1 *)(param_1 + 0x443) = 1;
        func_0x001b0140(2);
      }
    }
    else {
      param_2[1] = param_2[1] + '\x01';
      *(undefined2 *)(param_2 + 4) = 8;
      func_0x001b0140(1);
    }
  }
  else if (cVar1 == '\0') {
    FUN_005b7fd0(0x11,0,param_2 + 0xe,param_2[8]);
    param_2[1] = param_2[1] + '\x01';
  }
  return 0xffffffff;
}



================================================================