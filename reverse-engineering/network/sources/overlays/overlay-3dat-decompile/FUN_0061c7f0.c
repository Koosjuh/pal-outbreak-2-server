FUNCTION FUN_0061c7f0 @ 0x0061c7f0  size=240
CALLERS (1): FUN_00619e00@0x00619e00
CALLEES (0): 
----------------------------------------------------------------

void FUN_0061c7f0(undefined2 *param_1,int param_2,short param_3)

{
  int iVar1;
  undefined2 uStack_20;
  short sStack_1e;
  undefined2 uStack_1c;
  undefined2 uStack_1a;
  undefined4 uStack_18;
  undefined2 uStack_14;
  undefined2 uStack_12;
  short sStack_10;
  undefined2 uStack_e;
  
  for (iVar1 = 0; iVar1 < param_2; iVar1 = iVar1 + 1) {
    uStack_20 = *param_1;
    sStack_1e = param_1[1] + param_3;
    uStack_1c = param_1[2];
    uStack_1a = param_1[3];
    uStack_14 = param_1[4];
    uStack_12 = param_1[5];
    sStack_10 = param_1[6] + -1;
    uStack_e = param_1[7];
    uStack_18 = CONCAT22(param_1[8],param_1[9]);
    param_1 = param_1 + 10;
    func_0x001a2500(&uStack_20);
  }
  return;
}



================================================================