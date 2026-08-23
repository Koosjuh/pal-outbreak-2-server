FUNCTION FUN_00010cc0 @ 0x00010cc0 size=276
CALLERS (0): 
CALLEES (5): FUN_00010418@0x00010418, FUN_0000d31c@0x0000d31c, FUN_0000a9c0@0x0000a9c0, FUN_00010bd0@0x00010bd0, FUN_0000d2c0@0x0000d2c0

undefined4 FUN_00010cc0(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  
  uVar4 = 0xfffffe00;
  iVar1 = FUN_00010bd0();
  uVar2 = FUN_0000d2c0();
  if (iVar1 == 0) {
    if (param_2 == 0x280) {
      if (param_4 != 4) goto LAB_00010d9c;
      puVar3 = &DAT_0001b9d4;
    }
    else {
      if ((param_2 != 0x281) || (param_4 != 4)) goto LAB_00010d9c;
      puVar3 = &DAT_0001b9d8;
    }
    FUN_0000a9c0(puVar3,param_3,4);
    uVar4 = 0;
  }
  else if (param_2 < 0) {
    uVar4 = (**(code **)(iVar1 + 0x6c))(*(undefined4 *)(iVar1 + 0x44),param_2,param_3,param_4);
  }
  else {
    uVar4 = FUN_00010418(iVar1,param_2,param_3,param_4);
  }
LAB_00010d9c:
  FUN_0000d31c(uVar2);
  return uVar4;
}


================================================================