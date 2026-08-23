FUNCTION FUN_005da430 @ 0x005da430  size=128
CALLERS (1): FUN_005e7070@0x005e7070
CALLEES (0): 
----------------------------------------------------------------

void FUN_005da430(long param_1)

{
  func_0x00109eb8(iRam00701070 + 0x55d,param_1);
  if ((param_1 != 0) && (*(char *)param_1 != '\0')) {
    *(undefined1 *)(iRam00701070 + 0x31) = 0;
    func_0x0019c8b0(0x870870,0,0x10);
    func_0x00109eb8(0x870870,param_1);
  }
  return;
}



================================================================