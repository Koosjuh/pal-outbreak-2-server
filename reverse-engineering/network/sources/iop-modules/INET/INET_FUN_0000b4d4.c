FUNCTION FUN_0000b4d4 @ 0x0000b4d4 size=68
CALLERS (1): FUN_00011fb8@0x00011fb8
CALLEES (1): FUN_0000d508@0x0000d508

void FUN_0000b4d4(void)

{
  int iVar1;
  
  for (iVar1 = DAT_0001b984; iVar1 != 0; iVar1 = *(int *)(iVar1 + 4)) {
    FUN_0000d508(iVar1 + 0x28,1);
  }
  return;
}


================================================================