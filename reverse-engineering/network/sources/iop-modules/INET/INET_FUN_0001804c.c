FUNCTION FUN_0001804c @ 0x0001804c size=292
CALLERS (1): FUN_00018170@0x00018170
CALLEES (6): FUN_0000e588@0x0000e588, FUN_0000a494@0x0000a494, FUN_00018170@0x00018170, FUN_0000d31c@0x0000d31c, FUN_0000d2c0@0x0000d2c0, FUN_00009eec@0x00009eec

void FUN_0001804c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined2 param_4,
                 undefined4 param_5,undefined2 param_6)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  
  uVar1 = FUN_0000d2c0();
  piVar2 = (int *)FUN_0000e588();
  do {
    if (piVar2 == (int *)0x0) {
LAB_00018134:
      FUN_0000d31c(uVar1);
      FUN_00009eec(param_1);
      return;
    }
    if ((piVar2[0x12] & 0x16U) == 0x16) {
      iVar3 = FUN_0000a494(param_1);
      uVar4 = 0;
      if (iVar3 == 0) {
        *(int *)(piVar2[0x68] + 0x48) = *(int *)(piVar2[0x68] + 0x48) + 1;
        goto LAB_00018134;
      }
      *(int *)(piVar2[0x68] + 0x40) = *(int *)(piVar2[0x68] + 0x40) + 1;
      if (piVar2 != (int *)0x0) {
        uVar4 = piVar2[0x1c];
      }
      FUN_00018170(piVar2,iVar3,param_2,uVar4,param_4,param_5,param_6);
    }
    piVar2 = (int *)*piVar2;
  } while( true );
}


================================================================