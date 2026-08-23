FUNCTION FUN_005bfb40 @ 0x005bfb40  size=160
CALLERS (0): 
CALLEES (6): FUN_005c7d00@0x005c7d00, FUN_005bf180@0x005bf180, FUN_005c7e30@0x005c7e30, FUN_005bdfe0@0x005bdfe0, FUN_005c1f30@0x005c1f30, FUN_005c4dc0@0x005c4dc0
----------------------------------------------------------------

void FUN_005bfb40(char *param_1)

{
  FUN_005c7d00();
  if (*param_1 == '\0') {
    uRam006cbc84 = 0;
    FUN_005bf180(0);
    FUN_005c4dc0();
    uRam006cbc80 = (undefined2)*(undefined4 *)(param_1 + 0xc);
  }
  else {
    if (*param_1 == '\'') {
      uRam006cbc84 = 0xff;
      FUN_005c7e30(5);
    }
    uRam006cbc80 = (undefined2)*(undefined4 *)(param_1 + 0xc);
  }
  uRam006cbc7e = 2;
  uRam006cbc7c = FUN_005c1f30(0,0);
  FUN_005bdfe0(0);
  return;
}



================================================================