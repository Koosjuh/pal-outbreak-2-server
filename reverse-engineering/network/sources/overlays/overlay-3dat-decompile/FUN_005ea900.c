FUNCTION FUN_005ea900 @ 0x005ea900  size=136
CALLERS (2): FUN_005f0e10@0x005f0e10, FUN_005ea880@0x005ea880
CALLEES (4): FUN_005ec100@0x005ec100, FUN_005efb30@0x005efb30, FUN_005efc60@0x005efc60, FUN_005efa60@0x005efa60
----------------------------------------------------------------

void FUN_005ea900(void)

{
  ushort *puVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = iRam007012a0;
  puVar1 = (ushort *)(iRam007012a0 + 0xd894);
  *(undefined1 *)(iRam007012a0 + 0x18d) = 0;
  iVar2 = iVar2 + ((uint)*puVar1 * 0x18 - (uint)*puVar1) * 4;
  iVar3 = iVar2 + 0x24e0;
  FUN_005ec100(*(undefined1 *)(iVar2 + 0x252f));
  FUN_005efb30(iVar3);
  if (*(char *)(iRam007012a0 + 0x186) == '\0') {
    FUN_005efa60(iRam007012a0 + 0xe10);
  }
  FUN_005efc60(iVar3);
  return;
}



================================================================