FUNCTION FUN_0000203c @ 0x0000203c size=1004
CALLERS (2): FUN_0000271c@0x0000271c, FUN_00002f5c@0x00002f5c
CALLEES (10): FUN_0000018c@0x0000018c, FUN_00003d40@0x00003d40, FUN_00001ed4@0x00001ed4, FUN_00001688@0x00001688, FUN_00001e2c@0x00001e2c, FUN_00001894@0x00001894, FUN_00001ff4@0x00001ff4, FUN_00001da4@0x00001da4, FUN_00001f64@0x00001f64, FUN_00003c6c@0x00003c6c

undefined4 FUN_0000203c(int param_1,int param_2)

{
  int iVar1;
  char *pcVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 local_a8 [32];
  undefined1 auStack_28 [16];
  
  uVar3 = *(undefined4 *)(param_1 + 8);
  uVar4 = *(undefined4 *)(param_1 + 0x10);
  if (param_2 == 3) {
    FUN_0000018c(uVar3,9,auStack_28,0x10);
    iVar1 = FUN_00003c6c(local_a8,0x80,auStack_28);
    if (iVar1 != 0) {
      local_a8[0] = DAT_00004650;
    }
    FUN_00003d40("inetctl: (ID=%d) [ %s ]\n",uVar3,local_a8);
LAB_00002100:
    *(int *)(param_1 + 0x10) = param_2;
    goto switchD_0000212c_caseD_4;
  }
  if (3 < param_2) {
    if (param_2 != 4) goto LAB_00002108;
LAB_0000228c:
    *(undefined4 *)(param_1 + 0x10) = 5;
    goto switchD_0000212c_caseD_4;
  }
  if (param_2 == 2) {
    FUN_00001e2c(uVar3);
    *(undefined4 *)(param_1 + 0x10) = 0;
    goto switchD_0000212c_caseD_4;
  }
LAB_00002108:
  switch(*(undefined4 *)(param_1 + 0x10)) {
  case 0:
    if (param_2 == 1) {
      *(undefined4 *)(param_1 + 0x10) = 5;
      iVar1 = FUN_00001da4(uVar3);
      *(int *)(param_1 + 0x18) = iVar1;
      if (iVar1 == 0) {
        FUN_00003d40("inetctl: (ID=%d)",uVar3);
        FUN_00003d40(" configuration for this I/F is not set yet\n");
        FUN_00001ed4(*(undefined4 *)(param_1 + 8),7);
      }
      else {
        FUN_00003d40("inetctl: (ID=%d)",uVar3);
        FUN_00003d40(" display_name=%s\n",*(undefined4 *)(*(int *)(param_1 + 0x18) + 8));
        if ((DAT_000045dc == 0) && (iVar1 = FUN_00001688(param_1), iVar1 == 0)) {
          *(undefined4 *)(param_1 + 0x10) = 1;
          FUN_00001ff4(*(undefined4 *)(param_1 + 8));
        }
        FUN_00001ed4(*(undefined4 *)(param_1 + 8),6);
      }
    }
    break;
  case 1:
    if (param_2 != 5) {
      iVar1 = FUN_0000018c(uVar3,0x10001,0,0);
      if (iVar1 == 0) {
        *(undefined4 *)(param_1 + 0x10) = 5;
      }
      break;
    }
    iVar1 = FUN_00001894(param_1);
    if (0 < iVar1) {
      FUN_0000018c(uVar3,0x10001,0,0);
      *(undefined4 *)(param_1 + 0x10) = 2;
      break;
    }
    goto LAB_00002100;
  case 2:
    if (param_2 != 10) {
      if (param_2 != 9) break;
      *(undefined4 *)(param_1 + 0x14) = 0xffffffff;
      goto LAB_0000228c;
    }
    *(undefined4 *)(param_1 + 0x14) = 0xffffffff;
    iVar1 = FUN_0000018c(uVar3,0x10000,0,0);
    goto LAB_000022d8;
  case 3:
    if ((param_2 == 9) && (iVar1 = FUN_0000018c(uVar3,0x10001,0,0), iVar1 == 0)) {
      *(undefined4 *)(param_1 + 0x10) = 4;
    }
    break;
  case 5:
    if (param_2 != 8) break;
    iVar1 = FUN_00001688(param_1);
LAB_000022d8:
    if (iVar1 == 0) {
      *(undefined4 *)(param_1 + 0x10) = 1;
      FUN_00001ff4(*(undefined4 *)(param_1 + 8));
    }
  }
switchD_0000212c_caseD_4:
  if (DAT_000045d8 != 0) {
    FUN_00003d40("inetctl: (ID=%d) ",uVar3);
    FUN_00001f64(uVar4);
    FUN_00003d40(&DAT_00004654);
    switch(param_2) {
    case 1:
      pcVar2 = s_Attach_00004658;
      break;
    case 2:
      pcVar2 = s_Detach_00004660;
      break;
    case 3:
      pcVar2 = s_Start_00004668;
      break;
    case 4:
      pcVar2 = &DAT_00004670;
      break;
    case 5:
      pcVar2 = s_Error_00004678;
      break;
    default:
      pcVar2 = &DAT_0000464c;
      break;
    case 8:
      pcVar2 = (char *)&PTR_DAT_00004680;
      break;
    case 9:
      pcVar2 = &DAT_00004684;
      break;
    case 10:
      pcVar2 = s_Retry_0000468c;
    }
    FUN_00003d40(pcVar2);
    FUN_00003d40(&DAT_00004694);
    FUN_00001f64(*(undefined4 *)(param_1 + 0x10));
    if (*(int *)(param_1 + 0x10) == 2) {
      FUN_00003d40(&DAT_00004698,*(undefined4 *)(param_1 + 0x14));
    }
    FUN_00003d40(&DAT_000046a0);
  }
  FUN_00001ed4(uVar3,param_2);
  return 0;
}


================================================================