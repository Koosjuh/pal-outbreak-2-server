FUNCTION FUN_0000e584 @ 0x0000e584 size=216
CALLERS (1): FUN_000008a4@0x000008a4
CALLEES (1): FUN_00014e24@0x00014e24

undefined4 FUN_0000e584(short param_1,short param_2,int *param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = (int)param_1;
  if (iVar2 < 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = 0;
    if (iVar2 <= DAT_000168e0) {
      iVar3 = (&DAT_00016190)[iVar2];
    }
  }
  if (iVar3 == 0) {
    uVar1 = 0xffffffff;
  }
  else {
    FUN_00014e24("entry %08x vendor %s product %s\n",iVar3,iVar3 + 0x30,iVar3 + 0x130);
    if (param_2 == 1) {
      *param_3 = iVar3 + 0x30;
    }
    else if (param_2 == 2) {
      *param_3 = iVar3 + 0x130;
    }
    else {
      *param_3 = 0;
    }
    uVar1 = 0;
  }
  return uVar1;
}


================================================================