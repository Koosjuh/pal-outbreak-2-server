FUNCTION FUN_00000774 @ 0x00000774 size=132
CALLERS (1): FUN_000007f8@0x000007f8
CALLEES (1): FUN_00003d6c@0x00003d6c

void FUN_00000774(int param_1,int param_2)

{
  FUN_00003d6c(param_2,param_1,0x10);
  FUN_00003d6c(param_2 + 0x14,param_1 + 0x10,0x10);
  FUN_00003d6c(param_2 + 0x28,param_1 + 0x20,0x10);
  *(undefined4 *)(param_1 + 0x30) = *(undefined4 *)(param_2 + 0x3c);
  *(undefined4 *)(param_1 + 0x34) = *(undefined4 *)(param_2 + 0x40);
  *(undefined4 *)(param_1 + 0x38) = *(undefined4 *)(param_2 + 0x44);
  FUN_00003d6c(param_2 + 0x48,param_1 + 0x3c,9);
  return;
}


================================================================