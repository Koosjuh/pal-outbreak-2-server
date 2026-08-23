FUNCTION FUN_005b8b60 @ 0x005b8b60  size=400
CALLERS (0): 
CALLEES (5): FUN_005af2e0@0x005af2e0, FUN_00618c20@0x00618c20, FUN_005af2c0@0x005af2c0, FUN_005af1e0@0x005af1e0, FUN_0062fd90@0x0062fd90
----------------------------------------------------------------

void FUN_005b8b60(undefined8 param_1)

{
  char *pcVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  
  iVar4 = (int)param_1;
  cVar3 = *(char *)(iVar4 + 4);
  pcVar1 = *(char **)(iVar4 + 0x10);
  if (cVar3 == '\x02') {
    FUN_00618c20();
  }
  else {
    if (cVar3 != '\x01') {
      if (cVar3 != '\0') {
        return;
      }
      *(undefined1 *)(iVar4 + 4) = 1;
      *(undefined1 *)(iVar4 + 1) = 0;
    }
    if (cRam006c4fd3 == '\x02') {
      *(undefined1 *)(iVar4 + 4) = 2;
      *(undefined1 *)(iVar4 + 5) = 0;
    }
    else if (cRam006c4fd3 == '\x01') {
      FUN_00618c20(param_1);
    }
    else {
      iVar2 = FUN_0062fd90(*(undefined1 *)(iVar4 + 2));
      iVar2 = iVar2 + *(char *)(iVar4 + 3) * 0xc;
      FUN_005af2e0(*(undefined1 *)(iVar2 + 1));
      cVar3 = *(char *)(iVar4 + 3);
      if ((((cVar3 == '\n') || (cVar3 == '\t')) || (cVar3 == '\x01')) || (cVar3 == '\0')) {
        FUN_005af2c0(*(undefined1 *)(iVar2 + 2));
        FUN_005af1e0(*(undefined2 *)(iVar2 + 4),*(undefined2 *)(iVar2 + 6),
                     *(undefined1 *)(iVar2 + 3),*(undefined4 *)(iVar2 + 8));
        cVar3 = *pcVar1;
      }
      else {
        if (cVar3 + -2 < (int)(uint)bRam006970f4) {
          FUN_005af2c0(*(undefined1 *)(iVar2 + 2));
          FUN_005af1e0(*(undefined2 *)(iVar2 + 4),*(undefined2 *)(iVar2 + 6),
                       *(undefined1 *)(iVar2 + 3),(cVar3 + -2) * 0x14a8 + 0x6970f6);
        }
        cVar3 = *pcVar1;
      }
      if (cVar3 == *(char *)(iVar4 + 3)) {
        *(undefined1 *)(iVar4 + 1) = 1;
      }
      else {
        *(undefined1 *)(iVar4 + 1) = 0;
      }
    }
  }
  return;
}



================================================================