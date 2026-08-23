FUNCTION FUN_0000a29c @ 0x0000a29c size=124
CALLERS (0): 
CALLEES (1): FUN_00009e60@0x00009e60

undefined4 FUN_0000a29c(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = FUN_00009e60(param_2,param_3);
  if (iVar1 == 0) {
    param_3 = 0;
  }
  else {
    *(undefined4 *)(iVar1 + 0xc) = param_4;
    piVar2 = (int *)param_1[1];
    *(int **)(iVar1 + 4) = piVar2;
    if (piVar2 == (int *)0x0) {
      *param_1 = iVar1;
    }
    else {
      *piVar2 = iVar1;
    }
    param_1[1] = iVar1;
  }
  return param_3;
}


================================================================