FUNCTION FUN_005b7270 @ 0x005b7270  size=168
CALLERS (1): FUN_005b7320@0x005b7320
CALLEES (3): FUN_005b6f90@0x005b6f90, FUN_005b7f00@0x005b7f00, FUN_005b6ea0@0x005b6ea0
----------------------------------------------------------------

void FUN_005b7270(undefined8 param_1)

{
  char cVar1;
  
  if ((*pcRam006ca87c != '\\') && (*pcRam006ca87c == '<')) {
    do {
      cVar1 = FUN_005b7f00(pcRam006ca87c);
      if (cVar1 != '\x01') {
        return;
      }
      if (*pcRam006ca87c != '<') {
        return;
      }
      pcRam006ca87c = pcRam006ca87c + 1;
      FUN_005b6ea0();
      FUN_005b6f90(param_1);
    } while ((*(uint *)((int)param_1 + 4) & 0x188) == 0);
  }
  return;
}



================================================================