
undefined8 FUN_001c63c0(undefined8 param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
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
    if (8 < uVar1) {
      uVar1 = 8;
    }
    uRam00365bb0 = (undefined2)uVar1;
    if (uVar1 == 0) {
      *(undefined1 *)(iVar3 + 0xd) = 0x31;
    }
    else {
      for (uVar5 = 0; uVar5 < uVar1; uVar5 = uVar5 + 1 & 0xff) {
        iVar4 = uVar5 * 4;
        *(uint *)(iVar4 + 0x365bf4) = iRam0035ccb8 + uVar5 * 0x200;
        uVar2 = FUN_001c3b10(param_1);
        *(undefined4 *)(iVar4 + 0x365bb4) = uVar2;
        uVar2 = FUN_001c3b10(param_1);
        *(undefined4 *)(iVar4 + 0x365bd4) = uVar2;
      }
      uRam00365c18 = 0;
      uRam00365c14 = 0;
      *(undefined1 *)(iVar3 + 0xd) = 0x41;
    }
  }
  return 0;
}

