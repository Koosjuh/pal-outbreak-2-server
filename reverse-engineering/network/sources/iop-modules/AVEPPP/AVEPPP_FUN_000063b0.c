FUNCTION FUN_000063b0 @ 0x000063b0 size=184
CALLERS (1): FUN_00002d98@0x00002d98
CALLEES (2): FUN_0001073c@0x0001073c, FUN_00010764@0x00010764

void FUN_000063b0(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4,
                 undefined4 *param_5,undefined4 *param_6)

{
  int iVar1;
  
  iVar1 = DAT_00014a2c;
  FUN_0001073c();
  *param_1 = *(undefined4 *)(iVar1 + 8);
  *param_2 = *(undefined4 *)(iVar1 + 0xc);
  *param_3 = *(undefined4 *)(iVar1 + 0x18);
  *param_4 = *(undefined4 *)(iVar1 + 0x1c);
  *param_5 = *(undefined4 *)(iVar1 + 100);
  *param_6 = *(undefined4 *)(iVar1 + 0x68);
  FUN_00010764();
  return;
}


================================================================