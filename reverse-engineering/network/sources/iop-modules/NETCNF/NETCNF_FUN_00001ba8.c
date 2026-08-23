FUNCTION FUN_00001ba8 @ 0x00001ba8 size=76
CALLERS (8): FUN_00003f98@0x00003f98, FUN_00002280@0x00002280, FUN_00003060@0x00003060, FUN_000023e0@0x000023e0, FUN_000032bc@0x000032bc, FUN_000036ac@0x000036ac, FUN_00001cdc@0x00001cdc, FUN_000027e4@0x000027e4
CALLEES (0): 

char * FUN_00001ba8(char *param_1)

{
  char cVar1;
  char cVar2;
  
  cVar1 = *param_1;
  cVar2 = '\0';
  if (*param_1 != '\0') {
    do {
      if (cVar1 == '\n') break;
      param_1 = param_1 + 1;
      cVar1 = *param_1;
    } while (*param_1 != '\0');
    cVar2 = *param_1;
  }
  return param_1 + (cVar2 == '\n');
}


================================================================