FUNCTION FUN_005b6c90 @ 0x005b6c90  size=92
CALLERS (6): FUN_006018d0@0x006018d0, FUN_00602230@0x00602230, FUN_00601760@0x00601760, FUN_006020e0@0x006020e0, FUN_005b3cb0@0x005b3cb0, FUN_005b3ed0@0x005b3ed0
CALLEES (1): FUN_00618ba0@0x00618ba0
----------------------------------------------------------------

void FUN_005b6c90(undefined1 param_1,undefined1 param_2,undefined4 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = FUN_00618ba0();
  iVar1 = (int)lVar2;
  if (lVar2 != 0) {
    *(undefined1 *)(iVar1 + 1) = 0;
    *(undefined1 **)(iVar1 + 0xc) = &LAB_005b6d50;
    *(undefined1 *)(iVar1 + 3) = param_1;
    *(undefined1 *)(iVar1 + 0x38) = param_2;
    *(undefined4 *)(iVar1 + 0x10) = param_3;
  }
  return;
}



================================================================