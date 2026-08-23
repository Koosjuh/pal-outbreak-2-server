FUNCTION FUN_005ffb20 @ 0x005ffb20  size=184
CALLERS (1): FUN_005ff9f0@0x005ff9f0
CALLEES (2): FUN_005c2390@0x005c2390, FUN_005c2340@0x005c2340
----------------------------------------------------------------

void FUN_005ffb20(int param_1)

{
  char cVar1;
  short sVar2;
  
  cVar1 = *(char *)(param_1 + 0xf);
  if (cVar1 == '\x02') {
    *(char *)(param_1 + 0xe) = *(char *)(param_1 + 0xe) + '\x01';
    *(undefined1 *)(param_1 + 0xf) = 0;
  }
  else if (cVar1 == '\x01') {
    sVar2 = *(short *)(param_1 + 0x16) + -1;
    *(short *)(param_1 + 0x16) = sVar2;
    if (sVar2 < 0) {
      *(char *)(param_1 + 0xf) = *(char *)(param_1 + 0xf) + '\x01';
      *(undefined2 *)(param_1 + 0x16) = 0;
    }
  }
  else if (cVar1 == '\0') {
    FUN_005c2390(0x601580);
    FUN_005c2340(0x601690);
    *(char *)(param_1 + 0xf) = *(char *)(param_1 + 0xf) + '\x01';
    *(undefined2 *)(param_1 + 0x16) = 0x10;
  }
  return;
}



================================================================