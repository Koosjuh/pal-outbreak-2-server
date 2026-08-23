FUNCTION FUN_000023e0 @ 0x000023e0 size=416
CALLERS (1): FUN_00000464@0x00000464
CALLEES (9): FUN_00001ae0@0x00001ae0, FUN_00009638@0x00009638, FUN_00001ba8@0x00001ba8, FUN_00001750@0x00001750, FUN_00006740@0x00006740, FUN_00001bf4@0x00001bf4, FUN_00002050@0x00002050, FUN_000020b0@0x000020b0, FUN_000094b8@0x000094b8

int FUN_000023e0(undefined4 param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  bool bVar1;
  char cVar2;
  int iVar3;
  char *pcVar4;
  
  iVar3 = FUN_00001ae0(&DAT_0000bef8,0x100,param_1);
  if ((((-1 < iVar3) &&
       (iVar3 = FUN_00001750(param_2,&DAT_0000bef8,&DAT_0000bff8,0x100,param_3), -1 < iVar3)) &&
      (iVar3 = FUN_000020b0(&DAT_0000bef8,&DAT_0000ab64), -1 < iVar3)) &&
     (bVar1 = iVar3 != 0, iVar3 = -8, bVar1)) {
    cVar2 = *DAT_0000ab64;
    pcVar4 = DAT_0000ab64;
    while (cVar2 != '\0') {
      iVar3 = FUN_00002050(param_2,pcVar4);
      if (((0 < iVar3) && (iVar3 = FUN_00001bf4(&DAT_0000b5f8,pcVar4,3), iVar3 == 0)) &&
         ((iVar3 = FUN_00009638(&DAT_0000b5f8,&DAT_0000bff8), iVar3 == 0 &&
          (iVar3 = FUN_00001bf4(&DAT_0000b5f8,pcVar4,2), iVar3 == 0)))) {
        FUN_000094b8(DAT_0000ab64);
        *param_4 = &DAT_0000bef8;
        param_4[1] = &DAT_0000b5f8;
        if (param_2 == 0) {
          param_4[5] = 1;
        }
        else {
          param_4[5] = 2;
        }
        iVar3 = FUN_00006740(param_4);
        return iVar3;
      }
      pcVar4 = (char *)FUN_00001ba8(pcVar4);
      cVar2 = *pcVar4;
    }
    FUN_000094b8(DAT_0000ab64);
    iVar3 = -8;
  }
  return iVar3;
}


================================================================