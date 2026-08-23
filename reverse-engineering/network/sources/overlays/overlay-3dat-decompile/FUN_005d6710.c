FUNCTION FUN_005d6710 @ 0x005d6710  size=92
CALLERS (1): FUN_005d8340@0x005d8340
CALLEES (1): FUN_005d6680@0x005d6680
----------------------------------------------------------------

void FUN_005d6710(undefined8 param_1)

{
  int iVar1;
  
  FUN_005d6680(iRam00701068 + 0x4f694,param_1);
  iVar1 = (int)param_1;
  *(undefined1 *)(iVar1 + 0x10c) = 0;
  *(undefined1 *)(iVar1 + 0x10d) = 0;
  *(undefined4 *)(iVar1 + 0x110) = 0;
  *(undefined4 *)(iVar1 + 0x114) = 0;
  *(undefined4 *)(iVar1 + 0x11c) = 0;
  *(undefined4 *)(iVar1 + 0x120) = 0;
  *(undefined1 *)(iVar1 + 0x125) = 0;
  *(undefined1 *)(iVar1 + 0x124) = 0;
  return;
}



================================================================