FUNCTION FUN_00618460 @ 0x00618460  size=164
CALLERS (1): FUN_00610830@0x00610830
CALLEES (1): FUN_006186e0@0x006186e0
----------------------------------------------------------------

undefined8 FUN_00618460(int param_1)

{
  long lVar1;
  undefined8 uVar2;
  
  if (*(char *)(param_1 + 1) != '\x01') {
    if (*(char *)(param_1 + 1) != '\0') {
      return 0xfffffffffffffffe;
    }
    if ('\x01' < *(char *)(param_1 + 5)) {
      return 0xfffffffffffffff1;
    }
    if (iRam003908cc != 0) {
      return 0xfffffffffffffffe;
    }
    *(undefined1 *)(param_1 + 1) = 1;
    func_0x001f45e0(0);
    func_0x001f51b0(*(undefined1 *)(param_1 + 5));
  }
  func_0x001f4630();
  lVar1 = func_0x001f5620();
  if (lVar1 == -1) {
    return 0xfffffffffffffffe;
  }
  *(undefined1 *)(param_1 + 1) = 0;
  uVar2 = FUN_006186e0(lVar1);
  return uVar2;
}



================================================================