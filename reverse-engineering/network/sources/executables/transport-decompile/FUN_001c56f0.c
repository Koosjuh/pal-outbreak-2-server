
undefined8 FUN_001c56f0(undefined8 param_1)

{
  uint uVar1;
  uint uVar2;
  long lVar3;
  int iVar4;
  uint *puVar5;
  
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
    uVar1 = FUN_001c3ab0();
    uVar1 = uVar1 & 0xffff;
    if (uVar1 == bRam00365ce4) {
      uVar2 = FUN_001c3b10(param_1);
      if (uVar2 == uRam00365ce8) {
        *(undefined1 *)(iVar4 + 0xd) = 0x3d;
        uRam00365ce8 = uVar2 + 0x2f2;
        puVar5 = (uint *)(uVar1 * 4 + 0x365c24);
        if ((*puVar5 <= uRam00365ce8) || (0x7ff < uRam00365ce8)) {
          uRam00365ce8 = 0;
          bRam00365ce4 = bRam00365ce4 + 1;
          if ((uRam00365c20 <= bRam00365ce4) || (1 < bRam00365ce4)) {
            bRam00365ce4 = 0;
            uRam00365ce8 = 0;
            *(undefined1 *)(iVar4 + 0xd) = 0x3f;
          }
        }
        if ((*puVar5 != 0) &&
           (lVar3 = FUN_001c3b90(param_1,iRam0035ccc0 + uVar1 * 0x800 + uVar2,0x2f2), lVar3 < 0)) {
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

