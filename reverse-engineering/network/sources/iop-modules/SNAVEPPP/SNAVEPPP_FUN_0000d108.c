FUNCTION FUN_0000d108 @ 0x0000d108 size=408
CALLERS (0): 
CALLEES (2): FUN_0000075c@0x0000075c, FUN_00008fac@0x00008fac

undefined4 FUN_0000d108(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  short sVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  undefined4 local_res8 [2];
  byte local_20;
  byte local_1f;
  
  iVar6 = (int)*(short *)(param_2 + 2);
  iVar7 = *(int *)(param_1 + 0x30);
  uVar5 = 0;
  local_res8[0] = param_3;
  if (*(char *)(param_2 + 1) == *(char *)(param_1 + 1)) {
    while (0 < iVar6) {
      sVar2 = FUN_00008fac(&local_20,local_res8);
      if (sVar2 == -1) {
        return 0;
      }
      iVar6 = iVar6 - (uint)local_1f;
      if (iVar6 < 0) {
        return 0xffffffff;
      }
      if (local_20 < 9) {
        if (local_20 < uVar5) {
          return 0xffffffff;
        }
        if (((int)*(short *)(iVar7 + 0x1c) >> (local_20 & 0x1f) & 1U) == 0) {
          return 0xffffffff;
        }
      }
      iVar4 = local_1f - 2;
      iVar1 = local_1f - 3;
      while (0 < iVar4) {
        sVar2 = FUN_0000075c(local_res8,&DAT_00013674,1);
        if (sVar2 != 1) {
          return 0xffffffff;
        }
        if (DAT_00013674 == 0xffff) goto LAB_0000d140;
        iVar4 = iVar1 << 0x10;
        iVar1 = iVar1 + -1;
      }
      uVar5 = (uint)local_20;
      if ((uVar5 < 9) &&
         ((uVar5 != 3 || (((int)*(short *)(iVar7 + 0x1c) >> (local_20 & 0x1f) & 1U) == 0)))) {
        *(ushort *)(iVar7 + 0x1c) = *(ushort *)(iVar7 + 0x1c) & ~(ushort)(1 << (local_20 & 0x1f));
      }
    }
    uVar3 = 0;
  }
  else {
LAB_0000d140:
    uVar3 = 0xffffffff;
  }
  return uVar3;
}


================================================================