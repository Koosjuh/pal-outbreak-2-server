FUNCTION FUN_0000ebe0 @ 0x0000ebe0 size=96
CALLERS (1): FUN_0000ec64@0x0000ec64
CALLEES (2): FUN_00011c80@0x00011c80, FUN_00011ba4@0x00011ba4

void FUN_0000ebe0(int param_1)

{
  int iVar1;
  
  while (iVar1 = FUN_00011c80(param_1 + 0x58), iVar1 != 0) {
    FUN_00011ba4(param_1,iVar1);
  }
  while (iVar1 = FUN_00011c80(param_1 + 0x50), iVar1 != 0) {
    FUN_00011ba4(param_1,iVar1);
  }
  return;
}


================================================================