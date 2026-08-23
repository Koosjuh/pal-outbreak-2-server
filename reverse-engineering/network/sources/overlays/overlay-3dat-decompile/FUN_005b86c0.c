FUNCTION FUN_005b86c0 @ 0x005b86c0  size=440
CALLERS (0): 
CALLEES (5): FUN_005af2e0@0x005af2e0, FUN_00618c20@0x00618c20, FUN_005af2c0@0x005af2c0, FUN_005af1e0@0x005af1e0, FUN_0062fd90@0x0062fd90
----------------------------------------------------------------

void FUN_005b86c0(undefined8 param_1)

{
  char cVar1;
  char *pcVar2;
  long lVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = (int)param_1;
  cVar1 = *(char *)(iVar4 + 4);
  pcVar2 = *(char **)(iVar4 + 0x10);
  if (cVar1 == '\x02') {
    FUN_00618c20();
    return;
  }
  if (cVar1 != '\x01') {
    if (cVar1 != '\0') {
      return;
    }
    *(undefined1 *)(iVar4 + 4) = 1;
    *(undefined1 *)(iVar4 + 1) = 0;
    cVar1 = *(char *)(iVar4 + 2);
    if ((((cVar1 != '\x16') && (cVar1 != '\x17')) && (cVar1 != '\v')) && (cVar1 != '\0')) {
      if (cVar1 != '\x19') goto LAB_005b8754;
      *(undefined4 *)(iVar4 + 0x30) = 0;
    }
    *(undefined4 *)(iVar4 + 0x34) = 0xffffffe6;
  }
LAB_005b8754:
  if (cRam006c4fd3 == '\x02') {
    *(undefined1 *)(iVar4 + 4) = 2;
    *(undefined1 *)(iVar4 + 5) = 0;
  }
  else if (cRam006c4fd3 == '\x01') {
    FUN_00618c20(param_1);
  }
  else if ((*(char *)(iVar4 + 2) != '\b') ||
          ((long)*(char *)(iVar4 + 3) < (long)(ulong)uRam006c45fe)) {
    lVar3 = FUN_0062fd90(*(char *)(iVar4 + 2));
    if (lVar3 == 0) {
      if (*pcVar2 == *(char *)(iVar4 + 3)) {
        *(undefined1 *)(iVar4 + 1) = 1;
      }
      else {
        *(undefined1 *)(iVar4 + 1) = 0;
      }
    }
    else {
      iVar5 = (int)lVar3 + *(char *)(iVar4 + 3) * 0xc;
      FUN_005af2e0(*(undefined1 *)(iVar5 + 1));
      if (*pcVar2 == *(char *)(iVar4 + 3)) {
        FUN_005af2c0(0xf);
        *(undefined1 *)(iVar4 + 1) = 1;
      }
      else {
        FUN_005af2c0(0);
        *(undefined1 *)(iVar4 + 1) = 0;
      }
      FUN_005af1e0(*(undefined2 *)(iVar5 + 4),*(undefined2 *)(iVar5 + 6),*(undefined1 *)(iVar5 + 3),
                   *(undefined4 *)(iVar5 + 8));
    }
  }
  return;
}



================================================================