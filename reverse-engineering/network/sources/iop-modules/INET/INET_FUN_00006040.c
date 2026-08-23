FUNCTION FUN_00006040 @ 0x00006040 size=104
CALLERS (1): FUN_000060a8@0x000060a8
CALLEES (0): 

int FUN_00006040(int param_1,ushort *param_2,uint param_3)

{
  ushort uVar1;
  uint uVar2;
  
  uVar1 = *param_2;
  for (param_3 = param_3 >> 4; param_3 != 0; param_3 = param_3 - 1) {
    uVar2 = (uint)uVar1;
    uVar1 = param_2[8];
    param_1 = param_1 + uVar2 + (uint)param_2[1] + (uint)param_2[2] + (uint)param_2[3] +
              (uint)param_2[4] + (uint)param_2[5] + (uint)param_2[6] + (uint)param_2[7];
    param_2 = param_2 + 8;
  }
  return param_1;
}


================================================================