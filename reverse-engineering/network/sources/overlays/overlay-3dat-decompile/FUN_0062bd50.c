FUNCTION FUN_0062bd50 @ 0x0062bd50  size=68
CALLERS (2): FUN_0062a6d0@0x0062a6d0, FUN_0062bbc0@0x0062bbc0
CALLEES (0): 
----------------------------------------------------------------

undefined4 FUN_0062bd50(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = 0;
  iVar3 = 0;
  iVar2 = 0;
  do {
    if (*(char *)(param_1 + iVar2 * 4 + iVar3 * 5 + 0x1055) != '\0') {
      uVar1 = 1;
    }
    iVar3 = iVar3 + 1;
    iVar2 = iVar3 * 8;
  } while (iVar3 < 3);
  return uVar1;
}



================================================================