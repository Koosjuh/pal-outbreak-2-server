FUNCTION FUN_0000b8d0 @ 0x0000b8d0 size=420
CALLERS (0): 
CALLEES (2): FUN_0000075c@0x0000075c, FUN_00008fac@0x00008fac

undefined4 FUN_0000b8d0(int param_1,int param_2,undefined4 param_3)

{
  ushort uVar1;
  int iVar2;
  short sVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  undefined4 local_res8 [2];
  byte local_20;
  byte local_1f;
  
  iVar8 = (int)*(short *)(param_2 + 2);
  iVar9 = *(int *)(param_1 + 0x30);
  local_res8[0] = param_3;
  if (*(char *)(param_2 + 1) == *(char *)(param_1 + 1)) {
    while (0 < iVar8) {
      sVar3 = FUN_00008fac(&local_20,local_res8);
      if (sVar3 == -1) {
        return 0;
      }
      iVar8 = iVar8 - (uint)local_1f;
      if (iVar8 < 0) {
        return 0xffffffff;
      }
      uVar6 = (uint)local_20;
      uVar7 = (uint)*(short *)(iVar9 + 0x28);
      if (uVar6 < 8) {
        uVar7 = (int)uVar7 >> (uVar6 & 0x1f) & 1;
      }
      else if ((uVar6 + 0x80 & 0xff) < 0x10) {
        uVar7 = (int)uVar7 >> (local_20 - 0x78 & 0x1f) & 1;
      }
      else {
        uVar7 = uVar7 & 1;
      }
      if (uVar7 == 0) {
        return 0xffffffff;
      }
      iVar5 = local_1f - 2;
      iVar2 = local_1f - 3;
      while (0 < iVar5) {
        sVar3 = FUN_0000075c(local_res8,&DAT_00013624,1);
        if (sVar3 != 1) {
          return 0xffffffff;
        }
        if (DAT_00013624 == 0xffff) goto LAB_0000b908;
        iVar5 = iVar2 << 0x10;
        iVar2 = iVar2 + -1;
      }
      uVar7 = (uint)local_20;
      if (uVar7 < 8) {
LAB_0000ba34:
        uVar1 = ~(ushort)(1 << (uVar7 & 0x1f));
      }
      else {
        if ((uVar7 + 0x80 & 0xff) < 0x10) {
          uVar7 = local_20 - 0x78;
          goto LAB_0000ba34;
        }
        uVar1 = 0xfffe;
      }
      *(ushort *)(iVar9 + 0x28) = *(ushort *)(iVar9 + 0x28) & uVar1;
    }
    uVar4 = 0;
  }
  else {
LAB_0000b908:
    uVar4 = 0xffffffff;
  }
  return uVar4;
}


================================================================