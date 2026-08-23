FUNCTION FUN_000015e4 @ 0x000015e4 size=68
CALLERS (0): 
CALLEES (1): FUN_00002b8c@0x00002b8c

undefined4 FUN_000015e4(int param_1)

{
  *(undefined4 *)(param_1 + 0x30) = 1;
  FUN_00002b8c(*(undefined4 *)(param_1 + 0x20),2);
  return 0;
}


================================================================