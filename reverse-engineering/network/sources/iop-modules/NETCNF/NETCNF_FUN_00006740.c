FUNCTION FUN_00006740 @ 0x00006740 size=420
CALLERS (3): FUN_000026a0@0x000026a0, FUN_000023e0@0x000023e0, FUN_00000828@0x00000828
CALLEES (4): FUN_00009720@0x00009720, FUN_00009648@0x00009648, FUN_0000626c@0x0000626c, FUN_000062ec@0x000062ec

int FUN_00006740(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  if (param_1[5] == 1) {
    iVar1 = FUN_0000626c(param_1);
    if (iVar1 == 0) {
      if (((int *)param_1[6] == (int *)0x0) || (piVar3 = *(int **)param_1[6], piVar3 == (int *)0x0))
      {
        iVar1 = -0xe;
      }
      else {
        iVar2 = FUN_00009648(param_1[1],0x3a);
        if (iVar2 != 0) {
          *param_1 = param_1[1];
        }
        do {
          if (piVar3[3] == 0) {
            piVar3[5] = 0;
          }
          else {
            param_1[1] = piVar3[3];
            iVar1 = FUN_000062ec(param_1);
            if (iVar1 == 0) {
              piVar3[5] = param_1[7];
              iVar1 = 0;
            }
            else {
              FUN_00009720("netcnf: load_attach ifc(%d)\n",iVar1);
              piVar3[5] = 0;
              if (iVar1 + 0xfU < 2) {
                piVar3[6] = 0;
                return iVar1;
              }
              iVar1 = -0x15;
            }
          }
          if (piVar3[4] == 0) {
            piVar3[6] = 0;
          }
          else {
            param_1[1] = piVar3[4];
            iVar1 = FUN_000062ec(param_1);
            if (iVar1 == 0) {
              piVar3[6] = param_1[7];
              iVar1 = 0;
            }
            else {
              FUN_00009720("netcnf: load_attach dev(%d)\n",iVar1);
              piVar3[6] = 0;
              if (iVar1 + 0xfU < 2) {
                return iVar1;
              }
              iVar1 = -0x15;
            }
          }
          piVar3 = (int *)*piVar3;
        } while (piVar3 != (int *)0x0);
      }
    }
  }
  else if (param_1[5] == 2) {
    iVar1 = FUN_000062ec(param_1);
  }
  else {
    iVar1 = -1;
  }
  return iVar1;
}


================================================================