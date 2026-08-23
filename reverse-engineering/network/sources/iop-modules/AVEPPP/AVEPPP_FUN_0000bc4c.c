FUNCTION FUN_0000bc4c @ 0x0000bc4c size=72
CALLERS (1): FUN_00001ff8@0x00001ff8
CALLEES (2): FUN_0000a624@0x0000a624, FUN_000075dc@0x000075dc

undefined4 FUN_0000bc4c(int param_1)

{
  FUN_000075dc();
  if (**(char **)(param_1 + 0xc) == '\x03') {
    FUN_0000a624(param_1);
  }
  return 0;
}


================================================================