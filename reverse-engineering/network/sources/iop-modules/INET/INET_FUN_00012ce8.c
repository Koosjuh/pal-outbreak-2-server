FUNCTION FUN_00012ce8 @ 0x00012ce8 size=312
CALLERS (2): FUN_00015430@0x00015430, FUN_00015d6c@0x00015d6c
CALLEES (1): FUN_00012ac8@0x00012ac8

void FUN_00012ce8(int param_1,short param_2,int param_3,short param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  iVar1 = DAT_0001b9a0;
  while( true ) {
    if (iVar1 == 0) {
      FUN_00012ac8(uVar2,param_1,param_2,param_3,param_4);
      return;
    }
    if ((((((param_1 == *(int *)(iVar1 + 0x14)) || (*(int *)(iVar1 + 0x14) == 0)) || (param_1 == 0))
         && (((param_2 == *(short *)(iVar1 + 0x1a) || (*(short *)(iVar1 + 0x1a) == 0)) ||
             (param_2 == 0)))) &&
        (((param_3 == *(int *)(iVar1 + 0x10) || (*(int *)(iVar1 + 0x10) == 0)) || (param_3 == 0))))
       && (((param_4 == *(short *)(iVar1 + 0x18) || (*(short *)(iVar1 + 0x18) == 0)) ||
           (param_4 == 0)))) break;
    if ((((*(uint *)(iVar1 + 0x2c) & 1) != 0) && (0 < *(int *)(iVar1 + 0x28))) &&
       ((*(int *)(iVar1 + 0x28) < 10 && (*(short *)(iVar1 + 0x1a) == param_2)))) {
      uVar2 = 1;
    }
    iVar1 = *(int *)(iVar1 + 4);
  }
  *(int *)(iVar1 + 0x14) = param_1;
  *(short *)(iVar1 + 0x1a) = param_2;
  *(int *)(iVar1 + 0x10) = param_3;
  *(short *)(iVar1 + 0x18) = param_4;
  return;
}


================================================================