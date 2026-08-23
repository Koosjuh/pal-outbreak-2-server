FUNCTION FUN_00002d80 @ 0x00002d80 size=500
CALLERS (0): 
CALLEES (5): FUN_000037dc@0x000037dc, FUN_00003614@0x00003614, FUN_00003818@0x00003818, FUN_00003790@0x00003790, FUN_00003810@0x00003810

void FUN_00002d80(void)

{
  int *piVar1;
  short sVar2;
  short sVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  short sVar6;
  int iVar7;
  short *psVar8;
  undefined4 uVar9;
  short *psVar10;
  short local_28 [2];
  undefined4 local_24;
  short local_20;
  undefined1 local_1e;
  short local_1c;
  short *local_18;
  
  do {
    iVar7 = FUN_000037dc(DAT_00008bec,1,0x10,0);
    if (iVar7 < 0) {
      FUN_00003790();
    }
    if (*(short *)(DAT_00008be0 + 3) != 0) goto LAB_00002e58;
    if (*(short *)(DAT_00008be4 + 3) != 0) {
      FUN_00003818(DAT_00008be8);
      uVar5 = DAT_00008be8;
      puVar4 = DAT_00008be4;
      uVar9 = *DAT_00008be4;
      DAT_00008be4 = DAT_00008be0;
      DAT_00008be0 = puVar4;
      puVar4[2] = uVar9;
      FUN_00003810(uVar5);
    }
    sVar6 = *(short *)(DAT_00008be0 + 3);
    while (sVar6 != 0) {
LAB_00002e58:
      psVar10 = (short *)DAT_00008be0[2];
      local_28[0] = *psVar10;
      local_24 = *(undefined4 *)(psVar10 + 2);
      local_20 = psVar10[4];
      local_1e = 1;
      local_1c = psVar10[5];
      local_18 = psVar10 + 6;
      sVar6 = FUN_00003614(&DAT_00004121,local_28,0);
      if (sVar6 != 0) {
        FUN_00003818(DAT_00008be8);
        iVar7 = 0;
        psVar8 = &DAT_00008bf0;
        do {
          if (*psVar8 == -1) {
            *psVar8 = *psVar10;
            (&DAT_00008bf2)[iVar7 * 2] = sVar6;
            break;
          }
          iVar7 = iVar7 + 1;
          psVar8 = psVar8 + 2;
        } while (iVar7 < 8);
        FUN_00003810(DAT_00008be8);
      }
      puVar4 = DAT_00008be0;
      sVar2 = psVar10[5];
      sVar3 = psVar10[1];
      piVar1 = DAT_00008be0 + 2;
      sVar6 = *(short *)(DAT_00008be0 + 3) + -1;
      *(short *)(DAT_00008be0 + 3) = sVar6;
      puVar4[2] = *piVar1 + (int)sVar3 + (int)sVar2 + 0xc;
    }
    DAT_00008be0[2] = *DAT_00008be0;
  } while( true );
}


================================================================