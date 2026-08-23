FUNCTION FUN_00006468 @ 0x00006468 size=64
CALLERS (0): 
CALLEES (2): FUN_0001073c@0x0001073c, FUN_00010764@0x00010764

void FUN_00006468(int param_1)

{
  FUN_0001073c();
  DAT_00012ecc = 8;
  if (param_1 != 0) {
    DAT_00012ecc = 2;
  }
  FUN_00010764();
  return;
}


================================================================