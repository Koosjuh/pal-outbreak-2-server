FUNCTION FUN_0000dcfc @ 0x0000dcfc size=736
CALLERS (1): FUN_0000e0e0@0x0000e0e0
CALLEES (6): FUN_0000dc38@0x0000dc38, FUN_00010aac@0x00010aac, FUN_00009044@0x00009044, FUN_0000db50@0x0000db50, FUN_000008c8@0x000008c8, FUN_0000075c@0x0000075c

bool FUN_0000dcfc(int param_1,int param_2,undefined4 *param_3)

{
  short sVar1;
  undefined4 *puVar2;
  uint uVar3;
  byte bVar4;
  char *pcVar5;
  byte *pbVar6;
  byte *pbVar7;
  int iVar8;
  byte *pbVar9;
  byte *pbVar10;
  undefined4 *local_res8 [2];
  
  pbVar9 = (byte *)0x0;
  pbVar10 = (byte *)0x0;
  local_res8[0] = param_3;
  sVar1 = FUN_0000075c(local_res8,&DAT_00013724,1);
  uVar3 = 0xffffffff;
  if (sVar1 == 1) {
    uVar3 = (uint)DAT_00013724;
  }
  if ((short)uVar3 != -1) {
    pbVar9 = &DAT_0001a470;
    pbVar6 = pbVar9;
    pbVar7 = pbVar9;
    if (0 < (short)uVar3) {
      do {
        uVar3 = uVar3 - 1;
        pbVar6 = pbVar7 + 1;
        if ((local_res8[0] == (undefined4 *)0x0) || (*(ushort *)(local_res8[0] + 1) < 2)) {
          sVar1 = FUN_0000075c(local_res8,&DAT_00013724,1);
          bVar4 = 0xff;
          if (sVar1 == 1) {
            bVar4 = DAT_00013724;
          }
        }
        else {
          *(ushort *)(local_res8[0] + 1) = *(ushort *)(local_res8[0] + 1) - 1;
          bVar4 = *(byte *)*local_res8[0];
          *local_res8[0] = (byte *)*local_res8[0] + 1;
        }
        *pbVar7 = bVar4;
        pbVar7 = pbVar6;
      } while (0 < (int)(uVar3 * 0x10000));
    }
    *pbVar6 = 0;
  }
  sVar1 = FUN_0000075c(local_res8,&DAT_00013724,1);
  uVar3 = 0xffffffff;
  if (sVar1 == 1) {
    uVar3 = (uint)DAT_00013724;
  }
  if ((short)uVar3 != -1) {
    pbVar10 = &DAT_0001a570;
    pbVar6 = pbVar10;
    pbVar7 = pbVar10;
    if (0 < (short)uVar3) {
      do {
        uVar3 = uVar3 - 1;
        pbVar6 = pbVar7 + 1;
        if ((local_res8[0] == (undefined4 *)0x0) || (*(ushort *)(local_res8[0] + 1) < 2)) {
          sVar1 = FUN_0000075c(local_res8,&DAT_00013724,1);
          bVar4 = 0xff;
          if (sVar1 == 1) {
            bVar4 = DAT_00013724;
          }
        }
        else {
          *(ushort *)(local_res8[0] + 1) = *(ushort *)(local_res8[0] + 1) - 1;
          bVar4 = *(byte *)*local_res8[0];
          *local_res8[0] = (byte *)*local_res8[0] + 1;
        }
        *pbVar7 = bVar4;
        pbVar7 = pbVar6;
      } while (0 < (int)(uVar3 * 0x10000));
    }
    *pbVar6 = 0;
  }
  sVar1 = FUN_0000db50(pbVar9,pbVar10);
  iVar8 = 3;
  if (sVar1 == 0) {
    iVar8 = 2;
    pcVar5 = " Welcome";
    *(byte **)(*(int *)(param_1 + 0xc) + 0xd8) = pbVar9;
  }
  else {
    pcVar5 = " Invalid username or password";
  }
  sVar1 = FUN_00010aac(pcVar5);
  puVar2 = (undefined4 *)FUN_000008c8(pcVar5,(int)sVar1);
  *(char *)*puVar2 = (char)sVar1 + -1;
  FUN_00009044(param_1,iVar8,*(undefined1 *)(param_2 + 1),puVar2);
  if (iVar8 == 3) {
    if (*(char *)(param_1 + 6) == '\0') {
      FUN_0000dc38(param_1);
    }
    else {
      *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + -1;
    }
  }
  return iVar8 != 2;
}


================================================================