FUNCTION FUN_0060ee80 @ 0x0060ee80  size=152
CALLERS (1): FUN_00610830@0x00610830
CALLEES (3): FUN_006157e0@0x006157e0, FUN_00616150@0x00616150, FUN_006157e8@0x006157e8
----------------------------------------------------------------

bool FUN_0060ee80(int param_1)

{
  long lVar1;
  
  do {
    lVar1 = FUN_00616150(param_1 + 0x19af4,*(undefined4 *)(param_1 + 0x19ae0),param_1 + 0x19b34);
  } while (lVar1 < 0);
  do {
    lVar1 = FUN_006157e0();
  } while (lVar1 != 0);
  FUN_006157e8(param_1 + 0x197c0);
  return *(int *)(param_1 + 0x197c0) == -0x14;
}



================================================================