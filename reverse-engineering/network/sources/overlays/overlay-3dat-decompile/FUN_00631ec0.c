FUNCTION FUN_00631ec0 @ 0x00631ec0  size=184
CALLERS (1): FUN_00631790@0x00631790
CALLEES (3): FUN_006341d0@0x006341d0, FUN_00637e10@0x00637e10, FUN_00637e90@0x00637e90
----------------------------------------------------------------

void FUN_00631ec0(void)

{
  ulong uVar1;
  long lVar2;
  undefined2 *puVar3;
  int iVar4;
  
  if (*(char *)(iRam00715da8 + 0x2f) == '\0') {
    iVar4 = iRam00715da8 + 0x260;
    if (*(short *)(iRam00715da8 + 0x260) == 0) {
      iVar4 = iRam00715da8 + 0x4c;
      uVar1 = FUN_006341d0(iVar4,*(undefined2 *)(iRam00715da8 + 0x2a));
    }
    else {
      uVar1 = FUN_006341d0(iVar4,*(undefined2 *)(iRam00715da8 + 0x2c));
    }
    lVar2 = FUN_00637e90(iVar4);
    if ((long)(uVar1 & 0xffff) < lVar2) {
      puVar3 = (undefined2 *)(iVar4 + (int)(uVar1 & 0xffff) * 2);
      *puVar3 = 0;
      FUN_00637e10(puVar3,puVar3 + 1);
      *(undefined1 *)(iRam00715da8 + 0x28) = 0;
    }
  }
  return;
}



================================================================