
undefined8 FUN_001c92d0(undefined8 param_1)

{
  undefined4 uVar1;
  long lVar2;
  undefined4 *puVar3;
  
  puVar3 = (undefined4 *)param_1;
  switch(*puVar3) {
  case 0:
  case 7:
    cRam00365dd0 = FUN_001c3a60();
    if (cRam00365dd0 == '\0') {
      *(undefined1 *)((int)puVar3 + 0xd) = 0x23;
    }
    else if (cRam00365dd0 == '\x01') {
      lVar2 = FUN_001c3b90(param_1,(int)puVar3 + 0x4e,0xe);
      if (lVar2 < 0) {
        puVar3[0x37] = 0xffffffff;
        *(undefined1 *)(puVar3 + 3) = 7;
        *(undefined1 *)((int)puVar3 + 0xd) = 0;
        *(undefined1 *)((int)puVar3 + 0xe) = 0;
        *(undefined1 *)((int)puVar3 + 0xf) = 0;
        *(undefined2 *)(puVar3 + 4) = 0;
        *(undefined2 *)((int)puVar3 + 0x12) = 0;
        *(undefined2 *)(puVar3 + 5) = 0;
        *(undefined2 *)((int)puVar3 + 0x16) = 0;
      }
      else {
        FUN_001069a8(0x365dd1,(int)puVar3 + 0x4e,10);
        uRam00365ddb = 0;
        FUN_001069a8(0x365de1,puVar3 + 0x16,4);
        uRam00365de5 = 0;
        uVar1 = FUN_001c3b10(param_1);
        puVar3[0x1c] = uVar1;
        uRam00365dec = puVar3[0x1c];
        uVar1 = FUN_001c3b10(param_1);
        puVar3[0x1d] = uVar1;
        puVar3[0x12] = 0;
        *(undefined1 *)((int)puVar3 + 0xd) = 0x17;
      }
    }
    else {
      puVar3[0x37] = 0xffffffff;
      *(undefined1 *)(puVar3 + 3) = 7;
      *(undefined1 *)((int)puVar3 + 0xd) = 0;
      *(undefined1 *)((int)puVar3 + 0xe) = 0;
      *(undefined1 *)((int)puVar3 + 0xf) = 0;
      *(undefined2 *)(puVar3 + 4) = 0;
      *(undefined2 *)((int)puVar3 + 0x12) = 0;
      *(undefined2 *)(puVar3 + 5) = 0;
      *(undefined2 *)((int)puVar3 + 0x16) = 0;
    }
    break;
  case 1:
    *(undefined1 *)((int)puVar3 + 0xd) = 0x34;
    break;
  case 2:
    *(undefined1 *)((int)puVar3 + 0xd) = 0x10;
    break;
  case 3:
    *(undefined1 *)((int)puVar3 + 0xd) = 0x1f;
    break;
  case 4:
    uRam00365e0c = (undefined2)puVar3[1];
    uRam00365e10 = 0;
    uRam00365e18 = 0;
    uRam00365e12 = 0;
    uRam00365e0e = uRam00365e0c;
    *(undefined1 *)((int)puVar3 + 0xd) = 8;
    break;
  case 5:
    *(undefined1 *)((int)puVar3 + 0xd) = 4;
    break;
  case 6:
    *(undefined1 *)((int)puVar3 + 0xd) = 0x10;
  }
  return 0;
}

