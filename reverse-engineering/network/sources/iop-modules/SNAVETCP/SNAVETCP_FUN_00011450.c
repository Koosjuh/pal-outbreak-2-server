FUNCTION FUN_00011450 @ 0x00011450 size=72
CALLERS (1): FUN_000007b0@0x000007b0
CALLEES (2): FUN_000029c8@0x000029c8, FUN_00011d00@0x00011d00

int FUN_00011450(undefined4 *param_1)

{
  short sVar1;
  undefined1 auStack_10 [8];
  
  FUN_00011d00(auStack_10,param_1 + 1,6);
  sVar1 = FUN_000029c8(*param_1,auStack_10,*(undefined2 *)((int)param_1 + 10));
  return (int)sVar1;
}


================================================================