FUNCTION FUN_0000e660 @ 0x0000e660 size=116
CALLERS (1): FUN_0000d458@0x0000d458
CALLEES (1): FUN_00010c38@0x00010c38

undefined4 FUN_0000e660(int param_1)

{
  if ((DAT_00012efc & 2) != 0) {
    FUN_00010c38("  PAP: fsm state ==> Req-Sent\n");
  }
  *(undefined1 *)(param_1 + 0x38) = 2;
  *(byte *)(param_1 + 0x3a) = *(byte *)(param_1 + 0x3a) | 0x20;
  *(byte *)(param_1 + 2) = *(byte *)(param_1 + 2) | 0x20;
  return 0;
}


================================================================