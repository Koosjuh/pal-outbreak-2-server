FUNCTION FUN_00006318 @ 0x00006318 size=152
CALLERS (1): FUN_00002900@0x00002900
CALLEES (2): FUN_0001073c@0x0001073c, FUN_00010764@0x00010764

void FUN_00006318(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  FUN_0001073c();
  DAT_00012eb0 = param_5;
  DAT_00012ee0 = param_6;
  DAT_00012eb8 = param_3;
  DAT_00012ed8 = param_4;
  DAT_00012ee8 = param_1;
  DAT_00012eec = param_2;
  FUN_00010764();
  return;
}


================================================================