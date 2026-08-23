FUNCTION FUN_00003ad0 @ 0x00003ad0 size=268
CALLERS (0): 
CALLEES (12): FUN_00003d40@0x00003d40, FUN_000000c4@0x000000c4, FUN_00003dd8@0x00003dd8, FUN_00003e2c@0x00003e2c, FUN_00003e70@0x00003e70, FUN_00003dc8@0x00003dc8, FUN_00000148@0x00000148, FUN_00000104@0x00000104, FUN_00003d1c@0x00003d1c, FUN_000035fc@0x000035fc, FUN_00003d14@0x00003d14, FUN_00003a98@0x00003a98

int FUN_00003ad0(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  if (param_1 < 0) {
    FUN_00000104();
    iVar1 = FUN_00003d1c(&DAT_00003be0);
    if (iVar1 == 0) {
      FUN_00003dd8(DAT_000046e0);
      FUN_00003dc8(DAT_000046e0);
      FUN_00003e2c(DAT_000046e8);
      FUN_00003e70(DAT_000046e4);
      for (piVar3 = (int *)DAT_000046ec; piVar3 != (int *)0x0; piVar3 = (int *)*piVar3) {
        FUN_000000c4(piVar3[7]);
      }
      FUN_000000c4(DAT_000045e4);
      iVar2 = 1;
    }
    else {
      FUN_00000148();
      FUN_00003d40("inetctl: can\'t unload (busy)\n");
      iVar2 = 2;
    }
  }
  else {
    iVar1 = FUN_000035fc();
    iVar2 = 1;
    if (iVar1 == 0) {
      iVar1 = FUN_00003d14(&DAT_00003be0);
      if (iVar1 == 0) {
        iVar1 = FUN_00003a98();
        iVar2 = (uint)(iVar1 != 0) << 1;
      }
      else {
        iVar2 = 1;
      }
    }
  }
  return iVar2;
}


================================================================