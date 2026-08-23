FUNCTION FUN_0000fddc @ 0x0000fddc size=216
CALLERS (1): FUN_0000ff60@0x0000ff60
CALLEES (3): FUN_00016f74@0x00016f74, FUN_00019520@0x00019520, FUN_0000ba80@0x0000ba80

int FUN_0000fddc(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if ((param_2 < 0) || (param_1 == 0)) {
    iVar2 = -0x200;
  }
  else {
    iVar1 = FUN_00016f74(0,1,param_1,param_2);
    iVar2 = iVar1;
    if (-1 < iVar1) {
      param_1 = param_1 + iVar1 * 0x4c;
      param_2 = param_2 + iVar1 * -0x4c;
      iVar2 = FUN_00019520(0,1,param_1,param_2);
      if (-1 < iVar2) {
        iVar3 = FUN_0000ba80(0,1,param_1 + iVar2 * 0x4c,param_2 + iVar2 * -0x4c);
        iVar2 = iVar1 + iVar2 + iVar3;
        if (iVar3 < 0) {
          iVar2 = iVar3;
        }
      }
    }
  }
  return iVar2;
}


================================================================