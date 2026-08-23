FUNCTION FUN_005d6b80 @ 0x005d6b80  size=136
CALLERS (2): FUN_005d6ce0@0x005d6ce0, FUN_005d6c90@0x005d6c90
CALLEES (0): 
----------------------------------------------------------------

void FUN_005d6b80(int *param_1,int *param_2)

{
  int *piVar1;
  int *piVar2;
  
  piVar2 = (int *)0x0;
  while (piVar1 = param_1, param_1 = (int *)*piVar1, param_1 != (int *)0x0) {
    if (param_1 == param_2) {
      piVar2 = piVar1;
    }
  }
  if (piVar2 != (int *)0x0) {
    if (*param_2 != 0) {
      *piVar2 = *param_2;
      *piVar1 = (int)param_2;
      *param_2 = 0;
    }
    func_0x00106b60(param_2 + 1,0,0x100);
    param_2[0x41] = 0;
    func_0x00106b60(param_2 + 0x42,0,2);
  }
  return;
}



================================================================