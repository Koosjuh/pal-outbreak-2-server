FUNCTION FUN_0000a750 @ 0x0000a750 size=56
CALLERS (3): FUN_0000ce88@0x0000ce88, FUN_0000d884@0x0000d884, FUN_00007000@0x00007000
CALLEES (0): 

int FUN_0000a750(int param_1)

{
  if ((*(uint *)(param_1 + 0xd8) & 1) == 0) {
    return (int)DAT_000161a4 - *(int *)(param_1 + 8);
  }
  return (int)DAT_000161a4;
}


================================================================