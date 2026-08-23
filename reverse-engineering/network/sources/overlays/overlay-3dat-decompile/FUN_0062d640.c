FUNCTION FUN_0062d640 @ 0x0062d640  size=228
CALLERS (1): FUN_0062d5e0@0x0062d5e0
CALLEES (7): FUN_0062d730@0x0062d730, FUN_0062d810@0x0062d810, FUN_0062e8d0@0x0062e8d0, FUN_005f4b80@0x005f4b80, FUN_005f4be0@0x005f4be0, FUN_0062e3c0@0x0062e3c0, FUN_0062d950@0x0062d950
----------------------------------------------------------------

void FUN_0062d640(undefined8 param_1)

{
  char cVar1;
  long lVar2;
  
  cVar1 = *(char *)((int)param_1 + 0xe);
  if (cVar1 == '\x04') {
    FUN_0062e8d0();
  }
  else if (cVar1 == '\x03') {
    FUN_005f4b80();
    lVar2 = FUN_005f4be0();
    if (lVar2 == 0) {
      *(undefined1 *)((int)param_1 + 0x992) = 1;
    }
    FUN_0062e3c0(param_1,lVar2);
  }
  else if (cVar1 == '\x02') {
    FUN_005f4b80();
    FUN_005f4be0();
    FUN_0062d950(param_1);
  }
  else if (cVar1 == '\x01') {
    FUN_005f4b80();
    FUN_005f4be0();
    FUN_0062d810(param_1);
  }
  else if (cVar1 == '\0') {
    FUN_0062d730();
  }
  return;
}



================================================================