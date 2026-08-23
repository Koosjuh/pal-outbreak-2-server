FUNCTION FUN_00003528 @ 0x00003528 size=212
CALLERS (0): 
CALLEES (4): FUN_000000c4@0x000000c4, FUN_00000148@0x00000148, FUN_00000104@0x00000104, FUN_00003d84@0x00003d84

undefined4 FUN_00003528(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  
  FUN_00000104();
  piVar4 = (int *)DAT_00004700;
  while (piVar1 = piVar4, piVar1 != (int *)0x0) {
    piVar4 = (int *)*piVar1;
    if ((param_1 == 0) || (iVar3 = FUN_00003d84(param_1,piVar1[2]), iVar3 == 0)) {
      uVar2 = piVar1[1];
      if (*piVar1 != 0) {
        *(int *)(*piVar1 + 4) = piVar1[1];
        uVar2 = DAT_00004704;
      }
      DAT_00004704 = uVar2;
      iVar3 = *piVar1;
      if ((int *)piVar1[1] != (int *)0x0) {
        *(int *)piVar1[1] = *piVar1;
        iVar3 = DAT_00004700;
      }
      DAT_00004700 = iVar3;
      FUN_000000c4(piVar1);
    }
  }
  FUN_00000148();
  return 0;
}


================================================================