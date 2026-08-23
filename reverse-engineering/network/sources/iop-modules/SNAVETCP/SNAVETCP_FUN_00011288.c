FUNCTION FUN_00011288 @ 0x00011288 size=100
CALLERS (1): FUN_00000720@0x00000720
CALLEES (0): 

undefined4 FUN_00011288(short *param_1)

{
  undefined4 uVar1;
  
  if ((*param_1 == 1) && (3 < (ushort)param_1[1])) {
    **(int **)(param_1 + 2) = (int)DAT_00016194;
    uVar1 = 4;
  }
  else {
    uVar1 = 0xfffffff3;
  }
  return uVar1;
}


================================================================