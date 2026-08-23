FUNCTION FUN_00604810 @ 0x00604810  size=68
CALLERS (4): FUN_006277a0@0x006277a0, FUN_0062cfd0@0x0062cfd0, FUN_00627ea0@0x00627ea0, FUN_00604e70@0x00604e70
CALLEES (0): 
----------------------------------------------------------------

int FUN_00604810(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  iVar2 = 0;
  while ((iVar2 < (int)(param_2 & 0xff) && (*(char *)(param_1 + iVar2 * 0x38 + 0x10) != '\0'))) {
    iVar1 = iVar1 + 1;
    iVar2 = iVar2 + 1;
  }
  return iVar1;
}



================================================================