FUNCTION FUN_000009c0 @ 0x000009c0 size=172
CALLERS (1): FUN_00002098@0x00002098
CALLEES (3): FUN_000029bc@0x000029bc, FUN_0000293c@0x0000293c, FUN_000029c4@0x000029c4

void FUN_000009c0(int param_1)

{
  undefined2 uVar1;
  short sVar2;
  undefined4 uVar3;
  
  FUN_000029c4(DAT_00004db0);
  uVar3 = DAT_00004a2c;
  sVar2 = DAT_00004a28;
  uVar1 = DAT_00004a26;
  if (DAT_00004a24 == 0) {
    *(undefined4 *)(param_1 + 0x18) = 0;
  }
  else {
    *(int *)(param_1 + 0x18) = (int)DAT_00004a24;
    *(undefined2 *)(param_1 + 0x1c) = uVar1;
    *(short *)(param_1 + 0x1e) = sVar2;
    *(undefined4 *)(param_1 + 0x20) = uVar3;
    FUN_0000293c(param_1 + 0x24,&DAT_00004a30,(int)sVar2);
    DAT_00004a24 = 0;
  }
  FUN_000029bc(DAT_00004db0);
  return;
}


================================================================