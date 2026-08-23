FUNCTION FUN_00001800 @ 0x00001800 size=304
CALLERS (0): 
CALLEES (9): FUN_0000e0f0@0x0000e0f0, FUN_000044b4@0x000044b4, FUN_000124b8@0x000124b8, FUN_0000e234@0x0000e234, FUN_0000e1a8@0x0000e1a8, FUN_000125a0@0x000125a0, FUN_00012490@0x00012490, FUN_0000e278@0x0000e278, FUN_00012638@0x00012638

void FUN_00001800(void)

{
  short sVar1;
  int *piVar2;
  
  FUN_00012490();
  DAT_000161ac = DAT_000161ac + 1;
  FUN_0000e0f0(&DAT_00018590);
  FUN_000124b8();
  while (DAT_000161ae == 0) {
    sVar1 = FUN_0000e234(&DAT_00018590);
    if (sVar1 == 0) {
      FUN_00012490();
      do {
        piVar2 = (int *)FUN_0000e278(&DAT_00018590);
        if (*piVar2 == 1) {
          FUN_000044b4(piVar2[3],(int)(short)piVar2[2],(int)(short)piVar2[1]);
        }
        FUN_0000e1a8(&DAT_00018590);
        sVar1 = FUN_0000e234(&DAT_00018590);
      } while (sVar1 == 0);
      FUN_000124b8();
    }
    FUN_000125a0();
  }
  FUN_00012490();
  DAT_000161ac = DAT_000161ac + -1;
  FUN_000124b8();
  FUN_00012638();
  return;
}


================================================================