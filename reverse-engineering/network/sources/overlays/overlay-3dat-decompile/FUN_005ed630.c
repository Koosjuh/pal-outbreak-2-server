FUNCTION FUN_005ed630 @ 0x005ed630  size=176
CALLERS (3): FUN_005ee220@0x005ee220, FUN_005ee470@0x005ee470, FUN_005ed6e0@0x005ed6e0
CALLEES (0): 
----------------------------------------------------------------

undefined8 FUN_005ed630(char *param_1)

{
  char cVar1;
  undefined8 uVar2;
  
  cVar1 = *param_1;
  uVar2 = 0;
  if (cVar1 == '/') {
    uVar2 = 0x11;
  }
  else if (cVar1 == '.') {
    uVar2 = 3;
  }
  else if (cVar1 == '-') {
    uVar2 = 2;
  }
  else if (cVar1 == ',') {
    uVar2 = 1;
  }
  else if (cVar1 == '(') {
    uVar2 = 4;
  }
  else if (cVar1 == '\n') {
    uVar2 = 1;
  }
  else if (cVar1 != '\t') {
    if (cVar1 == '\v') {
      uVar2 = 2;
    }
    else {
      if (cVar1 != '\b') {
        *param_1 = '\0';
        return 0;
      }
      uVar2 = 3;
    }
  }
  *param_1 = '\0';
  return uVar2;
}



================================================================