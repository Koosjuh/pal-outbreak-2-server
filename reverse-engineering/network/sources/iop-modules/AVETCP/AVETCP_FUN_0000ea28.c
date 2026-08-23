FUNCTION FUN_0000ea28 @ 0x0000ea28 size=316
CALLERS (1): FUN_00004314@0x00004314
CALLEES (5): FUN_00013260@0x00013260, FUN_0000eb64@0x0000eb64, FUN_00012cb0@0x00012cb0, FUN_00012558@0x00012558, FUN_00012530@0x00012530

int FUN_0000ea28(undefined4 param_1,short param_2)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = (int)param_2;
  if (iVar3 < 0) {
    iVar4 = 0;
  }
  else {
    iVar4 = 0;
    if (iVar3 <= DAT_000168e0) {
      iVar4 = (&DAT_00016190)[iVar3];
    }
  }
  iVar3 = -1;
  if (iVar4 != 0) {
    FUN_00012530();
    DAT_00016ed4 = FUN_00012cb0(0,0x5ea,0);
    if (DAT_00016ed4 == 0) {
      FUN_00012558();
      iVar3 = -1;
    }
    else {
      iVar3 = FUN_00013260();
      if (*(int *)(iVar3 + 8) != 0) {
        DAT_00016ed4 = DAT_00016ed4 + 2;
      }
      iVar2 = FUN_0000eb64(DAT_00016ed4,param_1);
      iVar3 = -0x10000;
      if (iVar2 != 0) {
        uVar1 = (**(code **)(iVar4 + 0x1c))((int)*(short *)(iVar4 + 4),DAT_00016ed4);
        if (uVar1 == 0) {
          uVar1 = 0;
        }
        iVar3 = (uint)uVar1 << 0x10;
      }
      iVar3 = iVar3 >> 0x10;
      FUN_00012558();
    }
  }
  return iVar3;
}


================================================================