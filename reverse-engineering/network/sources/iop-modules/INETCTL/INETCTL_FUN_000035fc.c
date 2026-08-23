FUNCTION FUN_000035fc @ 0x000035fc size=1180
CALLERS (1): FUN_00003ad0@0x00003ad0
CALLEES (14): FUN_00003d40@0x00003d40, FUN_00003e70@0x00003e70, FUN_00003e2c@0x00003e2c, FUN_00002540@0x00002540, FUN_00003e24@0x00003e24, FUN_00003d64@0x00003d64, FUN_00003d84@0x00003d84, FUN_00003e68@0x00003e68, FUN_00003d9c@0x00003d9c, FUN_00003dc0@0x00003dc0, FUN_00003dc8@0x00003dc8, FUN_00000000@0x00000000, FUN_00003dd0@0x00003dd0, FUN_00003d94@0x00003d94

int FUN_000035fc(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  char *pcVar5;
  int *piVar6;
  undefined4 local_50;
  undefined4 local_4c;
  code *local_48;
  int local_44;
  int local_40;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  piVar6 = (int *)(param_2 + 4);
  while (param_1 = param_1 + -1, 0 < param_1) {
    iVar2 = FUN_00003d84(s__help_000046ac,*piVar6);
    if (iVar2 == 0) goto LAB_000038c8;
    iVar2 = FUN_00003d84("-no_check_magic",*piVar6);
    if (iVar2 == 0) {
      DAT_000045d0 = 1;
    }
    else {
      iVar2 = FUN_00003d84("-no_decode",*piVar6);
      if (iVar2 == 0) {
        DAT_000045d4 = 1;
      }
      else {
        iVar2 = FUN_00003d84("-no_auto",*piVar6);
        if (iVar2 == 0) {
          DAT_000045dc = 1;
        }
        else {
          iVar2 = FUN_00003d84("-verbose",*piVar6);
          if (iVar2 == 0) {
            DAT_000045d8 = 1;
          }
          else {
            iVar2 = FUN_00003d94(s_pool__000046b4,*piVar6,5);
            if (iVar2 == 0) {
              iVar2 = *piVar6;
              pcVar5 = (char *)(iVar2 + 5);
              uVar3 = FUN_00003d64((int)*(char *)(iVar2 + 5));
              if ((uVar3 & 4) == 0) goto LAB_000038c8;
              DAT_000045e8 = FUN_00003d9c(pcVar5,0,10);
              cVar1 = *(char *)(iVar2 + 5);
              while ((cVar1 != '\0' && (uVar3 = FUN_00003d64((int)*pcVar5), (uVar3 & 4) != 0))) {
                pcVar5 = pcVar5 + 1;
                cVar1 = *pcVar5;
              }
              iVar2 = FUN_00003d84(pcVar5,&DAT_000046bc);
              if (iVar2 == 0) {
                DAT_000045e8 = DAT_000045e8 << 10;
              }
              else {
LAB_000038b8:
                cVar1 = *pcVar5;
LAB_000038c0:
                if (cVar1 != '\0') goto LAB_000038c8;
              }
            }
            else {
              iVar2 = FUN_00003d94(s_thpri__000046c0,*piVar6,6);
              if (iVar2 == 0) {
                iVar2 = *piVar6;
                pcVar5 = (char *)(iVar2 + 6);
                uVar3 = FUN_00003d64((int)*(char *)(iVar2 + 6));
                if (((uVar3 & 4) == 0) ||
                   (DAT_000045c8 = FUN_00003d9c(pcVar5,0,10), 0x72 < DAT_000045c8 - 9U))
                goto LAB_000038c8;
                if (*(char *)(iVar2 + 6) != '\0') {
                  do {
                    uVar3 = FUN_00003d64((int)*pcVar5);
                    if ((uVar3 & 4) == 0) goto LAB_000038b8;
                    pcVar5 = pcVar5 + 1;
                    cVar1 = '\0';
                  } while (*pcVar5 != '\0');
                  goto LAB_000038c0;
                }
              }
              else {
                iVar2 = FUN_00003d94("thstack=",*piVar6,8);
                if (iVar2 != 0) break;
                iVar2 = *piVar6;
                pcVar5 = (char *)(iVar2 + 8);
                uVar3 = FUN_00003d64((int)*(char *)(iVar2 + 8));
                if ((uVar3 & 4) == 0) goto LAB_000038c8;
                DAT_000045cc = FUN_00003d9c(pcVar5,0,10);
                cVar1 = *(char *)(iVar2 + 8);
                while ((cVar1 != '\0' && (uVar3 = FUN_00003d64((int)*pcVar5), (uVar3 & 4) != 0))) {
                  pcVar5 = pcVar5 + 1;
                  cVar1 = *pcVar5;
                }
                iVar2 = FUN_00003d84(pcVar5,&DAT_000046bc);
                if (iVar2 != 0) goto LAB_000038b8;
                DAT_000045cc = DAT_000045cc << 10;
              }
            }
          }
        }
      }
    }
    piVar6 = piVar6 + 1;
  }
  if (DAT_000045dc == 0) {
    if (param_1 != 1) goto LAB_000038c8;
  }
  else {
    if (1 < param_1) {
LAB_000038c8:
      iVar2 = FUN_00000000();
      return iVar2;
    }
    if (param_1 != 1) goto LAB_00003944;
  }
  iVar2 = FUN_00002540(*piVar6);
  if (iVar2 != 0) {
    return -1;
  }
LAB_00003944:
  DAT_000046fc = 0;
  DAT_000046f8 = 0;
  local_38 = 1;
  local_30 = 1;
  local_2c = 1;
  local_34 = 0;
  DAT_000046e4 = FUN_00003e68(&local_38);
  if (DAT_000046e4 < 1) {
    FUN_00003d40("inetctl: CreateSema (%d)\n",DAT_000046e4);
    iVar2 = DAT_000046e4;
  }
  else {
    local_28 = 0;
    local_20 = 0;
    local_24 = 0;
    DAT_000046e8 = FUN_00003e24(&local_28);
    if (DAT_000046e8 < 1) {
      FUN_00003d40("inetctl: CreateEventFlag (%d)\n",DAT_000046e8);
      iVar2 = DAT_000046e8;
    }
    else {
      local_50 = 0x2000000;
      local_48 = FUN_0000271c;
      local_4c = 0;
      local_40 = DAT_000045c8;
      local_44 = DAT_000045cc;
      DAT_000046e0 = FUN_00003dc0(&local_50);
      if (DAT_000046e0 < 1) {
        FUN_00003d40("inetctl: CreateThread (%d)\n",DAT_000046e0);
        FUN_00003e70(DAT_000046e4);
        FUN_00003e2c(DAT_000046e8);
        iVar2 = DAT_000046e0;
      }
      else {
        iVar4 = FUN_00003dd0(DAT_000046e0,0);
        iVar2 = 0;
        if (iVar4 != 0) {
          FUN_00003d40("inetctl: StartThread (%d)\n",iVar4);
          FUN_00003e70(DAT_000046e4);
          FUN_00003e2c(DAT_000046e8);
          FUN_00003dc8(DAT_000046e0);
          iVar2 = iVar4;
        }
      }
    }
  }
  return iVar2;
}


================================================================