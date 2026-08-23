FUNCTION FUN_00618600 @ 0x00618600  size=200
CALLERS (1): FUN_00610830@0x00610830
CALLEES (1): FUN_006186e0@0x006186e0
----------------------------------------------------------------

undefined8 FUN_00618600(int param_1)

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
    func_0x001f54b0(*(undefined1 *)(param_1 + 5),0x6543c0,0x70f340);
  }
  func_0x001f4630();
  lVar1 = func_0x001f5620();
  if (lVar1 == -1) {
    return 0xfffffffffffffffe;
  }
  *(undefined1 *)(param_1 + 1) = 0;
  if (lVar1 < 0) {
    uVar2 = FUN_006186e0(lVar1);
    return uVar2;
  }
  return 0xffffffffffffffff;
}



================================================================