
undefined8 FUN_001c65c0(undefined8 param_1)

{
  int iVar1;
  uint uVar2;
  long lVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  
  iVar4 = (int)param_1;
  if (*(char *)(*(int *)(iVar4 + 0x30) + 6) == -1) {
    *(undefined4 *)(iVar4 + 0xdc) = 9;
    *(undefined1 *)(iVar4 + 0xc) = 7;
    *(undefined1 *)(iVar4 + 0xd) = 0;
    *(undefined1 *)(iVar4 + 0xe) = 0;
    *(undefined1 *)(iVar4 + 0xf) = 0;
    *(undefined2 *)(iVar4 + 0x10) = 0;
    *(undefined2 *)(iVar4 + 0x12) = 0;
    *(undefined2 *)(iVar4 + 0x14) = 0;
    *(undefined2 *)(iVar4 + 0x16) = 0;
  }
  else {
    iVar1 = FUN_001c3b10();
    uVar6 = (uint)bRam00365c14;
    iVar5 = uVar6 * 4;
    if (iVar1 == *(int *)(iVar5 + 0x365bb4)) {
      iVar1 = FUN_001c3b10(param_1);
      uVar2 = FUN_001c3ab0(param_1);
      uRam00365c18 = iVar1 + (uVar2 & 0xffff);
      if ((uRam00365c18 < *(uint *)(iVar5 + 0x365bd4)) && (uRam00365c18 < 0x200)) {
        *(undefined1 *)(iVar4 + 0xd) = 0x41;
      }
      else {
        uRam00365c18 = 0;
        bRam00365c14 = bRam00365c14 + 1;
        if ((bRam00365c14 < uRam00365bb0) && (bRam00365c14 < 8)) {
          *(undefined1 *)(iVar4 + 0xd) = 0x41;
        }
        else {
          *(undefined1 *)(iVar4 + 0xd) = 0x31;
        }
      }
      lVar3 = FUN_001c3b90(param_1,iRam0035ccb8 + uVar6 * 0x200 + iVar1);
      if (lVar3 < 0) {
        *(undefined4 *)(iVar4 + 0xdc) = 0xffffffff;
        *(undefined1 *)(iVar4 + 0xc) = 7;
        *(undefined1 *)(iVar4 + 0xd) = 0;
        *(undefined1 *)(iVar4 + 0xe) = 0;
        *(undefined1 *)(iVar4 + 0xf) = 0;
        *(undefined2 *)(iVar4 + 0x10) = 0;
        *(undefined2 *)(iVar4 + 0x12) = 0;
        *(undefined2 *)(iVar4 + 0x14) = 0;
        *(undefined2 *)(iVar4 + 0x16) = 0;
      }
    }
    else {
      *(undefined4 *)(iVar4 + 0xdc) = 0xffffffff;
      *(undefined1 *)(iVar4 + 0xc) = 7;
      *(undefined1 *)(iVar4 + 0xd) = 0;
      *(undefined1 *)(iVar4 + 0xe) = 0;
      *(undefined1 *)(iVar4 + 0xf) = 0;
      *(undefined2 *)(iVar4 + 0x10) = 0;
      *(undefined2 *)(iVar4 + 0x12) = 0;
      *(undefined2 *)(iVar4 + 0x14) = 0;
      *(undefined2 *)(iVar4 + 0x16) = 0;
    }
  }
  return 0;
}

