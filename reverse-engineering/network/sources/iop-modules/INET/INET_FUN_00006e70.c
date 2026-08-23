FUNCTION FUN_00006e70 @ 0x00006e70 size=56
CALLERS (5): FUN_0001866c@0x0001866c, FUN_00008d64@0x00008d64, FUN_00001108@0x00001108, FUN_00007e28@0x00007e28, FUN_000067c4@0x000067c4
CALLEES (0): 

uint FUN_00006e70(int param_1,uint param_2)

{
  if ((param_1 != 0) && ((*(uint *)(param_1 + 0x48) & 0x400) == 0)) {
    return 0xffffffff;
  }
  return (uint)((param_2 & 0xf0000000) == 0xe0000000);
}


================================================================