FUNCTION FUN_005b8190 @ 0x005b8190  size=288
CALLERS (0): 
CALLEES (1): FUN_00618c20@0x00618c20
----------------------------------------------------------------

void FUN_005b8190(int param_1)

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
      cVar1 = *(char *)(param_1 + 2);
      if ((((cVar1 == '\x19') || (cVar1 == '\x16')) || (cVar1 == '\x17')) ||
         ((cVar1 == '\v' || (cVar1 == '\0')))) {
        *(undefined4 *)(param_1 + 0x34) = 0xffffffe6;
      }
    }
    if (cRam006c4fd3 == '\x02') {
      *(undefined1 *)(param_1 + 4) = 2;
      *(undefined1 *)(param_1 + 5) = 0;
    }
    else if (cRam006c4fd3 == '\x01') {
      FUN_00618c20();
    }
    else {
      if (**(char **)(param_1 + 0x10) == *(char *)(param_1 + 3)) {
        *(undefined1 *)(param_1 + 1) = 0;
      }
      else {
        *(undefined1 *)(param_1 + 1) = 1;
      }
      if ((*(char *)(param_1 + 2) == '\x06') &&
         ((long)(ulong)uRam006c45fe <= (long)*(char *)(param_1 + 3))) {
        *(undefined1 *)(param_1 + 1) = 0;
      }
    }
  }
  return;
}



================================================================