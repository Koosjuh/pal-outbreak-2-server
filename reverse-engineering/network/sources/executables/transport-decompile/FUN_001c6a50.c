
undefined8 FUN_001c6a50(undefined8 param_1)

{
  char cVar1;
  ulong uVar2;
  int iVar3;
  
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
    cVar1 = FUN_001c3a60();
    if (cVar1 == '\x01') {
      uVar2 = FUN_001c3b10(param_1);
      if (uVar2 < 0x100) {
        if (uVar2 == 0) {
          uRam0035b7d0 = 0;
          *(undefined1 *)(iVar3 + 0xd) = 0x1d;
        }
        else {
          uRam0035b7d0 = (undefined4)uVar2;
          FUN_00106b60(0x35b7e0,0,0x100);
          *(undefined4 *)(iVar3 + 0x48) = 0;
          *(undefined1 *)(iVar3 + 0xd) = 0x27;
        }
      }
      else {
        *(undefined4 *)(iVar3 + 0xdc) = 0xffffffff;
        *(undefined1 *)(iVar3 + 0xc) = 7;
        *(undefined1 *)(iVar3 + 0xd) = 0;
        *(undefined1 *)(iVar3 + 0xe) = 0;
        *(undefined1 *)(iVar3 + 0xf) = 0;
        *(undefined2 *)(iVar3 + 0x10) = 0;
        *(undefined2 *)(iVar3 + 0x12) = 0;
        *(undefined2 *)(iVar3 + 0x14) = 0;
        *(undefined2 *)(iVar3 + 0x16) = 0;
      }
    }
    else {
      *(undefined4 *)(iVar3 + 0xdc) = 0xffffffff;
      *(undefined1 *)(iVar3 + 0xc) = 7;
      *(undefined1 *)(iVar3 + 0xd) = 0;
      *(undefined1 *)(iVar3 + 0xe) = 0;
      *(undefined1 *)(iVar3 + 0xf) = 0;
      *(undefined2 *)(iVar3 + 0x10) = 0;
      *(undefined2 *)(iVar3 + 0x12) = 0;
      *(undefined2 *)(iVar3 + 0x14) = 0;
      *(undefined2 *)(iVar3 + 0x16) = 0;
    }
  }
  return 0;
}

