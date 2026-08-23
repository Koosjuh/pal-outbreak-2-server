FUNCTION FUN_00012bc0 @ 0x00012bc0 size=64
CALLERS (4): FUN_00016d00@0x00016d00, FUN_000130cc@0x000130cc, FUN_00014c8c@0x00014c8c, FUN_00014ad4@0x00014ad4
CALLEES (1): FUN_00017bf4@0x00017bf4

void FUN_00012bc0(int param_1)

{
  undefined4 uVar1;
  
  *(undefined4 *)(param_1 + 0xb0) = 0;
  *(undefined4 *)(param_1 + 0xb4) = 0;
  *(undefined4 *)(param_1 + 0xb8) = 0;
  *(undefined4 *)(param_1 + 0xbc) = 0;
  *(undefined4 *)(param_1 + 0xc0) = 0;
  uVar1 = FUN_00017bf4(*(undefined4 *)(param_1 + 200));
  *(undefined4 *)(param_1 + 200) = uVar1;
  return;
}


================================================================