
undefined8 FUN_001c45f0(int *param_1)

{
  int iVar1;
  
  if (*(char *)(param_1[0xc] + 6) == -1) {
    uRam0036847c = 0;
  }
  else {
    uRam0036847c = FUN_001c3b10();
  }
  iVar1 = *param_1;
  if (((iVar1 == 7) || (iVar1 == 0)) || (iVar1 == 1)) {
    *(undefined1 *)((int)param_1 + 0xd) = 0xe;
  }
  else if (iVar1 == 2) {
    *(undefined1 *)((int)param_1 + 0xd) = 0x2d;
  }
  else {
    *(undefined1 *)((int)param_1 + 0xd) = 0x31;
  }
  return 0;
}

