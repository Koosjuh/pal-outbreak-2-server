FUNCTION FUN_000137cc @ 0x000137cc size=192
CALLERS (0): 
CALLEES (1): FUN_00013670@0x00013670

undefined4 FUN_000137cc(int param_1,undefined2 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_00013670(*param_2);
  uVar2 = 1;
  if (iVar1 != 0) {
    if (param_1 == 0) {
      uVar2 = 1;
      if ((*(int *)(iVar1 + 4) == 1) &&
         ((*(int *)(iVar1 + 8) == 0 || (uVar2 = 1, *(int *)(iVar1 + 8) == *(int *)(param_2 + 6)))))
      {
        if ((*(short *)(iVar1 + 0xc) == 0) || (*(short *)(iVar1 + 0xc) == param_2[8])) {
          *(int *)(param_2 + 10) = iVar1 + 0xe;
          uVar2 = 0;
        }
        else {
          uVar2 = 1;
        }
      }
    }
    else {
      *(undefined4 *)(iVar1 + 4) = 2;
      uVar2 = 0;
      *(int *)(iVar1 + 0x810) = (int)(short)param_2[4];
    }
  }
  return uVar2;
}


================================================================