FUNCTION FUN_00001750 @ 0x00001750 size=352
CALLERS (7): FUN_00003060@0x00003060, FUN_000036ac@0x000036ac, FUN_000023e0@0x000023e0, FUN_00003988@0x00003988, FUN_00003f98@0x00003f98, FUN_000027e4@0x000027e4, FUN_000032bc@0x000032bc
CALLEES (5): FUN_000095f8@0x000095f8, FUN_00009660@0x00009660, FUN_00009658@0x00009658, FUN_00001560@0x00001560, FUN_000013a0@0x000013a0

undefined4 FUN_00001750(int param_1,undefined4 param_2,char *param_3,undefined4 param_4,int param_5)

{
  char cVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  int iVar7;
  char local_28 [8];
  
  if (param_5 != 0) {
    FUN_000013a0(param_3,param_4,param_5,0x8b);
    pcVar6 = param_3;
    if (param_1 != 0) {
      return 0;
    }
    while( true ) {
      uVar3 = FUN_000095f8((int)*pcVar6);
      iVar7 = 0;
      if ((uVar3 & 4) != 0) break;
      pcVar6 = pcVar6 + 1;
    }
    while( true ) {
      uVar3 = FUN_000095f8((int)*pcVar6);
      if ((uVar3 & 4) == 0) break;
      pcVar5 = local_28 + iVar7;
      if (3 < iVar7) {
        return 0xfffffff5;
      }
      iVar7 = iVar7 + 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
      *pcVar5 = cVar1;
    }
    local_28[iVar7] = '\0';
    iVar7 = FUN_00009660(local_28,0,10);
    iVar4 = FUN_00009658(param_2,&DAT_00009978,2);
    if (iVar4 == 0) {
      bVar2 = iVar7 - 1U < 6;
    }
    else {
      iVar4 = FUN_00009658(param_2,&DAT_0000997c,3);
      if (iVar4 == 0) {
        bVar2 = iVar7 - 1U < 10;
      }
      else {
        bVar2 = iVar7 - 1U < 1000;
      }
    }
    if (bVar2) {
      FUN_00001560(param_3,param_4,"Combination",local_28);
      return 0;
    }
  }
  return 0xfffffff5;
}


================================================================