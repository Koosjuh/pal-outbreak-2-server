FUNCTION FUN_000009bc @ 0x000009bc size=144
CALLERS (2): FUN_00001894@0x00001894, FUN_00000a4c@0x00000a4c
CALLEES (3): FUN_00003d40@0x00003d40, FUN_00003d6c@0x00003d6c, FUN_00003d8c@0x00003d8c

int FUN_000009bc(int param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  
  iVar1 = FUN_00003d8c(param_2);
  if (*param_3 < iVar1 + 1) {
    FUN_00003d40("inetctl: too long phone number\n");
    param_1 = 0;
  }
  else {
    FUN_00003d6c(param_2,param_1,iVar1);
    param_1 = param_1 + iVar1;
    *param_3 = *param_3 - iVar1;
  }
  return param_1;
}


================================================================