FUNCTION FUN_00002280 @ 0x00002280 size=352
CALLERS (2): FUN_00000368@0x00000368, FUN_000003e0@0x000003e0
CALLEES (7): FUN_00009660@0x00009660, FUN_00001ae0@0x00001ae0, FUN_00001ba8@0x00001ba8, FUN_00001bf4@0x00001bf4, FUN_00002050@0x00002050, FUN_000020b0@0x000020b0, FUN_000094b8@0x000094b8

int FUN_00002280(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  undefined4 *puVar5;
  
  iVar1 = FUN_00001ae0(&DAT_0000bef8,0x100,param_1);
  if ((-1 < iVar1) && (iVar1 = FUN_000020b0(&DAT_0000bef8,&DAT_0000ab60), 0 < iVar1)) {
    iVar1 = 0;
    if (*DAT_0000ab60 != '\0') {
      puVar5 = param_3 + 0x42;
      pcVar4 = DAT_0000ab60;
      do {
        iVar2 = FUN_00002050(param_2,pcVar4);
        if ((0 < iVar2) && (iVar1 = iVar1 + 1, param_3 != (undefined4 *)0x0)) {
          *param_3 = param_2;
          iVar2 = FUN_00001bf4(&DAT_0000b5f8,pcVar4,1);
          if (iVar2 == 0) {
            uVar3 = FUN_00009660(&DAT_0000b5f8,0,10);
            puVar5[-0x41] = uVar3;
            iVar2 = FUN_00001bf4(param_3 + 2,pcVar4,2);
            if ((iVar2 == 0) && (iVar2 = FUN_00001bf4(puVar5,pcVar4,3), iVar2 == 0)) {
              puVar5 = puVar5 + 0x82;
              param_3 = param_3 + 0x82;
            }
          }
        }
        pcVar4 = (char *)FUN_00001ba8(pcVar4);
      } while (*pcVar4 != '\0');
    }
    FUN_000094b8(DAT_0000ab60);
  }
  return iVar1;
}


================================================================