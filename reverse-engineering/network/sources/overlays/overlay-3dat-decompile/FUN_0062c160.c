FUNCTION FUN_0062c160 @ 0x0062c160  size=112
CALLERS (1): FUN_0062bda0@0x0062bda0
CALLEES (0): 
----------------------------------------------------------------

void FUN_0062c160(int param_1,int param_2)

{
  func_0x001069a8(param_1 + *(int *)(param_1 + 0x1460) * 0x8a + 0x12ca,param_1 + 0x5ec,0x81);
  *(int *)(param_1 + 0x1460) = *(int *)(param_1 + 0x1460) + 1;
  *(undefined1 *)(param_2 + 1) = 1;
  *(undefined1 *)(param_2 + 2) = 0;
  return;
}



================================================================