FUNCTION FUN_005fb790 @ 0x005fb790  size=208
CALLERS (1): FUN_005fb710@0x005fb710
CALLEES (4): FUN_005b6900@0x005b6900, FUN_005b68e0@0x005b68e0, FUN_005bfdd0@0x005bfdd0, FUN_005b9060@0x005b9060
----------------------------------------------------------------

void FUN_005fb790(int param_1)

{
  char cVar1;
  short sVar2;
  
  cVar1 = *(char *)(param_1 + 0x10);
  if (cVar1 == '\x03') {
    FUN_005b6900();
  }
  else if (cVar1 == '\x02') {
    *(undefined1 *)(param_1 + 0x10) = 3;
    FUN_005b68e0();
    *(undefined1 *)(param_1 + 0x42b) = 0x12;
    FUN_005bfdd0(0x5fc610);
  }
  else if (cVar1 == '\x01') {
    sVar2 = *(short *)(param_1 + 0x16) + -1;
    *(short *)(param_1 + 0x16) = sVar2;
    if (sVar2 < 0) {
      *(char *)(param_1 + 0x10) = *(char *)(param_1 + 0x10) + '\x01';
    }
  }
  else if (cVar1 == '\0') {
    *(undefined1 *)(param_1 + 0x10) = 1;
    FUN_005b9060(0x14,param_1 + 0x5ec);
    *(undefined2 *)(param_1 + 0x16) = 0x2e;
  }
  return;
}



================================================================