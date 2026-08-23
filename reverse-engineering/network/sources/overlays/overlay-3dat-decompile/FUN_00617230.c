FUNCTION FUN_00617230 @ 0x00617230  size=56
CALLERS (1): FUN_00616c40@0x00616c40
CALLEES (0): 
----------------------------------------------------------------

void FUN_00617230(int param_1)

{
  *(short *)(param_1 + 0x16) = *(short *)(param_1 + 0x16) + -1;
  if (*(short *)(param_1 + 0x16) < 0) {
    *(char *)(param_1 + 0xe) = *(char *)(param_1 + 0xe) + '\x01';
    *(undefined1 *)(param_1 + 0xf) = 0;
    *(undefined2 *)(param_1 + 0x16) = 0x96;
  }
  return;
}



================================================================