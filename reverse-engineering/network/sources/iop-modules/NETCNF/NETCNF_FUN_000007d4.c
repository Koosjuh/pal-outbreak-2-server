FUNCTION FUN_000007d4 @ 0x000007d4 size=84
CALLERS (0): 
CALLEES (2): FUN_00009618@0x00009618, FUN_00004dd0@0x00004dd0

undefined4 FUN_000007d4(int param_1)

{
  if (param_1 != 0) {
    FUN_00009618(param_1,0x160);
    FUN_00004dd0(param_1);
  }
  return 0;
}


================================================================