
undefined8 FUN_001c4960(undefined8 param_1)

{
  char cVar1;
  uint uVar2;
  long lVar3;
  int iVar4;
  uint uVar5;
  uint *puVar6;
  
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
    FUN_001c2f30();
  }
  else {
    cVar1 = FUN_001c3a60();
    if (cVar1 == '\x02') {
      *(undefined1 *)(iVar4 + 0xd) = 0x14;
    }
    else if (cVar1 == '\x01') {
      FUN_00106b60(0x36844c,0,0x20);
      lVar3 = FUN_001c3b90(param_1,0x36844c,0x1f);
      if (lVar3 < 0) {
        FUN_001c2f30();
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
      else {
        lVar3 = FUN_0010a338(0x36842c,0x36844c,0x1f);
        if (lVar3 == 0) {
          *(undefined1 *)(iVar4 + 0xd) = 0x14;
        }
        else {
          uRam0036842a = FUN_001c3ab0(param_1);
          if (uRam0036842a == 0) {
            FUN_001c2f30();
            *(undefined4 *)(iVar4 + 0xdc) = 0xffffffff;
            *(undefined1 *)(iVar4 + 0xc) = 7;
            *(undefined1 *)(iVar4 + 0xd) = 0;
            *(undefined1 *)(iVar4 + 0xe) = 0;
            *(undefined1 *)(iVar4 + 0xf) = 0;
            *(undefined2 *)(iVar4 + 0x10) = 0;
            *(undefined2 *)(iVar4 + 0x12) = 0;
            *(undefined2 *)(iVar4 + 0x14) = 0;
            *(undefined2 *)(iVar4 + 0x16) = 0;
            return 0;
          }
          if (2 < uRam0036842a) {
            uRam0036842a = 2;
          }
          if (iRam0036846c != 0) {
            FUN_001069a8(uRam00368478,uRam00368474);
          }
          iRam00368470 = iRam0036846c;
          for (uVar5 = 0; uVar5 < uRam0036842a; uVar5 = uVar5 + 1 & 0xffff) {
            puVar6 = (uint *)(uVar5 * 4 + 0x36846c);
            uVar2 = FUN_001c3b10(param_1);
            *puVar6 = uVar2;
            if (0x2000 < *puVar6) {
              FUN_001c2f30();
              *(undefined4 *)(iVar4 + 0xdc) = 0xffffffff;
              *(undefined1 *)(iVar4 + 0xc) = 7;
              *(undefined1 *)(iVar4 + 0xd) = 0;
              *(undefined1 *)(iVar4 + 0xe) = 0;
              *(undefined1 *)(iVar4 + 0xf) = 0;
              *(undefined2 *)(iVar4 + 0x10) = 0;
              *(undefined2 *)(iVar4 + 0x12) = 0;
              *(undefined2 *)(iVar4 + 0x14) = 0;
              *(undefined2 *)(iVar4 + 0x16) = 0;
              return 0;
            }
          }
          FUN_001c2f30();
          *(undefined1 *)(iVar4 + 0xd) = 0x12;
        }
        *(undefined4 *)(iVar4 + 0x48) = 0;
        uRam00368424 = 0;
        uRam00368421 = 0;
      }
    }
    else if (cVar1 == '\0') {
      FUN_001c2f30();
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
    else {
      FUN_001c2f30();
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

