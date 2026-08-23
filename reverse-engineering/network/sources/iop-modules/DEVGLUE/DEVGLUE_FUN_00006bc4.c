FUNCTION FUN_00006bc4 @ 0x00006bc4 size=80
CALLERS (3): FUN_0000560c@0x0000560c, FUN_00006c1c@0x00006c1c, FUN_0000678c@0x0000678c
CALLEES (1): FUN_00008034@0x00008034

void FUN_00006bc4(int param_1,short param_2,undefined2 param_3)

{
  undefined4 uVar1;
  
  uVar1 = FUN_00008034();
  *(undefined4 *)(param_1 + 0xc) = uVar1;
  *(int *)(param_1 + 8) = (int)param_2;
  *(undefined2 *)(param_1 + 6) = param_3;
  return;
}


================================================================