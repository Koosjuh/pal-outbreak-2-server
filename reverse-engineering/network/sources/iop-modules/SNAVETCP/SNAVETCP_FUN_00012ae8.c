FUNCTION FUN_00012ae8 @ 0x00012ae8 size=208
CALLERS (0): 
CALLEES (3): FUN_0001271c@0x0001271c, FUN_000126d4@0x000126d4, FUN_00012660@0x00012660

int FUN_00012ae8(byte *param_1)

{
  byte bVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  if (param_1 == (byte *)0x0) {
    iVar3 = 0;
  }
  else {
    iVar3 = 0;
    bVar1 = *param_1;
    for (iVar5 = 0; (bVar1 != 0 && (iVar5 < 8)); iVar5 = iVar5 + 1) {
      bVar1 = FUN_00012660(*param_1);
      *param_1 = bVar1;
      sVar2 = FUN_000126d4(bVar1);
      if (sVar2 == 0) {
        sVar2 = FUN_0001271c(*param_1);
        if (sVar2 == 0) {
          return iVar3;
        }
        iVar4 = *param_1 - 0x57;
      }
      else {
        iVar4 = *param_1 - 0x30;
      }
      iVar3 = iVar3 * 0x10 + iVar4;
      param_1 = param_1 + 1;
      bVar1 = *param_1;
    }
  }
  return iVar3;
}


================================================================