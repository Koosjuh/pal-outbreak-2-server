FUNCTION FUN_00001930 @ 0x00001930 size=384
CALLERS (0): 
CALLEES (9): FUN_00012608@0x00012608, FUN_00006844@0x00006844, FUN_00012580@0x00012580, FUN_0000bf04@0x0000bf04, FUN_0000c5dc@0x0000c5dc, FUN_000124b8@0x000124b8, FUN_00002914@0x00002914, FUN_00012490@0x00012490, FUN_00012638@0x00012638

void FUN_00001930(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar2 = FUN_00012608();
  FUN_00012490();
  DAT_000161ac = DAT_000161ac + 1;
  FUN_000124b8();
  iVar4 = iVar2;
  iVar1 = iVar2;
  iVar5 = iVar2;
  while (DAT_000161ae == 0) {
    FUN_00012580((int)DAT_0001617c);
    iVar3 = FUN_00012608();
    if (999 < (uint)(iVar3 - iVar2)) {
      FUN_00012490();
      FUN_00006844();
      FUN_000124b8();
      iVar2 = iVar3;
    }
    if (499 < (uint)(iVar3 - iVar5)) {
      FUN_00012490();
      FUN_0000bf04();
      FUN_000124b8();
      iVar5 = iVar3;
    }
    if (99 < (uint)(iVar3 - iVar4)) {
      FUN_0000c5dc();
      iVar4 = iVar3;
    }
    if (59999 < (uint)(iVar3 - iVar1)) {
      FUN_00012490();
      FUN_00002914();
      FUN_000124b8();
      iVar1 = iVar3;
    }
  }
  FUN_00012490();
  DAT_000161ac = DAT_000161ac + -1;
  FUN_000124b8();
  FUN_00012638();
  return;
}


================================================================