FUNCTION FUN_005d6ce0 @ 0x005d6ce0  size=100
CALLERS (4): FUN_005d78d0@0x005d78d0, FUN_005d8340@0x005d8340, FUN_005d79e0@0x005d79e0, FUN_005d7a30@0x005d7a30
CALLEES (1): FUN_005d6b80@0x005d6b80
----------------------------------------------------------------

void FUN_005d6ce0(undefined8 param_1)

{
  int iVar1;
  
  FUN_005d6b80(iRam00701068 + 0x4f47c,param_1);
  iVar1 = (int)param_1;
  if (*(int *)(iVar1 + 0x114) != 0) {
    func_0x001cb490();
  }
  *(undefined4 *)(iVar1 + 0x114) = 0;
  *(undefined4 *)(iVar1 + 0x10c) = 0;
  *(undefined4 *)(iVar1 + 0x110) = 0;
  *(undefined2 *)(iVar1 + 0x118) = 0;
  *(undefined2 *)(iVar1 + 0x11a) = 0;
  return;
}



================================================================