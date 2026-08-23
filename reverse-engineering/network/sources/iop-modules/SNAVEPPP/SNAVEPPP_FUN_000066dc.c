FUNCTION FUN_000066dc @ 0x000066dc size=48
CALLERS (3): FUN_000067bc@0x000067bc, FUN_00006f6c@0x00006f6c, FUN_00006e04@0x00006e04
CALLEES (1): FUN_0000a7ac@0x0000a7ac

void FUN_000066dc(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0xc);
  FUN_0000a7ac(iVar1 + 0xa0);
  FUN_0000a7ac(iVar1 + 4);
  return;
}


================================================================