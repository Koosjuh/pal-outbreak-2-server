FUNCTION FUN_0062c870 @ 0x0062c870  size=248
CALLERS (1): FUN_0062c350@0x0062c350
CALLEES (3): FUN_005b9110@0x005b9110, FUN_005b9060@0x005b9060, FUN_005b8cf0@0x005b8cf0
----------------------------------------------------------------

void FUN_0062c870(int param_1,undefined1 *param_2)

{
  char cVar1;
  short sVar2;
  
  cVar1 = param_2[2];
  if (cVar1 == '\x03') {
    param_2[2] = 1;
    *(undefined2 *)(param_2 + 4) = 0x88;
    FUN_005b8cf0(*(char *)(param_1 + 0x10b4) + -0x78);
  }
  else if (cVar1 == '\x02') {
    *param_2 = 1;
    param_2[1] = 0;
    param_2[2] = 0;
  }
  else if (cVar1 == '\x01') {
    sVar2 = *(short *)(param_2 + 4);
    *(short *)(param_2 + 4) = sVar2 + -1;
    if ((short)(sVar2 + -1) < 1) {
      param_2[2] = param_2[2] + '\x01';
      FUN_005b9110(0x4c);
    }
  }
  else if ((cVar1 == '\0') &&
          (*(short *)(param_2 + 4) = *(short *)(param_2 + 4) + -1, *(short *)(param_2 + 4) < 1)) {
    param_2[2] = param_2[2] + '\x01';
    *(undefined2 *)(param_2 + 4) = 0x88;
    FUN_005b9060(0x14,param_1 + 0x5ec);
  }
  return;
}



================================================================