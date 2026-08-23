FUNCTION FUN_0000e278 @ 0x0000e278 size=44
CALLERS (1): FUN_00001800@0x00001800
CALLEES (0): 

int FUN_0000e278(int param_1)

{
  if ((int)DAT_0001618e == 0) {
    trap(0x1c00);
  }
  return param_1 + (*(uint *)(param_1 + 8) % (uint)(int)DAT_0001618e) * 0x10 + 0xc;
}


================================================================