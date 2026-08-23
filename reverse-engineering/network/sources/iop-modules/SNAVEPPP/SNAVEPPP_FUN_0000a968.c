FUNCTION FUN_0000a968 @ 0x0000a968 size=76
CALLERS (0): 
CALLEES (0): 

void FUN_0000a968(int param_1)

{
  if (*(int *)(param_1 + 0x30) != 0) {
    (**(code **)(*(int *)(param_1 + 0x2c) + 0x10))();
    *(undefined4 *)(param_1 + 0x30) = 0;
  }
  return;
}


================================================================