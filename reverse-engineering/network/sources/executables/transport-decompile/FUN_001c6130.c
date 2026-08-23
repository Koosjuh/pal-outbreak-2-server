
undefined8 FUN_001c6130(undefined8 param_1)

{
  int iVar1;
  uint uVar2;
  long lVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  
  piVar4 = (int *)param_1;
  if (*(char *)(piVar4[0xc] + 6) == -1) {
    piVar4[0x37] = 9;
    *(undefined1 *)(piVar4 + 3) = 7;
    *(undefined1 *)((int)piVar4 + 0xd) = 0;
    *(undefined1 *)((int)piVar4 + 0xe) = 0;
    *(undefined1 *)((int)piVar4 + 0xf) = 0;
    *(undefined2 *)(piVar4 + 4) = 0;
    *(undefined2 *)((int)piVar4 + 0x12) = 0;
    *(undefined2 *)(piVar4 + 5) = 0;
    *(undefined2 *)((int)piVar4 + 0x16) = 0;
  }
  else {
    iVar1 = FUN_001c3b10();
    uVar6 = (uint)bRam00365db4;
    iVar5 = uVar6 * 4;
    if (iVar1 == *(int *)(iVar5 + 0x365d74)) {
      iVar1 = FUN_001c3b10(param_1);
      uVar2 = FUN_001c3ab0(param_1);
      uRam00365db8 = iVar1 + (uVar2 & 0xffff);
      if ((uRam00365db8 < *(uint *)(iVar5 + 0x365cf4)) && (uRam00365db8 < 0x1000)) {
        *(undefined1 *)((int)piVar4 + 0xd) = 0x2b;
      }
      else {
        uRam00365db8 = 0;
        bRam00365db4 = bRam00365db4 + 1;
        if ((bRam00365db4 < uRam00365cf0) && (bRam00365db4 < 8)) {
          *(undefined1 *)((int)piVar4 + 0xd) = 0x2b;
        }
        else if (*piVar4 == 3) {
          *(undefined1 *)((int)piVar4 + 0xd) = 0x31;
        }
        else {
          *(undefined1 *)((int)piVar4 + 0xd) = 2;
        }
      }
      lVar3 = FUN_001c3b90(param_1,iRam0035ccc8 + uVar6 * 0x800 + iVar1 + 0x1000);
      if (lVar3 < 0) {
        piVar4[0x37] = -1;
        *(undefined1 *)(piVar4 + 3) = 7;
        *(undefined1 *)((int)piVar4 + 0xd) = 0;
        *(undefined1 *)((int)piVar4 + 0xe) = 0;
        *(undefined1 *)((int)piVar4 + 0xf) = 0;
        *(undefined2 *)(piVar4 + 4) = 0;
        *(undefined2 *)((int)piVar4 + 0x12) = 0;
        *(undefined2 *)(piVar4 + 5) = 0;
        *(undefined2 *)((int)piVar4 + 0x16) = 0;
      }
    }
    else {
      piVar4[0x37] = -1;
      *(undefined1 *)(piVar4 + 3) = 7;
      *(undefined1 *)((int)piVar4 + 0xd) = 0;
      *(undefined1 *)((int)piVar4 + 0xe) = 0;
      *(undefined1 *)((int)piVar4 + 0xf) = 0;
      *(undefined2 *)(piVar4 + 4) = 0;
      *(undefined2 *)((int)piVar4 + 0x12) = 0;
      *(undefined2 *)(piVar4 + 5) = 0;
      *(undefined2 *)((int)piVar4 + 0x16) = 0;
    }
  }
  return 0;
}

