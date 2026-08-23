FUNCTION FUN_0060e060 @ 0x0060e060  size=248
CALLERS (1): FUN_0060f910@0x0060f910
CALLEES (6): FUN_00615670@0x00615670, FUN_006157e0@0x006157e0, FUN_0060f680@0x0060f680, FUN_006158b8@0x006158b8, FUN_00616210@0x00616210, FUN_006157e8@0x006157e8
----------------------------------------------------------------

undefined4 FUN_0060e060(int param_1)

{
  undefined4 uVar1;
  long lVar2;
  
  FUN_0060f680(0x64b730,0x61,0x64b6a0,0,0);
  FUN_0060f680(0x64b750,0x16,0x64b710,0,0);
  func_0x001a21b0();
  FUN_00615670();
  do {
    lVar2 = FUN_00616210(0x1000);
  } while (lVar2 < 0);
  do {
    lVar2 = FUN_006157e0();
  } while (lVar2 != 0);
  do {
    lVar2 = FUN_006157e8(param_1 + 0x197c0);
  } while (lVar2 < 0);
  if (*(int *)(param_1 + 0x197c0) < 0) {
    uVar1 = 0xffffffff;
  }
  else {
    FUN_006158b8(0);
    func_0x001a21b0();
    uVar1 = 0;
  }
  return uVar1;
}



================================================================