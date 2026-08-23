FUNCTION FUN_00001bf4 @ 0x00001bf4 size=232
CALLERS (11): FUN_00003f98@0x00003f98, FUN_00002280@0x00002280, FUN_00003988@0x00003988, FUN_000026a0@0x000026a0, FUN_00003060@0x00003060, FUN_000023e0@0x000023e0, FUN_00002050@0x00002050, FUN_000032bc@0x000032bc, FUN_000036ac@0x000036ac, FUN_00001cdc@0x00001cdc, FUN_000027e4@0x000027e4
CALLEES (0): 

undefined4 FUN_00001bf4(char *param_1,char *param_2,int param_3)

{
  char cVar1;
  char cVar2;
  
  while (0 < param_3) {
    param_3 = param_3 + -1;
    cVar1 = *param_2;
    if (*param_2 == '\0') {
LAB_00001c4c:
      if (*param_2 != ',') {
        return 0xffffffff;
      }
    }
    else if (*param_2 != ',') {
      while (cVar1 != '\n') {
        param_2 = param_2 + 1;
        cVar1 = *param_2;
        if ((*param_2 == '\0') || (*param_2 == ',')) break;
      }
      goto LAB_00001c4c;
    }
    param_2 = param_2 + 1;
  }
  cVar1 = *param_2;
  cVar2 = *param_2;
  if (((cVar1 != '\0') && (cVar1 != ',')) && (cVar1 != '\n')) {
    while (param_2 = param_2 + 1, cVar2 != '\r') {
      *param_1 = cVar2;
      cVar1 = *param_2;
      cVar2 = *param_2;
      param_1 = param_1 + 1;
      if (((cVar1 == '\0') || (cVar1 == ',')) || (cVar1 == '\n')) break;
    }
  }
  *param_1 = '\0';
  return 0;
}


================================================================