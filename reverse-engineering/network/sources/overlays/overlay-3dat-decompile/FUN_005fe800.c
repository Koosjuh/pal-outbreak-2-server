FUNCTION FUN_005fe800 @ 0x005fe800  size=200
CALLERS (1): FUN_005fe730@0x005fe730
CALLEES (1): FUN_00618b60@0x00618b60
----------------------------------------------------------------

void FUN_005fe800(int param_1)

{
  if ((*(char *)(param_1 + 0x97d) == '\0') && (*(char *)(param_1 + 0x97e) == '\0')) {
    *(char *)(param_1 + 0xf) = *(char *)(param_1 + 0xf) + '\x01';
    *(undefined1 *)(param_1 + 0x10) = 0;
  }
  else {
    *(undefined1 *)(param_1 + 0xf) = 4;
    *(undefined1 *)(param_1 + 0x10) = 0;
  }
  *(undefined1 *)(param_1 + 0x56b) = 0;
  FUN_00618b60();
  uRam006c5497 = cRam006c550e != '\0';
  uRam006c5498 = 0;
  uRam006c5499 = uRam006c5497;
  *(undefined4 *)(param_1 + 0x984) = 0x1e;
  if (cRam0034363e == '\x01') {
    *(undefined4 *)(param_1 + 0x984) = 0x19;
  }
  *(undefined4 *)(param_1 + 0x988) = 0x14;
  *(undefined1 *)(param_1 + 0x97f) = 0;
  return;
}



================================================================