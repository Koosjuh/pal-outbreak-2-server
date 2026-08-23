FUNCTION FUN_00000e40 @ 0x00000e40 size=324
CALLERS (0): 
CALLEES (9): FUN_00004efc@0x00004efc, FUN_00004f7c@0x00004f7c, FUN_00004e7c@0x00004e7c, FUN_00004cdc@0x00004cdc, FUN_000028b8@0x000028b8, FUN_00007cf4@0x00007cf4, FUN_00002978@0x00002978, FUN_000029f8@0x000029f8, FUN_000028f8@0x000028f8

uint FUN_00000e40(undefined4 param_1,undefined4 param_2)

{
  short sVar1;
  uint uVar2;
  int iVar3;
  
  if (DAT_000096d4 == 0) {
    switch(param_1) {
    case 0:
      goto switchD_00000e90_caseD_0;
    case 1:
      uVar2 = FUN_000028f8(DAT_00009708,param_2);
      uVar2 = ~uVar2;
      break;
    case 2:
      uVar2 = FUN_00002978(DAT_00009708,param_2);
      uVar2 = ~uVar2;
      break;
    case 3:
      uVar2 = FUN_000029f8(DAT_00009708,param_2);
      uVar2 = ~uVar2;
      break;
    case 4:
      iVar3 = FUN_000028b8(DAT_00009708);
      goto LAB_00000f64;
    default:
      goto switchD_00000e90_default;
    }
  }
  else {
    sVar1 = FUN_00007cf4();
    iVar3 = (int)sVar1;
    switch(param_1) {
    case 0:
switchD_00000e90_caseD_0:
      return 1;
    case 1:
      uVar2 = FUN_00004e7c(iVar3,param_2);
      uVar2 = ~uVar2;
      break;
    case 2:
      uVar2 = FUN_00004efc(iVar3,param_2);
      uVar2 = ~uVar2;
      break;
    case 3:
      uVar2 = FUN_00004f7c(iVar3,param_2);
      uVar2 = ~uVar2;
      break;
    case 4:
      iVar3 = FUN_00004cdc(iVar3);
LAB_00000f64:
      return (uint)(iVar3 == 2);
    default:
switchD_00000e90_default:
      return 0;
    }
  }
  return uVar2 >> 0x1f;
}


================================================================