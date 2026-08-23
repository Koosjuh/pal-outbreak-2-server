
void FUN_001cb410(void)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 1;
  piVar2 = (int *)0x36c570;
  do {
    if (*piVar2 != 0) {
      FUN_001cb490();
    }
    FUN_00106b60(piVar2,0,0x10);
    iVar1 = iVar1 + 1;
    piVar2 = piVar2 + 4;
  } while (iVar1 < 0x100);
  DAT_0024c7f8 = 0xffffffff;
  return;
}

