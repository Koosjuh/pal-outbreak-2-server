FUNCTION FUN_00011498 @ 0x00011498 size=68
CALLERS (1): FUN_000007d4@0x000007d4
CALLEES (2): FUN_00002a0c@0x00002a0c, FUN_00011d00@0x00011d00

int FUN_00011498(undefined4 *param_1)

{
  short sVar1;
  undefined1 auStack_10 [8];
  
  FUN_00011d00(auStack_10,param_1 + 1,6);
  sVar1 = FUN_00002a0c(*param_1,auStack_10);
  return (int)sVar1;
}


================================================================