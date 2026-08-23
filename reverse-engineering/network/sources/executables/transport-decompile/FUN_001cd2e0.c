
void FUN_001cd2e0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  FUN_00106b60(0x36c420,0,0x140);
  FUN_00106b60(0x36c350,0,0xc0);
  piVar4 = *(int **)(param_1 + 0x14);
  iVar6 = 0x36c350;
  iVar5 = 0x36c420;
  iVar7 = 0;
  iVar3 = *(int *)(param_1 + 0x14) + 0x14680;
  piRam0036c410 = piVar4;
  do {
    FUN_00106b60(iVar6,0,0xc);
    FUN_00106b60(piVar4,0,0x1468);
    *piVar4 = (int)(piVar4 + 0x208);
    iVar2 = 0;
    piVar4[1] = (int)(piVar4 + 0x288);
    piVar4[0x206] = (int)(piVar4 + 0x308);
    piVar4[0x202] = iVar3;
    *(char *)(iVar6 + 1) = (char)iVar7;
    iVar3 = iVar3 + 0x1300;
    *(int **)(iVar6 + 4) = piVar4;
    *(char *)(iVar5 + 0xe) = (char)iVar7;
    do {
      iVar1 = iVar2 * 2;
      iVar2 = iVar2 + 1;
      *(undefined2 *)(iVar5 + iVar1 + 2) = 0xffff;
    } while (iVar2 < 6);
    iVar7 = iVar7 + 1;
    iVar6 = iVar6 + 0xc;
    piVar4 = piVar4 + 0x51a;
    iVar5 = iVar5 + 0x14;
  } while (iVar7 < 0x10);
  FUN_00106b60(0x36c310,0,0x40);
  iVar5 = 0x36c310;
  iVar3 = 0;
  iVar6 = *(int *)(param_1 + 0x14) + 0x27680;
  do {
    *(int *)(iVar5 + 4) = iVar6;
    FUN_00106b60(*(undefined4 *)(iVar5 + 4),0,0x1000);
    *(char *)(iVar5 + 1) = (char)iVar3;
    iVar6 = iVar6 + 0x1000;
    iVar3 = iVar3 + 1;
    iVar5 = iVar5 + 0x10;
  } while (iVar3 < 4);
  return;
}

