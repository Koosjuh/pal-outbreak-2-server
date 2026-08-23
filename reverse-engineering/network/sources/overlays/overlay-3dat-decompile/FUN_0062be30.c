FUNCTION FUN_0062be30 @ 0x0062be30  size=164
CALLERS (1): FUN_0062bda0@0x0062bda0
CALLEES (1): FUN_005b8cf0@0x005b8cf0
----------------------------------------------------------------

void FUN_0062be30(int param_1,int param_2)

{
  short sVar1;
  
  if (*(char *)(param_2 + 2) == '\x01') {
    sVar1 = *(short *)(param_2 + 4) + -1;
    *(short *)(param_2 + 4) = sVar1;
    if (sVar1 < 0) {
      *(char *)(param_2 + 1) = *(char *)(param_2 + 1) + '\x01';
      *(undefined1 *)(param_2 + 2) = 0;
    }
  }
  else if (*(char *)(param_2 + 2) == '\0') {
    *(undefined4 *)(param_1 + 0x1460) = 0;
    *(char *)(param_2 + 2) = *(char *)(param_2 + 2) + '\x01';
    *(undefined2 *)(param_2 + 4) = 0x10;
    FUN_005b8cf0(100);
    func_0x00106b60(param_1 + 0x12c2,0,0x19e);
  }
  return;
}



================================================================