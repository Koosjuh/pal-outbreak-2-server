FUNCTION FUN_0000eecc @ 0x0000eecc size=72
CALLERS (3): FUN_000034a8@0x000034a8, FUN_0000f344@0x0000f344, FUN_0000ad44@0x0000ad44
CALLEES (0): 

void FUN_0000eecc(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *param_1;
  if (iVar2 != 0) {
    iVar1 = *(int *)(iVar2 + 0x10) + -1;
    *(int *)(iVar2 + 0x10) = iVar1;
    if ((iVar1 == 0) && ((*(ushort *)(iVar2 + 0xe) & 1) == 0)) {
      *(undefined2 *)(iVar2 + 0xe) = 0;
    }
    *param_1 = 0;
  }
  return;
}


================================================================