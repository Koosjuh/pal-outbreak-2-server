FUNCTION FUN_0000dfdc @ 0x0000dfdc size=260
CALLERS (1): FUN_0000e0e0@0x0000e0e0
CALLEES (3): FUN_0000075c@0x0000075c, FUN_00000710@0x00000710, FUN_00000928@0x00000928

undefined4 FUN_0000dfdc(int param_1,int param_2,undefined4 param_3)

{
  short sVar1;
  short sVar2;
  undefined4 uVar3;
  ushort uVar4;
  int iVar5;
  int iVar6;
  undefined4 local_res8 [2];
  
  iVar6 = *(int *)(param_1 + 0x30);
  uVar3 = 0xffffffff;
  if (*(char *)(param_2 + 1) == *(char *)(param_1 + 1)) {
    local_res8[0] = param_3;
    sVar1 = FUN_0000075c(local_res8,&DAT_00013724,1);
    uVar4 = 0xffff;
    if (sVar1 == 1) {
      uVar4 = (ushort)DAT_00013724;
    }
    iVar5 = (int)(short)uVar4;
    uVar3 = 0xffffffff;
    if ((iVar5 != -1) && (uVar3 = 0, iVar5 != 0)) {
      sVar1 = FUN_00000710(local_res8[0]);
      sVar2 = FUN_00000928(local_res8[0],&DAT_0001a670,uVar4);
      (&DAT_0001a670)[sVar2] = 0;
      *(undefined **)(iVar6 + 8) = &DAT_0001a670;
      if ((sVar2 < iVar5) || (uVar3 = 0, iVar5 < sVar1)) {
        uVar3 = 1;
      }
    }
  }
  return uVar3;
}


================================================================