FUNCTION FUN_00617110 @ 0x00617110  size=276
CALLERS (1): FUN_00616c40@0x00616c40
CALLEES (2): FUN_005af2f0@0x005af2f0, FUN_00617bb0@0x00617bb0
----------------------------------------------------------------

void FUN_00617110(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (*(char *)(param_1 + 0xf) == '\x01') {
    *(char *)(param_1 + 0xe) = *(char *)(param_1 + 0xe) + '\x01';
    *(undefined1 *)(param_1 + 0xf) = 0;
    *(undefined2 *)(param_1 + 0x16) = 10;
    FUN_005af2f0(0);
    FUN_00617bb0();
  }
  else if (*(char *)(param_1 + 0xf) == '\0') {
    *(undefined1 *)(param_1 + 0xf) = 1;
    func_0x00106b60(0x70f330,0xffffffffffffffff,4);
    for (iVar2 = 0; iVar2 < (int)(uint)*(byte *)(param_1 + 0x990); iVar2 = iVar2 + 1) {
      iVar1 = param_1 + iVar2 * 0x3b0;
      if (*(short *)(iVar1 + 0x22ca) == 0) {
        *(char *)(iVar2 + 0x70f330) = (char)*(undefined2 *)(iVar1 + 0x22c8);
      }
      else {
        *(undefined1 *)(iVar2 + 0x70f330) = 8;
      }
    }
    func_0x001d40e0(0,0,0x70f330);
    *(undefined2 *)(param_1 + 0xc) = *(undefined2 *)(param_1 + 0x1f18);
    *(char *)(param_1 + 9) = (char)*(undefined2 *)(param_1 + 0x1f1a);
    *(char *)(param_1 + 8) = (char)*(undefined2 *)(param_1 + 0x1f1c);
  }
  return;
}



================================================================