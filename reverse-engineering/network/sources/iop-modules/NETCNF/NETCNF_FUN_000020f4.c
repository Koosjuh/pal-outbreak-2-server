FUNCTION FUN_000020f4 @ 0x000020f4 size=300
CALLERS (3): FUN_00003988@0x00003988, FUN_00003060@0x00003060, FUN_000036ac@0x000036ac
CALLEES (5): FUN_00008ddc@0x00008ddc, FUN_000090a8@0x000090a8, FUN_000096ec@0x000096ec, FUN_000091c8@0x000091c8, FUN_00001560@0x00001560

undefined4 FUN_000020f4(int param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  char local_118 [256];
  
  if (param_1 == 0) {
    uVar1 = 0xfffffff7;
  }
  else {
    FUN_00001560(local_118,0x100,param_1,&DAT_000099f0);
    iVar2 = FUN_00008ddc(local_118,0x602,0x1ff);
    if (iVar2 < 0) {
      uVar1 = 0xfffffffd;
      if (iVar2 == -5) {
        uVar1 = 0xffffffee;
      }
    }
    else {
      iVar3 = FUN_000090a8(iVar2,param_2,param_3);
      if (param_3 == iVar3) {
        FUN_000091c8(iVar2);
        iVar2 = FUN_000096ec(local_118,param_1);
        if (iVar2 != -5) {
          iVar2 = 0;
          if (local_118[0] != ':') {
            iVar3 = 1;
            do {
              iVar2 = iVar3;
              iVar3 = iVar2 + 1;
            } while (local_118[iVar2] != ':');
          }
          local_118[iVar2 + 1] = '\0';
          return 0;
        }
      }
      else {
        FUN_000091c8(iVar2);
        if (iVar3 != -5) {
          return 0xfffffffb;
        }
      }
      uVar1 = 0xffffffee;
    }
  }
  return uVar1;
}


================================================================