FUNCTION FUN_00000928 @ 0x00000928 size=96
CALLERS (1): FUN_0000dfdc@0x0000dfdc
CALLEES (1): FUN_00010b3c@0x00010b3c

int FUN_00000928(undefined4 *param_1,int param_2,ushort param_3)

{
  int iVar1;
  
  if (param_2 == 0) {
    iVar1 = 0;
  }
  else {
    if (*(ushort *)(param_1 + 1) < param_3) {
      param_3 = *(ushort *)(param_1 + 1);
    }
    FUN_00010b3c(param_2,*param_1,param_3);
    iVar1 = (int)(short)param_3;
  }
  return iVar1;
}


================================================================