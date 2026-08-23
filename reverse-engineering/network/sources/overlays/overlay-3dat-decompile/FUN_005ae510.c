FUNCTION FUN_005ae510 @ 0x005ae510  size=288
CALLERS (1): FUN_005ae3e0@0x005ae3e0
CALLEES (6): FUN_00637180@0x00637180, FUN_005af2e0@0x005af2e0, FUN_005b9110@0x005b9110, FUN_005af2c0@0x005af2c0, FUN_005af1e0@0x005af1e0, FUN_005b9060@0x005b9060
----------------------------------------------------------------

void FUN_005ae510(int param_1)

{
  char cVar1;
  undefined1 auStack_20 [32];
  
  cVar1 = *(char *)(param_1 + 0x54b5);
  if (cVar1 == '\x03') {
    *(short *)(param_1 + 0x54ba) = *(short *)(param_1 + 0x54ba) + -1;
    if (*(short *)(param_1 + 0x54ba) == 0) {
      *(char *)(param_1 + 0x54b4) = *(char *)(param_1 + 0x54b4) + '\x01';
      *(undefined1 *)(param_1 + 0x54b5) = 0;
      *(undefined2 *)(param_1 + 0x54ba) = 0;
    }
    FUN_005af2c0(0);
    FUN_005af2e0(0x14);
    func_0x00109728(auStack_20,0x638858,(int)*(short *)(param_1 + 0x54ba) / 0x1e);
    FUN_005af1e0(0x1f2,0x4c,2,auStack_20);
  }
  else if (cVar1 == '\x02') {
    if (*(char *)(param_1 + 0x54bd) != '\0') {
      *(undefined1 *)(param_1 + 0x54b5) = 3;
      *(undefined2 *)(param_1 + 0x54ba) = 300;
    }
  }
  else if (cVar1 == '\x01') {
    *(undefined1 *)(param_1 + 0x54b5) = 2;
    *(undefined1 *)(param_1 + 0x51a2) = 2;
    FUN_005b9060(1,param_1 + 0x51b4);
  }
  else if (cVar1 == '\0') {
    *(undefined1 *)(param_1 + 0x54b5) = 1;
    FUN_005b9110(0x4c);
    FUN_00637180();
  }
  return;
}



================================================================