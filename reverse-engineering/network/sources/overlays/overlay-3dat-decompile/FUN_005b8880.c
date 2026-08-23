FUNCTION FUN_005b8880 @ 0x005b8880  size=388
CALLERS (0): 
CALLEES (5): FUN_005af2e0@0x005af2e0, FUN_00618c20@0x00618c20, FUN_005af2c0@0x005af2c0, FUN_005af1e0@0x005af1e0, FUN_0062fd90@0x0062fd90
----------------------------------------------------------------

void FUN_005b8880(undefined8 param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined1 auStack_50 [80];
  
  iVar3 = (int)param_1;
  cVar1 = *(char *)(iVar3 + 4);
  if (cVar1 == '\x02') {
    FUN_00618c20();
  }
  else {
    if (cVar1 != '\x01') {
      if (cVar1 != '\0') {
        return;
      }
      *(undefined1 *)(iVar3 + 4) = 1;
      *(undefined1 *)(iVar3 + 1) = 0;
    }
    if (cRam006c4fd3 == '\x02') {
      *(undefined1 *)(iVar3 + 4) = 2;
      *(undefined1 *)(iVar3 + 5) = 0;
    }
    else if (cRam006c4fd3 == '\x01') {
      FUN_00618c20(param_1);
    }
    else if ((long)*(char *)(iVar3 + 3) < (long)(ulong)uRam006c45fe) {
      iVar2 = FUN_0062fd90(*(undefined1 *)(iVar3 + 2));
      cVar1 = cRam006c4fdb;
      iVar2 = iVar2 + *(char *)(iVar3 + 3) * 0xc;
      FUN_005af2e0(*(undefined1 *)(iVar2 + 1));
      if (cVar1 == *(char *)(iVar3 + 3)) {
        FUN_005af2c0(0xf);
        *(undefined1 *)(iVar3 + 1) = 1;
      }
      else {
        FUN_005af2c0(0);
        *(undefined1 *)(iVar3 + 1) = 0;
      }
      if (*(char *)(iVar3 + 2) == '\x06') {
        func_0x00109728(auStack_50,0x639d50,*(undefined4 *)(iVar2 + 8),
                        (int)cRam006c4fda + (int)*(char *)(iVar3 + 3) + 1);
        FUN_005af1e0(*(undefined2 *)(iVar2 + 4),*(undefined2 *)(iVar2 + 6),
                     *(undefined1 *)(iVar2 + 3),auStack_50);
      }
      else {
        FUN_005af1e0(*(undefined2 *)(iVar2 + 4),*(undefined2 *)(iVar2 + 6),
                     *(undefined1 *)(iVar2 + 3),*(undefined4 *)(iVar2 + 8));
      }
    }
  }
  return;
}



================================================================