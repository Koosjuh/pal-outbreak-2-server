
undefined8 FUN_001c6e80(undefined8 param_1)

{
  char cVar1;
  int *piVar2;
  
  piVar2 = (int *)param_1;
  if (*(char *)(piVar2[0xc] + 6) == -1) {
    piVar2[0x37] = 9;
    *(undefined1 *)(piVar2 + 3) = 7;
    *(undefined1 *)((int)piVar2 + 0xd) = 0;
    *(undefined1 *)((int)piVar2 + 0xe) = 0;
    *(undefined1 *)((int)piVar2 + 0xf) = 0;
    *(undefined2 *)(piVar2 + 4) = 0;
    *(undefined2 *)((int)piVar2 + 0x12) = 0;
    *(undefined2 *)(piVar2 + 5) = 0;
    *(undefined2 *)((int)piVar2 + 0x16) = 0;
  }
  else {
    cVar1 = FUN_001c3a60();
    if (cVar1 == '\x01') {
      uRam00365e04 = FUN_001c3b10(param_1);
      uRam00365e00 = FUN_001c3b10(param_1);
      *(undefined1 *)((int)piVar2 + 0xd) = 6;
      uRam00365e1a = 8;
      uRam00365e18 = 0;
      uRam00365e12 = 0;
      uRam00365e10 = 0;
      uRam00365e0c = 0;
    }
    else if (cVar1 == '\0') {
      if (*piVar2 == 5) {
        uRam00365e18 = 0;
        uRam00365e12 = 0;
        uRam00365e10 = 0;
        uRam00365e0c = 0;
        *(undefined1 *)((int)piVar2 + 0xd) = 0xc;
      }
      else {
        uRam00365e18 = 0;
        uRam00365e12 = 0;
        uRam00365e10 = 0;
        uRam00365e0c = 0;
        *(undefined1 *)((int)piVar2 + 0xd) = 8;
      }
    }
    else {
      piVar2[0x37] = -1;
      *(undefined1 *)(piVar2 + 3) = 7;
      *(undefined1 *)((int)piVar2 + 0xd) = 0;
      *(undefined1 *)((int)piVar2 + 0xe) = 0;
      *(undefined1 *)((int)piVar2 + 0xf) = 0;
      *(undefined2 *)(piVar2 + 4) = 0;
      *(undefined2 *)((int)piVar2 + 0x12) = 0;
      *(undefined2 *)(piVar2 + 5) = 0;
      *(undefined2 *)((int)piVar2 + 0x16) = 0;
    }
  }
  return 0;
}

