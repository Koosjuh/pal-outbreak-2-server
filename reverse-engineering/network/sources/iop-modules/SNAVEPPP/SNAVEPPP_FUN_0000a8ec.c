FUNCTION FUN_0000a8ec @ 0x0000a8ec size=124
CALLERS (2): FUN_0000d71c@0x0000d71c, FUN_0000be40@0x0000be40
CALLEES (2): FUN_00010094@0x00010094, FUN_000096d8@0x000096d8

void FUN_0000a8ec(int param_1)

{
  *(undefined1 *)(param_1 + 4) = *(undefined1 *)(*(int *)(param_1 + 0x2c) + 9);
  *(undefined1 *)(param_1 + 7) = *(undefined1 *)(*(int *)(param_1 + 0x2c) + 10);
  *(undefined1 *)(param_1 + 5) = *(undefined1 *)(*(int *)(param_1 + 0x2c) + 0xb);
  FUN_000096d8();
  *(code **)(param_1 + 0x20) = FUN_0000a40c;
  *(int *)(param_1 + 0x24) = param_1;
  FUN_00010094(param_1 + 0x10,*(undefined4 *)(*(int *)(param_1 + 0x2c) + 0xc));
  return;
}


================================================================