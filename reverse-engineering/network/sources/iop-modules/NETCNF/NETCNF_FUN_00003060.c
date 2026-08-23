FUNCTION FUN_00003060 @ 0x00003060 size=604
CALLERS (1): FUN_000032bc@0x000032bc
CALLEES (10): FUN_00009638@0x00009638, FUN_00001ba8@0x00001ba8, FUN_00001750@0x00001750, FUN_00009620@0x00009620, FUN_00001bf4@0x00001bf4, FUN_00002050@0x00002050, FUN_00009470@0x00009470, FUN_000020b0@0x000020b0, FUN_000020f4@0x000020f4, FUN_000094b8@0x000094b8

int FUN_00003060(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  
  if (param_3 == 0) {
    iVar2 = -0xb;
  }
  else {
    iVar2 = FUN_00001750(param_2,&DAT_0000bef8,&DAT_0000bff8,0x100,param_4);
    if (-1 < iVar2) {
      iVar2 = FUN_000020b0(param_1,&DAT_0000ab6c);
      if (iVar2 < 1) {
        if (iVar2 == 0) {
          iVar2 = -3;
        }
      }
      else {
        pcVar3 = (char *)FUN_00009470(iVar2);
        if (pcVar3 != (char *)0x0) {
          cVar1 = *DAT_0000ab6c;
          pcVar5 = pcVar3;
          pcVar4 = DAT_0000ab6c;
joined_r0x00003138:
          if (cVar1 == '\0') {
            FUN_000094b8(DAT_0000ab6c);
            iVar2 = FUN_000020f4(param_1,pcVar3,(int)pcVar5 - (int)pcVar3);
            FUN_000094b8(pcVar3);
            return iVar2;
          }
          iVar2 = FUN_00002050(param_2,pcVar4);
          if ((iVar2 < 1) || (iVar2 = FUN_00001bf4(&DAT_0000b5f8,pcVar4,3), iVar2 != 0))
          goto LAB_00003220;
          iVar2 = FUN_00009638(&DAT_0000b5f8,param_3);
          if (iVar2 != 0) {
            iVar2 = FUN_00009638(&DAT_0000b5f8,&DAT_0000bff8);
            if (iVar2 == 0) {
              FUN_000094b8(DAT_0000ab6c);
              FUN_000094b8(pcVar3);
              return -0xb;
            }
            goto LAB_00003220;
          }
          iVar2 = FUN_00001bf4(&DAT_0000b5f8,pcVar4,2);
          if (iVar2 != 0) goto LAB_00003220;
          iVar2 = FUN_00009620(pcVar5,"%d,%d,%s,%s\n",param_2,1,&DAT_0000b5f8,&DAT_0000bff8);
          pcVar5 = pcVar5 + iVar2;
          pcVar4 = (char *)FUN_00001ba8(pcVar4);
          goto LAB_00003250;
        }
        FUN_000094b8(DAT_0000ab6c);
        iVar2 = -2;
      }
    }
  }
  return iVar2;
LAB_00003220:
  for (; *pcVar4 != '\0'; pcVar4 = pcVar4 + 1) {
    if (*pcVar4 == '\n') goto LAB_00003240;
    *pcVar5 = *pcVar4;
    pcVar5 = pcVar5 + 1;
  }
  cVar1 = *pcVar4;
  if (cVar1 == '\n') {
LAB_00003240:
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
    *pcVar5 = cVar1;
    pcVar5 = pcVar5 + 1;
LAB_00003250:
    cVar1 = *pcVar4;
  }
  goto joined_r0x00003138;
}


================================================================