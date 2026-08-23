FUNCTION FUN_0000043c @ 0x0000043c size=160
CALLERS (2): FUN_00001688@0x00001688, FUN_00000a4c@0x00000a4c
CALLEES (3): FUN_0000018c@0x0000018c, FUN_00003d40@0x00003d40, FUN_00003c64@0x00003c64

int FUN_0000043c(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined1 auStack_28 [16];
  
  if (param_3 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_00003c64(4,auStack_28,param_3,0,0);
    if (iVar1 < 0) {
      FUN_00003d40("sceInetName2Address(%s) -> %d\n",param_3,iVar1);
    }
    else {
      iVar1 = FUN_0000018c(param_1,param_2,auStack_28,0x10);
    }
  }
  return iVar1;
}


================================================================