FUNCTION FUN_000006d8 @ 0x000006d8 size=120
CALLERS (2): FUN_00001628@0x00001628, FUN_000011c4@0x000011c4
CALLEES (4): FUN_000029ec@0x000029ec, FUN_00002a84@0x00002a84, FUN_00002a04@0x00002a04, FUN_00002a7c@0x00002a7c

void FUN_000006d8(int param_1)

{
  int iVar1;
  undefined4 local_18 [2];
  
  FUN_00002a7c(local_18);
  iVar1 = *(int *)(param_1 + 0x1c);
  *(undefined4 *)(param_1 + 0x1c) = 0;
  FUN_00002a84(local_18[0]);
  if (iVar1 == 0) goto LAB_00000728;
  do {
    FUN_00002a04(param_1 + 0x13c,iVar1);
    *(int *)(param_1 + 0xe4) = *(int *)(param_1 + 0xe4) + 1;
LAB_00000728:
    iVar1 = FUN_000029ec(param_1 + 0x194);
  } while (iVar1 != 0);
  return;
}


================================================================