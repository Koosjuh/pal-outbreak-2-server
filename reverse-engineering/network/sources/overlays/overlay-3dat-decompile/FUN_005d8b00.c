FUNCTION FUN_005d8b00 @ 0x005d8b00  size=140
CALLERS (2): FUN_005ef4f0@0x005ef4f0, FUN_005c8ed0@0x005c8ed0
CALLEES (1): FUN_005cab10@0x005cab10
----------------------------------------------------------------

void FUN_005d8b00(int param_1)

{
  ulong uVar1;
  
  uVar1 = func_0x0010a050();
  if (0x3c < uVar1) {
    *(undefined1 *)(param_1 + 0x38) = 0x20;
    *(undefined1 *)(param_1 + 0x39) = 0x2e;
    *(undefined1 *)(param_1 + 0x3a) = 0x2e;
    *(undefined1 *)(param_1 + 0x3b) = 0x2e;
    *(undefined1 *)(param_1 + 0x3c) = 0;
  }
  FUN_005cab10(0,1,0x10,0x1ac,0,0,0xffffffffff000001,0x14);
  return;
}



================================================================