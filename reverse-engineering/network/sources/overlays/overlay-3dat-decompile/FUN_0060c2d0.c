FUNCTION FUN_0060c2d0 @ 0x0060c2d0  size=84
CALLERS (2): FUN_0060cb40@0x0060cb40, FUN_0060c6e0@0x0060c6e0
CALLEES (0): 
----------------------------------------------------------------

int FUN_0060c2d0(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (iVar1 == 0) {
    param_2 = 0;
    *(undefined1 *)(param_1 + 3) = 0xfd;
  }
  else {
    if (iVar1 < param_2) {
      param_2 = iVar1;
    }
    param_1[2] = param_1[0x2a] + (param_1[1] - iVar1);
    *param_1 = *param_1 - param_2;
  }
  return param_2;
}



================================================================