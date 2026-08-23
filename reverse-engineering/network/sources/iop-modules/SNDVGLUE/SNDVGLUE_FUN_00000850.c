FUNCTION FUN_00000850 @ 0x00000850 size=548
CALLERS (0): 
CALLEES (7): FUN_0000031c@0x0000031c, FUN_00001068@0x00001068, FUN_00005354@0x00005354, FUN_00000f90@0x00000f90, FUN_00000440@0x00000440, FUN_00004ffc@0x00004ffc, FUN_000050f4@0x000050f4

int FUN_00000850(undefined4 param_1,undefined4 *param_2,uint param_3)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *local_c;
  
  iVar4 = -1;
  switch(param_1) {
  case 1:
    if (3 < param_3) {
      *param_2 = DAT_00009704;
      iVar4 = 4;
    }
    break;
  case 2:
    if (3 < param_3) {
      *param_2 = DAT_00009700;
      iVar4 = 4;
    }
    break;
  case 3:
    if (param_3 == 4) {
      uVar3 = FUN_00000f90();
      *param_2 = uVar3;
      iVar4 = 4;
    }
    break;
  case 4:
  case 5:
    iVar4 = FUN_00001068(param_1,param_2);
    break;
  case 6:
    if ((0x30b < param_3) && ((&DAT_00009718)[DAT_00009708] != 0)) {
      FUN_0000031c(DAT_00009708,param_2);
      iVar4 = 0x30c;
    }
    break;
  case 7:
    if ((0x30b < param_3) && ((&DAT_00009720)[DAT_0000970c] != 0)) {
      FUN_00000440(DAT_0000970c,param_2);
      iVar4 = 0x30c;
    }
    break;
  case 8:
    if (3 < param_3) {
      uVar3 = FUN_000050f4(DAT_0000970c);
      iVar4 = 4;
      *param_2 = uVar3;
    }
    break;
  case 9:
    if ((3 < param_3) && (iVar4 = FUN_00005354(DAT_0000970c,param_2), -1 < iVar4)) {
      iVar4 = 4;
    }
    break;
  case 10:
    if ((5 < (int)param_3) && (iVar4 = FUN_00004ffc(DAT_0000970c,&local_c), iVar4 == 0)) {
      uVar1 = *(undefined1 *)(local_c + 1);
      uVar2 = *(undefined1 *)((int)local_c + 5);
      *param_2 = *local_c;
      *(undefined1 *)(param_2 + 1) = uVar1;
      *(undefined1 *)((int)param_2 + 5) = uVar2;
    }
  }
  return iVar4;
}


================================================================