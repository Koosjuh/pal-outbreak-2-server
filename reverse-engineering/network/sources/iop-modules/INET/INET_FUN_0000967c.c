FUNCTION FUN_0000967c @ 0x0000967c size=236
CALLERS (1): FUN_00011370@0x00011370
CALLEES (3): FUN_000199a4@0x000199a4, FUN_00019920@0x00019920, FUN_00019928@0x00019928

int FUN_0000967c(int param_1,int param_2)

{
  int iVar1;
  undefined4 local_20 [2];
  
  FUN_00019920(local_20);
  if (DAT_0001ba08 < param_2) {
    param_2 = DAT_0001ba08;
  }
  iVar1 = 0x2000 - (DAT_0001ba04 & 0x1fff);
  if (param_2 < iVar1) {
    iVar1 = param_2;
  }
  if (0 < iVar1) {
    FUN_000199a4(param_1,(DAT_0001ba04 & 0x1fff) + 0x1ba0c,iVar1);
  }
  if (iVar1 < param_2) {
    FUN_000199a4(param_1 + iVar1,(DAT_0001ba04 + iVar1 & 0x1fff) + 0x1ba0c,param_2 - iVar1);
  }
  DAT_0001ba04 = DAT_0001ba04 + param_2;
  DAT_0001ba08 = DAT_0001ba08 - param_2;
  FUN_00019928(local_20[0]);
  return param_2;
}


================================================================