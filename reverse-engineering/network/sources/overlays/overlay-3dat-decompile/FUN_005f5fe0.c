FUNCTION FUN_005f5fe0 @ 0x005f5fe0  size=228
CALLERS (1): FUN_005f5f80@0x005f5f80
CALLEES (2): FUN_005f62e0@0x005f62e0, FUN_005f61d0@0x005f61d0
----------------------------------------------------------------

void FUN_005f5fe0(undefined8 param_1)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  
  pcVar2 = (char *)param_1;
  pcVar2[10] = '\0';
  pcVar2[0xb] = '\0';
  func_0x00106b60(0x70a150,0,0x12c0);
  pcVar2[8] = '\0';
  pcVar2[9] = '\0';
  iVar3 = 0;
  iVar1 = 0;
  do {
    if (*(int *)((iVar1 + iVar3) * 0x10 + 0x695d8c) != 0) {
      FUN_005f61d0(param_1);
    }
    iVar3 = iVar3 + 1;
    iVar1 = iVar3 * 2;
  } while (iVar3 < 100);
  iVar3 = 0;
  iVar1 = 0;
  do {
    iVar1 = (iVar1 + iVar3) * 0x10;
    if ((*(int *)(iVar1 + 0x695d8c) == 0) && (*(int *)(iVar1 + 0x695d88) != 0)) {
      FUN_005f61d0(param_1);
    }
    iVar3 = iVar3 + 1;
    iVar1 = iVar3 * 2;
  } while (iVar3 < 100);
  *pcVar2 = *pcVar2 + '\x01';
  FUN_005f62e0(param_1);
  return;
}



================================================================