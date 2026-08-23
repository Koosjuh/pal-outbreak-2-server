FUNCTION FUN_00016de8 @ 0x00016de8 size=68
CALLERS (0): 
CALLEES (1): FUN_00016d00@0x00016d00

void FUN_00016de8(int param_1)

{
  if (param_1 != 0) {
    *(undefined4 *)(param_1 + 0x34) = 0xfffffe0b;
    *(uint *)(param_1 + 0x2c) = *(uint *)(param_1 + 0x2c) | 0x4000000;
  }
  FUN_00016d00(param_1,0xfffffe0b);
  return;
}


================================================================