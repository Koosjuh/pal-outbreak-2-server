FUNCTION FUN_00001210 @ 0x00001210 size=48
CALLERS (0): 
CALLEES (1): FUN_00002b94@0x00002b94

undefined4 FUN_00001210(int param_1)

{
  FUN_00002b94(*(undefined4 *)(param_1 + 0x20),0x10);
  return *(undefined4 *)(param_1 + 0x40);
}


================================================================