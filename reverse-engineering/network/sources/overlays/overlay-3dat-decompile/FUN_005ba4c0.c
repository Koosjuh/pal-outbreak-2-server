FUNCTION FUN_005ba4c0 @ 0x005ba4c0  size=88
CALLERS (2): FUN_00628860@0x00628860, FUN_00629c20@0x00629c20
CALLEES (3): FUN_005af2e0@0x005af2e0, FUN_005af2c0@0x005af2c0, FUN_005af1e0@0x005af1e0
----------------------------------------------------------------

void FUN_005ba4c0(char *param_1)

{
  while( true ) {
    FUN_005af2c0(param_1[2]);
    FUN_005af2e0(param_1[1]);
    FUN_005af1e0(*(undefined2 *)(param_1 + 4),*(undefined2 *)(param_1 + 6),param_1[3],
                 *(undefined4 *)(param_1 + 8));
    if (*param_1 != '\0') break;
    param_1 = param_1 + 0xc;
  }
  return;
}



================================================================