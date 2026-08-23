FUNCTION FUN_005d7320 @ 0x005d7320  size=160
CALLERS (1): FUN_005d0a40@0x005d0a40
CALLEES (2): FUN_005d6630@0x005d6630, FUN_005d7310@0x005d7310
----------------------------------------------------------------

int FUN_005d7320(void)

{
  int iVar1;
  undefined8 uVar2;
  int extraout_a0_lo;
  
  uVar2 = FUN_005d6630(iRam00701068 + 0x4f694,iRam00701018 + 4);
  iVar1 = (int)uVar2;
  *(undefined4 *)(iVar1 + 0x104) = 4;
  *(undefined1 *)(iVar1 + 0x10c) = 6;
  *(undefined1 *)(iVar1 + 0x10d) = 1;
  *(int *)(iVar1 + 0x110) = iRam00701018 + 4;
  cRam00701010 = cRam00701010 + '\x01';
  *(char *)(iVar1 + 0x108) = cRam00701010;
  iVar1 = FUN_005d7310(uVar2);
  *(undefined1 *)(extraout_a0_lo + 0x109) = *(undefined1 *)(iVar1 + 1);
  uRam00701000 = 5;
  return iRam00701018 + 4;
}



================================================================