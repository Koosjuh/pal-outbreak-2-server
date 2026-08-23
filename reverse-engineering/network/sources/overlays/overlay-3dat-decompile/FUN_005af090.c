FUNCTION FUN_005af090 @ 0x005af090  size=136
CALLERS (1): FUN_005acab0@0x005acab0
CALLEES (0): 
----------------------------------------------------------------

void FUN_005af090(int param_1)

{
  if ((*(char *)(param_1 + 0x146b) != '\0') &&
     (*(short *)(param_1 + 0x1468) = *(short *)(param_1 + 0x1468) + -1,
     *(short *)(param_1 + 0x1468) < 0)) {
    *(undefined2 *)(param_1 + 0x1468) =
         *(undefined2 *)(*(int *)(param_1 + 0x146c) * 2 + param_1 + 0x1464);
    if (cRam0034363e == '\x01') {
      *(short *)(param_1 + 0x1468) =
           (short)(int)(DAT_00692670 * (float)(int)*(short *)(param_1 + 0x1468));
    }
    *(undefined1 *)(param_1 + 0x146a) = 1;
  }
  return;
}



================================================================