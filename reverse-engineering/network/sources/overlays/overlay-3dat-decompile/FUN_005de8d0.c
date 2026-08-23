FUNCTION FUN_005de8d0 @ 0x005de8d0  size=208
CALLERS (1): FUN_005dea10@0x005dea10
CALLEES (1): FUN_005de820@0x005de820
----------------------------------------------------------------

undefined4 FUN_005de8d0(long param_1)

{
  int *piVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  long lVar5;
  int *piVar6;
  int *extraout_a3_lo;
  undefined4 extraout_t0_lo;
  
  if (param_1 == 0) {
    uVar4 = 0;
  }
  else {
    piVar2 = *(int **)(iRam00701068 + 0x4db78);
    piVar6 = (int *)(iRam00701068 + 0x4db70);
    while (piVar1 = piVar2,
          (uint)(piVar1[1] - (piVar6[1] + *piVar6)) < (uint)param_1 + (0x10 - ((uint)param_1 & 0xf))
          ) {
      if (piVar1 == (int *)(iRam00701068 + 0x4f364)) {
        return 0;
      }
      piVar6 = piVar1;
      piVar2 = (int *)piVar1[2];
    }
    lVar5 = FUN_005de820();
    if (lVar5 == 0) {
      uVar4 = 0;
    }
    else {
      puVar3 = (undefined4 *)lVar5;
      *puVar3 = extraout_t0_lo;
      puVar3[1] = extraout_a3_lo[1] + *extraout_a3_lo;
      puVar3[2] = extraout_a3_lo[2];
      extraout_a3_lo[2] = (int)puVar3;
      uVar4 = puVar3[1];
    }
  }
  return uVar4;
}



================================================================