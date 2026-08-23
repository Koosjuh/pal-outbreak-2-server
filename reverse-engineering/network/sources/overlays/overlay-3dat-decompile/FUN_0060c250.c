FUNCTION FUN_0060c250 @ 0x0060c250  size=128
CALLERS (1): FUN_0060c6e0@0x0060c6e0
CALLEES (0): 
----------------------------------------------------------------

int FUN_0060c250(int *param_1,undefined8 param_2,int param_3)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (iVar1 == 0) {
    param_3 = 0;
    *(undefined1 *)(param_1 + 3) = 0xfd;
  }
  else {
    if (iVar1 < param_3) {
      param_3 = iVar1;
    }
    func_0x001069a8(param_2,param_1[0x2a] + (param_1[1] - iVar1),param_3);
    *param_1 = *param_1 - param_3;
  }
  return param_3;
}



================================================================