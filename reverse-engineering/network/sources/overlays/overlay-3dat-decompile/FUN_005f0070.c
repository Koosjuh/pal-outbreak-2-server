FUNCTION FUN_005f0070 @ 0x005f0070  size=60
CALLERS (1): FUN_005eb250@0x005eb250
CALLEES (0): 
----------------------------------------------------------------

void FUN_005f0070(int param_1,int param_2)

{
  *(short *)(param_1 + 0x28) =
       *(short *)(param_1 + 0x32) + *(short *)(param_2 + 0x28) + *(short *)(param_2 + 0x2c);
  *(short *)(param_1 + 0x2a) =
       *(short *)(param_1 + 0x32) + *(short *)(param_2 + 0x2a) + *(short *)(param_2 + 0x2e);
  *(undefined2 *)(param_1 + 0x2c) = 0;
  *(undefined2 *)(param_1 + 0x2e) = 0;
  return;
}



================================================================