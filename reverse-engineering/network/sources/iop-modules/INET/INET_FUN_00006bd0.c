FUNCTION FUN_00006bd0 @ 0x00006bd0 size=92
CALLERS (1): FUN_00008bb8@0x00008bb8
CALLEES (1): FUN_00006630@0x00006630

void FUN_00006bd0(int param_1,int param_2)

{
  if (((*(int *)(param_2 + 0x14) == 1) && (*(int *)(param_2 + 8) != -0x1fffffff)) &&
     (*(int *)(*(int *)(param_1 + 0x1a0) + 0x14) != 1)) {
    FUN_00006630(param_1,0x17);
  }
  return;
}


================================================================