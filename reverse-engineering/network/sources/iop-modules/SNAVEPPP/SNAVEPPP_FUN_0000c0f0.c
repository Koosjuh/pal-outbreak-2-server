FUNCTION FUN_0000c0f0 @ 0x0000c0f0 size=80
CALLERS (1): FUN_0000d5a8@0x0000d5a8
CALLEES (0): 

undefined4 FUN_0000c0f0(ushort *param_1,int param_2)

{
  *(int *)(param_1 + 4) = param_2;
  if (param_2 == -1) {
    param_1[2] = param_1[2] & 0xfffb;
    *param_1 = *param_1 & 0xfffb;
  }
  else {
    param_1[2] = param_1[2] | 4;
    *param_1 = *param_1 | 4;
  }
  return 0;
}


================================================================