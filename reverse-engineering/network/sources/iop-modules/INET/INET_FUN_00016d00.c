FUNCTION FUN_00016d00 @ 0x00016d00 size=232
CALLERS (11): FUN_0001493c@0x0001493c, FUN_00014eb8@0x00014eb8, FUN_00014fd8@0x00014fd8, FUN_0001380c@0x0001380c, FUN_000151ec@0x000151ec, FUN_00014c8c@0x00014c8c, FUN_000150c8@0x000150c8, FUN_00016de8@0x00016de8, FUN_00015a28@0x00015a28, FUN_000161ec@0x000161ec, FUN_00014df8@0x00014df8
CALLEES (5): FUN_00013264@0x00013264, FUN_00012bc0@0x00012bc0, FUN_0000d8cc@0x0000d8cc, FUN_000100c4@0x000100c4, FUN_00012c00@0x00012c00

undefined4 FUN_00016d00(int param_1,int param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_1 == 0) {
    return 0xfffffe04;
  }
  *(uint *)(param_1 + 0x2c) = *(uint *)(param_1 + 0x2c) | 0x800000;
  FUN_00012bc0();
  FUN_00012c00(param_1);
  *(int *)(param_1 + 0x30) = param_2;
  switch(*(undefined4 *)(param_1 + 0x28)) {
  case 0:
    uVar1 = 0xfffffe04;
    goto switchD_00016d68_default;
  case 1:
  case 2:
switchD_00016d68_caseD_1:
    if (param_2 != -0x1f5) goto LAB_00016da8;
    break;
  case 3:
  case 4:
  case 5:
  case 6:
  case 7:
    if (param_2 == -0x1f5) {
      FUN_00013264(param_1,4,*(undefined4 *)(param_1 + 0x3c),0,0);
      goto switchD_00016d68_caseD_1;
    }
LAB_00016da8:
    *(undefined4 *)(param_1 + 0x30) = 0xfffffe02;
    break;
  case 8:
  case 9:
  case 10:
    break;
  default:
    goto switchD_00016d68_default;
  }
  *(undefined4 *)(param_1 + 0x28) = 0;
switchD_00016d68_default:
  FUN_0000d8cc(param_1 + 0xcc);
  FUN_000100c4();
  return uVar1;
}


================================================================