FUNCTION FUN_0000091c @ 0x0000091c size=160
CALLERS (1): FUN_00000a4c@0x00000a4c
CALLEES (3): FUN_00003d40@0x00003d40, FUN_00003d6c@0x00003d6c, FUN_00003d8c@0x00003d8c

undefined1 * FUN_0000091c(int param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  undefined1 *puVar2;
  
  iVar1 = FUN_00003d8c(param_2);
  if (*param_3 < iVar1 + 1) {
    FUN_00003d40("inetctl: too long chat\n");
    puVar2 = (undefined1 *)0x0;
  }
  else {
    FUN_00003d6c(param_2,param_1,iVar1);
    *(undefined1 *)(param_1 + iVar1) = 0x20;
    puVar2 = (undefined1 *)(param_1 + iVar1) + 1;
    *param_3 = (*param_3 + -1) - iVar1;
  }
  return puVar2;
}


================================================================