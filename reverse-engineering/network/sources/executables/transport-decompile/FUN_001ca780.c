
void FUN_001ca780(void)

{
  uRam003688e0 = 1;
  FUN_001cac60();
  WaitSema(DAT_00248860);
  DeleteSema(DAT_00248860);
  DAT_00248860 = 0xffffffff;
  DAT_00248858 = 0xffffffff;
  return;
}

