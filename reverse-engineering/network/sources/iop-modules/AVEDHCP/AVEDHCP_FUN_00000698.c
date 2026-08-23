FUNCTION FUN_00000698 @ 0x00000698 size=296
CALLERS (0): 
CALLEES (1): FUN_000005a8@0x000005a8

undefined4 FUN_00000698(short param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  
  DAT_00002f50 = 1;
  uVar4 = 0xffffffff;
  if (param_1 == 0) {
    iVar1 = FUN_000005a8(0xf,0);
    if (iVar1 == 0) {
      if (DAT_00002eb4 < 2) {
        DAT_00002f50 = 10;
        uVar4 = 0xffffffff;
      }
      else {
LAB_00000774:
        DAT_00002f50 = 0;
        uVar4 = 0;
      }
    }
    else {
      DAT_00002f50 = 0x19;
      uVar4 = 0xffffffff;
    }
  }
  else {
    uVar2 = 0;
    iVar1 = 0;
    do {
      iVar3 = (int)*(short *)((int)&DAT_00002eb8 + iVar1);
      uVar2 = uVar2 + 1;
      if (iVar3 == param_1) {
        iVar1 = FUN_000005a8(0xf,0);
        if (iVar1 != 0) {
          DAT_00002f50 = 0x19;
          return 0xffffffff;
        }
        iVar1 = FUN_000005a8(iVar3,param_2);
        if (iVar1 != 0) {
          DAT_00002f50 = iVar3 + 10;
          return 0xffffffff;
        }
        goto LAB_00000774;
      }
      iVar1 = iVar1 + 0xc;
    } while (uVar2 < 0xc);
  }
  return uVar4;
}


================================================================