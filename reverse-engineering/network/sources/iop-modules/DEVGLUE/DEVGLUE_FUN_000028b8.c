FUNCTION FUN_000028b8 @ 0x000028b8 size=64
CALLERS (2): FUN_00000e40@0x00000e40, FUN_00000dec@0x00000dec
CALLEES (0): 

undefined4 FUN_000028b8(int param_1)

{
  undefined4 uVar1;
  
  if ((&DAT_00009718)[param_1] == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = 2;
    if (*(int *)((&DAT_00009718)[param_1] + 0x5c) == 0) {
      return 1;
    }
  }
  return uVar1;
}


================================================================