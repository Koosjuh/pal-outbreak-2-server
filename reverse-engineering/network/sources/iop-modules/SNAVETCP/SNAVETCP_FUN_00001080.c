FUNCTION FUN_00001080 @ 0x00001080 size=40
CALLERS (9): FUN_0000b3d4@0x0000b3d4, FUN_00007000@0x00007000, FUN_0000f4fc@0x0000f4fc, FUN_0000f580@0x0000f580, FUN_00005f10@0x00005f10, FUN_00002020@0x00002020, FUN_0000af84@0x0000af84, FUN_0000f8f0@0x0000f8f0, FUN_0000c088@0x0000c088
CALLEES (0): 

uint FUN_00001080(uint param_1)

{
  return param_1 << 0x18 | (param_1 & 0xff00) << 8 | param_1 >> 8 & 0xff00 | param_1 >> 0x18;
}


================================================================