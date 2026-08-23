FUNCTION FUN_00007308 @ 0x00007308 size=128
CALLERS (1): FUN_0000d458@0x0000d458
CALLEES (1): FUN_00010c38@0x00010c38

undefined4 FUN_00007308(int param_1)

{
  if ((DAT_00012efc & 2) != 0) {
    FUN_00010c38("  CHAP: fsm state ==> Listen\n");
  }
  *(undefined1 *)(param_1 + 0xa0) = 1;
  *(byte *)(param_1 + 0xa2) = *(byte *)(param_1 + 0xa2) | 0x10;
  *(byte *)(param_1 + 2) = *(byte *)(param_1 + 2) | 0x10;
  *(undefined1 *)(param_1 + 0xa3) = *(undefined1 *)(param_1 + 0xa4);
  return 0;
}


================================================================