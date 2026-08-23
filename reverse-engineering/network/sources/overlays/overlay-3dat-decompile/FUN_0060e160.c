FUNCTION FUN_0060e160 @ 0x0060e160  size=96
CALLERS (1): FUN_006101a0@0x006101a0
CALLEES (2): FUN_0060f5e0@0x0060f5e0, FUN_006162d8@0x006162d8
----------------------------------------------------------------

undefined8 FUN_0060e160(void)

{
  long lVar1;
  
  FUN_006162d8();
  lVar1 = func_0x0011a660(0x64b770);
  if (-1 < lVar1) {
    FUN_0060f5e0(lVar1);
  }
  lVar1 = func_0x0011a660(0x64b790);
  if (-1 < lVar1) {
    FUN_0060f5e0(lVar1);
  }
  return 0;
}



================================================================