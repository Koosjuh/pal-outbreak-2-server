FUNCTION FUN_00006590 @ 0x00006590 size=332
CALLERS (0): 
CALLEES (6): FUN_00010aac@0x00010aac, FUN_00010b3c@0x00010b3c, FUN_0001078c@0x0001078c, FUN_000107bc@0x000107bc, FUN_00010aa4@0x00010aa4, FUN_000006b0@0x000006b0

undefined4 * FUN_00006590(int param_1)

{
  undefined1 uVar1;
  ushort uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  uint uVar5;
  undefined1 *puVar6;
  int iVar7;
  uint uVar8;
  int *piVar9;
  
  piVar9 = *(int **)(param_1 + 0x30);
  puVar4 = (undefined4 *)0x0;
  if ((*piVar9 != 0) && (puVar4 = (undefined4 *)0x0, piVar9[1] != 0)) {
    puVar3 = (undefined4 *)FUN_000006b0(0);
    puVar4 = (undefined4 *)0x0;
    if (puVar3 != (undefined4 *)0x0) {
      puVar6 = (undefined1 *)*puVar3;
      iVar7 = 0;
      FUN_0001078c();
      uVar2 = FUN_000107bc();
      DAT_000135d4 = (uVar2 & 0x1f) + 0x10;
      *puVar6 = (undefined1)DAT_000135d4;
      puVar6 = puVar6 + 1;
      if (DAT_000135d4 != 0) {
        do {
          iVar7 = iVar7 + 1;
          uVar1 = FUN_000107bc();
          *puVar6 = uVar1;
          puVar6 = puVar6 + 1;
        } while (iVar7 < (int)(uint)DAT_000135d4);
      }
      iVar7 = FUN_00010aac(*piVar9);
      if (0 < iVar7) {
        FUN_00010aa4(puVar6,*piVar9);
        puVar6[iVar7] = 0;
        (puVar6 + iVar7)[1] = 0;
      }
      uVar5 = (uint)*(ushort *)(puVar3 + 1) + (uint)DAT_000135d4 + iVar7 + 2;
      uVar8 = uVar5 & 0xffff;
      *(short *)(puVar3 + 1) = (short)uVar5;
      if (0x80 < uVar8) {
        uVar8 = 0x80;
      }
      FUN_00010b3c(&DAT_0001aaf0,*puVar3,uVar8);
      puVar4 = puVar3;
    }
  }
  return puVar4;
}


================================================================