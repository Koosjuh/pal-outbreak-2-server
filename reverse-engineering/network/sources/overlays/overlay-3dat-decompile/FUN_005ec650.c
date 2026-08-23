FUNCTION FUN_005ec650 @ 0x005ec650  size=116
CALLERS (15): FUN_005eaa10@0x005eaa10, FUN_005ea990@0x005ea990, FUN_005eab70@0x005eab70, FUN_005e96d0@0x005e96d0, FUN_005e9710@0x005e9710, FUN_005e9ef0@0x005e9ef0, FUN_005ebbd0@0x005ebbd0, FUN_005eaa70@0x005eaa70, FUN_005ebaf0@0x005ebaf0, FUN_005e8e00@0x005e8e00, FUN_005e95e0@0x005e95e0, FUN_005e9b70@0x005e9b70, ...
CALLEES (0): 
----------------------------------------------------------------

int FUN_005ec650(byte *param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = func_0x0010a050();
  iVar3 = 0;
  for (iVar4 = 0; iVar4 < iVar2; iVar4 = iVar4 + 1) {
    bVar1 = *param_1;
    if ((bVar1 < 0x3a) && (0x2f < bVar1)) {
      iVar3 = iVar3 * 10 + (bVar1 - 0x30);
    }
    param_1 = param_1 + 1;
  }
  return iVar3;
}



================================================================