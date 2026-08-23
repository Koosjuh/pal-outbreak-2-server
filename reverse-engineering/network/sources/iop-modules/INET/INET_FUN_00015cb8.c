FUNCTION FUN_00015cb8 @ 0x00015cb8 size=68
CALLERS (1): FUN_00011fb8@0x00011fb8
CALLEES (1): FUN_0000d508@0x0000d508

void FUN_00015cb8(void)

{
  int iVar1;
  
  for (iVar1 = DAT_0001b9a0; iVar1 != 0; iVar1 = *(int *)(iVar1 + 4)) {
    FUN_0000d508(iVar1 + 0xcc,1);
  }
  return;
}


================================================================