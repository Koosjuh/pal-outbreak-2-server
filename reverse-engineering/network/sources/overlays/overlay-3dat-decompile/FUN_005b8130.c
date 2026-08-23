FUNCTION FUN_005b8130 @ 0x005b8130  size=84
CALLERS (4): FUN_005fc850@0x005fc850, FUN_005b7fd0@0x005b7fd0, FUN_005b4c80@0x005b4c80, FUN_00617bb0@0x00617bb0
CALLEES (1): FUN_00618ba0@0x00618ba0
----------------------------------------------------------------

long FUN_005b8130(undefined2 *param_1)

{
  undefined1 *puVar1;
  long lVar2;
  
  lVar2 = FUN_00618ba0();
  if (lVar2 == 0) {
    lVar2 = 0;
  }
  else {
    puVar1 = (undefined1 *)lVar2;
    *puVar1 = 1;
    puVar1[1] = 1;
    *(undefined2 *)(puVar1 + 0x22) = *param_1;
    *(undefined4 *)(puVar1 + 0xc) = *(undefined4 *)(param_1 + 4);
    puVar1[3] = *(undefined1 *)((int)param_1 + 5);
  }
  return lVar2;
}



================================================================