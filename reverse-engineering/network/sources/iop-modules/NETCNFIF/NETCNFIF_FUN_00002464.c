FUNCTION FUN_00002464 @ 0x00002464 size=244
CALLERS (0): 
CALLEES (3): FUN_0000283c@0x0000283c, FUN_000028e8@0x000028e8, FUN_00002918@0x00002918

undefined4
FUN_00002464(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 *param_5)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  DAT_00006448 = param_3;
  DAT_0000644c = param_4;
  iVar1 = FUN_00002918();
  iVar4 = iVar1 + 1;
  iVar2 = FUN_00002918(param_2);
  DAT_00006450 = iVar4;
  DAT_00006454 = iVar2 + 1;
  FUN_000028e8(&DAT_00006458,param_1,iVar4);
  FUN_000028e8(iVar1 + 0x6459,param_2,iVar2 + 1);
  iVar1 = FUN_0000283c(&DAT_00006420,0xc,0,&DAT_00006448,iVar2 + iVar4 + 0x50U & 0xffffffc0,
                       &DAT_00006448,0x40,0,0);
  uVar3 = 0xffffffff;
  if (-1 < iVar1) {
    *param_5 = DAT_0000644c;
    uVar3 = DAT_00006448;
  }
  return uVar3;
}


================================================================