FUNCTION FUN_00008c68 @ 0x00008c68 size=96
CALLERS (3): FUN_00009028@0x00009028, FUN_000092cc@0x000092cc, FUN_000091c8@0x000091c8
CALLEES (0): 

int FUN_00008c68(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  iVar1 = 0;
  while ((*(int *)((int)&DAT_0000c220 + iVar1) != param_1 ||
         ((*(int *)((int)&DAT_0000c340 + iVar1) != param_2 && (param_2 != 0))))) {
    iVar2 = iVar2 + 1;
    iVar1 = iVar1 + 0x124;
    if (3 < iVar2) {
      return -1;
    }
  }
  return iVar2;
}


================================================================