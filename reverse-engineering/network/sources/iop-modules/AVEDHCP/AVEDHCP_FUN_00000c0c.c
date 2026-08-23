FUNCTION FUN_00000c0c @ 0x00000c0c size=160
CALLERS (2): FUN_00000cac@0x00000cac, FUN_000001e8@0x000001e8
CALLEES (0): 

undefined4
FUN_00000c0c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5
            ,int param_6,int param_7,undefined4 param_8)

{
  undefined4 uVar1;
  
  DAT_00002f50 = 0;
  uVar1 = 2;
  if ((((DAT_00002eb0 == 0) && (uVar1 = 1, param_5 != 0)) && (param_6 != 0)) && (param_7 != 0)) {
    DAT_00004254 = param_5;
    DAT_00004258 = param_6;
    DAT_0000425c = param_7;
    DAT_00004268 = param_2;
    DAT_0000426c = param_3;
    DAT_000042a8 = param_8;
    DAT_00002eb0 = 1;
    DAT_00002f7c = 0;
    return 0;
  }
  DAT_00002f50 = uVar1;
  return 0xffffffff;
}


================================================================