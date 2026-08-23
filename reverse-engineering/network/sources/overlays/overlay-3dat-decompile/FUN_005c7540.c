FUNCTION FUN_005c7540 @ 0x005c7540  size=100
CALLERS (1): FUN_005c7210@0x005c7210
CALLEES (3): FUN_005c75d0@0x005c75d0, FUN_005c75b0@0x005c75b0, FUN_005c76e0@0x005c76e0
----------------------------------------------------------------

void FUN_005c7540(int param_1)

{
  char cVar1;
  
  cVar1 = *(char *)(param_1 + 0x21);
  if (cVar1 == '\x02') {
    FUN_005c76e0();
  }
  else if (cVar1 == '\x01') {
    FUN_005c75d0();
  }
  else if (cVar1 == '\0') {
    FUN_005c75b0();
  }
  return;
}



================================================================