FUNCTION FUN_00635f80 @ 0x00635f80  size=528
CALLERS (1): FUN_00634ab0@0x00634ab0
CALLEES (8): FUN_00637540@0x00637540, FUN_00637690@0x00637690, FUN_00637140@0x00637140, FUN_006322c0@0x006322c0, FUN_00634970@0x00634970, FUN_006378b0@0x006378b0, FUN_00633470@0x00633470, FUN_00637260@0x00637260
----------------------------------------------------------------

void FUN_00635f80(long param_1)

{
  byte bVar1;
  undefined1 uVar2;
  bool bVar3;
  bool bVar4;
  char cVar5;
  uint uVar6;
  long lVar7;
  ulong uVar8;
  byte bVar9;
  int iVar10;
  
  bVar4 = false;
  if (*(char *)(iRam00715da8 + 0x2f) == '\0') {
    bVar1 = *(byte *)(iRam00715da8 + 0x1f);
    uVar8 = (ulong)bVar1;
    uVar2 = *(undefined1 *)(iRam00715da8 + 0x1e);
    if (((uVar8 == 4) || (bVar9 = bVar1, uVar8 == 5)) && (bVar9 = 3, param_1 != 0)) {
      bVar9 = 0;
    }
    iVar10 = 0;
    bVar3 = true;
    while (bVar3) {
      cVar5 = bVar9 + 1;
      if (param_1 != 0) {
        cVar5 = bVar9 - 1;
      }
      uVar6 = (int)cVar5 + 4U & 3;
      if (((int)((int)cVar5 + 4U) < 0) && (uVar6 != 0)) {
        uVar6 = uVar6 - 4;
      }
      bVar9 = (byte)uVar6;
      lVar7 = FUN_00637260(uVar6 & 0xff,iRam00715da8 + 0x1f,iRam00715da8 + 0x1e);
      if ((lVar7 == 0) && ((long)(char)bVar9 != uVar8)) {
        bVar4 = true;
        break;
      }
      iVar10 = iVar10 + 1;
      bVar3 = iVar10 < 4;
    }
    if (bVar4) {
      *(undefined2 *)(iRam00715da8 + 0x48) = 0;
      *(undefined1 *)(iRam00715da8 + 0x35) = 0;
      *(byte *)(iRam00715da8 + 0x4a) = *(byte *)(iRam00715da8 + 0x4a) & 0xfe;
      *(undefined4 *)(iRam00715da8 + 0x248) = 1;
    }
    else {
      *(undefined1 *)(iRam00715da8 + 0x1e) = uVar2;
      *(byte *)(iRam00715da8 + 0x1f) = bVar1;
      *(undefined4 *)(iRam00715da8 + 0x248) = 5;
    }
    if (*(char *)(iRam00715da8 + 0x1e) == '\x04') {
      FUN_006378b0();
    }
    FUN_00637540();
    FUN_00637690();
    FUN_00637140();
    FUN_006322c0();
    if (*(char *)(iRam00715da8 + 0x36) != '\0') {
      FUN_00633470();
      FUN_00634970(0,0);
    }
  }
  else {
    *(undefined4 *)(iRam00715da8 + 0x248) = 5;
  }
  return;
}



================================================================