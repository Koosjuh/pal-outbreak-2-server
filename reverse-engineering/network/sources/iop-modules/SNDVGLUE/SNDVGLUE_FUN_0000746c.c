FUNCTION FUN_0000746c @ 0x0000746c size=64
CALLERS (2): FUN_000076f4@0x000076f4, FUN_000074ac@0x000074ac
CALLEES (1): FUN_00007270@0x00007270

int FUN_0000746c(int param_1)

{
  short sVar1;
  int iVar2;
  int local_10 [2];
  
  local_10[0] = param_1 + 0x24e;
  sVar1 = FUN_00007270(local_10);
  iVar2 = -1;
  if (-1 < sVar1) {
    iVar2 = (int)sVar1;
  }
  return iVar2;
}


================================================================