FUNCTION FUN_005bd8c0 @ 0x005bd8c0  size=116
CALLERS (0): 
CALLEES (2): FUN_005bdfe0@0x005bdfe0, FUN_005bdef0@0x005bdef0
----------------------------------------------------------------

void FUN_005bd8c0(char *param_1)

{
  if (*param_1 == '\0') {
    uRam006cbc84 = 0;
  }
  else if (*param_1 == '\'') {
    uRam006cbc84 = 0xff;
  }
  uRam006cbc80 = (undefined2)*(undefined4 *)(param_1 + 0xc);
  uRam006cbc7e = 2;
  uRam006cbc7c = FUN_005bdef0(0,0);
  FUN_005bdfe0(0);
  return;
}



================================================================