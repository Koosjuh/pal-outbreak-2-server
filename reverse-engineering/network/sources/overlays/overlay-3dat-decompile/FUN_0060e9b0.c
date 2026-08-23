FUNCTION FUN_0060e9b0 @ 0x0060e9b0  size=168
CALLERS (2): FUN_00610580@0x00610580, FUN_00610830@0x00610830
CALLEES (0): 
----------------------------------------------------------------

int FUN_0060e9b0(int *param_1,int *param_2)

{
  int iVar1;
  long lVar2;
  
  if (*param_1 == *param_2) {
    lVar2 = func_0x0010a338(param_1 + 2,param_2 + 2,0xff);
    if (lVar2 == 0) {
      if ((short)param_1[1] == (short)param_2[1]) {
        lVar2 = func_0x0010a338(param_1 + 0x42,param_2 + 0x42,0xff);
        if (lVar2 == 0) {
          iVar1 = -(uint)(*(short *)((int)param_1 + 6) != *(short *)((int)param_2 + 6));
        }
        else {
          iVar1 = -1;
        }
      }
      else {
        iVar1 = -1;
      }
    }
    else {
      iVar1 = -1;
    }
  }
  else {
    iVar1 = -1;
  }
  return iVar1;
}



================================================================