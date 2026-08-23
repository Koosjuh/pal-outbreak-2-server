
undefined8 FUN_001c91d0(undefined8 param_1)

{
  long lVar1;
  int iVar2;
  
  iVar2 = (int)param_1;
  if (cRam0035ccb3 == '\0') {
    FUN_00106b60(0x35cc70,0,0x3f);
    lVar1 = FUN_001c3b90(param_1,0x35cc70,0x3e);
    if (lVar1 < 1) {
      *(undefined4 *)(iVar2 + 0xdc) = 0xffffffc8;
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
    sRam0035ccb0 = FUN_001c3ab0(param_1);
    if (sRam0035ccb0 == 0) {
      *(undefined4 *)(iVar2 + 0xdc) = 0xffffffc8;
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
  }
  *(undefined1 *)(iVar2 + 0xd) = 0x31;
  cRam0035ccb3 = 1;
  return 0;
}

