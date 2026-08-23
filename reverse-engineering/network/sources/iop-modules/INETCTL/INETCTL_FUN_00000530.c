FUNCTION FUN_00000530 @ 0x00000530 size=108
CALLERS (3): FUN_00001c6c@0x00001c6c, FUN_00002c3c@0x00002c3c, FUN_00001b80@0x00001b80
CALLEES (2): FUN_0000018c@0x0000018c, FUN_00003d84@0x00003d84

uint FUN_00000530(int param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;
  
  if (param_1 == 0) {
    uVar1 = 0;
  }
  else {
    iVar2 = FUN_0000018c(param_2,param_3,&DAT_00004fc8,0x400);
    if (iVar2 == 0) {
      iVar2 = FUN_00003d84(param_1,&DAT_00004fc8);
      uVar1 = (uint)(iVar2 != 0);
    }
    else {
      uVar1 = 0xffffffff;
    }
  }
  return uVar1;
}


================================================================