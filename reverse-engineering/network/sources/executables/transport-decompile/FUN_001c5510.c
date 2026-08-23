
undefined8 FUN_001c5510(undefined8 param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
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
    if (2 < uVar1) {
      uVar1 = 2;
    }
    if (uVar1 == 0) {
      *(undefined1 *)(iVar3 + 0xd) = 0x3f;
    }
    else {
      uRam00365c20 = (undefined2)uVar1;
      for (iVar4 = 0; iVar4 < (int)uVar1; iVar4 = iVar4 + 1) {
        *(int *)(iVar4 * 4 + 0x365c64) = iRam0035ccc0 + iVar4 * 0x800;
        uVar2 = FUN_001c3b10(param_1);
        *(undefined4 *)(iVar4 * 4 + 0x365c24) = uVar2;
      }
      uRam00365ce8 = 0;
      uRam00365ce4 = 0;
      *(undefined1 *)(iVar3 + 0xd) = 0x3d;
    }
  }
  return 0;
}

