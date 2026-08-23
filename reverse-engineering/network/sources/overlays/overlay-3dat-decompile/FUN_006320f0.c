FUNCTION FUN_006320f0 @ 0x006320f0  size=404
CALLERS (9): FUN_00635ab0@0x00635ab0, FUN_00630c90@0x00630c90, FUN_006334f0@0x006334f0, FUN_00630750@0x00630750, FUN_00631ff0@0x00631ff0, FUN_006353e0@0x006353e0, FUN_006355a0@0x006355a0, FUN_00634ab0@0x00634ab0, FUN_006378b0@0x006378b0
CALLEES (7): FUN_00634280@0x00634280, FUN_00637ed0@0x00637ed0, FUN_006341d0@0x006341d0, FUN_00637e10@0x00637e10, FUN_00634310@0x00634310, FUN_00637d10@0x00637d10, FUN_00634160@0x00634160
----------------------------------------------------------------

void FUN_006320f0(undefined8 param_1,undefined8 param_2,undefined2 param_3,int param_4)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined2 *puVar6;
  short *psVar7;
  int iVar8;
  undefined1 auStack_210 [520];
  undefined1 auStack_8 [4];
  undefined1 auStack_4 [4];
  
  if (*(int *)(iRam00715da8 + 0x4a8) == 1) {
    iVar8 = 0;
    iVar2 = FUN_00634310();
    iVar3 = FUN_00634310(param_2);
    if (param_4 < iVar2 + iVar3) {
      iVar3 = 0;
      while( true ) {
        psVar7 = (short *)((int)param_2 + iVar3 * 2);
        sVar1 = *psVar7;
        if (sVar1 == 0) break;
        FUN_00637d10(sVar1,auStack_4);
        iVar8 = iVar8 + 2;
        if (param_4 - iVar2 < iVar8) break;
        iVar3 = iVar3 + 1;
      }
      *psVar7 = 0;
    }
  }
  else {
    iVar2 = FUN_00634280();
    iVar3 = FUN_00634280(param_2);
    if (param_4 < iVar2 + iVar3) {
      iVar3 = 0;
      iVar8 = 0;
      while( true ) {
        psVar7 = (short *)((int)param_2 + iVar8 * 2);
        sVar1 = *psVar7;
        if (sVar1 == 0) break;
        iVar4 = FUN_00637d10(sVar1,auStack_8);
        iVar3 = iVar3 + iVar4;
        if (param_4 - iVar2 < iVar3) break;
        iVar8 = iVar8 + 1;
      }
      *psVar7 = 0;
    }
  }
  uVar5 = FUN_006341d0(param_1,param_3);
  puVar6 = (undefined2 *)((int)param_1 + (uVar5 & 0xffff) * 2);
  FUN_00637ed0(auStack_210,puVar6,0xfa);
  *puVar6 = 0;
  FUN_00637e10(param_1,param_2);
  FUN_00637e10(param_1,auStack_210);
  FUN_00634160(param_2);
  return;
}



================================================================