FUNCTION FUN_005fb010 @ 0x005fb010  size=72
CALLERS (1): FUN_005fa0b0@0x005fa0b0
CALLEES (1): FUN_005fb670@0x005fb670
----------------------------------------------------------------

void FUN_005fb010(int param_1)

{
  long lVar1;
  
  lVar1 = FUN_005fb670();
  if (lVar1 == 0) {
    *(char *)(param_1 + 0xf) = *(char *)(param_1 + 0xf) + '\x01';
    *(undefined1 *)(param_1 + 0x10) = 0;
  }
  else {
    *(undefined1 *)(param_1 + 0xf) = 4;
    *(undefined1 *)(param_1 + 0x10) = 0;
  }
  return;
}



================================================================