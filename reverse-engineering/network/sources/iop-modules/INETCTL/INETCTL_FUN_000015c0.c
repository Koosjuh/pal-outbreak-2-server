FUNCTION FUN_000015c0 @ 0x000015c0 size=200
CALLERS (1): FUN_00001688@0x00001688
CALLEES (2): FUN_000002f0@0x000002f0, FUN_00003c7c@0x00003c7c

undefined4 FUN_000015c0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 local_18 [2];
  
  iVar3 = *(int *)(param_1 + 0x24);
  iVar2 = *(int *)(iVar3 + 4);
  iVar1 = FUN_000002f0(*(undefined4 *)(iVar3 + 8),0x10c,*(undefined4 *)(iVar2 + 0x13c));
  if (iVar1 != 0) {
    return 0xffffffff;
  }
  switch(*(undefined4 *)(iVar2 + 0x14c)) {
  case 1:
    local_18[0] = 0xcf;
    break;
  case 2:
    local_18[0] = 1;
    break;
  case 3:
    local_18[0] = 2;
    break;
  case 4:
    local_18[0] = 0x42;
    break;
  case 5:
    local_18[0] = 4;
    break;
  case 6:
    local_18[0] = 8;
    break;
  case 7:
    local_18[0] = 0x48;
    break;
  default:
    goto LAB_00001674;
  }
  FUN_00003c7c(*(undefined4 *)(iVar3 + 8),0x81020000,local_18,4);
LAB_00001674:
  return 0;
}


================================================================