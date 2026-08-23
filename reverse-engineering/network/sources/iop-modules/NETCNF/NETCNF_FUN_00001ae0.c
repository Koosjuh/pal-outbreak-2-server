FUNCTION FUN_00001ae0 @ 0x00001ae0 size=200
CALLERS (7): FUN_00003f98@0x00003f98, FUN_00002280@0x00002280, FUN_00003988@0x00003988, FUN_000023e0@0x000023e0, FUN_000032bc@0x000032bc, FUN_000036ac@0x000036ac, FUN_000027e4@0x000027e4
CALLEES (4): FUN_0000141c@0x0000141c, FUN_00009648@0x00009648, FUN_000013a0@0x000013a0, FUN_00009658@0x00009658

undefined4 FUN_00001ae0(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  char *pcVar4;
  
  FUN_000013a0();
  iVar1 = FUN_00009648(param_1,0x3a);
  if (iVar1 == 0) {
    uVar2 = 0xfffffff7;
  }
  else {
    iVar3 = FUN_00009658(param_1,&DAT_00009978,2);
    if (iVar3 == 0) {
      *(undefined1 *)(iVar1 + 1) = 0;
      pcVar4 = "/BWNETCNF/BWNETCNF";
      uVar2 = 0x113;
    }
    else {
      iVar3 = FUN_00009658(param_1,&DAT_0000997c,3);
      if (iVar3 != 0) {
        return 0;
      }
      *(undefined1 *)(iVar1 + 1) = 0;
      pcVar4 = "/etc/network/net.db";
      uVar2 = 0x117;
    }
    FUN_0000141c(param_1,param_2,pcVar4,uVar2);
    uVar2 = 0;
  }
  return uVar2;
}


================================================================