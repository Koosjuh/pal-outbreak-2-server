FUNCTION FUN_00003f98 @ 0x00003f98 size=436
CALLERS (1): FUN_00000b9c@0x00000b9c
CALLEES (10): FUN_00008940@0x00008940, FUN_00001ae0@0x00001ae0, FUN_00009638@0x00009638, FUN_00001ba8@0x00001ba8, FUN_00008614@0x00008614, FUN_00001750@0x00001750, FUN_00001bf4@0x00001bf4, FUN_00002050@0x00002050, FUN_000020b0@0x000020b0, FUN_000094b8@0x000094b8

int FUN_00003f98(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  char cVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  
  iVar2 = FUN_00001ae0(&DAT_0000bef8,0x100,param_1);
  if ((-1 < iVar2) &&
     (iVar2 = FUN_00001750(param_2,&DAT_0000bef8,&DAT_0000c0f8,0x100,param_3), -1 < iVar2)) {
    iVar2 = FUN_000020b0(&DAT_0000bef8,&DAT_0000ab7c);
    if (iVar2 < 1) {
      if (iVar2 == 0) {
        iVar2 = -3;
      }
    }
    else {
      iVar2 = 0;
      cVar1 = *DAT_0000ab7c;
      pcVar4 = DAT_0000ab7c;
      while (cVar1 != '\0') {
        iVar3 = FUN_00002050(param_2,pcVar4);
        if ((0 < iVar3) && (iVar3 = FUN_00001bf4(&DAT_0000b5f8,pcVar4,3), iVar3 == 0)) {
          iVar3 = FUN_00009638(&DAT_0000b5f8,&DAT_0000c0f8);
          if ((iVar3 == 0) && (iVar3 = FUN_00001bf4(param_4 + 0x40,pcVar4,2), iVar3 == 0)) {
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
        iVar2 = FUN_00008940(&DAT_0000bef8,param_4 + 0x40,param_4 + 0x440);
        if (iVar2 == 0) {
          iVar2 = -0xb;
        }
        else {
          iVar2 = FUN_00008614(param_4 + 0x440,param_2,*(undefined4 *)(param_4 + 0x20),
                               *(undefined4 *)(param_4 + 0x24));
        }
      }
      FUN_000094b8(DAT_0000ab7c);
    }
  }
  return iVar2;
}


================================================================