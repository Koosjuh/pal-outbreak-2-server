FUNCTION FUN_005b6cf0 @ 0x005b6cf0  size=92
CALLERS (1): FUN_005f8340@0x005f8340
CALLEES (1): FUN_00618ba0@0x00618ba0
----------------------------------------------------------------

void FUN_005b6cf0(undefined1 param_1,undefined1 param_2,undefined4 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = FUN_00618ba0();
  iVar1 = (int)lVar2;
  if (lVar2 != 0) {
    *(undefined1 *)(iVar1 + 1) = 0;
    *(undefined1 **)(iVar1 + 0xc) = &LAB_005b6d80;
    *(undefined1 *)(iVar1 + 3) = param_1;
    *(undefined1 *)(iVar1 + 0x38) = param_2;
    *(undefined4 *)(iVar1 + 0x10) = param_3;
  }
  return;
}



================================================================