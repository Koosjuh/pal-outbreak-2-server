FUNCTION FUN_005ba520 @ 0x005ba520  size=80
CALLERS (1): FUN_00628860@0x00628860
CALLEES (3): FUN_005af2e0@0x005af2e0, FUN_005af2c0@0x005af2c0, FUN_005af1e0@0x005af1e0
----------------------------------------------------------------

void FUN_005ba520(int param_1,undefined8 param_2)

{
  FUN_005af2c0(*(undefined1 *)(param_1 + 2));
  FUN_005af2e0(*(undefined1 *)(param_1 + 1));
  FUN_005af1e0(*(undefined2 *)(param_1 + 4),*(undefined2 *)(param_1 + 6),
               *(undefined1 *)(param_1 + 3),param_2);
  return;
}



================================================================