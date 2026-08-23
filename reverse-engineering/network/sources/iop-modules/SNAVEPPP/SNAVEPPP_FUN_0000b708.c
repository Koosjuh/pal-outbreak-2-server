FUNCTION FUN_0000b708 @ 0x0000b708 size=456
CALLERS (0): 
CALLEES (2): FUN_0000ad1c@0x0000ad1c, FUN_00008fac@0x00008fac

undefined4 FUN_0000b708(int param_1,int param_2,undefined4 param_3)

{
  ushort uVar1;
  short sVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  undefined4 local_res8 [2];
  byte local_20;
  byte local_1f;
  
  iVar7 = (int)*(short *)(param_2 + 2);
  iVar6 = *(int *)(param_1 + 0x30);
  local_res8[0] = param_3;
  if (*(char *)(param_2 + 1) == *(char *)(param_1 + 1)) {
    while (0 < iVar7) {
      sVar2 = FUN_00008fac(&local_20,local_res8);
      if (sVar2 == -1) {
        return 0;
      }
      iVar7 = iVar7 - (uint)local_1f;
      if (iVar7 < 0) {
        return 0xffffffff;
      }
      uVar4 = (uint)local_20;
      uVar5 = (uint)*(short *)(iVar6 + 0x28);
      if (uVar4 < 8) {
        uVar5 = (int)uVar5 >> (uVar4 & 0x1f) & 1;
      }
      else if ((uVar4 + 0x80 & 0xff) < 0x10) {
        uVar5 = (int)uVar5 >> (local_20 - 0x78 & 0x1f) & 1;
      }
      else {
        uVar5 = uVar5 & 1;
      }
      if (uVar5 == 0) {
        uVar5 = (uint)local_20;
        if (uVar5 < 8) {
LAB_0000b814:
          uVar1 = (ushort)(1 << (uVar5 & 0x1f));
        }
        else {
          if ((uVar5 + 0x80 & 0xff) < 0x10) {
            uVar5 = local_20 - 0x78;
            goto LAB_0000b814;
          }
          uVar1 = 1;
        }
        *(ushort *)(iVar6 + 0x28) = *(ushort *)(iVar6 + 0x28) | uVar1;
      }
      sVar2 = FUN_0000ad1c(local_res8,iVar6,iVar6,&local_20,0);
      if (sVar2 == -1) goto LAB_0000b744;
      if (sVar2 == 4) {
        uVar5 = (uint)local_20;
        if (uVar5 < 8) {
LAB_0000b88c:
          uVar1 = ~(ushort)(1 << (uVar5 & 0x1f));
        }
        else {
          if ((uVar5 + 0x80 & 0xff) < 0x10) {
            uVar5 = local_20 - 0x78;
            goto LAB_0000b88c;
          }
          uVar1 = 0xfffe;
        }
        *(ushort *)(iVar6 + 0x28) = *(ushort *)(iVar6 + 0x28) & uVar1;
      }
    }
    uVar3 = 0;
  }
  else {
LAB_0000b744:
    uVar3 = 0xffffffff;
  }
  return uVar3;
}


================================================================