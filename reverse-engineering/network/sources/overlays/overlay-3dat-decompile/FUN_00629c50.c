FUNCTION FUN_00629c50 @ 0x00629c50  size=172
CALLERS (0): 
CALLEES (1): FUN_00618c20@0x00618c20
----------------------------------------------------------------

void FUN_00629c50(int param_1)

{
  char cVar1;
  
  cVar1 = *(char *)(param_1 + 4);
  if (cVar1 == '\x02') {
    FUN_00618c20();
  }
  else {
    if (cVar1 != '\x01') {
      if (cVar1 != '\0') {
        return;
      }
      *(undefined1 *)(param_1 + 4) = 1;
    }
    if ((long)*(char *)(param_1 + 3) < (long)(ulong)bRam006c555e) {
      *(undefined1 *)(param_1 + 1) = 1;
      if (*(char *)(*(char *)(param_1 + 3) * 0xa5 + 0x6c5562) == '\0') {
        *(undefined2 *)(param_1 + 0x22) = 0x82;
      }
      else {
        *(undefined2 *)(param_1 + 0x22) = 0x83;
      }
    }
    else {
      *(undefined1 *)(param_1 + 1) = 0;
    }
  }
  return;
}



================================================================