FUNCTION FUN_00013170 @ 0x00013170 size=240
CALLERS (1): FUN_00000aa0@0x00000aa0
CALLEES (1): FUN_00014e24@0x00014e24

undefined4 FUN_00013170(int param_1)

{
  undefined4 uVar1;
  
  DAT_00016f8c = 9;
  DAT_00016f90 = (uint)(DAT_00016174 != 0);
  uVar1 = 0;
  if (param_1 != 0) {
    if (*(int *)(param_1 + 4) - 1U < 0x7e) {
      if (DAT_00016178 != 0) {
        FUN_00014e24("AT_PS2_Init: tskPri == %d\n");
      }
      DAT_00016f8c = *(undefined4 *)(param_1 + 4);
      if (DAT_00016178 != 0) {
        FUN_00014e24("AT_PS2_Init: an986 == %d\n",*(undefined4 *)(param_1 + 8));
      }
      DAT_00016f90 = *(uint *)(param_1 + 8);
      uVar1 = 0;
    }
    else {
      uVar1 = 0xffffffff;
      if (DAT_00016178 != 0) {
        FUN_00014e24("AT_PS2_Init: argument error tskPri == %d\n");
        uVar1 = 0xffffffff;
      }
    }
  }
  return uVar1;
}


================================================================