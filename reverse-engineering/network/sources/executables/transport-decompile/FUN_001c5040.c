
undefined8 FUN_001c5040(undefined8 param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  int iVar5;
  
  iVar3 = (int)param_1;
  if (*(char *)(*(int *)(iVar3 + 0x30) + 6) == -1) {
    *(undefined4 *)(iVar3 + 0xdc) = 9;
    *(undefined1 *)(iVar3 + 0xc) = 7;
    *(undefined1 *)(iVar3 + 0xd) = 0;
    *(undefined1 *)(iVar3 + 0xe) = 0;
    *(undefined1 *)(iVar3 + 0xf) = 0;
    *(undefined2 *)(iVar3 + 0x10) = 0;
    *(undefined2 *)(iVar3 + 0x12) = 0;
    *(undefined2 *)(iVar3 + 0x14) = 0;
    *(undefined2 *)(iVar3 + 0x16) = 0;
  }
  else {
    uVar1 = FUN_001c3ab0();
    uVar1 = uVar1 & 0xffff;
    if (uVar1 == 0) {
      *(undefined1 *)(iVar3 + 0xd) = 0x3b;
    }
    else {
      if (8 < uVar1) {
        uVar1 = 8;
      }
      uRam00365cf0 = (undefined2)uVar1;
      for (iVar5 = 0; iVar5 < (int)uVar1; iVar5 = iVar5 + 1) {
        puVar4 = (uint *)(iVar5 * 4 + 0x365cf4);
        *(int *)(iVar5 * 4 + 0x365d34) = iRam0035ccc8 + iVar5 * 0x400 + 0x1000;
        uVar2 = FUN_001c3b10(param_1);
        *puVar4 = uVar2;
        if (0x400 < *puVar4) {
          *(undefined4 *)(iVar3 + 0xdc) = 0xffffffff;
          *(undefined1 *)(iVar3 + 0xc) = 7;
          *(undefined1 *)(iVar3 + 0xd) = 0;
          *(undefined1 *)(iVar3 + 0xe) = 0;
          *(undefined1 *)(iVar3 + 0xf) = 0;
          *(undefined2 *)(iVar3 + 0x10) = 0;
          *(undefined2 *)(iVar3 + 0x12) = 0;
          *(undefined2 *)(iVar3 + 0x14) = 0;
          *(undefined2 *)(iVar3 + 0x16) = 0;
          return 0;
        }
      }
      uRam00365db8 = 0;
      uRam00365db4 = 0;
      *(undefined1 *)(iVar3 + 0xd) = 0x1b;
    }
  }
  return 0;
}

