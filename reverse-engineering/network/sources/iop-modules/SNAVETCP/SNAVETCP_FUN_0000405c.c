FUNCTION FUN_0000405c @ 0x0000405c size=160
CALLERS (1): FUN_000046d4@0x000046d4
CALLEES (1): FUN_0000e7ec@0x0000e7ec

undefined4 FUN_0000405c(uint param_1,uint param_2,undefined4 param_3,short param_4)

{
  short sVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = param_4 * 0x2c;
  if ((&DAT_00022871)[iVar3] == '\x02') {
    uVar2 = 0xffffffff;
  }
  else {
    (&DAT_00022874)[param_4 * 0xb] = param_1;
    *(uint *)(&DAT_0002287c + iVar3) = param_1 & param_2;
    *(undefined4 *)(&DAT_00022878 + iVar3) = param_3;
    *(uint *)(&DAT_00022880 + iVar3) = param_2;
    sVar1 = FUN_0000e7ec();
    uVar2 = 0xffffffff;
    if (sVar1 == 0) {
      uVar2 = 0;
    }
  }
  return uVar2;
}


================================================================