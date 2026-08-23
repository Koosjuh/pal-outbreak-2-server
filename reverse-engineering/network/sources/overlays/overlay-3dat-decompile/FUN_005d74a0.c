FUNCTION FUN_005d74a0 @ 0x005d74a0  size=148
CALLERS (5): FUN_005d3930@0x005d3930, FUN_005d47f0@0x005d47f0, FUN_005ca380@0x005ca380, FUN_005d5900@0x005d5900, FUN_005d5640@0x005d5640
CALLEES (3): FUN_005d6a10@0x005d6a10, FUN_005d7410@0x005d7410, FUN_005d6630@0x005d6630
----------------------------------------------------------------

void FUN_005d74a0(undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_005d6630(iRam00701068 + 0x4f694,*param_1);
  *(undefined4 *)(iVar1 + 0x104) = 4;
  *(undefined1 *)(iVar1 + 0x10c) = 3;
  *(undefined1 *)(iVar1 + 0x10d) = 1;
  uVar2 = FUN_005d7410();
  *(undefined4 *)(iVar1 + 0x110) = uVar2;
  cRam00701010 = cRam00701010 + '\x01';
  *(char *)(iVar1 + 0x108) = cRam00701010;
  *(undefined1 *)(iVar1 + 0x109) = 0;
  FUN_005d6a10(iVar1 + 0x108,1,1);
  uRam00701000 = 2;
  return;
}



================================================================