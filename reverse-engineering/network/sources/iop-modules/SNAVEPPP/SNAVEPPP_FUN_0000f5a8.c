FUNCTION FUN_0000f5a8 @ 0x0000f5a8 size=36
CALLERS (2): FUN_0000f42c@0x0000f42c, FUN_0000efbc@0x0000efbc
CALLEES (0): 

undefined4 FUN_0000f5a8(int param_1)

{
  if (param_1 != 0) {
    *(byte *)(param_1 + 0xd) = *(byte *)(param_1 + 0xd) | 1;
    return 0;
  }
  return 0;
}


================================================================