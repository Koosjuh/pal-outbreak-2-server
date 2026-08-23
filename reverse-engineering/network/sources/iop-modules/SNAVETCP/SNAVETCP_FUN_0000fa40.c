FUNCTION FUN_0000fa40 @ 0x0000fa40 size=76
CALLERS (1): FUN_000003c4@0x000003c4
CALLEES (1): FUN_000047dc@0x000047dc

int FUN_0000fa40(short *param_1)

{
  short sVar1;
  int iVar2;
  
  iVar2 = -0x10;
  if (*param_1 == 0) {
    sVar1 = FUN_000047dc(0);
    iVar2 = (int)sVar1;
    DAT_00017e10 = 0;
    DAT_00017e14 = 0;
    DAT_00017e18 = 0;
  }
  return iVar2;
}


================================================================