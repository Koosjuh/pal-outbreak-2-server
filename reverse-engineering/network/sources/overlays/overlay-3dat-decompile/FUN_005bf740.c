FUNCTION FUN_005bf740 @ 0x005bf740  size=232
CALLERS (0): 
CALLEES (2): FUN_005c7d00@0x005c7d00, FUN_005bf280@0x005bf280
----------------------------------------------------------------

void FUN_005bf740(char *param_1,undefined4 *param_2)

{
  long lVar1;
  
  FUN_005c7d00();
  if (*param_1 == '\0') {
    uRam006cbc35 = 1;
    uRam006cbc84 = 0;
    lVar1 = FUN_005bf280(*param_2);
    if ((lVar1 != -1) && (param_2[1] == 0x55534552)) {
      *(undefined4 *)((int)lVar1 * 0x24 + 0x6fec18) = param_2[2];
      *(short *)((int)lVar1 * 0x144 + 0x6ce5de) = (short)param_2[2];
    }
  }
  else if (*param_1 == '\'') {
    uRam006cbc84 = 0xff;
    uRam006cbc35 = 2;
  }
  return;
}



================================================================