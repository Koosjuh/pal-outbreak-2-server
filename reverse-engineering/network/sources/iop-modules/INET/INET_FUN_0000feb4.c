FUNCTION FUN_0000feb4 @ 0x0000feb4 size=172
CALLERS (1): FUN_0000ff60@0x0000ff60
CALLEES (3): FUN_00016f74@0x00016f74, FUN_00019520@0x00019520, FUN_0000ba80@0x0000ba80

int FUN_0000feb4(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if ((param_2 < 0) || (param_1 == 0)) {
    iVar2 = -0x200;
  }
  else {
    iVar1 = FUN_00016f74(0,0x11,param_1,param_2);
    iVar2 = iVar1;
    if (-1 < iVar1) {
      param_1 = param_1 + iVar1 * 0x10;
      param_2 = param_2 + iVar1 * -0x10;
      iVar2 = FUN_00019520(0,0x11,param_1,param_2);
      iVar1 = iVar1 + iVar2;
      if ((-1 < iVar2) &&
         (iVar2 = FUN_0000ba80(0,0x11,param_1 + iVar2 * 0x10,param_2 + iVar2 * -0x10), -1 < iVar2))
      {
        iVar2 = iVar1 + iVar2;
      }
    }
  }
  return iVar2;
}


================================================================