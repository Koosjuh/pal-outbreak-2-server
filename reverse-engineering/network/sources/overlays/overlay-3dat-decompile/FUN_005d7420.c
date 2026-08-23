FUNCTION FUN_005d7420 @ 0x005d7420  size=128
CALLERS (0): 
CALLEES (2): FUN_005d7410@0x005d7410, FUN_005d6630@0x005d6630
----------------------------------------------------------------

void FUN_005d7420(undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_005d6630(iRam00701068 + 0x4f694,*param_1);
  *(undefined4 *)(iVar1 + 0x104) = 4;
  *(undefined1 *)(iVar1 + 0x10c) = 1;
  *(undefined1 *)(iVar1 + 0x10d) = 1;
  uVar2 = FUN_005d7410();
  *(undefined4 *)(iVar1 + 0x110) = uVar2;
  cRam00701010 = cRam00701010 + '\x01';
  *(char *)(iVar1 + 0x108) = cRam00701010;
  *(undefined1 *)(iVar1 + 0x109) = 0;
  uRam00701000 = 1;
  return;
}



================================================================