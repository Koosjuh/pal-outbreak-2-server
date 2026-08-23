FUNCTION FUN_0000956c @ 0x0000956c size=272
CALLERS (1): FUN_00009768@0x00009768
CALLEES (3): FUN_000199a4@0x000199a4, FUN_00019920@0x00019920, FUN_00019928@0x00019928

int FUN_0000956c(int param_1,int param_2,int *param_3)

{
  int iVar1;
  undefined4 local_20 [2];
  
  FUN_00019920(local_20);
  iVar1 = DAT_0001ba08 + param_2 + -0x2000;
  if (0 < iVar1) {
    DAT_0001ba04 = DAT_0001ba04 + iVar1;
    DAT_0001ba08 = DAT_0001ba08 - iVar1;
  }
  iVar1 = 0x2000 - (DAT_0001ba00 & 0x1fff);
  if (param_2 < iVar1) {
    iVar1 = param_2;
  }
  FUN_000199a4((DAT_0001ba00 & 0x1fff) + 0x1ba0c,param_1,iVar1);
  if (iVar1 < param_2) {
    FUN_000199a4((DAT_0001ba00 + iVar1 & 0x1fff) + 0x1ba0c,param_1 + iVar1,param_2 - iVar1);
  }
  DAT_0001ba00 = DAT_0001ba00 + param_2;
  DAT_0001ba08 = DAT_0001ba08 + param_2;
  FUN_00019928(local_20[0]);
  *param_3 = *param_3 + param_2;
  return param_1;
}


================================================================