FUNCTION FUN_005f8e20 @ 0x005f8e20  size=152
CALLERS (1): FUN_005f8d40@0x005f8d40
CALLEES (5): FUN_005fb710@0x005fb710, FUN_005f8fc0@0x005f8fc0, FUN_005f8ec0@0x005f8ec0, FUN_005f9150@0x005f9150, FUN_005fa0b0@0x005fa0b0
----------------------------------------------------------------

void FUN_005f8e20(int param_1)

{
  char cVar1;
  
  cVar1 = *(char *)(param_1 + 0xe);
  if (cVar1 == '\x04') {
    FUN_005fb710();
  }
  else if (cVar1 == '\x03') {
    FUN_005f9150();
  }
  else if (cVar1 == '\x02') {
    FUN_005fa0b0();
  }
  else if (cVar1 == '\x01') {
    FUN_005f8fc0();
  }
  else if (cVar1 == '\0') {
    FUN_005f8ec0();
  }
  return;
}



================================================================