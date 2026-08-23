FUNCTION FUN_005b29b0 @ 0x005b29b0  size=228
CALLERS (1): FUN_005b24e0@0x005b24e0
CALLEES (3): FUN_005b14b0@0x005b14b0, FUN_005af2c0@0x005af2c0, FUN_005af1e0@0x005af1e0
----------------------------------------------------------------

void FUN_005b29b0(int param_1)

{
  char cVar1;
  long lVar2;
  
  cVar1 = *(char *)(param_1 + 0xf);
  if (cVar1 == '\x03') {
    *(undefined1 *)(param_1 + 0xe) = 2;
    *(undefined1 *)(param_1 + 0xf) = 0;
  }
  else if (cVar1 == '\x02') {
    *(undefined1 *)(param_1 + 0xf) = 3;
  }
  else if (cVar1 == '\x01') {
    lVar2 = FUN_005b14b0(0x10);
    if (lVar2 != 0) {
      *(char *)(param_1 + 0xf) = *(char *)(param_1 + 0xf) + '\x01';
    }
    FUN_005af2c0(0);
    FUN_005af1e0(0x10e,0x104,2,0x638c70);
    FUN_005af1e0(0x109,0x11b,2,0x638c90);
    FUN_005af1e0(0x109,0x132,2,0x638cb0);
  }
  else if (cVar1 == '\0') {
    *(undefined1 *)(param_1 + 0xf) = 1;
  }
  return;
}



================================================================