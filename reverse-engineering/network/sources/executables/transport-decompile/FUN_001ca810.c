
void FUN_001ca810(void)

{
  while ((iRam003688e0 == 0 && (DAT_00248868 != -1))) {
    FUN_001cae70();
    SetAlarm(0x100,0x1ca7d0,0);
    WaitSema(DAT_00248868);
  }
  DeleteSema(DAT_00248868);
  DAT_00248868 = 0xffffffff;
  DeleteSema(DAT_00248848);
  DAT_00248848 = 0xffffffff;
  SignalSema(DAT_00248860);
  ExitDeleteThread();
  return;
}

