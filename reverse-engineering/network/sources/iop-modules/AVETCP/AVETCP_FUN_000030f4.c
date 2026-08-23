FUNCTION FUN_000030f4 @ 0x000030f4 size=72
CALLERS (1): FUN_00003220@0x00003220
CALLEES (1): FUN_00006e48@0x00006e48

undefined4 FUN_000030f4(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = 0;
    if (*(int *)(param_1 + 4) != 0) {
      FUN_00006e48();
      DAT_00016526 = 0;
      uVar1 = 0;
    }
  }
  return uVar1;
}


================================================================