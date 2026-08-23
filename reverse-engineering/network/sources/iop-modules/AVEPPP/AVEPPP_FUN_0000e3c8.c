FUNCTION FUN_0000e3c8 @ 0x0000e3c8 size=144
CALLERS (1): FUN_0000d400@0x0000d400
CALLEES (2): FUN_00010070@0x00010070, FUN_00010c38@0x00010c38

void FUN_0000e3c8(undefined1 *param_1)

{
  if (*(int *)(param_1 + 0x30) != 0) {
    param_1[2] = 0;
    switch(*param_1) {
    case 2:
      FUN_00010070(param_1 + 0x10);
    case 1:
    case 5:
    case 6:
      if ((DAT_00012efc & 2) != 0) {
        FUN_00010c38("  PAP: fsm state ==> Closed\n");
      }
      *param_1 = 0;
    }
  }
  return;
}


================================================================