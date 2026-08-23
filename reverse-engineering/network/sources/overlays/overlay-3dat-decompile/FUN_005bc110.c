FUNCTION FUN_005bc110 @ 0x005bc110  size=168
CALLERS (1): FUN_005bba20@0x005bba20
CALLEES (0): 
----------------------------------------------------------------

void FUN_005bc110(undefined8 param_1,int param_2)

{
  if (cRam006ff2b1 != '\0') {
    func_0x0010a4f0(((uint)*(byte *)(param_2 + 4) * 0x44 + (uint)*(byte *)(param_2 + 4)) * 4 +
                    0x6fffad,param_2 + 6,0x10);
    func_0x0010a4f0(((uint)*(byte *)(param_2 + 4) * 0x44 + (uint)*(byte *)(param_2 + 4)) * 4 +
                    0x6fffbd,param_2 + 0x16,0x10);
  }
  return;
}



================================================================