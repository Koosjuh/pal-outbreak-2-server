FUNCTION FUN_00617030 @ 0x00617030  size=216
CALLERS (1): FUN_00616c40@0x00616c40
CALLEES (2): FUN_005af300@0x005af300, FUN_00618b60@0x00618b60
----------------------------------------------------------------

void FUN_00617030(int param_1)

{
  char cVar1;
  short sVar2;
  
  cVar1 = *(char *)(param_1 + 0xf);
  if (cVar1 == '\x02') {
    sVar2 = *(short *)(param_1 + 0x16) + -1;
    *(short *)(param_1 + 0x16) = sVar2;
    if (sVar2 < 0) {
      *(char *)(param_1 + 0xe) = *(char *)(param_1 + 0xe) + '\x01';
      *(undefined1 *)(param_1 + 0xf) = 0;
    }
  }
  else if (cVar1 == '\x01') {
    sVar2 = *(short *)(param_1 + 0x16) + -1;
    *(short *)(param_1 + 0x16) = sVar2;
    if (sVar2 < 0) {
      FUN_00618b60();
      *(char *)(param_1 + 0xf) = *(char *)(param_1 + 0xf) + '\x01';
      *(undefined2 *)(param_1 + 0x16) = 2;
      func_0x003adb80();
    }
  }
  else if (cVar1 == '\0') {
    *(undefined1 *)(param_1 + 0xf) = 1;
    *(undefined2 *)(param_1 + 0x16) = 10;
    FUN_005af300(0);
  }
  return;
}



================================================================