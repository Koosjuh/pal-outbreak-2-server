FUNCTION FUN_00628f00 @ 0x00628f00  size=108
CALLERS (1): FUN_00628e10@0x00628e10
CALLEES (3): FUN_00629a40@0x00629a40, FUN_005af400@0x005af400, FUN_00629d00@0x00629d00
----------------------------------------------------------------

undefined4 FUN_00628f00(int param_1,undefined8 param_2)

{
  char *pcVar1;
  
  pcVar1 = (char *)param_2;
  *pcVar1 = *pcVar1 + '\x01';
  if (*(char *)(param_1 + 0x9ce) == '\0') {
    pcVar1[10] = '\b';
    pcVar1[0xb] = '\0';
  }
  else {
    pcVar1[10] = '\0';
    pcVar1[0xb] = '\0';
  }
  pcVar1[0xc] = '\0';
  pcVar1[0xd] = '\0';
  pcVar1[0xe] = '\0';
  pcVar1[0xf] = '\0';
  FUN_005af400();
  FUN_00629a40(param_2,0);
  FUN_00629d00(param_2,0);
  return 0xffffffff;
}



================================================================