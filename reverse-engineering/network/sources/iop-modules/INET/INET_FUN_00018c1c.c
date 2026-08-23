FUNCTION FUN_00018c1c @ 0x00018c1c size=68
CALLERS (1): FUN_00011fb8@0x00011fb8
CALLEES (1): FUN_0000d508@0x0000d508

void FUN_00018c1c(void)

{
  int iVar1;
  int unaff_gp;
  
  for (iVar1 = *(int *)(unaff_gp + -0x7a18); iVar1 != 0; iVar1 = *(int *)(iVar1 + 4)) {
    FUN_0000d508(iVar1 + 0x34,1);
  }
  return;
}


================================================================