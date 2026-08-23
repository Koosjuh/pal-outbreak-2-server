FUNCTION FUN_00000ec4 @ 0x00000ec4 size=948
CALLERS (0): 
CALLEES (2): FUN_0000274c@0x0000274c, FUN_000028bc@0x000028bc

void FUN_00000ec4(int param_1)

{
  int iVar1;
  char *pcVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  int *piVar6;
  undefined4 *puVar7;
  undefined1 auStack_120 [256];
  
  FUN_000028bc("-----------------------\n");
  if ((*(int **)(param_1 + 0x18) != (int *)0x0) && (iVar1 = **(int **)(param_1 + 0x18), iVar1 != 0))
  {
    FUN_000028bc("display_name     : \"%s\"\n",*(undefined4 *)(iVar1 + 8));
    FUN_000028bc("attach_ifc       : \"%s\"\n",*(undefined4 *)(iVar1 + 0xc));
    FUN_000028bc("attach_dev       : \"%s\"\n",*(undefined4 *)(iVar1 + 0x10));
    puVar3 = *(undefined4 **)(iVar1 + 0x14);
    if (puVar3 != (undefined4 *)0x0) {
      iVar5 = 0;
      FUN_000028bc("address          : \"%s\"\n",puVar3[7]);
      FUN_000028bc("netmask          : \"%s\"\n",puVar3[8]);
      FUN_000028bc("auth_name        : \"%s\"\n",puVar3[0x1c]);
      FUN_000028bc("auth_key         : \"%s\"\n",puVar3[0x1d]);
      FUN_000028bc("dhcp_host_name   : \"%s\"\n",puVar3[5]);
      FUN_000028bc("peer_name        : \"%s\"\n",puVar3[0x1e]);
      FUN_000028bc("type(ifc)        : \"%d\"\n",*puVar3);
      FUN_000028bc("dhcp             : \"%x\"\n",*(undefined1 *)(puVar3 + 4));
      FUN_000028bc("want.dns1_nego   : \"%x\"\n",*(undefined1 *)((int)puVar3 + 0x97));
      FUN_000028bc("want.dns2_nego   : \"%x\"\n",*(undefined1 *)(puVar3 + 0x26));
      FUN_000028bc("allow.f_auth     : \"%d\"\n",*(undefined1 *)((int)puVar3 + 0xf7));
      FUN_000028bc("allow.auth       : \"%d\"\n",*(undefined1 *)(puVar3 + 0x3d));
      FUN_000028bc("pppoe            : \"%x\"\n",*(undefined1 *)((int)puVar3 + 0x12e));
      FUN_000028bc("want.prc_nego    : \"%x\"\n",*(undefined1 *)((int)puVar3 + 0x93));
      FUN_000028bc("want.acc_nego    : \"%x\"\n",*(undefined1 *)(puVar3 + 0x25));
      FUN_000028bc("want.accm_nego   : \"%x\"\n",*(undefined1 *)((int)puVar3 + 0x91));
      FUN_000028bc("mtu              : \"%d\"\n",puVar3[0x4f]);
      FUN_000028bc("idle_timeout(ifc): \"%d\"\n",puVar3[0x22]);
      FUN_000028bc("redial_count     : \"%d\"\n",puVar3[10]);
      for (piVar6 = (int *)puVar3[0x54]; piVar6 != (int *)0x0; piVar6 = (int *)*piVar6) {
        if (piVar6[2] == 1) {
          FUN_0000274c(auStack_120,0x100,piVar6 + 3);
          iVar5 = iVar5 + 1;
          FUN_000028bc("dns%d_address     : \"%s\"\n",iVar5,auStack_120);
        }
        else if (piVar6[2] == 3) {
          FUN_0000274c(auStack_120,0x100,piVar6 + 8);
          FUN_000028bc("gateway          : \"%s\"\n",auStack_120);
        }
      }
      iVar5 = 0;
      puVar7 = puVar3;
      do {
        if (puVar7[0xe] == 0) goto LAB_00001198;
        if (iVar5 == 1) {
          uVar4 = puVar3[0xf];
          pcVar2 = "phone_numbers2   : \"%s\"\n";
LAB_0000118c:
          FUN_000028bc(pcVar2,uVar4);
        }
        else if (iVar5 < 2) {
          if (iVar5 == 0) {
            uVar4 = puVar3[0xe];
            pcVar2 = "phone_numbers1   : \"%s\"\n";
            goto LAB_0000118c;
          }
        }
        else if (iVar5 == 2) {
          uVar4 = puVar3[0x10];
          pcVar2 = "phone_numbers3   : \"%s\"\n";
          goto LAB_0000118c;
        }
LAB_00001198:
        puVar7 = puVar7 + 1;
        iVar5 = iVar5 + 1;
      } while (iVar5 < 10);
    }
    puVar3 = *(undefined4 **)(iVar1 + 0x18);
    if (puVar3 != (undefined4 *)0x0) {
      FUN_000028bc("type(dev)        : \"%d\"\n",*puVar3);
      FUN_000028bc("vendor           : \"%s\"\n",puVar3[1]);
      FUN_000028bc("product          : \"%s\"\n",puVar3[2]);
      FUN_000028bc("chat_additional  : \"%s\"\n",puVar3[9]);
      FUN_000028bc("outside_number   : \"%s\"\n",puVar3[0xc]);
      FUN_000028bc("outside_delay    : \"%s\"\n",puVar3[0xd]);
      FUN_000028bc("dialing_type     : \"%d\"\n",puVar3[0x1a]);
      FUN_000028bc("phy_config       : \"%d\"\n",puVar3[0x53]);
      FUN_000028bc("idle_timeout(dev): \"%d\"\n",puVar3[0x22]);
    }
  }
  FUN_000028bc("-----------------------\n");
  return;
}


================================================================