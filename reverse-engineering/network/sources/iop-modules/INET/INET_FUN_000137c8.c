FUNCTION FUN_000137c8 @ 0x000137c8 size=68
CALLERS (2): FUN_00015430@0x00015430, FUN_00013fd4@0x00013fd4
CALLEES (1): FUN_00013264@0x00013264

void FUN_000137c8(int param_1,int param_2)

{
  if ((param_2 == 0) || ((*(byte *)(param_2 + 0xd) & 4) == 0)) {
    FUN_00013264(param_1,0x10,*(undefined4 *)(param_1 + 0x3c),*(undefined4 *)(param_1 + 0x70),0);
  }
  return;
}


================================================================