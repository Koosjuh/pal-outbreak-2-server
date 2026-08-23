FUNCTION FUN_005aefb0 @ 0x005aefb0  size=224
CALLERS (1): FUN_005acab0@0x005acab0
CALLEES (0): 
----------------------------------------------------------------

void FUN_005aefb0(int param_1)

{
  *(int *)(param_1 + 0x984) = *(int *)(param_1 + 0x984) + -1;
  if (*(int *)(param_1 + 0x984) < 0) {
    *(undefined4 *)(param_1 + 0x984) = 0x1e;
    if (cRam0034363e == '\x01') {
      *(undefined4 *)(param_1 + 0x984) = 0x19;
    }
    if ((*(int *)(param_1 + 0x980) != 0) &&
       (*(int *)(param_1 + 0x980) = *(int *)(param_1 + 0x980) + -1, *(int *)(param_1 + 0x980) < 1))
    {
      *(undefined4 *)(param_1 + 0x980) = 0;
      *(undefined4 *)(param_1 + 0x988) = 4;
      if (cRam0034363e == '\x01') {
        *(int *)(param_1 + 0x988) = (int)(DAT_00692670 * (float)*(int *)(param_1 + 0x988));
      }
    }
    *(int *)(param_1 + 0x988) = *(int *)(param_1 + 0x988) + -1;
    if (*(int *)(param_1 + 0x988) < 0) {
      *(undefined4 *)(param_1 + 0x988) = 0x14;
      if (cRam0034363e == '\x01') {
        *(undefined4 *)(param_1 + 0x988) = 0x10;
      }
      *(undefined1 *)(param_1 + 0x97f) = 1;
    }
  }
  return;
}



================================================================