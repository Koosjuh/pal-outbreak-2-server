FUNCTION FUN_005c5a10 @ 0x005c5a10  size=188
CALLERS (0): 
CALLEES (2): FUN_005bdfe0@0x005bdfe0, FUN_005c6fb0@0x005c6fb0
----------------------------------------------------------------

void FUN_005c5a10(char *param_1,int param_2)

{
  if (*param_1 == '\0') {
    uRam006cbc84 = 0;
    if (*(int *)(param_2 + 4) == 0) {
      uRam00700420 = 0;
      uRam00700424 = 0;
      uRam00700428 = 0;
    }
    else {
      uRam00700420 = *(undefined4 *)(param_2 + 0x1c);
      uRam00700424 = *(undefined4 *)(param_2 + 0x20);
      uRam00700428 = *(undefined4 *)(param_2 + 0x24);
    }
  }
  else if (*param_1 == '\'') {
    uRam006cbc84 = 0xff;
  }
  uRam006cbc80 = (undefined2)*(undefined4 *)(param_1 + 0xc);
  uRam006cbc7e = 2;
  uRam006cbc7c = FUN_005c6fb0(0);
  FUN_005bdfe0(0);
  return;
}



================================================================