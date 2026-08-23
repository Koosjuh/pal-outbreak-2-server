FUNCTION FUN_005bfe90 @ 0x005bfe90  size=140
CALLERS (0): 
CALLEES (4): FUN_005c7d00@0x005c7d00, FUN_005bf130@0x005bf130, FUN_005c2080@0x005c2080, FUN_005bdfe0@0x005bdfe0
----------------------------------------------------------------

void FUN_005bfe90(char *param_1)

{
  FUN_005c7d00();
  if (*param_1 == '\0') {
    uRam006cbc84 = 0;
    FUN_005bf130(1);
    uRam006cbc80 = (undefined2)*(undefined4 *)(param_1 + 0xc);
  }
  else {
    if (*param_1 == '\'') {
      uRam006cbc84 = 0xff;
    }
    uRam006cbc80 = (undefined2)*(undefined4 *)(param_1 + 0xc);
  }
  uRam006cbc7e = 2;
  uRam006cbc7c = FUN_005c2080(1);
  FUN_005bdfe0(0);
  return;
}



================================================================