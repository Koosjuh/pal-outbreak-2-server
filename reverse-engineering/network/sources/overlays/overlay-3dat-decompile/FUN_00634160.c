FUNCTION FUN_00634160 @ 0x00634160  size=104
CALLERS (7): FUN_00631880@0x00631880, FUN_00630c90@0x00630c90, FUN_006345e0@0x006345e0, FUN_00632390@0x00632390, FUN_00631ac0@0x00631ac0, FUN_006378b0@0x006378b0, FUN_006320f0@0x006320f0
CALLEES (2): FUN_00637d10@0x00637d10, FUN_00637e90@0x00637e90
----------------------------------------------------------------

int FUN_00634160(short *param_1)

{
  int iVar1;
  long lVar2;
  int iVar3;
  undefined1 auStack_4 [4];
  
  iVar3 = 0;
  lVar2 = FUN_00637e90();
  if (lVar2 == 0) {
    iVar3 = 0;
  }
  else {
    for (; *param_1 != 0; param_1 = param_1 + 1) {
      FUN_00637d10(*param_1,auStack_4);
      iVar1 = func_0x001af420(auStack_4);
      iVar3 = iVar3 + iVar1;
    }
  }
  return iVar3;
}



================================================================