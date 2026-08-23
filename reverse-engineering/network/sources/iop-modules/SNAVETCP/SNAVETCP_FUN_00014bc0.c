FUNCTION FUN_00014bc0 @ 0x00014bc0 size=44
CALLERS (1): FUN_00014d1c@0x00014d1c
CALLEES (0): 

void FUN_00014bc0(int param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = *(int *)((int)&DAT_00016fa0 + ((param_1 << 0x10) >> 0xe));
  if (iVar1 != 0) {
    *param_2 = iVar1 + 0x818;
  }
  return;
}


================================================================