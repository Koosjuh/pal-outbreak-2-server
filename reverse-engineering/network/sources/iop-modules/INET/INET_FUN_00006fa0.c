FUNCTION FUN_00006fa0 @ 0x00006fa0 size=252
CALLERS (1): FUN_0000709c@0x0000709c
CALLEES (6): FUN_0000709c@0x0000709c, FUN_0000d2c0@0x0000d2c0, FUN_0000e588@0x0000e588, FUN_0000d31c@0x0000d31c, FUN_00009eec@0x00009eec, FUN_0000a494@0x0000a494

void FUN_00006fa0(undefined2 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  
  uVar1 = FUN_0000d2c0();
  for (piVar2 = (int *)FUN_0000e588(); piVar2 != (int *)0x0; piVar2 = (int *)*piVar2) {
    if ((piVar2[0x12] & 0x16U) == 0x16) {
      iVar3 = FUN_0000a494(param_4);
      uVar4 = 0;
      if (iVar3 == 0) break;
      *(int *)(piVar2[0x68] + 0x20) = *(int *)(piVar2[0x68] + 0x20) + 1;
      if (piVar2 != (int *)0x0) {
        uVar4 = piVar2[0x1c];
      }
      FUN_0000709c(piVar2,uVar4,0xffffffff,param_1,param_2,param_3,iVar3,0);
    }
  }
  FUN_0000d31c(uVar1);
  FUN_00009eec(param_4);
  return;
}


================================================================