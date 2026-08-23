
int FUN_001cd160(undefined1 param_1,undefined1 param_2,undefined1 param_3)

{
  long lVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined1 auStack_200 [256];
  undefined1 auStack_100 [256];
  
  FUN_00109728(auStack_100,0x24c9e0,param_1,param_2,param_3);
  iVar3 = iRam003435dc;
  iVar2 = 0;
  uVar4 = 0;
  if (cRam00343577 == '\0') {
    FUN_00109728(auStack_200,0x24ca00,param_1,auStack_100);
    lVar1 = FUN_001cb360(auStack_200,iVar3,1,0);
    if (lVar1 < 1) goto LAB_001cd238;
    iVar2 = (int)lVar1;
  }
  else {
    FUN_00109728(auStack_200,0x24ca20,auStack_100);
    lVar1 = FUN_001a0df0(auStack_200,iVar3);
    if (lVar1 < 1) goto LAB_001cd238;
    iVar2 = (int)lVar1;
  }
  uVar4 = iVar2 + 0x3fU & 0xffffffc0;
  func_0x0068d200(iVar3);
  iVar2 = 1;
LAB_001cd238:
  iVar3 = iVar3 + uVar4;
  if (cRam00343577 == '\0') {
    FUN_00109728(auStack_200,0x24ca30,param_1,auStack_100);
    lVar1 = FUN_001cb360(auStack_200,iVar3,1,0);
  }
  else {
    FUN_00109728(auStack_200,0x24ca50,auStack_100);
    lVar1 = FUN_001a0df0(auStack_200,iVar3);
  }
  if (0 < lVar1) {
    func_0x0068d330(iVar3);
    iVar2 = iVar2 + 2;
  }
  return iVar2;
}

