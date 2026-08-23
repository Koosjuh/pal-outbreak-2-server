FUNCTION FUN_0062bda0 @ 0x0062bda0  size=132
CALLERS (1): FUN_0062ba70@0x0062ba70
CALLEES (4): FUN_0062c030@0x0062c030, FUN_0062c160@0x0062c160, FUN_0062bee0@0x0062bee0, FUN_0062be30@0x0062be30
----------------------------------------------------------------

undefined8 FUN_0062bda0(undefined8 param_1,int param_2)

{
  char cVar1;
  
  cVar1 = *(char *)(param_2 + 1);
  if (cVar1 == '\x03') {
    FUN_0062c160();
  }
  else if (cVar1 == '\x02') {
    FUN_0062c030();
  }
  else if (cVar1 == '\x01') {
    FUN_0062bee0();
  }
  else if (cVar1 == '\0') {
    FUN_0062be30();
  }
  return 0;
}



================================================================