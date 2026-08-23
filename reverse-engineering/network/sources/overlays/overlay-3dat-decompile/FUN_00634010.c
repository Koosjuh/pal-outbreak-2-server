FUNCTION FUN_00634010 @ 0x00634010  size=192
CALLERS (2): FUN_00632390@0x00632390, FUN_00631ac0@0x00631ac0
CALLEES (2): FUN_00637d10@0x00637d10, FUN_00637e90@0x00637e90
----------------------------------------------------------------

undefined8 FUN_00634010(short *param_1,int param_2)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  int iVar4;
  int iVar5;
  short *psVar6;
  undefined1 auStack_4 [4];
  
  lVar2 = FUN_00637e90();
  iVar5 = 0;
  if (lVar2 == 0) {
    uVar3 = 0;
  }
  else {
    iVar4 = 0;
    psVar6 = param_1;
    while( true ) {
      if ((*psVar6 == 0) || (param_2 <= iVar5)) break;
      FUN_00637d10(*psVar6,auStack_4);
      iVar1 = func_0x001af420(auStack_4);
      iVar5 = iVar5 + iVar1;
      psVar6 = psVar6 + 1;
      iVar4 = iVar4 + 1;
    }
    if (param_2 < iVar5) {
      uVar3 = 0xffffffffffffffff;
    }
    else {
      FUN_00637d10(param_1[iVar4],auStack_4);
      uVar3 = func_0x001af420(auStack_4);
    }
  }
  return uVar3;
}



================================================================