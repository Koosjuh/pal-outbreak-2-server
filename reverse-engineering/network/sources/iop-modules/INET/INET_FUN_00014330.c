FUNCTION FUN_00014330 @ 0x00014330 size=80
CALLERS (0): 
CALLEES (1): FUN_00013b50@0x00013b50

void FUN_00014330(int param_1)

{
  *(uint *)(param_1 + 0x2c) = *(uint *)(param_1 + 0x2c) | 0x9000;
  *(undefined4 *)(param_1 + 200) = 0;
  if ((*(int *)(param_1 + 0x6c) == 0) || (0 < *(int *)(param_1 + 0x40))) {
    FUN_00013b50(param_1);
  }
  return;
}


================================================================