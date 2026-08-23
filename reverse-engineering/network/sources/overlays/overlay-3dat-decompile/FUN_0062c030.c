FUNCTION FUN_0062c030 @ 0x0062c030  size=292
CALLERS (1): FUN_0062bda0@0x0062bda0
CALLEES (0): 
----------------------------------------------------------------

void FUN_0062c030(int param_1,int param_2)

{
  *(undefined2 *)(*(int *)(param_1 + 0x1460) * 0x8a + param_1 + 0x12c2) =
       *(undefined2 *)(param_1 + 0x10b8);
  *(undefined2 *)(*(int *)(param_1 + 0x1460) * 0x8a + param_1 + 0x12c4) =
       *(undefined2 *)(param_1 + 0x10ba);
  *(undefined2 *)(*(int *)(param_1 + 0x1460) * 0x8a + param_1 + 0x12c6) =
       *(undefined2 *)(param_1 + 0x10bc);
  *(undefined1 *)(*(int *)(param_1 + 0x1460) * 0x8a + param_1 + 0x12c8) =
       *(undefined1 *)(param_1 + 0x10be);
  *(undefined1 *)(*(int *)(param_1 + 0x1460) * 0x8a + param_1 + 0x12c9) =
       *(undefined1 *)(param_1 + 0x10bf);
  func_0x001069a8(param_1 + *(int *)(param_1 + 0x1460) * 0x8a + 0x12ca,param_1 + 0x10c0,0x81);
  *(int *)(param_1 + 0x1460) = *(int *)(param_1 + 0x1460) + 1;
  *(undefined1 *)(param_2 + 1) = 1;
  *(undefined1 *)(param_2 + 2) = 0;
  return;
}



================================================================