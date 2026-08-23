FUNCTION FUN_0000b518 @ 0x0000b518 size=84
CALLERS (1): FUN_0000f40c@0x0000f40c
CALLEES (1): FUN_0000b100@0x0000b100

int FUN_0000b518(undefined4 param_1,uint param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  
  if (((param_2 < 0x100) && (param_3 == 0)) && (param_4 == 0)) {
    iVar1 = FUN_0000b100();
    iVar2 = -0x1f8;
    if (iVar1 != 0) {
      iVar2 = iVar1;
    }
  }
  else {
    iVar2 = -0x200;
  }
  return iVar2;
}


================================================================