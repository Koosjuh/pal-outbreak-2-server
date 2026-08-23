FUNCTION FUN_00614e60 @ 0x00614e60  size=588
CALLERS (1): FUN_00614c80@0x00614c80
CALLEES (1): FUN_00637f90@0x00637f90
----------------------------------------------------------------

void FUN_00614e60(short *param_1,int param_2,short param_3,short param_4,undefined4 param_5)

{
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  int iVar6;
  short unaff_s0_lo;
  short unaff_s1_lo;
  int iVar7;
  short sStack_20;
  short sStack_1e;
  short sStack_1c;
  short sStack_1a;
  undefined4 uStack_18;
  short sStack_14;
  short sStack_12;
  short sStack_10;
  short sStack_e;
  
  iVar7 = 0;
  do {
    if (param_2 <= iVar7) {
      return;
    }
    sVar1 = param_1[5];
    iVar6 = (short)(param_1[4] << 2) * 2;
    sStack_14 = *(short *)(&DAT_0064b820 + iVar6);
    sStack_12 = *(short *)(&DAT_0064b822 + iVar6);
    sVar2 = *(short *)(&DAT_0064b824 + iVar6);
    sVar3 = *(short *)(&DAT_0064b826 + iVar6);
    if (sVar1 == 3) {
      sVar4 = sStack_12 + sVar3 + -1;
      sVar5 = sStack_14 + sVar2 + -1;
      unaff_s1_lo = sStack_14;
      unaff_s0_lo = sStack_12;
LAB_00615014:
      sStack_14 = sVar5;
      sStack_12 = sVar4;
      sStack_20 = *param_1;
    }
    else {
      sVar5 = sStack_14;
      if (sVar1 == 2) {
        sVar4 = sStack_12 + sVar3 + -1;
        unaff_s1_lo = sStack_14 + sVar2 + -1;
        unaff_s0_lo = sStack_12;
        goto LAB_00615014;
      }
      sVar4 = sStack_12;
      if (sVar1 == 1) {
        sVar5 = sStack_14 + sVar2 + -1;
        unaff_s1_lo = sStack_14;
        unaff_s0_lo = sStack_12 + sVar3 + -1;
        goto LAB_00615014;
      }
      if (sVar1 == 0) {
        unaff_s1_lo = sStack_14 + sVar2 + -1;
        unaff_s0_lo = sStack_12 + sVar3 + -1;
        goto LAB_00615014;
      }
      sStack_20 = *param_1;
    }
    sStack_20 = sStack_20 + param_3;
    sStack_1e = param_1[1] + param_4;
    sStack_1c = param_1[2];
    sStack_1a = param_1[3];
    uStack_18 = param_5;
    sStack_10 = unaff_s1_lo;
    sStack_e = unaff_s0_lo;
    FUN_00637f90(&sStack_20,*(undefined4 *)(iRam0070d1c0 + 0x1aec0));
    param_1 = param_1 + 6;
    iVar7 = iVar7 + 1;
  } while( true );
}



================================================================