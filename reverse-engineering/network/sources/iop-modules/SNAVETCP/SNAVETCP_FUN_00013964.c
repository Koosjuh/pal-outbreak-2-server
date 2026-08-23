FUNCTION FUN_00013964 @ 0x00013964 size=88
CALLERS (1): FUN_00014384@0x00014384
CALLEES (2): FUN_000008d4@0x000008d4, FUN_0001379c@0x0001379c

void FUN_00013964(int param_1)

{
  undefined2 local_10 [4];
  
  if ((&DAT_00016fa0)[param_1] != 0) {
    local_10[0] = *(undefined2 *)((&DAT_00016fa0)[param_1] + 2);
    FUN_000008d4(&DAT_00004113,local_10,0);
    FUN_0001379c(param_1);
  }
  return;
}


================================================================