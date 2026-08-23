FUNCTION FUN_0000161c @ 0x0000161c size=172
CALLERS (1): FUN_000016c8@0x000016c8
CALLEES (3): FUN_00000b70@0x00000b70, FUN_00002910@0x00002910, FUN_00001320@0x00001320

undefined4 FUN_0000161c(int param_1,int *param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  for (param_2 = (int *)*param_2; param_2 != (int *)0x0; param_2 = (int *)*param_2) {
    FUN_00000b70(param_1);
    FUN_00002910(param_1,param_2[3]);
    FUN_00002910(param_1 + 0x100,param_2[4]);
    if (param_2[5] != 0) {
      uVar1 = FUN_00001320(param_1,param_2[5],1);
    }
    if (param_2[6] != 0) {
      uVar1 = FUN_00001320(param_1,param_2[6],2);
    }
  }
  return uVar1;
}


================================================================