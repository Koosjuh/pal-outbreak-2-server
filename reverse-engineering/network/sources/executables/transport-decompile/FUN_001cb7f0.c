
undefined4 FUN_001cb7f0(undefined8 param_1,int param_2,ulong param_3)

{
  undefined4 uVar1;
  long lVar2;
  ulong uVar3;
  undefined4 *extraout_a2_lo;
  undefined4 *extraout_a2_lo_00;
  undefined8 extraout_a3;
  long unaff_s0;
  
  if ((long)param_3 < 3) {
    if ((param_2 == -1) && (param_2 = DAT_0024c7f8, DAT_0024c7f8 == -1)) {
      return 0;
    }
    lVar2 = FUN_001cb590(param_2);
    unaff_s0 = 0;
    param_1 = extraout_a3;
    if (lVar2 != 0) {
      return *(undefined4 *)lVar2;
    }
  }
  uVar3 = param_3 & 0xffff;
  if (uVar3 == 4) {
    lVar2 = FUN_001cb360(param_1,iRam0036b9b8,param_3,0);
    if ((0 < lVar2) && (unaff_s0 = FUN_001cb590(*(undefined4 *)(iRam0036b9b8 + 8)), unaff_s0 == 0))
    {
      unaff_s0 = FUN_001cb5f0(*extraout_a2_lo_00,iRam0036b9b8);
    }
  }
  else if (uVar3 == 3) {
    unaff_s0 = 0;
    lVar2 = FUN_001cb360(param_1,iRam0036b9b8,param_3,0);
    if ((0 < lVar2) && (unaff_s0 = FUN_001cb590(*(undefined4 *)(iRam0036b9b8 + 8)), unaff_s0 == 0))
    {
      unaff_s0 = FUN_001cb5f0(*extraout_a2_lo,iRam0036b9b8);
    }
  }
  else if (uVar3 == 2) {
    unaff_s0 = FUN_001cb5f0(param_2,param_1);
  }
  else if (uVar3 == 1) {
    if ((param_3 & 0x10000) == 0) {
      lVar2 = FUN_001cb360(param_1,iRam0036b9b8,param_3,0);
      if (lVar2 < 1) goto LAB_001cb9f4;
    }
    else {
      lVar2 = FUN_001cb360(param_1,iRam0036b9b8 + 0x100000,param_3,0);
      if (lVar2 < 1) goto LAB_001cb9f4;
      FUN_001a79b0(iRam0036b9b8 + 0x100000);
    }
    unaff_s0 = FUN_001cb5f0(param_2,iRam0036b9b8);
  }
  else if ((uVar3 == 0) && (lVar2 = FUN_001cb360(param_1,iRam0036b9b8,param_3,0), 0 < lVar2)) {
    unaff_s0 = FUN_001cb5f0(param_2,iRam0036b9b8);
  }
LAB_001cb9f4:
  if (unaff_s0 == 0) {
    uVar1 = 0;
  }
  else if ((long)param_3 < 3) {
    uVar1 = *(undefined4 *)unaff_s0;
  }
  else {
    uVar1 = ((undefined4 *)unaff_s0)[1];
  }
  return uVar1;
}

