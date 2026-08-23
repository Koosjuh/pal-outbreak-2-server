FUNCTION FUN_006075e0 @ 0x006075e0  size=216
CALLERS (1): FUN_00606cf0@0x00606cf0
CALLEES (7): FUN_005af310@0x005af310, thunk_EXT_FUN_001b3720@0x005af360, FUN_00606ac0@0x00606ac0, FUN_005be900@0x005be900, FUN_00618b60@0x00618b60, FUN_005be8c0@0x005be8c0, FUN_005b24c0@0x005b24c0
----------------------------------------------------------------

void FUN_006075e0(int param_1)

{
  char cVar1;
  long lVar2;
  
  cVar1 = *(char *)(param_1 + 1);
  if (cVar1 == '\x03') {
    uRam003c8a80 = 0;
    FUN_00606ac0();
  }
  else if (cVar1 == '\x02') {
    lVar2 = FUN_005be900();
    if (lVar2 == 1) {
      *(char *)(param_1 + 1) = *(char *)(param_1 + 1) + '\x01';
    }
  }
  else if (cVar1 == '\x01') {
    thunk_EXT_FUN_001b3720();
    FUN_00618b60();
    FUN_005be8c0();
    *(char *)(param_1 + 1) = *(char *)(param_1 + 1) + '\x01';
  }
  else if ((cVar1 == '\0') && (lVar2 = FUN_005af310(), lVar2 != 0)) {
    *(char *)(param_1 + 1) = *(char *)(param_1 + 1) + '\x01';
    func_0x003adb80();
    FUN_005b24c0();
  }
  return;
}



================================================================