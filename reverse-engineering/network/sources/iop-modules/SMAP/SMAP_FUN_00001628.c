FUNCTION FUN_00001628 @ 0x00001628 size=92
CALLERS (0): 
CALLEES (2): FUN_000006d8@0x000006d8, FUN_00002b8c@0x00002b8c

undefined4 FUN_00001628(int param_1)

{
  if (*(int *)(param_1 + 0x38) == 0) {
    FUN_000006d8();
  }
  else {
    FUN_00002b8c(*(undefined4 *)(param_1 + 0x20),8);
  }
  return 0;
}


================================================================