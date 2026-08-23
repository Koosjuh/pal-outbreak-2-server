FUNCTION FUN_005c29c0 @ 0x005c29c0  size=128
CALLERS (0): 
CALLEES (3): FUN_005c7d00@0x005c7d00, FUN_005c08b0@0x005c08b0, FUN_005bdfe0@0x005bdfe0
----------------------------------------------------------------

void FUN_005c29c0(char *param_1)

{
  FUN_005c7d00();
  if (*param_1 == '\0') {
    uRam006cbc84 = 0;
  }
  else if (*param_1 == '\'') {
    uRam006cbc84 = 0xff;
  }
  uRam006cbc80 = (undefined2)*(undefined4 *)(param_1 + 0xc);
  uRam006cbc7e = 2;
  uRam006cbc7c = FUN_005c08b0(0);
  FUN_005bdfe0(0);
  return;
}



================================================================