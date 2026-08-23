FUNCTION FUN_00000e60 @ 0x00000e60 size=100
CALLERS (1): FUN_000003c0@0x000003c0
CALLEES (1): FUN_000028f0@0x000028f0

void FUN_00000e60(int param_1,int param_2,int param_3,undefined4 param_4)

{
  FUN_000028f0(param_1,0,0x870);
  *(int *)(param_1 + 0xc) = param_2;
  *(int *)(param_1 + 8) = param_2;
  *(int *)(param_1 + 0x10) = param_2 + param_3;
  *(undefined4 *)(param_1 + 0x24) = param_4;
  return;
}


================================================================