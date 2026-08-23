FUNCTION FUN_00001530 @ 0x00001530 size=68
CALLERS (11): FUN_000032fc@0x000032fc, FUN_000127f0@0x000127f0, FUN_000027d8@0x000027d8, FUN_00002428@0x00002428, FUN_0000cdd4@0x0000cdd4, FUN_00001a94@0x00001a94, FUN_00004b68@0x00004b68, FUN_000022f4@0x000022f4, FUN_00004754@0x00004754, FUN_00001da8@0x00001da8, FUN_00001f88@0x00001f88
CALLEES (1): FUN_00011d90@0x00011d90

void FUN_00001530(uint param_1)

{
  FUN_00011d90("%d.%d.%d.%d",param_1 >> 0x18,param_1 >> 0x10 & 0xff,param_1 >> 8 & 0xff,
               param_1 & 0xff);
  return;
}


================================================================