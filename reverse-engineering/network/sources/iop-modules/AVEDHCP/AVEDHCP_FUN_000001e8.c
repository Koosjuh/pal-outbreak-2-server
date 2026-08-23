FUNCTION FUN_000001e8 @ 0x000001e8 size=96
CALLERS (0): 
CALLEES (1): FUN_00000c0c@0x00000c0c

int FUN_000001e8(short *param_1)

{
  short sVar1;
  
  sVar1 = FUN_00000c0c((int)*param_1,*(undefined4 *)(param_1 + 2),*(undefined4 *)(param_1 + 4),
                       *(undefined4 *)(param_1 + 6),*(undefined4 *)(param_1 + 8),
                       *(undefined4 *)(param_1 + 10),*(undefined4 *)(param_1 + 0xc),
                       *(undefined4 *)(param_1 + 0xe));
  return (int)sVar1;
}


================================================================