
int FUN_001801b0(undefined8 param_1,uint param_2)

{
  uint uVar1;
  undefined8 uVar2;
  long lVar3;
  int iVar4;
  uint *puVar5;
  uint uVar6;
  uint *puVar7;
  
  uVar6 = 0;
  while ((uVar6 < 0x280 && (*(int *)(iRam0027e5a8 + uVar6 * 0x180 + 4) != 0))) {
    uVar6 = uVar6 + 1;
  }
  puVar5 = (uint *)(iRam0027e5a8 + uVar6 * 0x180);
  FUN_001840a0(puVar5,0,0x180);
  puVar7 = (uint *)param_1;
  puVar5[1] = *puVar7;
  puVar5[2] = puVar7[3];
  *puVar5 = param_2;
  puVar5[0x14] = 0;
  puVar5[0x15] = 0;
  if ((param_2 & 4) == 0) {
    puVar5[4] = 0x30;
    puVar5[4] = puVar5[4] + (puVar7[7] + 0xf & 0xfffffff0);
    puVar5[4] = puVar5[4] + (puVar7[6] + 0xf & 0xfffffff0);
    uVar1 = FUN_00184170(puVar5[4],3);
    puVar5[5] = uVar1;
    uVar2 = thunk_FUN_00197ad0(puVar5[5]);
    FUN_001840d0(uVar2,param_1,0x24);
    iVar4 = (int)uVar2 + 0x30;
    FUN_001840d0(iVar4,puVar7[2],puVar7[7]);
    FUN_001840d0(iVar4 + (puVar7[7] + 0xf & 0xfffffff0),puVar7[4],puVar7[6]);
  }
  puVar5[3] = uRam0028a3f0;
  lVar3 = FUN_00180340(puVar5,param_1);
  if (lVar3 == 0) {
    FUN_001829c0(uVar6 + 1);
    iVar4 = 0;
  }
  else {
    iVar4 = uVar6 + 1;
  }
  return iVar4;
}

