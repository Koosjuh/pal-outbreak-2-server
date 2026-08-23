
undefined8 FUN_001c6c60(undefined8 param_1)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  long lVar4;
  int iVar5;
  
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
    cVar1 = FUN_001c3a60();
    if (cVar1 == '\x01') {
      iVar2 = FUN_001c3b10(param_1);
      uVar3 = FUN_001c3ab0(param_1);
      uVar3 = iVar2 + (uVar3 & 0xffff);
      if ((uVar3 < uRam0035b7d0) && (uVar3 < 0x100)) {
        *(uint *)(iVar5 + 0x48) = uVar3;
        *(undefined1 *)(iVar5 + 0xd) = 0x27;
      }
      else {
        *(undefined1 *)(iVar5 + 0xd) = 0x1d;
      }
      lVar4 = FUN_001c3b90(param_1,iVar2 + 0x35b7e0);
      if (lVar4 < 0) {
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

