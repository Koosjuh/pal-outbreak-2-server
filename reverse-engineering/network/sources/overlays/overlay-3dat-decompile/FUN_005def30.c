FUNCTION FUN_005def30 @ 0x005def30  size=232
CALLERS (2): FUN_005df170@0x005df170, FUN_005df340@0x005df340
CALLEES (1): FUN_005df780@0x005df780
----------------------------------------------------------------

/* WARNING: Removing unreachable block (ram,0x005def8c) */

char * FUN_005def30(char *param_1,char *param_2)

{
  bool bVar1;
  char cVar2;
  
  bVar1 = false;
  cVar2 = FUN_005df780();
  if (cVar2 == '\x01') {
    param_1 = param_1 + 6;
  }
  else {
    if (cVar2 != '\0') {
      do {
        if (bVar1) {
          if (param_2 <= param_1) {
            return (char *)0x0;
          }
          if (*param_1 == '/') {
            return param_1;
          }
        }
        else {
          if (param_2 <= param_1 + 1) {
            return (char *)0x0;
          }
          if ((*param_1 == '/') && (param_1[1] == '/')) {
            bVar1 = true;
            param_1 = param_1 + 1;
          }
        }
        param_1 = param_1 + 1;
      } while( true );
    }
    param_1 = (char *)0x0;
  }
  return param_1;
}



================================================================