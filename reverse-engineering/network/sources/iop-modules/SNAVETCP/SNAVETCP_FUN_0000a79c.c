FUNCTION FUN_0000a79c @ 0x0000a79c size=48
CALLERS (5): FUN_00008c70@0x00008c70, FUN_0000b3d4@0x0000b3d4, FUN_00007000@0x00007000, FUN_00008bf0@0x00008bf0, FUN_0000daec@0x0000daec
CALLEES (0): 

int FUN_0000a79c(int param_1)

{
  if ((*(uint *)(param_1 + 0xd8) & 1) == 0) {
    return *(int *)(param_1 + 8) + *(int *)(param_1 + 0x18);
  }
  return *(int *)(param_1 + 0x18);
}


================================================================