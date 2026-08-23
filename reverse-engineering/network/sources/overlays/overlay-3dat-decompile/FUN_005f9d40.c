FUNCTION FUN_005f9d40 @ 0x005f9d40  size=272
CALLERS (2): FUN_005f9540@0x005f9540, FUN_005f9e50@0x005f9e50
CALLEES (0): 
----------------------------------------------------------------

void FUN_005f9d40(void)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  char cVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  
  iVar10 = 0;
  do {
    iVar9 = iVar10 * 0x14a8;
    *(undefined1 *)(iVar9 + 0x69713b) = 0;
    cVar4 = *(char *)(iVar9 + 0x697137) + -1;
    if (cVar4 < '\0') {
      cVar4 = '\0';
    }
    iVar10 = iVar10 + 1;
    *(char *)(iVar9 + 0x69713c) = cVar4;
  } while (iVar10 < 0x20);
  uVar5 = (uint)bRam006970f4;
  for (iVar10 = 0; iVar10 < (int)uVar5; iVar10 = iVar10 + 1) {
    iVar9 = iVar10 * 0x14a8 + 0x6970a0;
    bVar1 = *(byte *)(iVar10 * 0x14a8 + 0x69713a);
    uVar6 = (uint)*(byte *)(iVar9 + (uint)bVar1 + 0x8dd);
    if (uVar6 != 0) {
      for (iVar7 = 0; iVar7 < (int)uVar6; iVar7 = iVar7 + 1) {
        iVar8 = iVar9 + ((uint)bVar1 * 2 + (uint)bVar1) * 0x20 + iVar7 * 3;
        bVar2 = *(byte *)(iVar8 + 0x8fe);
        bVar3 = *(byte *)(iVar8 + 0x8ff);
        iVar8 = (uint)*(byte *)(iVar8 + 0x8fd) * 0x14a8;
        *(byte *)(iVar8 + 0x69713b) = bVar2;
        *(byte *)(iVar8 + 0x69713c) = bVar3;
        if (*(byte *)(iVar8 + 0x69713a) < bVar2) {
          *(byte *)(iVar8 + 0x69713a) = bVar2;
        }
        else if (bVar3 < *(byte *)(iVar8 + 0x69713a)) {
          *(byte *)(iVar8 + 0x69713a) = bVar3;
        }
      }
    }
  }
  return;
}



================================================================