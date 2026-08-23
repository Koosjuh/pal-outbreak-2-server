FUNCTION FUN_0000fc50 @ 0x0000fc50 size=216
CALLERS (1): FUN_00002530@0x00002530
CALLEES (6): FUN_00002d88@0x00002d88, FUN_00000620@0x00000620, FUN_00002d58@0x00002d58, FUN_00010540@0x00010540, FUN_000105e0@0x000105e0, FUN_00002584@0x00002584

undefined4 FUN_0000fc50(void)

{
  int iVar1;
  
  FUN_00010540();
  FUN_00002584(0);
  iVar1 = FUN_00002d88();
  if (iVar1 == 0) {
    FUN_00002d58(0);
  }
  DAT_00012ecc = 0;
  DAT_00012eb4 = 0;
  DAT_00012ee4 = 0;
  DAT_00012ed4 = 0;
  DAT_00012edc = 0;
  DAT_00012ebc = 0;
  DAT_00012ec0 = 0;
  DAT_00012ef0 = 0;
  FUN_00000620(1,0);
  FUN_000105e0();
  DAT_00012ee8 = 0;
  DAT_00012eec = 0;
  DAT_00012eb8 = 0xffffffff;
  DAT_00012ed8 = 0xffffffff;
  DAT_00012eb0 = 0xffffffff;
  DAT_00012ee0 = 0xffffffff;
  DAT_00012ed0 = 1;
  return 0;
}


================================================================