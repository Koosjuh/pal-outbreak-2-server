FUNCTION FUN_000026bc @ 0x000026bc size=180
CALLERS (1): FUN_00002770@0x00002770
CALLEES (8): FUN_00002970@0x00002970, FUN_00002884@0x00002884, FUN_000028f4@0x000028f4, FUN_0000287c@0x0000287c, FUN_00002980@0x00002980, FUN_000029b4@0x000029b4, FUN_000028b0@0x000028b0, FUN_000028ec@0x000028ec

undefined4 FUN_000026bc(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_10 [2];
  
  FUN_0000287c(local_10);
  iVar1 = FUN_000028b0(&DAT_000027b0);
  FUN_00002884(local_10[0]);
  if ((iVar1 == 0) || (uVar2 = 2, iVar1 == -0xd5)) {
    iVar1 = FUN_000028ec(&DAT_00003088,&DAT_00003070);
    uVar2 = 2;
    if (iVar1 != 0) {
      iVar1 = FUN_000028f4(&DAT_00003070);
      uVar2 = 2;
      if (iVar1 != 0) {
        FUN_00002980(DAT_00004a20);
        FUN_00002970(DAT_00004a20);
        FUN_000029b4(DAT_00004db0);
        uVar2 = 1;
      }
    }
  }
  return uVar2;
}


================================================================