FUNCTION FUN_000092f8 @ 0x000092f8 size=68
CALLERS (0): 
CALLEES (1): FUN_00009e28@0x00009e28

void FUN_000092f8(uint param_1)

{
  FUN_00009e28("%d.%d.%d.%d",param_1 >> 0x18,param_1 >> 0x10 & 0xff,param_1 >> 8 & 0xff,
               param_1 & 0xff);
  return;
}


================================================================