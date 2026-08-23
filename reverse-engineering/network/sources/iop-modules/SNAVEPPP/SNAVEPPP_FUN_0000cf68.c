FUNCTION FUN_0000cf68 @ 0x0000cf68 size=416
CALLERS (0): 
CALLEES (2): FUN_00008fac@0x00008fac, FUN_0000c5a0@0x0000c5a0

undefined4 FUN_0000cf68(int param_1,int param_2,undefined4 param_3)

{
  short sVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined4 local_res8 [2];
  byte local_28;
  byte local_27;
  
  uVar6 = 0;
  iVar5 = (int)*(short *)(param_2 + 2);
  iVar4 = *(int *)(param_1 + 0x30);
  local_res8[0] = param_3;
  if (*(char *)(param_2 + 1) == *(char *)(param_1 + 1)) {
    while (0 < iVar5) {
      sVar1 = FUN_00008fac(&local_28,local_res8);
      if (sVar1 == -1) {
        return 0;
      }
      iVar5 = iVar5 - (uint)local_27;
      if (iVar5 < 0) {
        return 0xffffffff;
      }
      if (local_28 < 9) {
        uVar3 = (uint)local_28;
        if ((uVar3 < uVar6) || (((int)*(short *)(iVar4 + 0x1c) >> (uVar3 & 0x1f) & 1U) == 0)) {
          if (((int)*(short *)(iVar4 + 0x1c) >> (uVar3 & 0x1f) & 1U) != 0) goto LAB_0000cfac;
          *(ushort *)(iVar4 + 0x1c) = *(ushort *)(iVar4 + 0x1c) | (ushort)(1 << (uVar3 & 0x1f));
          uVar6 = 9;
        }
        else {
          uVar6 = (uint)local_28;
        }
      }
      sVar1 = FUN_0000c5a0(local_res8,iVar4,iVar4,&local_28,0);
      if (sVar1 == -1) goto LAB_0000cfac;
      if (((sVar1 == 4) && (local_28 < 9)) &&
         ((local_28 != 3 || ((*(short *)(iVar4 + 0x1c) >> 3 & 1U) == 0)))) {
        *(ushort *)(iVar4 + 0x1c) = *(ushort *)(iVar4 + 0x1c) & ~(ushort)(1 << (local_28 & 0x1f));
      }
    }
    uVar2 = 0;
  }
  else {
LAB_0000cfac:
    uVar2 = 0xffffffff;
  }
  return uVar2;
}


================================================================