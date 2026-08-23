FUNCTION FUN_00006aec @ 0x00006aec size=792
CALLERS (1): FUN_00006f6c@0x00006f6c
CALLEES (9): FUN_000009cc@0x000009cc, FUN_0000075c@0x0000075c, FUN_00010aac@0x00010aac, FUN_000008c8@0x000008c8, FUN_00009044@0x00009044, FUN_00010b34@0x00010b34, FUN_00000990@0x00000990, FUN_00010aa4@0x00010aa4, FUN_00000ac0@0x00000ac0

undefined4 FUN_00006aec(int param_1,int param_2,undefined4 *param_3)

{
  ushort uVar1;
  short sVar2;
  undefined4 uVar3;
  int iVar4;
  byte bVar5;
  int iVar6;
  byte *pbVar7;
  byte *pbVar8;
  uint uVar9;
  byte *pbVar10;
  undefined4 *local_res8 [2];
  undefined1 auStack_88 [88];
  int local_30;
  
  local_30 = *(int *)(param_1 + 0x30);
  pbVar10 = (byte *)0x0;
  if (*(char *)(param_2 + 1) == *(char *)(param_1 + 1)) {
    uVar1 = *(ushort *)(param_2 + 2);
    local_res8[0] = param_3;
    sVar2 = FUN_0000075c(local_res8,&DAT_00013594,1);
    uVar9 = 0xffffffff;
    if (sVar2 == 1) {
      uVar9 = (uint)DAT_00013594;
    }
    iVar4 = (int)(short)uVar9;
    if (iVar4 != -1) {
      pbVar10 = &DAT_0001a8a0;
      iVar6 = 0;
      pbVar8 = pbVar10;
      if (0 < iVar4) {
        do {
          if ((local_res8[0] == (undefined4 *)0x0) || (*(ushort *)(local_res8[0] + 1) < 2)) {
            sVar2 = FUN_0000075c(local_res8,&DAT_00013594,1);
            bVar5 = 0xff;
            if (sVar2 == 1) {
              bVar5 = DAT_00013594;
            }
          }
          else {
            *(ushort *)(local_res8[0] + 1) = *(ushort *)(local_res8[0] + 1) - 1;
            bVar5 = *(byte *)*local_res8[0];
            *local_res8[0] = (byte *)*local_res8[0] + 1;
          }
          iVar6 = iVar6 + 1;
          *pbVar8 = bVar5;
          pbVar8 = pbVar8 + 1;
        } while (iVar6 < iVar4);
      }
    }
    iVar4 = (uVar1 - uVar9) + -1;
    iVar6 = iVar4 * 0x10000;
    if (iVar4 * 0x10000 < 0) {
      iVar6 = 0;
    }
    iVar6 = iVar6 >> 0x10;
    if (iVar6 != 0) {
      pbVar7 = &DAT_0001a7a0;
      iVar4 = 0;
      pbVar8 = pbVar7;
      if (0 < iVar6) {
        do {
          pbVar7 = pbVar8 + 1;
          if ((local_res8[0] == (undefined4 *)0x0) || (*(ushort *)(local_res8[0] + 1) < 2)) {
            sVar2 = FUN_0000075c(local_res8,&DAT_00013594,1);
            bVar5 = 0xff;
            if (sVar2 == 1) {
              bVar5 = DAT_00013594;
            }
          }
          else {
            *(ushort *)(local_res8[0] + 1) = *(ushort *)(local_res8[0] + 1) - 1;
            bVar5 = *(byte *)*local_res8[0];
            *local_res8[0] = (byte *)*local_res8[0] + 1;
          }
          iVar4 = iVar4 + 1;
          *pbVar8 = bVar5;
          pbVar8 = pbVar7;
        } while (iVar4 < iVar6);
      }
      *pbVar7 = 0;
    }
    DAT_0001a8e0 = *(undefined1 *)(param_2 + 1);
    FUN_00010aa4(&DAT_0001a8e1,*(undefined4 *)(local_30 + 4));
    sVar2 = FUN_00010aac(*(undefined4 *)(local_30 + 4));
    FUN_00000990(auStack_88);
    FUN_000009cc(auStack_88,&DAT_0001a8e0,sVar2 + 1);
    FUN_000009cc(auStack_88,&DAT_0001aaf1,DAT_000135d4);
    FUN_00000ac0(&DAT_0001a961,auStack_88);
    FUN_00010b34(&DAT_0001a961,pbVar10,0x10);
    FUN_00010aa4(&DAT_0001a961,"Wellcome!!");
    uVar3 = FUN_00010aac(&DAT_0001a961);
    uVar3 = FUN_000008c8(&DAT_0001a961,uVar3);
    FUN_00009044(param_1,3,*(undefined1 *)(param_2 + 1),uVar3);
    uVar3 = 0;
  }
  else {
    uVar3 = 0xffffffff;
  }
  return uVar3;
}


================================================================