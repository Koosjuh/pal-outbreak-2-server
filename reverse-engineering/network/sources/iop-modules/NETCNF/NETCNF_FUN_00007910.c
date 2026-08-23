FUNCTION FUN_00007910 @ 0x00007910 size=100
CALLERS (1): FUN_00007b40@0x00007b40
CALLEES (1): FUN_00006f00@0x00006f00

int FUN_00007910(undefined4 param_1,int *param_2)

{
  int iVar1;
  
  param_2 = (int *)*param_2;
  while( true ) {
    if (param_2 == (int *)0x0) {
      return 0;
    }
    iVar1 = FUN_00006f00(param_1,&DAT_0000a970,param_2 + 2);
    if (iVar1 < 0) break;
    param_2 = (int *)*param_2;
  }
  return iVar1;
}


================================================================