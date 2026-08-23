FUNCTION FUN_0000029c @ 0x0000029c size=168
CALLERS (1): FUN_00001108@0x00001108
CALLEES (3): FUN_00000238@0x00000238, FUN_00006ea8@0x00006ea8, FUN_00000160@0x00000160

int FUN_0000029c(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  
  if ((param_1 == 0) || (iVar2 = FUN_00006ea8(), piVar1 = DAT_0001b950, iVar2 != 0)) {
    iVar2 = 0;
  }
  else {
    for (; piVar1 != (int *)0x0; piVar1 = (int *)*piVar1) {
      if (param_2 == piVar1[4]) {
        if (piVar1 == DAT_0001b950) {
          return (int)piVar1;
        }
        FUN_00000238(piVar1);
        return (int)piVar1;
      }
    }
    iVar2 = FUN_00000160(param_1,param_2);
  }
  return iVar2;
}


================================================================