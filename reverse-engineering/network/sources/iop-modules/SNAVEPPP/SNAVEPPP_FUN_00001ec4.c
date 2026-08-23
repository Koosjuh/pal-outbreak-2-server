FUNCTION FUN_00001ec4 @ 0x00001ec4 size=308
CALLERS (1): FUN_000054a8@0x000054a8
CALLEES (8): FUN_000075dc@0x000075dc, FUN_0000bcfc@0x0000bcfc, FUN_0000bd98@0x0000bd98, FUN_0000bd30@0x0000bd30, FUN_0000bcc8@0x0000bcc8, FUN_0000bc94@0x0000bc94, FUN_0000bdcc@0x0000bdcc, FUN_0000bd64@0x0000bd64

undefined4
FUN_00001ec4(short param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  short sVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar1 = DAT_00014a2c;
  FUN_000075dc();
  sVar2 = FUN_0000bdcc((int)param_1,iVar1);
  uVar3 = 0xffffffef;
  if (sVar2 == 0) {
    iVar4 = iVar1 + 0x4c;
    sVar2 = FUN_0000bdcc((int)param_1,iVar4);
    uVar3 = 0xffffffef;
    if (sVar2 == 0) {
      sVar2 = FUN_0000bc94(iVar1,param_2);
      uVar3 = 0xffffffef;
      if (sVar2 == 0) {
        sVar2 = FUN_0000bcfc(iVar1,param_4);
        uVar3 = 0xffffffef;
        if (sVar2 == 0) {
          sVar2 = FUN_0000bd30(iVar1,param_5);
          uVar3 = 0xffffffef;
          if (sVar2 == 0) {
            sVar2 = FUN_0000bcc8(iVar4,param_3);
            uVar3 = 0xffffffef;
            if (sVar2 == 0) {
              sVar2 = FUN_0000bd64(iVar4,param_6);
              if (sVar2 == 0) {
                sVar2 = FUN_0000bd98(iVar4,param_7);
                uVar3 = 0xffffffef;
                if (sVar2 == 0) {
                  uVar3 = 0;
                }
              }
              else {
                uVar3 = 0xffffffef;
              }
            }
          }
        }
      }
    }
  }
  return uVar3;
}


================================================================