FUNCTION FUN_005fb710 @ 0x005fb710  size=128
CALLERS (1): FUN_005f8e20@0x005f8e20
CALLEES (4): FUN_005fb9b0@0x005fb9b0, FUN_005f8060@0x005f8060, FUN_005fb790@0x005fb790, FUN_005fb860@0x005fb860
----------------------------------------------------------------

void FUN_005fb710(int param_1)

{
  char cVar1;
  
  cVar1 = *(char *)(param_1 + 0xf);
  if (cVar1 == '\x03') {
    FUN_005f8060();
  }
  else if (cVar1 == '\x02') {
    FUN_005fb9b0();
  }
  else if (cVar1 == '\x01') {
    FUN_005fb860();
  }
  else if (cVar1 == '\0') {
    FUN_005fb790();
  }
  return;
}



================================================================