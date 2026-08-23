FUNCTION FUN_000018b0 @ 0x000018b0 size=220
CALLERS (1): FUN_00001a28@0x00001a28
CALLEES (4): FUN_00008ddc@0x00008ddc, FUN_000091c8@0x000091c8, FUN_000090a8@0x000090a8, FUN_00009028@0x00009028

undefined4 FUN_000018b0(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined1 auStack_210 [512];
  
  iVar1 = FUN_00008ddc(param_2,0x602,0x1ff);
  if (iVar1 < 0) {
    uVar2 = 0xfffffffd;
  }
  else {
    iVar3 = FUN_00008ddc(param_1,1,0);
    if (iVar3 < 0) {
      FUN_000091c8(iVar1);
      uVar2 = 0xfffffffd;
    }
    else {
      do {
        iVar4 = FUN_00009028(iVar3,auStack_210,0x200);
        if (iVar4 < 1) {
          FUN_000091c8(iVar1);
          FUN_000091c8(iVar3);
          if (iVar4 < 0) {
            return 0xfffffffc;
          }
          return 0;
        }
        iVar5 = FUN_000090a8(iVar1,auStack_210,iVar4);
      } while (iVar4 == iVar5);
      FUN_000091c8(iVar1);
      FUN_000091c8(iVar3);
      uVar2 = 0xfffffffb;
    }
  }
  return uVar2;
}


================================================================