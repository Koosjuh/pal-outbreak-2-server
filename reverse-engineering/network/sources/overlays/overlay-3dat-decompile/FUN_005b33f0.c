FUNCTION FUN_005b33f0 @ 0x005b33f0  size=284
CALLERS (1): FUN_005b24e0@0x005b24e0
CALLEES (7): FUN_005af310@0x005af310, FUN_005ba7b0@0x005ba7b0, FUN_005af2f0@0x005af2f0, FUN_005af300@0x005af300, FUN_005b14b0@0x005b14b0, FUN_00618b60@0x00618b60, FUN_005b9060@0x005b9060
----------------------------------------------------------------

void FUN_005b33f0(int param_1)

{
  char cVar1;
  long lVar2;
  
  cVar1 = *(char *)(param_1 + 0xf);
  if (cVar1 == '\x02') {
    lVar2 = FUN_005af310();
    if (lVar2 != 0) {
      FUN_00618b60();
      *(undefined1 *)(param_1 + 0xe) = 3;
      *(undefined1 *)(param_1 + 0xf) = 1;
    }
  }
  else if (cVar1 == '\x01') {
    *(short *)(param_1 + 0x16) = *(short *)(param_1 + 0x16) + -1;
    if (*(short *)(param_1 + 0x16) < 1) {
      *(char *)(param_1 + 0xf) = *(char *)(param_1 + 0xf) + '\x01';
      FUN_005af300(0,10);
    }
    else if ((*(short *)(param_1 + 0x16) < 0xf0) && (lVar2 = FUN_005b14b0(0x10), lVar2 != 0)) {
      *(char *)(param_1 + 0xf) = *(char *)(param_1 + 0xf) + '\x01';
      func_0x001b0140(1);
      FUN_005af300(0,10);
    }
  }
  else if (cVar1 == '\0') {
    *(undefined1 *)(param_1 + 0xf) = 1;
    *(undefined2 *)(param_1 + 0x16) = 300;
    FUN_005b9060(0,param_1 + 0x5ec);
    FUN_005ba7b0();
    FUN_005af2f0(0,10);
  }
  return;
}



================================================================