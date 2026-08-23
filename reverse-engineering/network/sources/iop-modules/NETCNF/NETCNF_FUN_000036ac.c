FUNCTION FUN_000036ac @ 0x000036ac size=732
CALLERS (1): FUN_00000678@0x00000678
CALLEES (15): FUN_00001ae0@0x00001ae0, FUN_00001750@0x00001750, FUN_00002220@0x00002220, FUN_000096f4@0x000096f4, FUN_000016e8@0x000016e8, FUN_00001bf4@0x00001bf4, FUN_00002050@0x00002050, FUN_000020b0@0x000020b0, FUN_00009638@0x00009638, FUN_00001ba8@0x00001ba8, FUN_00009470@0x00009470, FUN_00001cdc@0x00001cdc, FUN_00009658@0x00009658, FUN_000020f4@0x000020f4, FUN_000094b8@0x000094b8

int FUN_000036ac(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5,int param_6)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  int iVar6;
  char *pcVar7;
  
  bVar2 = false;
  DAT_0000ab74 = (char *)0x0;
  iVar3 = FUN_00001ae0(&DAT_0000bef8,0x100,param_1);
  if ((-1 < iVar3) &&
     (((param_6 != 0 || (iVar3 = FUN_000016e8(&DAT_0000bef8), -1 < iVar3)) &&
      (iVar3 = FUN_00001750(param_2,&DAT_0000bef8,&DAT_0000bff8,0x100,param_3), -1 < iVar3)))) {
    iVar3 = FUN_000020b0(&DAT_0000bef8,&DAT_0000ab74);
    if (iVar3 < 1) {
      if (iVar3 == 0) {
        iVar3 = -3;
      }
    }
    else {
      pcVar4 = (char *)FUN_00009470(iVar3);
      if (pcVar4 == (char *)0x0) {
        FUN_000094b8(DAT_0000ab74);
        iVar3 = -2;
      }
      else {
        iVar3 = FUN_00001cdc(&DAT_0000bef8,DAT_0000ab74,param_4,param_5);
        if (-1 < iVar3) {
          cVar1 = *DAT_0000ab74;
          pcVar7 = pcVar4;
          pcVar5 = DAT_0000ab74;
joined_r0x000037ec:
          if (cVar1 != '\0') {
            iVar3 = FUN_00002050(param_2,pcVar5);
            if (((iVar3 < 1) || (iVar3 = FUN_00001bf4(&DAT_0000b5f8,pcVar5,3), iVar3 != 0)) ||
               (iVar3 = FUN_00009638(&DAT_0000b5f8,&DAT_0000bff8), iVar3 != 0)) goto LAB_00003884;
            iVar3 = FUN_00001bf4(&DAT_0000b9f8,pcVar5,2);
            if (iVar3 == 0) {
              bVar2 = true;
            }
            pcVar5 = (char *)FUN_00001ba8(pcVar5);
            goto LAB_000038b4;
          }
          iVar3 = FUN_000020f4(&DAT_0000bef8,pcVar4,(int)pcVar7 - (int)pcVar4);
          if ((-1 < iVar3) && (bVar2)) {
            iVar3 = FUN_00002220(&DAT_0000bef8,&DAT_0000b9f8);
          }
        }
        FUN_000094b8(DAT_0000ab74);
        FUN_000094b8(pcVar4);
        iVar6 = FUN_00009658(&DAT_0000bef8,&DAT_0000997c,3);
        if ((iVar6 == 0) && (iVar6 = FUN_000096f4(&DAT_0000bef8,0), iVar6 == -5)) {
          iVar3 = -0x12;
        }
      }
    }
  }
  return iVar3;
LAB_00003884:
  for (; *pcVar5 != '\0'; pcVar5 = pcVar5 + 1) {
    if (*pcVar5 == '\n') goto LAB_000038a4;
    *pcVar7 = *pcVar5;
    pcVar7 = pcVar7 + 1;
  }
  cVar1 = *pcVar5;
  if (cVar1 == '\n') {
LAB_000038a4:
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
    *pcVar7 = cVar1;
    pcVar7 = pcVar7 + 1;
LAB_000038b4:
    cVar1 = *pcVar5;
  }
  goto joined_r0x000037ec;
}


================================================================