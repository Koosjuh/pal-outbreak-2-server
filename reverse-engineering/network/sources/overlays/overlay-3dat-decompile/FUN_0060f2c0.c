FUNCTION FUN_0060f2c0 @ 0x0060f2c0  size=136
CALLERS (2): FUN_00610580@0x00610580, FUN_00610830@0x00610830
CALLEES (0): 
----------------------------------------------------------------

int FUN_0060f2c0(int param_1)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)(param_1 * 0x1c + 0x35c000);
  if (piRam0035c3d8 == (int *)0x0) {
    iVar1 = -2;
    if (*(int *)(param_1 * 0x1c + 0x35c008) == 1) {
      if (*piVar2 == 1) {
        piRam0035c3d8 = piVar2;
        func_0x001bf5a0();
        func_0x001bf590();
        iVar1 = 1;
      }
      else {
        iVar1 = -2;
      }
    }
  }
  else {
    iVar1 = -(uint)(piRam0035c3d8 != piVar2);
  }
  return iVar1;
}



================================================================