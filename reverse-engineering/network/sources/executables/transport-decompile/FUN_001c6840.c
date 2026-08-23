
undefined8 FUN_001c6840(undefined8 param_1)

{
  uint uVar1;
  long lVar2;
  int *piVar3;
  undefined1 auStack_400 [1024];
  
  piVar3 = (int *)param_1;
  if (*(char *)(piVar3[0xc] + 6) == -1) {
    piVar3[0x37] = 9;
    *(undefined1 *)(piVar3 + 3) = 7;
    *(undefined1 *)((int)piVar3 + 0xd) = 0;
    *(undefined1 *)((int)piVar3 + 0xe) = 0;
    *(undefined1 *)((int)piVar3 + 0xf) = 0;
    *(undefined2 *)(piVar3 + 4) = 0;
    *(undefined2 *)((int)piVar3 + 0x12) = 0;
    *(undefined2 *)(piVar3 + 5) = 0;
    *(undefined2 *)((int)piVar3 + 0x16) = 0;
    return 0;
  }
  if ((*piVar3 == 0) || (*piVar3 == 7)) {
    uVar1 = FUN_001c3ab0(param_1);
    if ((uVar1 & 0xffff) != 0) {
      uRam0035b9e8 = uVar1 & 0xffff;
    }
    lVar2 = FUN_001c3b90(param_1,auStack_400,0xff);
    if (lVar2 < 0) {
      piVar3[0x37] = -1;
      *(undefined1 *)(piVar3 + 3) = 7;
      *(undefined1 *)((int)piVar3 + 0xd) = 0;
      *(undefined1 *)((int)piVar3 + 0xe) = 0;
      *(undefined1 *)((int)piVar3 + 0xf) = 0;
      *(undefined2 *)(piVar3 + 4) = 0;
      *(undefined2 *)((int)piVar3 + 0x12) = 0;
      *(undefined2 *)(piVar3 + 5) = 0;
      *(undefined2 *)((int)piVar3 + 0x16) = 0;
      return 0;
    }
    if (lVar2 != 0) {
      FUN_0010a4f0(0x35b8e0,auStack_400,0x100);
    }
    lVar2 = FUN_001c3b90(param_1,auStack_400,0xff);
    if (lVar2 < 0) {
      piVar3[0x37] = -1;
      *(undefined1 *)(piVar3 + 3) = 7;
      *(undefined1 *)((int)piVar3 + 0xd) = 0;
      *(undefined1 *)((int)piVar3 + 0xe) = 0;
      *(undefined1 *)((int)piVar3 + 0xf) = 0;
      *(undefined2 *)(piVar3 + 4) = 0;
      *(undefined2 *)((int)piVar3 + 0x12) = 0;
      *(undefined2 *)(piVar3 + 5) = 0;
      *(undefined2 *)((int)piVar3 + 0x16) = 0;
      return 0;
    }
    if (lVar2 != 0) {
      FUN_0010a4f0(0x35bee0,auStack_400,0x100);
    }
  }
  *(undefined1 *)((int)piVar3 + 0xd) = 0x25;
  return 0;
}

