FUNCTION FUN_005ace00 @ 0x005ace00  size=148
CALLERS (0): 
CALLEES (5): FUN_005af1a0@0x005af1a0, FUN_005ad530@0x005ad530, FUN_005acea0@0x005acea0, FUN_005ad030@0x005ad030, FUN_005ad680@0x005ad680
----------------------------------------------------------------

void FUN_005ace00(undefined8 param_1)

{
  char cVar1;
  
  cVar1 = *(char *)((int)param_1 + 0xe);
  if (cVar1 == '\x03') {
    FUN_005ad680();
  }
  else if (cVar1 == '\x02') {
    FUN_005ad530();
  }
  else if (cVar1 == '\x01') {
    FUN_005ad030();
  }
  else if (cVar1 == '\0') {
    FUN_005acea0();
  }
  FUN_005af1a0(param_1,0);
  return;
}



================================================================