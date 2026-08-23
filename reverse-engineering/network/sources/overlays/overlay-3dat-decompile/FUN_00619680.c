FUNCTION FUN_00619680 @ 0x00619680  size=196
CALLERS (1): FUN_00619330@0x00619330
CALLEES (2): FUN_005b9110@0x005b9110, FUN_005b8cf0@0x005b8cf0
----------------------------------------------------------------

undefined8 FUN_00619680(undefined8 param_1,char *param_2)

{
  char cVar1;
  int iVar2;
  
  cVar1 = param_2[1];
  if (cVar1 == '\x03') {
    *param_2 = *param_2 + '\x01';
    param_2[1] = '\0';
  }
  else if (cVar1 == '\x02') {
    FUN_005b9110(0x4c);
    param_2[1] = param_2[1] + '\x01';
  }
  else if (cVar1 == '\x01') {
    iVar2 = *(int *)(param_2 + 0x18);
    *(int *)(param_2 + 0x18) = iVar2 + -1;
    if (iVar2 + -1 < 0) {
      param_2[0x18] = '\0';
      param_2[0x19] = '\0';
      param_2[0x1a] = '\0';
      param_2[0x1b] = '\0';
      param_2[1] = param_2[1] + '\x01';
    }
  }
  else if (cVar1 == '\0') {
    FUN_005b8cf0(0x7a);
    param_2[1] = param_2[1] + '\x01';
    param_2[0x18] = '<';
    param_2[0x19] = '\0';
    param_2[0x1a] = '\0';
    param_2[0x1b] = '\0';
  }
  return 0;
}



================================================================