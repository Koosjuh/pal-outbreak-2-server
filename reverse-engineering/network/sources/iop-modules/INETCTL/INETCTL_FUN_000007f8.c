FUNCTION FUN_000007f8 @ 0x000007f8 size=292
CALLERS (1): FUN_00001688@0x00001688
CALLEES (6): FUN_00003d6c@0x00003d6c, FUN_00003cac@0x00003cac, FUN_00003c94@0x00003c94, FUN_00000774@0x00000774, FUN_00003c8c@0x00003c8c, FUN_00003ca4@0x00003ca4

undefined4 FUN_000007f8(undefined4 param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  undefined1 auStack_68 [60];
  undefined1 auStack_2c [12];
  
  if (param_2 != 0) {
    for (piVar2 = *(int **)(param_2 + 0x150); piVar2 != (int *)0x0; piVar2 = (int *)*piVar2) {
      iVar1 = piVar2[2];
      if (iVar1 == 2) {
        iVar1 = FUN_00003cac(piVar2 + 3);
joined_r0x000008dc:
        if (iVar1 != 0) {
          return 0xffffffff;
        }
      }
      else {
        if (2 < iVar1) {
          if (iVar1 == 3) {
            FUN_00000774(auStack_68,piVar2 + 3);
            FUN_00003d6c(param_1,auStack_2c,9);
            iVar1 = FUN_00003c8c(auStack_68);
          }
          else {
            if (iVar1 != 4) goto LAB_000008e4;
            FUN_00000774(auStack_68,piVar2 + 3);
            iVar1 = FUN_00003c94(auStack_68);
          }
          goto joined_r0x000008dc;
        }
        if (iVar1 == 1) {
          iVar1 = FUN_00003ca4(piVar2 + 3);
          goto joined_r0x000008dc;
        }
      }
LAB_000008e4:
    }
  }
  return 0;
}


================================================================