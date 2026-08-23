FUNCTION FUN_005f7800 @ 0x005f7800  size=180
CALLERS (1): FUN_005f76f0@0x005f76f0
CALLEES (6): FUN_005f8030@0x005f8030, FUN_005af1a0@0x005af1a0, FUN_005f78c0@0x005f78c0, FUN_005f8220@0x005f8220, FUN_005f7c80@0x005f7c80, FUN_005f7f30@0x005f7f30
----------------------------------------------------------------

void FUN_005f7800(undefined8 param_1)

{
  char cVar1;
  
  *(undefined1 *)((int)param_1 + 0x45a) = 1;
  cVar1 = *(char *)((int)param_1 + 0xe);
  if (cVar1 == '\x04') {
    FUN_005f8220();
  }
  else if (cVar1 == '\x03') {
    FUN_005f8030();
  }
  else if (cVar1 == '\x02') {
    FUN_005f7f30();
  }
  else if (cVar1 == '\x01') {
    FUN_005f7c80();
  }
  else if (cVar1 == '\0') {
    FUN_005f78c0();
  }
  FUN_005af1a0(param_1,1);
  return;
}



================================================================