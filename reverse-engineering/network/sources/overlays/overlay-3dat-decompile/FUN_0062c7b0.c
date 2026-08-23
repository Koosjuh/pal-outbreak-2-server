FUNCTION FUN_0062c7b0 @ 0x0062c7b0  size=192
CALLERS (1): FUN_0062c350@0x0062c350
CALLEES (2): FUN_005b6900@0x005b6900, FUN_005b9110@0x005b9110
----------------------------------------------------------------

void FUN_0062c7b0(int param_1,int param_2)

{
  if (*(char *)(param_1 + 0x10b4) == '\0') {
    FUN_005b6900();
  }
  else {
    *(undefined1 *)(param_2 + 2) = 0;
    *(undefined2 *)(param_2 + 4) = 6;
    FUN_005b9110(0x4c);
    if (*(char *)(param_1 + 0x10b4) == '\x01') {
      *(undefined1 *)(param_2 + 1) = 4;
      *(undefined1 *)(param_2 + 2) = 0;
      func_0x001b0140(5);
    }
    else if (*(char *)(param_1 + 0x10b4) == '\x02') {
      *(undefined1 *)(param_2 + 1) = 5;
      *(undefined1 *)(param_2 + 2) = 0;
      func_0x001b0140(4);
    }
    else {
      *(undefined1 *)(param_2 + 1) = 4;
      *(undefined1 *)(param_2 + 2) = 3;
      func_0x001b0140(5);
    }
  }
  return;
}



================================================================