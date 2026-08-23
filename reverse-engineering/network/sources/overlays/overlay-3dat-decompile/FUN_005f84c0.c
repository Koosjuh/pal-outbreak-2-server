FUNCTION FUN_005f84c0 @ 0x005f84c0  size=284
CALLERS (0): 
CALLEES (7): FUN_005af2e0@0x005af2e0, FUN_00618c20@0x00618c20, FUN_0062fdf0@0x0062fdf0, FUN_005af2c0@0x005af2c0, FUN_005af1e0@0x005af1e0, FUN_005f54d0@0x005f54d0, FUN_005b0950@0x005b0950
----------------------------------------------------------------

void FUN_005f84c0(int param_1)

{
  char cVar1;
  int iVar2;
  undefined1 auStack_60 [92];
  undefined2 uStack_4;
  undefined2 uStack_2;
  
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
    }
    if (*(char *)(param_1 + 2) == '\0') {
      iVar2 = FUN_0062fdf0(0);
      FUN_005af2e0(*(undefined1 *)(iVar2 + 1));
      FUN_005af2c0(*(undefined1 *)(iVar2 + 2));
      FUN_005b0950(uRam006c45f8,&uStack_4);
      func_0x00109728(auStack_60,0x649768,*(undefined4 *)(iVar2 + 8),uStack_4,
                      *(undefined4 *)(iVar2 + 0x14),uStack_2);
      FUN_005af1e0(*(undefined2 *)(iVar2 + 4),*(undefined2 *)(iVar2 + 6),*(undefined1 *)(iVar2 + 3),
                   auStack_60);
      FUN_005f54d0(0);
    }
    else if (*(char *)(param_1 + 2) == '\x01') {
      if ((cRam006c50fb == '\0') && ((cRam006c4b90 == '\x02' || (cRam006c4b90 == '\x0e')))) {
        *(undefined1 *)(param_1 + 1) = 1;
        *(undefined2 *)(param_1 + 0x22) = 0x37;
      }
      else {
        *(undefined1 *)(param_1 + 1) = 0;
      }
    }
  }
  return;
}



================================================================