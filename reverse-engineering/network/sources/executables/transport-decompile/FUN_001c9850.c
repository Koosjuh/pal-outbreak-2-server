
undefined8 FUN_001c9850(undefined8 param_1)

{
  char cVar1;
  short sVar2;
  long lVar3;
  int iVar4;
  
  iVar4 = (int)param_1;
  cVar1 = *(char *)(iVar4 + 0xd);
  if (cVar1 == '\x03') {
    FUN_001c3420(param_1,5);
    sVar2 = *(short *)(iVar4 + 0x10) + -1;
    *(short *)(iVar4 + 0x10) = sVar2;
    if (sVar2 < 1) {
      FUN_001c3420();
      lVar3 = FUN_001c9780();
      if (lVar3 == 0) {
        *(undefined4 *)(iVar4 + 0xdc) = 3;
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
      lVar3 = FUN_001ee430(*(undefined4 *)(iVar4 + 0x1c),0x35a714);
      if (lVar3 < 0) {
        FUN_001c3420(param_1,7);
        lVar3 = FUN_001c9780();
        if (lVar3 == 0) {
          *(undefined4 *)(iVar4 + 0xdc) = 4;
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
      else if (sRam0035a714 == 4) {
        uRam0035ccb3 = 0;
        *(undefined4 *)(iVar4 + 0xd8) = 2;
        if (*(char *)(iVar4 + 0xc) != '\a') {
          *(char *)(iVar4 + 0xc) = *(char *)(iVar4 + 0xc) + '\x01';
        }
        *(undefined1 *)(iVar4 + 0xd) = 0;
        *(undefined2 *)(iVar4 + 0x10) = 0x708;
      }
    }
  }
  else if (cVar1 == '\x02') {
    FUN_001c3420(param_1,4);
    lVar3 = FUN_001c3850(*(undefined4 *)(iVar4 + 0x18),
                         (uRam0035ccb0 & 0xff) << 8 | (int)(uint)uRam0035ccb0 >> 8);
    *(int *)(iVar4 + 0x1c) = (int)lVar3;
    if (lVar3 < 0) {
      lVar3 = FUN_001c9780(param_1);
      if (lVar3 == 0) {
        *(undefined4 *)(iVar4 + 0xdc) = 2;
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
      *(char *)(iVar4 + 0xd) = *(char *)(iVar4 + 0xd) + '\x01';
      *(undefined1 *)(iVar4 + 0xe) = 0;
      *(undefined2 *)(iVar4 + 0x10) = 0x708;
    }
  }
  else if (cVar1 == '\x01') {
    FUN_001c3420(param_1,3);
    lVar3 = FUN_001c08e0(iVar4 + 0xe,iVar4 + 0x10,iVar4 + 0x18,0x35cc70);
    if (lVar3 == -1) {
      lVar3 = FUN_001c9780(param_1);
      if (lVar3 == 0) {
        *(undefined4 *)(iVar4 + 0xdc) = 1;
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
    else if (lVar3 == 1) {
      *(char *)(iVar4 + 0xd) = *(char *)(iVar4 + 0xd) + '\x01';
    }
  }
  else if (cVar1 == '\0') {
    FUN_001c3420();
    *(char *)(iVar4 + 0xd) = *(char *)(iVar4 + 0xd) + '\x01';
    *(undefined1 *)(iVar4 + 0xe) = 0;
    *(undefined2 *)(iVar4 + 0x10) = 0;
  }
  return 0;
}

