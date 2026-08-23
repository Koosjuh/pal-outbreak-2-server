FUNCTION FUN_00001a20 @ 0x00001a20 size=236
CALLERS (1): FUN_00001c64@0x00001c64
CALLEES (3): FUN_000017dc@0x000017dc, FUN_00001958@0x00001958, FUN_0000182c@0x0000182c

undefined4 FUN_00001a20(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar2 = 0;
  if (FUN_00001320[param_2] == (code)0x0) {
    iVar3 = param_2 + 0x500;
    if ((*(char *)(param_2 + 0x500) == '\0') || (iVar1 = FUN_000017dc(iVar3), iVar1 == 0)) {
      iVar3 = 0;
    }
    uVar2 = FUN_0000182c(param_1,iVar3);
  }
  if (((*(char *)(param_2 + 0x600) != '\0') && (iVar3 = FUN_000017dc(param_2 + 0x600), iVar3 != 0))
     && (uVar2 = FUN_00001958(param_1,param_2 + 0x600,1), *(char *)(param_2 + 0x700) != '\0')) {
    iVar3 = FUN_000017dc(param_2 + 0x700);
    if (iVar3 != 0) {
      uVar2 = FUN_00001958(param_1,param_2 + 0x700,2);
    }
  }
  return uVar2;
}


================================================================