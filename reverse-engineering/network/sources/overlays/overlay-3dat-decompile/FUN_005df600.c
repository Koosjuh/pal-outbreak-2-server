FUNCTION FUN_005df600 @ 0x005df600  size=60
CALLERS (1): FUN_005df640@0x005df640
CALLEES (0): 
----------------------------------------------------------------

void FUN_005df600(char *param_1)

{
  char cVar1;
  
  cVar1 = *param_1;
  while (cVar1 != '\0') {
    if (('@' < cVar1) && (cVar1 < '[')) {
      *param_1 = *param_1 + ' ';
    }
    param_1 = param_1 + 1;
    cVar1 = *param_1;
  }
  return;
}



================================================================