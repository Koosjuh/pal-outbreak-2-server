
undefined8 FUN_001c4730(undefined8 param_1)

{
  int *piVar1;
  int iStack_4;
  
  piVar1 = (int *)param_1;
  if (*(char *)(piVar1[0xc] + 6) == -1) {
    piVar1[0x37] = 9;
    *(undefined1 *)(piVar1 + 3) = 7;
    *(undefined1 *)((int)piVar1 + 0xd) = 0;
    *(undefined1 *)((int)piVar1 + 0xe) = 0;
    *(undefined1 *)((int)piVar1 + 0xf) = 0;
    *(undefined2 *)(piVar1 + 4) = 0;
    *(undefined2 *)((int)piVar1 + 0x12) = 0;
    *(undefined2 *)(piVar1 + 5) = 0;
    *(undefined2 *)((int)piVar1 + 0x16) = 0;
  }
  else {
    if ((*piVar1 == 0) || (*piVar1 == 7)) {
      iStack_4 = FUN_001c3b10(param_1);
      if (iStack_4 != 0) {
        FUN_001069a8(0x248338,&iStack_4,4);
      }
      iStack_4 = FUN_001c3b10(param_1);
      if (iStack_4 != 0) {
        FUN_001069a8(0x248358,&iStack_4,4);
      }
      iStack_4 = FUN_001c3b10(param_1);
      if (iStack_4 != 0) {
        FUN_001069a8(0x349f70,&iStack_4,4);
      }
      FUN_001c3b10(param_1);
      FUN_001c3b10(param_1);
      FUN_001c3b10(param_1);
      FUN_001c3b10(param_1);
      FUN_001c3b10(param_1);
      FUN_001c3b10(param_1);
      FUN_001c3b10(param_1);
      FUN_001c3b10(param_1);
      FUN_001c3b10(param_1);
      FUN_001c3b10(param_1);
      FUN_001c3b10(param_1);
      FUN_001c3b10(param_1);
      FUN_001c3b10(param_1);
      FUN_001c3b10(param_1);
    }
    *(undefined1 *)((int)piVar1 + 0xd) = 0x1f;
  }
  return 0;
}

