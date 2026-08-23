FUNCTION FUN_005f0440 @ 0x005f0440  size=60
CALLERS (1): FUN_005f0480@0x005f0480
CALLEES (0): 
----------------------------------------------------------------

undefined1 FUN_005f0440(int param_1)

{
  for (; *(ushort *)(param_1 + 0x36) != 0;
      param_1 = iRam007012a0 + (uint)*(ushort *)(param_1 + 0x36) * 0x5c + 0x24e0) {
  }
  return *(undefined1 *)(param_1 + 0x18);
}



================================================================