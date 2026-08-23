FUNCTION FUN_005ff9f0 @ 0x005ff9f0  size=152
CALLERS (1): FUN_005ff950@0x005ff950
CALLEES (5): FUN_005ffbe0@0x005ffbe0, FUN_005ffa90@0x005ffa90, FUN_005ffb20@0x005ffb20, FUN_00600d10@0x00600d10, FUN_00600200@0x00600200
----------------------------------------------------------------

void FUN_005ff9f0(int param_1)

{
  char cVar1;
  
  cVar1 = *(char *)(param_1 + 0xe);
  if (cVar1 == '\x04') {
    FUN_00600d10();
  }
  else if (cVar1 == '\x03') {
    FUN_00600200();
  }
  else if (cVar1 == '\x02') {
    FUN_005ffbe0();
  }
  else if (cVar1 == '\x01') {
    FUN_005ffb20();
  }
  else if (cVar1 == '\0') {
    FUN_005ffa90();
  }
  return;
}



================================================================