FUNCTION FUN_00003988 @ 0x00003988 size=708
CALLERS (2): FUN_0000071c@0x0000071c, FUN_000032bc@0x000032bc
CALLEES (12): FUN_00001ae0@0x00001ae0, FUN_00009638@0x00009638, FUN_00009610@0x00009610, FUN_00001750@0x00001750, FUN_000096f4@0x000096f4, FUN_00001bf4@0x00001bf4, FUN_00002050@0x00002050, FUN_00009470@0x00009470, FUN_000020b0@0x000020b0, FUN_00009658@0x00009658, FUN_000020f4@0x000020f4, FUN_000094b8@0x000094b8

int FUN_00003988(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  int iVar8;
  char *pcVar9;
  
  bVar2 = false;
  iVar3 = FUN_00001ae0(&DAT_0000bef8,0x100,param_1);
  if (-1 < iVar3) {
    iVar3 = FUN_00001750(param_2,&DAT_0000bef8,&DAT_0000bff8,0x100,param_3);
    pcVar9 = (char *)0x0;
    if (-1 < iVar3) {
      DAT_0000ab78 = (char *)0x0;
      iVar3 = FUN_000020b0(&DAT_0000bef8,&DAT_0000ab78);
      if (iVar3 < 1) {
        if (iVar3 == 0) {
          iVar3 = -3;
        }
      }
      else {
        pcVar4 = (char *)FUN_00009470(iVar3);
        iVar8 = -2;
        if ((pcVar4 != (char *)0x0) && (pcVar9 = (char *)FUN_00009470(iVar3), pcVar9 != (char *)0x0)
           ) {
          cVar1 = *DAT_0000ab78;
          iVar8 = 0;
          pcVar7 = pcVar4;
          pcVar6 = pcVar9;
          pcVar5 = DAT_0000ab78;
joined_r0x00003a74:
          if (cVar1 != '\0') {
            iVar3 = FUN_00002050(param_2,pcVar5);
            if (((iVar3 < 1) || (iVar3 = FUN_00001bf4(&DAT_0000b5f8,pcVar5,3), iVar3 != 0)) ||
               (iVar3 = FUN_00009638(&DAT_0000b5f8,&DAT_0000bff8), iVar3 != 0)) goto LAB_00003b44;
            for (; *pcVar5 != '\0'; pcVar5 = pcVar5 + 1) {
              if (*pcVar5 == '\n') goto LAB_00003b08;
              *pcVar7 = *pcVar5;
              pcVar7 = pcVar7 + 1;
            }
            if (*pcVar5 == '\n') {
LAB_00003b08:
              cVar1 = *pcVar5;
              pcVar5 = pcVar5 + 1;
              *pcVar7 = cVar1;
              pcVar7 = pcVar7 + 1;
            }
            iVar8 = iVar8 + 1;
            if (pcVar9 < pcVar6) {
              bVar2 = true;
            }
            goto LAB_00003b74;
          }
          if (bVar2) {
            FUN_00009610(pcVar9,pcVar7,(int)pcVar6 - (int)pcVar9);
            iVar8 = FUN_000020f4(&DAT_0000bef8,pcVar4,
                                 pcVar7 + (((int)pcVar6 - (int)pcVar9) - (int)pcVar4));
          }
        }
        iVar3 = iVar8;
        FUN_000094b8(DAT_0000ab78);
        FUN_000094b8(pcVar4);
        FUN_000094b8(pcVar9);
        iVar8 = FUN_00009658(&DAT_0000bef8,&DAT_0000997c,3);
        if ((iVar8 == 0) && (iVar8 = FUN_000096f4(&DAT_0000bef8,0), iVar8 == -5)) {
          iVar3 = -0x12;
        }
      }
    }
  }
  return iVar3;
LAB_00003b44:
  for (; *pcVar5 != '\0'; pcVar5 = pcVar5 + 1) {
    if (*pcVar5 == '\n') goto LAB_00003b64;
    *pcVar6 = *pcVar5;
    pcVar6 = pcVar6 + 1;
  }
  cVar1 = *pcVar5;
  if (cVar1 == '\n') {
LAB_00003b64:
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
    *pcVar6 = cVar1;
    pcVar6 = pcVar6 + 1;
LAB_00003b74:
    cVar1 = *pcVar5;
  }
  goto joined_r0x00003a74;
}


================================================================