FUNCTION FUN_005ff950 @ 0x005ff950  size=160
CALLERS (1): FUN_005acab0@0x005acab0
CALLEES (6): FUN_00603e40@0x00603e40, FUN_0062ba00@0x0062ba00, FUN_005aec70@0x005aec70, FUN_005ff9f0@0x005ff9f0, FUN_0062ba70@0x0062ba70, FUN_005ffdc0@0x005ffdc0
----------------------------------------------------------------

void FUN_005ff950(undefined8 param_1)

{
  char cVar1;
  long lVar2;
  short sVar3;
  int iVar4;
  
  lVar2 = FUN_005aec70();
  if (lVar2 != 0) {
    return;
  }
  iVar4 = (int)param_1;
  cVar1 = *(char *)(iVar4 + 1);
  if (cVar1 == '\x02') {
    lVar2 = FUN_0062ba70(param_1);
    if (lVar2 != 0) {
      FUN_0062ba00(param_1,1);
    }
  }
  else if (cVar1 == '\x01') {
    FUN_00603e40(param_1);
  }
  else {
    if (cVar1 != '\0') {
      sVar3 = *(short *)(iVar4 + 0x43a);
      goto LAB_005ff9d0;
    }
    FUN_005ff9f0(param_1);
  }
  sVar3 = *(short *)(iVar4 + 0x43a);
LAB_005ff9d0:
  if (sVar3 != 0) {
    FUN_005ffdc0(param_1);
  }
  return;
}



================================================================