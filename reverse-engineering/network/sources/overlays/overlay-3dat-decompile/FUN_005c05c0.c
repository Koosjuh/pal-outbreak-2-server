FUNCTION FUN_005c05c0 @ 0x005c05c0  size=228
CALLERS (0): 
CALLEES (5): FUN_005c7d00@0x005c7d00, FUN_005bf180@0x005bf180, FUN_005c1ff0@0x005c1ff0, FUN_005c7e30@0x005c7e30, FUN_005bdfe0@0x005bdfe0
----------------------------------------------------------------

void FUN_005c05c0(char *param_1,int param_2)

{
  FUN_005c7d00();
  if (*param_1 == '\0') {
    uRam006cbc84 = 0;
    FUN_005bf180(2);
    uRam006febf4 = 0x96;
    uRam006ff2b1 = 1;
    uRam006ff2b2 = 1;
  }
  else if (*param_1 == '\'') {
    uRam006cbc84 = 0xff;
    if (*(int *)(param_2 + 4) == 0xf) {
      FUN_005c7e30(1);
      uRam006cbc80 = (undefined2)*(undefined4 *)(param_1 + 0xc);
      goto LAB_005c065c;
    }
    FUN_005c7e30(2);
  }
  uRam006cbc80 = (undefined2)*(undefined4 *)(param_1 + 0xc);
LAB_005c065c:
  uRam006cbc7e = 2;
  uRam006cbc7c = FUN_005c1ff0(0,0x6404f8);
  FUN_005bdfe0(0);
  return;
}



================================================================