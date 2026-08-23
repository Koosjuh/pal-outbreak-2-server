FUNCTION FUN_00614b90 @ 0x00614b90  size=188
CALLERS (1): FUN_0060f910@0x0060f910
CALLEES (6): FUN_00613b10@0x00613b10, thunk_EXT_FUN_001af0a0@0x00614770, FUN_00614c50@0x00614c50, FUN_00614c70@0x00614c70, FUN_00612120@0x00612120, FUN_00612ae0@0x00612ae0
----------------------------------------------------------------

void FUN_00614b90(void)

{
  func_0x001a7b70(0x61,0x1000000);
  func_0x001a7b70(0x5e,0x32);
  func_0x001a7b70(0x5f,5);
  func_0x001a7b70(0x60,0);
  func_0x001a7b70(99,0x10000);
  func_0x001a7b70(0x6c,1);
  FUN_00614c70();
  FUN_00614c50(0xffffffffffffffd0);
  func_0x00194050(1,iRam0070d1c0 + 8);
  func_0x001a7b70(4,*(undefined4 *)(iRam0070d1c0 + 8));
  FUN_00612120();
  FUN_00612ae0();
  FUN_00614c50(0xffffffffffffffe8);
  FUN_00613b10();
  thunk_EXT_FUN_001af0a0(0xfffffffffffffff0);
  return;
}



================================================================