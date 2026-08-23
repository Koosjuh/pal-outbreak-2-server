FUNCTION FUN_000067bc @ 0x000067bc size=816
CALLERS (1): FUN_00006f6c@0x00006f6c
CALLEES (11): FUN_000066dc@0x000066dc, FUN_000009cc@0x000009cc, FUN_0000075c@0x0000075c, FUN_00010aac@0x00010aac, FUN_00010b3c@0x00010b3c, FUN_00010b4c@0x00010b4c, FUN_000008c8@0x000008c8, FUN_00009044@0x00009044, FUN_00000990@0x00000990, FUN_00010aa4@0x00010aa4, FUN_00000ac0@0x00000ac0

void FUN_000067bc(int param_1,int param_2,undefined4 *param_3)

{
  ushort uVar1;
  short sVar2;
  short sVar3;
  undefined4 uVar4;
  int iVar5;
  byte bVar6;
  int iVar7;
  byte *pbVar8;
  byte *pbVar9;
  uint uVar10;
  undefined4 *puVar11;
  byte *pbVar12;
  undefined4 *local_res8 [2];
  undefined1 auStack_80 [88];
  
  pbVar12 = (byte *)0x0;
  puVar11 = *(undefined4 **)(param_1 + 0x30);
  uVar1 = *(ushort *)(param_2 + 2);
  local_res8[0] = param_3;
  sVar2 = FUN_0000075c(local_res8,&DAT_00013594,1);
  uVar10 = 0xffffffff;
  if (sVar2 == 1) {
    uVar10 = (uint)DAT_00013594;
  }
  sVar2 = (short)uVar10;
  iVar5 = (int)sVar2;
  if (iVar5 != -1) {
    pbVar12 = &DAT_0001ab70;
    iVar7 = 0;
    pbVar9 = pbVar12;
    if (0 < iVar5) {
      do {
        if ((local_res8[0] == (undefined4 *)0x0) || (*(ushort *)(local_res8[0] + 1) < 2)) {
          sVar3 = FUN_0000075c(local_res8,&DAT_00013594,1);
          bVar6 = 0xff;
          if (sVar3 == 1) {
            bVar6 = DAT_00013594;
          }
        }
        else {
          *(ushort *)(local_res8[0] + 1) = *(ushort *)(local_res8[0] + 1) - 1;
          bVar6 = *(byte *)*local_res8[0];
          *local_res8[0] = (byte *)*local_res8[0] + 1;
        }
        iVar7 = iVar7 + 1;
        *pbVar9 = bVar6;
        pbVar9 = pbVar9 + 1;
      } while (iVar7 < iVar5);
    }
  }
  iVar5 = (uVar1 - uVar10) + -1;
  iVar7 = iVar5 * 0x10000;
  if (iVar5 * 0x10000 < 0) {
    iVar7 = 0;
  }
  iVar7 = iVar7 >> 0x10;
  if (iVar7 != 0) {
    pbVar8 = &DAT_0001a9f0;
    iVar5 = 0;
    pbVar9 = pbVar8;
    if (0 < iVar7) {
      do {
        pbVar8 = pbVar9 + 1;
        if ((local_res8[0] == (undefined4 *)0x0) || (*(ushort *)(local_res8[0] + 1) < 2)) {
          sVar3 = FUN_0000075c(local_res8,&DAT_00013594,1);
          bVar6 = 0xff;
          if (sVar3 == 1) {
            bVar6 = DAT_00013594;
          }
        }
        else {
          *(ushort *)(local_res8[0] + 1) = *(ushort *)(local_res8[0] + 1) - 1;
          bVar6 = *(byte *)*local_res8[0];
          *local_res8[0] = (byte *)*local_res8[0] + 1;
        }
        iVar5 = iVar5 + 1;
        *pbVar9 = bVar6;
        pbVar9 = pbVar8;
      } while (iVar5 < iVar7);
    }
    *pbVar8 = 0;
  }
  DAT_0001abb0 = *(undefined1 *)(param_2 + 1);
  FUN_00010aa4(&DAT_0001abb1,puVar11[1]);
  uVar10 = FUN_00010aac(puVar11[1]);
  sVar3 = FUN_00010aac(*puVar11);
  FUN_00010b3c(&DAT_0001abb1 + (uVar10 & 0xffff),pbVar12,(int)sVar2);
  FUN_00010b4c(&DAT_0001ac31,0,0x81);
  DAT_0001ac31 = 0x10;
  FUN_00000990(auStack_80);
  FUN_000009cc(auStack_80,&DAT_0001abb0,(uVar10 & 0xffff) + sVar2 + 1);
  FUN_00000ac0(&DAT_0001ac32,auStack_80);
  FUN_00010b3c(&DAT_0001ac42,*puVar11,(int)sVar3);
  uVar4 = FUN_000008c8(&DAT_0001ac31,sVar3 + 0x11);
  FUN_00009044(param_1,2,*(undefined1 *)(param_2 + 1),uVar4);
  if (*(char *)(param_1 + 6) == '\0') {
    FUN_000066dc(param_1);
  }
  else {
    *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + -1;
  }
  return;
}


================================================================