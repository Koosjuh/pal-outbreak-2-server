FUNCTION FUN_005acda0 @ 0x005acda0  size=72
CALLERS (1): FUN_00601700@0x00601700
CALLEES (2): FUN_00637180@0x00637180, FUN_005af120@0x005af120
----------------------------------------------------------------

void FUN_005acda0(undefined1 *param_1,undefined1 param_2)

{
  *param_1 = 1;
  param_1[0xe] = 3;
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  uRam006c45f8 = param_2;
  FUN_00637180();
  FUN_005af120(0x6c4b90,0);
  return;
}



================================================================
FUNCTION thunk_FUN_005ace00 @ 0x005acdf0  size=8
CALLERS (1): FUN_005acab0@0x005acab0
CALLEES (0): 
----------------------------------------------------------------

void thunk_FUN_005ace00(undefined8 param_1)

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