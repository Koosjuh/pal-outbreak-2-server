FUNCTION FUN_00007b20 @ 0x00007b20 size=96
CALLERS (1): FUN_00007660@0x00007660
CALLEES (0): 

undefined4 FUN_00007b20(char *param_1,char *param_2,undefined4 *param_3)

{
  char cVar1;
  
  cVar1 = *param_1;
  if (cVar1 == '\0') {
    return 0;
  }
  do {
    param_1 = param_1 + 1;
    if (cVar1 == '\0') {
LAB_00007b6c:
      *param_2 = '\0';
      *param_3 = param_1 + -1;
      return 1;
    }
    if (cVar1 == '\n') {
      param_1 = param_1 + 1;
      goto LAB_00007b6c;
    }
    *param_2 = cVar1;
    param_2 = param_2 + 1;
    cVar1 = *param_1;
  } while( true );
}


================================================================