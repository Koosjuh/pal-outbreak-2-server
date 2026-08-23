
undefined8 FUN_001c9030(undefined8 param_1)

{
  long lVar1;
  int iVar2;
  
  iVar2 = (int)param_1;
  if (*(char *)(*(int *)(iVar2 + 0x30) + 6) == -1) {
    *(undefined4 *)(iVar2 + 0xdc) = 9;
    *(undefined1 *)(iVar2 + 0xc) = 7;
    *(undefined1 *)(iVar2 + 0xd) = 0;
    *(undefined1 *)(iVar2 + 0xe) = 0;
    *(undefined1 *)(iVar2 + 0xf) = 0;
    *(undefined2 *)(iVar2 + 0x10) = 0;
    *(undefined2 *)(iVar2 + 0x12) = 0;
    *(undefined2 *)(iVar2 + 0x14) = 0;
    *(undefined2 *)(iVar2 + 0x16) = 0;
    return 0;
  }
  cRam00365dc0 = FUN_001c3a60();
  if (cRam00365dc0 != '\0') {
    if (cRam00365dc0 != '\x01') {
      *(undefined4 *)(iVar2 + 0xdc) = 0xffffffff;
      *(undefined1 *)(iVar2 + 0xc) = 7;
      *(undefined1 *)(iVar2 + 0xd) = 0;
      *(undefined1 *)(iVar2 + 0xe) = 0;
      *(undefined1 *)(iVar2 + 0xf) = 0;
      *(undefined2 *)(iVar2 + 0x10) = 0;
      *(undefined2 *)(iVar2 + 0x12) = 0;
      *(undefined2 *)(iVar2 + 0x14) = 0;
      *(undefined2 *)(iVar2 + 0x16) = 0;
      return 0;
    }
    uRam00365dc4 = FUN_001c3a60(param_1);
    uRam00365dc4 = uRam00365dc4 & 0xff;
    lVar1 = FUN_001c3b90(param_1,iRam0035ccc8,0x13);
    if (lVar1 < 0) {
      *(undefined4 *)(iVar2 + 0xdc) = 0xffffffff;
      *(undefined1 *)(iVar2 + 0xc) = 7;
      *(undefined1 *)(iVar2 + 0xd) = 0;
      *(undefined1 *)(iVar2 + 0xe) = 0;
      *(undefined1 *)(iVar2 + 0xf) = 0;
      *(undefined2 *)(iVar2 + 0x10) = 0;
      *(undefined2 *)(iVar2 + 0x12) = 0;
      *(undefined2 *)(iVar2 + 0x14) = 0;
      *(undefined2 *)(iVar2 + 0x16) = 0;
      return 0;
    }
    iRam00365dc8 = iRam0035ccc8;
    lVar1 = FUN_001c3b90(param_1,iRam0035ccc8 + 0x14,0xfeb);
    if (lVar1 < 0) {
      *(undefined4 *)(iVar2 + 0xdc) = 0xffffffff;
      *(undefined1 *)(iVar2 + 0xc) = 7;
      *(undefined1 *)(iVar2 + 0xd) = 0;
      *(undefined1 *)(iVar2 + 0xe) = 0;
      *(undefined1 *)(iVar2 + 0xf) = 0;
      *(undefined2 *)(iVar2 + 0x10) = 0;
      *(undefined2 *)(iVar2 + 0x12) = 0;
      *(undefined2 *)(iVar2 + 0x14) = 0;
      *(undefined2 *)(iVar2 + 0x16) = 0;
      return 0;
    }
    iRam00365dcc = iRam0035ccc8 + 0x14;
  }
  *(undefined1 *)(iVar2 + 0xd) = 0x29;
  return 0;
}

