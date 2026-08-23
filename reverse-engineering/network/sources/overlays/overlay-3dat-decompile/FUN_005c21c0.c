FUNCTION FUN_005c21c0 @ 0x005c21c0  size=132
CALLERS (0): 
CALLEES (4): FUN_005c7d00@0x005c7d00, FUN_005c7e30@0x005c7e30, FUN_005bdfe0@0x005bdfe0, FUN_005c2250@0x005c2250
----------------------------------------------------------------

void FUN_005c21c0(char *param_1)

{
  FUN_005c7d00();
  if (*param_1 == '\0') {
    uRam006cbc84 = 0;
  }
  else if (*param_1 == '\'') {
    uRam006cbc84 = 0xff;
    FUN_005c7e30(3);
  }
  uRam006cbc80 = (undefined2)*(undefined4 *)(param_1 + 0xc);
  uRam006cbc7e = 2;
  uRam006cbc7c = FUN_005c2250();
  FUN_005bdfe0(0);
  return;
}



================================================================