FUNCTION FUN_00000230 @ 0x00000230 size=96
CALLERS (1): FUN_00000a4c@0x00000a4c
CALLEES (2): FUN_0000018c@0x0000018c, FUN_00003d8c@0x00003d8c

undefined4 FUN_00000230(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_3 == 0) {
    uVar1 = 0;
  }
  else {
    iVar2 = FUN_00003d8c(param_3);
    uVar1 = FUN_0000018c(param_1,param_2,param_3,iVar2 + 1);
  }
  return uVar1;
}


================================================================