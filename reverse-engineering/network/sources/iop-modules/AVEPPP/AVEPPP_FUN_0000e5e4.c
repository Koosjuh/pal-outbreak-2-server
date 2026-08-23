FUNCTION FUN_0000e5e4 @ 0x0000e5e4 size=124
CALLERS (1): FUN_0000d458@0x0000d458
CALLEES (1): FUN_00010c38@0x00010c38

void FUN_0000e5e4(int param_1)

{
  if ((DAT_00012efc & 2) != 0) {
    FUN_00010c38("  PAP: fsm state ==> Listen\n");
  }
  *(undefined1 *)(param_1 + 0x38) = 1;
  *(byte *)(param_1 + 0x3a) = *(byte *)(param_1 + 0x3a) | 0x10;
  *(byte *)(param_1 + 2) = *(byte *)(param_1 + 2) | 0x10;
  *(undefined1 *)(param_1 + 0x3b) = *(undefined1 *)(param_1 + 0x3c);
  return;
}


================================================================