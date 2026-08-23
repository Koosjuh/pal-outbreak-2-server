FUNCTION FUN_000193cc @ 0x000193cc size=88
CALLERS (1): FUN_00019424@0x00019424
CALLEES (2): FUN_0000d8cc@0x0000d8cc, FUN_000100c4@0x000100c4

undefined4 FUN_000193cc(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0xfffffe04;
  }
  else {
    if (*(int *)(param_1 + 0xc) == 2) {
      *(undefined4 *)(param_1 + 0x10) = param_2;
    }
    FUN_0000d8cc(param_1 + 0x34);
    FUN_000100c4();
    uVar1 = 0;
  }
  return uVar1;
}


================================================================