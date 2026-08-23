FUNCTION FUN_0000029c @ 0x0000029c size=152
CALLERS (1): FUN_00000334@0x00000334
CALLEES (4): FUN_00009540@0x00009540, FUN_000095c4@0x000095c4, FUN_00009548@0x00009548, FUN_00009720@0x00009720

undefined4 FUN_0000029c(void)

{
  int iVar1;
  undefined4 uVar2;
  char *pcVar3;
  int iVar4;
  
  iVar4 = 0;
  iVar1 = FUN_00009548(0xc90);
  pcVar3 = "netcnf: ReleaseLibraryEntries (%d)\n";
  if (iVar1 == 0) {
    iVar4 = 1;
    iVar1 = FUN_000095c4(DAT_0000afe0);
    if (iVar1 == 0) {
      iVar4 = 2;
      goto LAB_00000300;
    }
    pcVar3 = "netcnf: DeleteSema (%d)\n";
  }
  FUN_00009720(pcVar3,iVar1);
LAB_00000300:
  uVar2 = 1;
  if ((iVar4 != 2) && (uVar2 = 2, iVar4 == 1)) {
    FUN_00009540(0xc90);
    uVar2 = 2;
  }
  return uVar2;
}


================================================================