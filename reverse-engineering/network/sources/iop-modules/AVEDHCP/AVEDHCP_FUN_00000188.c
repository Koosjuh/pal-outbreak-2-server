FUNCTION FUN_00000188 @ 0x00000188 size=96
CALLERS (0): 
CALLEES (1): FUN_00000cac@0x00000cac

int FUN_00000188(short *param_1)

{
  short sVar1;
  
  sVar1 = FUN_00000cac((int)*param_1,*(undefined4 *)(param_1 + 2),*(undefined4 *)(param_1 + 4),
                       *(undefined4 *)(param_1 + 6),*(undefined4 *)(param_1 + 8),
                       *(undefined4 *)(param_1 + 10),*(undefined4 *)(param_1 + 0xc),
                       *(undefined4 *)(param_1 + 0xe));
  return (int)sVar1;
}


================================================================