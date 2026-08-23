FUNCTION FUN_00007388 @ 0x00007388 size=116
CALLERS (1): FUN_0000d458@0x0000d458
CALLEES (1): FUN_00010c38@0x00010c38

undefined4 FUN_00007388(int param_1)

{
  if ((DAT_00012efc & 2) != 0) {
    FUN_00010c38("  CHAP: fsm state ==> Req-Sent\n");
  }
  *(undefined1 *)(param_1 + 0xa0) = 2;
  *(byte *)(param_1 + 0xa2) = *(byte *)(param_1 + 0xa2) | 0x20;
  *(byte *)(param_1 + 2) = *(byte *)(param_1 + 2) | 0x20;
  return 0;
}


================================================================