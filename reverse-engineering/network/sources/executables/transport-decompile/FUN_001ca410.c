
undefined8 FUN_001ca410(undefined8 param_1)

{
  char cVar1;
  long lVar2;
  undefined4 *puVar3;
  
  puVar3 = (undefined4 *)param_1;
  cVar1 = *(char *)((int)puVar3 + 0xd);
  if (cVar1 == '\x02') {
    FUN_001c3450(param_1,100,4);
    if (99 < (int)puVar3[0x38]) {
      puVar3[0x36] = 3;
      puVar3[0x37] = 0;
    }
  }
  else if (cVar1 == '\x01') {
    FUN_001c3450(param_1,99,4);
    lVar2 = FUN_001c08e0((int)puVar3 + 0xe,puVar3 + 4,0x35bed8,0x35bee0);
    if (lVar2 == -1) {
      puVar3[0x37] = 1;
      *(undefined1 *)(puVar3 + 3) = 7;
      *(undefined1 *)((int)puVar3 + 0xd) = 0;
      *(undefined1 *)((int)puVar3 + 0xe) = 0;
      *(undefined1 *)((int)puVar3 + 0xf) = 0;
      *(undefined2 *)(puVar3 + 4) = 0;
      *(undefined2 *)((int)puVar3 + 0x12) = 0;
      *(undefined2 *)(puVar3 + 5) = 0;
      *(undefined2 *)((int)puVar3 + 0x16) = 0;
    }
    else if (lVar2 == 1) {
      *(char *)((int)puVar3 + 0xd) = *(char *)((int)puVar3 + 0xd) + '\x01';
    }
  }
  else if (cVar1 == '\0') {
    if (cRam0035ccb3 == '\0') {
      FUN_001c3450(param_1,0x62,4);
      switch(*puVar3) {
      case 0:
      case 1:
      case 3:
      case 7:
        *(char *)((int)puVar3 + 0xd) = *(char *)((int)puVar3 + 0xd) + '\x01';
        break;
      case 2:
      case 4:
      case 5:
      case 6:
        *(char *)((int)puVar3 + 0xd) = *(char *)((int)puVar3 + 0xd) + '\x02';
      }
      *(undefined1 *)((int)puVar3 + 0xe) = 0;
      *(undefined2 *)(puVar3 + 4) = 0;
    }
    else {
      *(undefined1 *)(puVar3 + 3) = 0;
      *(undefined1 *)((int)puVar3 + 0xd) = 0;
      *(undefined1 *)((int)puVar3 + 0xe) = 0;
      *(undefined1 *)((int)puVar3 + 0xf) = 0;
      *(undefined2 *)(puVar3 + 4) = 0;
      *(undefined2 *)((int)puVar3 + 0x12) = 0;
      *(undefined2 *)(puVar3 + 5) = 0;
      *(undefined2 *)((int)puVar3 + 0x16) = 0;
    }
  }
  return 0;
}

