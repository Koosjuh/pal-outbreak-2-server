
void FUN_001ca7d0(void)

{
  if (DAT_00248868 != -1) {
    iSignalSema();
    SYNC(0);
    EI();
  }
  return;
}

