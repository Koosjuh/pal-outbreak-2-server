FUNCTION FUN_005c75b0 @ 0x005c75b0  size=32
CALLERS (1): FUN_005c7540@0x005c7540
CALLEES (0): 
----------------------------------------------------------------

void FUN_005c75b0(int param_1)

{
  *(char *)(param_1 + 0x21) = *(char *)(param_1 + 0x21) + '\x01';
  *(undefined4 *)(param_1 + 8) = 1;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined1 *)(param_1 + 0x25) = 0;
  return;
}



================================================================