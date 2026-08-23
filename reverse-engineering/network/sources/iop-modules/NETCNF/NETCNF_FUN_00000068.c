FUNCTION FUN_00000068 @ 0x00000068 size=564
CALLERS (1): FUN_00000334@0x00000334
CALLEES (8): FUN_00009658@0x00009658, FUN_000095bc@0x000095bc, FUN_00000010@0x00000010, FUN_00009640@0x00009640, FUN_00009540@0x00009540, FUN_000095c4@0x000095c4, FUN_00009638@0x00009638, FUN_00009720@0x00009720

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00000068(int param_1,int *param_2)

{
  int iVar1;
  char *pcVar2;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  local_20 = 1;
  local_18 = 1;
  local_14 = 1;
  local_1c = 0;
  iVar1 = FUN_000095bc(&local_20);
  DAT_0000afe0 = iVar1;
  if (iVar1 < 1) {
    pcVar2 = "netcnf: CreateSema (%d)\n";
  }
  else {
    DAT_0000afe8 = '\0';
    DAT_0000b0e8 = '\0';
    if (param_1 < 3) {
      FUN_00000010();
      FUN_000095c4(DAT_0000afe0);
      return 1;
    }
    while (param_1 = param_1 + -1, 0 < param_1) {
      param_2 = param_2 + 1;
      iVar1 = FUN_00009658("icon=",*param_2,5);
      if (iVar1 == 0) {
        FUN_00009640(&DAT_0000afe8,*param_2 + 5);
      }
      else {
        iVar1 = FUN_00009658("iconsys=",*param_2,8);
        if (iVar1 == 0) {
          FUN_00009640(&DAT_0000b0e8,*param_2 + 8);
        }
        else {
          iVar1 = FUN_00009638("-no_check_capacity",*param_2);
          if (iVar1 == 0) {
            ram0x0000ab48 = 1;
          }
          else {
            iVar1 = FUN_00009638("-no_check_provider",*param_2);
            if (iVar1 != 0) {
              FUN_00000010();
              FUN_000095c4(DAT_0000afe0);
              return 1;
            }
            DAT_0000ab4c = 1;
          }
        }
      }
    }
    if ((DAT_0000afe8 == '\0') || (DAT_0000b0e8 == '\0')) {
      FUN_00000010();
      FUN_000095c4(DAT_0000afe0);
      return 1;
    }
    iVar1 = FUN_00009540(0xc90);
    if (iVar1 == 0) {
      return 2;
    }
    FUN_000095c4(DAT_0000afe0);
    pcVar2 = "netcnf: RegisterLibraryEntries (%d)\n";
  }
  FUN_00009720(pcVar2,iVar1);
  return 1;
}


================================================================