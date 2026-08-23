FUNCTION FUN_005bc1c0 @ 0x005bc1c0  size=108
CALLERS (1): FUN_005bba20@0x005bba20
CALLEES (0): 
----------------------------------------------------------------

void FUN_005bc1c0(undefined8 param_1,int param_2)

{
  if (cRam006ff2b1 != '\0') {
    func_0x001069a8((uint)*(ushort *)(param_2 + 6) +
                    ((uint)*(byte *)(param_2 + 4) * 0x44 + (uint)*(byte *)(param_2 + 4)) * 4 +
                    0x6fffd1,param_2 + 8,*(undefined1 *)(param_2 + 5));
  }
  return;
}



================================================================