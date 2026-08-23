FUNCTION FUN_0000071c @ 0x0000071c size=64
CALLERS (4): FUN_0000e0e0@0x0000e0e0, FUN_000041a0@0x000041a0, FUN_0000985c@0x0000985c, FUN_00006f6c@0x00006f6c
CALLEES (0): 

void FUN_0000071c(int *param_1,int param_2)

{
  int iVar1;
  
  if ((((param_1 != (int *)0x0) && (iVar1 = *param_1, iVar1 != 0)) && (param_2 != 0)) &&
     (param_2 <= (int)(uint)*(ushort *)(iVar1 + 4))) {
    *(short *)(iVar1 + 4) = (short)param_2;
  }
  return;
}


================================================================