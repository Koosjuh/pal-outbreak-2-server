FUNCTION FUN_005f0300 @ 0x005f0300  size=60
CALLERS (1): FUN_005eb7d0@0x005eb7d0
CALLEES (0): 
----------------------------------------------------------------

void FUN_005f0300(int param_1,int param_2)

{
  *(short *)(param_1 + 0x28) =
       *(short *)(param_1 + 0x30) + *(short *)(param_2 + 0x28) + *(short *)(param_2 + 0x2c);
  *(short *)(param_1 + 0x2a) =
       *(short *)(param_1 + 0x30) + *(short *)(param_2 + 0x2a) + *(short *)(param_2 + 0x2e);
  *(undefined2 *)(param_1 + 0x2c) = 0;
  *(undefined2 *)(param_1 + 0x2e) = 0;
  return;
}



================================================================