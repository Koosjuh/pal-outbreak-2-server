FUNCTION FUN_0000027c @ 0x0000027c size=160
CALLERS (0): 
CALLEES (2): FUN_000080bc@0x000080bc, FUN_000080c4@0x000080c4

int FUN_0000027c(int *param_1)

{
  int iVar1;
  undefined4 local_18 [2];
  
  FUN_000080bc(local_18);
  if (DAT_000096f0 != 0) {
    DAT_00009730 = 1;
    DAT_000096f0 = 0;
  }
  if (DAT_000096e0 != 0) {
    DAT_00009730 = 1;
    DAT_000096e0 = 0;
  }
  iVar1 = DAT_000096e4 + DAT_000096f4;
  FUN_000080c4(local_18[0]);
  *param_1 = iVar1;
  return (int)DAT_00009730;
}


================================================================