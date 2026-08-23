FUNCTION FUN_005f9150 @ 0x005f9150  size=152
CALLERS (1): FUN_005f8e20@0x005f8e20
CALLEES (5): FUN_005f91f0@0x005f91f0, FUN_005f99c0@0x005f99c0, FUN_005f9540@0x005f9540, FUN_005f9280@0x005f9280, FUN_005f97c0@0x005f97c0
----------------------------------------------------------------

void FUN_005f9150(int param_1)

{
  char cVar1;
  
  cVar1 = *(char *)(param_1 + 0xf);
  if (cVar1 == '\x04') {
    FUN_005f99c0();
  }
  else if (cVar1 == '\x03') {
    FUN_005f97c0();
  }
  else if (cVar1 == '\x02') {
    FUN_005f9540();
  }
  else if (cVar1 == '\x01') {
    FUN_005f9280();
  }
  else if (cVar1 == '\0') {
    FUN_005f91f0();
  }
  return;
}



================================================================