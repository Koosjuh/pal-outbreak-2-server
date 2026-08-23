
undefined8 FUN_001c5260(undefined8 param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  long lVar4;
  int iVar5;
  uint *puVar6;
  uint uVar7;
  
  iVar5 = (int)param_1;
  if (*(char *)(*(int *)(iVar5 + 0x30) + 6) == -1) {
    *(undefined4 *)(iVar5 + 0xdc) = 9;
    *(undefined1 *)(iVar5 + 0xc) = 7;
    *(undefined1 *)(iVar5 + 0xd) = 0;
    *(undefined1 *)(iVar5 + 0xe) = 0;
    *(undefined1 *)(iVar5 + 0xf) = 0;
    *(undefined2 *)(iVar5 + 0x10) = 0;
    *(undefined2 *)(iVar5 + 0x12) = 0;
    *(undefined2 *)(iVar5 + 0x14) = 0;
    *(undefined2 *)(iVar5 + 0x16) = 0;
  }
  else {
    uVar2 = FUN_001c3ab0();
    uVar2 = uVar2 & 0xffff;
    if (uVar2 == bRam00365db4) {
      uVar3 = FUN_001c3b10(param_1);
      if (uVar3 == uRam00365db8) {
        *(undefined1 *)(iVar5 + 0xd) = 0x1b;
        uRam00365db8 = uVar3 + 0x2f2;
        puVar6 = (uint *)(uVar2 * 4 + 0x365cf4);
        uVar1 = *puVar6;
        uVar7 = 0x2f2;
        if ((uVar1 <= uRam00365db8) || (0x3ff < uRam00365db8)) {
          uRam00365db8 = 0;
          uVar7 = uVar1 - uVar3 & 0xffff;
          bRam00365db4 = bRam00365db4 + 1;
          if ((uRam00365cf0 <= bRam00365db4) || (7 < bRam00365db4)) {
            bRam00365db4 = 0;
            uRam00365db8 = 0;
            *(undefined1 *)(iVar5 + 0xd) = 0x3b;
          }
        }
        if ((*puVar6 != 0) &&
           (lVar4 = FUN_001c3b90(param_1,iRam0035ccc8 + uVar2 * 0x400 + uVar3 + 0x1000,uVar7),
           lVar4 < 0)) {
          *(undefined4 *)(iVar5 + 0xdc) = 0xffffffff;
          *(undefined1 *)(iVar5 + 0xc) = 7;
          *(undefined1 *)(iVar5 + 0xd) = 0;
          *(undefined1 *)(iVar5 + 0xe) = 0;
          *(undefined1 *)(iVar5 + 0xf) = 0;
          *(undefined2 *)(iVar5 + 0x10) = 0;
          *(undefined2 *)(iVar5 + 0x12) = 0;
          *(undefined2 *)(iVar5 + 0x14) = 0;
          *(undefined2 *)(iVar5 + 0x16) = 0;
        }
      }
      else {
        *(undefined4 *)(iVar5 + 0xdc) = 0xffffffff;
        *(undefined1 *)(iVar5 + 0xc) = 7;
        *(undefined1 *)(iVar5 + 0xd) = 0;
        *(undefined1 *)(iVar5 + 0xe) = 0;
        *(undefined1 *)(iVar5 + 0xf) = 0;
        *(undefined2 *)(iVar5 + 0x10) = 0;
        *(undefined2 *)(iVar5 + 0x12) = 0;
        *(undefined2 *)(iVar5 + 0x14) = 0;
        *(undefined2 *)(iVar5 + 0x16) = 0;
      }
    }
    else {
      *(undefined4 *)(iVar5 + 0xdc) = 0xffffffff;
      *(undefined1 *)(iVar5 + 0xc) = 7;
      *(undefined1 *)(iVar5 + 0xd) = 0;
      *(undefined1 *)(iVar5 + 0xe) = 0;
      *(undefined1 *)(iVar5 + 0xf) = 0;
      *(undefined2 *)(iVar5 + 0x10) = 0;
      *(undefined2 *)(iVar5 + 0x12) = 0;
      *(undefined2 *)(iVar5 + 0x14) = 0;
      *(undefined2 *)(iVar5 + 0x16) = 0;
    }
  }
  return 0;
}

