FUNCTION FUN_00015e9c @ 0x00015e9c size=104
CALLERS (1): FUN_00016368@0x00016368
CALLEES (0): 

void FUN_00015e9c(int param_1,int param_2)

{
  uint uVar1;
  
  *(undefined4 *)(param_1 + 0xd4) = 0x28;
  *(undefined4 *)(param_1 + 0xd8) = 0x300;
  if ((*(uint *)(param_2 + 0x48) & 0x10) != 0) {
    uVar1 = *(uint *)(param_1 + 0xd8);
    *(int *)(param_1 + 0xd4) = *(int *)(param_1 + 0xd4) + 0xe;
    *(uint *)(param_1 + 0xd8) = uVar1 | 0x400;
    if ((*(uint *)(param_2 + 0x48) & 0x80) == 0) {
      *(uint *)(param_1 + 0xd8) = uVar1 | 0xc00;
      *(int *)(param_1 + 0xd4) = *(int *)(param_1 + 0xd4) + 2;
    }
  }
  return;
}


================================================================