FUNCTION FUN_0062fc20 @ 0x0062fc20  size=32
CALLERS (2): FUN_0062f990@0x0062f990, FUN_0062fa80@0x0062fa80
CALLEES (0): 
----------------------------------------------------------------

void FUN_0062fc20(int param_1)

{
  *(undefined2 *)(param_1 + 0x3a) = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0xffffffff;
  *(ushort *)(param_1 + 0x24) = *(ushort *)(param_1 + 0x24) | 0x80;
  *(undefined1 *)(param_1 + 9) = 0;
  return;
}



================================================================