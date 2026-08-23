FUNCTION FUN_005d70b0 @ 0x005d70b0  size=236
CALLERS (1): FUN_005d0960@0x005d0960
CALLEES (2): FUN_005d67d0@0x005d67d0, FUN_005d6630@0x005d6630
----------------------------------------------------------------

int FUN_005d70b0(void)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = FUN_005d67d0(iRam00701068 + 0x4f588,iRam00701018);
  iVar3 = FUN_005d6630(iRam00701068 + 0x4f694,iVar2 + 4);
  *(undefined4 *)(iVar3 + 0x104) = 4;
  if (iVar2 == iRam00701018) {
    *(undefined1 *)(iVar3 + 0x10c) = 6;
    *(undefined1 *)(iVar3 + 0x10d) = 1;
    *(int *)(iVar3 + 0x110) = iRam00701018 + 4;
    uVar1 = *(undefined1 *)(iVar2 + 0x109);
    *(undefined1 *)(iVar3 + 0x108) = *(undefined1 *)(iVar2 + 0x108);
    *(undefined1 *)(iVar3 + 0x109) = uVar1;
    uRam00701000 = 5;
  }
  else {
    *(undefined1 *)(iVar3 + 0x10c) = 4;
    *(undefined1 *)(iVar3 + 0x10d) = 1;
    *(int *)(iVar3 + 0x110) = iRam00701018 + 4;
    uVar1 = *(undefined1 *)(iVar2 + 0x109);
    *(undefined1 *)(iVar3 + 0x108) = *(undefined1 *)(iVar2 + 0x108);
    *(undefined1 *)(iVar3 + 0x109) = uVar1;
    uRam00701000 = 3;
  }
  return iVar2 + 4;
}



================================================================