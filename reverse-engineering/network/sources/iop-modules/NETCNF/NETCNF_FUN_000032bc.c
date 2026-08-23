FUNCTION FUN_000032bc @ 0x000032bc size=1008
CALLERS (1): FUN_000005b0@0x000005b0
CALLEES (24): FUN_00008940@0x00008940, FUN_00001ae0@0x00001ae0, FUN_00003988@0x00003988, FUN_00001750@0x00001750, FUN_00009650@0x00009650, FUN_00003060@0x00003060, FUN_000096f4@0x000096f4, FUN_000016e8@0x000016e8, FUN_00001bf4@0x00001bf4, FUN_000013a0@0x000013a0, FUN_00002050@0x00002050, FUN_00000000@0x00000000, FUN_000020b0@0x000020b0, FUN_00009638@0x00009638, FUN_00001ba8@0x00001ba8, FUN_0000141c@0x0000141c, FUN_00008614@0x00008614, FUN_000096ec@0x000096ec, FUN_00007c9c@0x00007c9c, FUN_000088ac@0x000088ac, FUN_00001cdc@0x00001cdc, FUN_00009658@0x00009658, FUN_00001560@0x00001560, FUN_000094b8@0x000094b8

int FUN_000032bc(undefined4 param_1,int param_2,undefined4 param_3,int param_4,undefined4 *param_5,
                undefined4 param_6,undefined4 param_7,int param_8)

{
  char cVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  undefined4 uVar5;
  undefined1 auStack_228 [256];
  char acStack_128 [256];
  
  iVar2 = FUN_00000000();
  if ((iVar2 != 0) && (iVar2 = FUN_000088ac(param_5,param_2), iVar2 < 0)) {
    return iVar2;
  }
  iVar2 = FUN_00001ae0(&DAT_0000bef8,0x100,param_1);
  if (iVar2 < 0) {
    return iVar2;
  }
  if ((param_8 == 0) && (iVar2 = FUN_000016e8(&DAT_0000bef8), iVar2 < 0)) {
    return iVar2;
  }
  iVar2 = FUN_00001750(param_2,&DAT_0000bef8,&DAT_0000c0f8,0x100,param_3);
  if (iVar2 < 0) {
    return iVar2;
  }
  iVar2 = FUN_000020b0(&DAT_0000bef8,&DAT_0000ab70);
  if (iVar2 < 1) {
    if (iVar2 != 0) {
      return iVar2;
    }
    return -3;
  }
  iVar2 = FUN_00001cdc(&DAT_0000bef8,DAT_0000ab70,param_6,param_7);
  if (-1 < iVar2) {
    iVar2 = 0;
    cVar1 = *DAT_0000ab70;
    pcVar4 = DAT_0000ab70;
    while (cVar1 != '\0') {
      iVar3 = FUN_00002050(param_2,pcVar4);
      if ((0 < iVar3) && (iVar3 = FUN_00001bf4(&DAT_0000b5f8,pcVar4,3), iVar3 == 0)) {
        iVar3 = FUN_00009638(&DAT_0000b5f8,&DAT_0000c0f8);
        if ((iVar3 == 0) && (iVar3 = FUN_00001bf4(auStack_228,pcVar4,2), iVar3 == 0)) {
          iVar2 = iVar2 + 1;
        }
      }
      pcVar4 = (char *)FUN_00001ba8(pcVar4);
      cVar1 = *pcVar4;
    }
    if (iVar2 == 0) {
      iVar2 = -8;
    }
    else {
      iVar3 = FUN_00000000();
      if (iVar3 != 0) {
        iVar2 = FUN_00008940(&DAT_0000bef8,auStack_228,acStack_128);
        if (iVar2 == 0) {
          iVar2 = -0xb;
          goto LAB_000035ec;
        }
        iVar2 = FUN_00008614(acStack_128,param_2,param_5[8],param_5[9]);
        if (iVar2 < 0) goto LAB_000035ec;
      }
      FUN_00001560(acStack_128,0x100,auStack_228,&DAT_000099f0);
      *param_5 = &DAT_0000bef8;
      param_5[1] = acStack_128;
      if (param_2 == 0) {
        uVar5 = 1;
      }
      else {
        uVar5 = 2;
      }
      param_5[5] = uVar5;
      iVar3 = FUN_00007c9c(param_5);
      if (iVar3 == 0) {
        FUN_000013a0(acStack_128,0x100,&DAT_0000bef8,0x3ef);
        iVar3 = FUN_00009650(acStack_128);
        for (pcVar4 = acStack_128 + iVar3; pcVar4 != acStack_128; pcVar4 = pcVar4 + -1) {
          if ((*pcVar4 == '/') || (*pcVar4 == '\\')) {
            pcVar4[1] = '\0';
            break;
          }
        }
        FUN_0000141c(acStack_128,0x100,auStack_228,0x3f6);
        FUN_000013a0(auStack_228,0x100,acStack_128,0x3f7);
        FUN_0000141c(acStack_128,0x100,&DAT_000099f0,0x3f8);
        iVar3 = FUN_000096ec(acStack_128,auStack_228);
        if (iVar3 == -5) {
          iVar2 = -0x12;
        }
      }
      else {
        iVar2 = -1;
      }
    }
  }
LAB_000035ec:
  FUN_000094b8(DAT_0000ab70);
  if ((-1 < iVar2) && (FUN_00003988(&DAT_0000bef8,param_2,&DAT_0000c0f8), param_4 != 0)) {
    iVar2 = FUN_00003060(&DAT_0000bef8,param_2,&DAT_0000c0f8,param_4);
  }
  iVar3 = FUN_00009658(&DAT_0000bef8,&DAT_0000997c,3);
  if ((iVar3 == 0) && (iVar3 = FUN_000096f4(&DAT_0000bef8,0), iVar3 == -5)) {
    iVar2 = -0x12;
  }
  return iVar2;
}


================================================================