FUNCTION FUN_00000be8 @ 0x00000be8 size=624
CALLERS (0): 
CALLEES (1): FUN_000028bc@0x000028bc

void FUN_00000be8(int param_1)

{
  FUN_000028bc(&DAT_00002c50);
  FUN_000028bc("attach_ifc      :\"%s\"\n",param_1);
  FUN_000028bc("attach_dev      :\"%s\"\n",param_1 + 0x100);
  FUN_000028bc("dhcp_host_name  :\"%s\"\n",param_1 + 0x200);
  FUN_000028bc("address         :\"%s\"\n",param_1 + 0x300);
  FUN_000028bc("netmask         :\"%s\"\n",param_1 + 0x400);
  FUN_000028bc("gateway         :\"%s\"\n",param_1 + 0x500);
  FUN_000028bc("dns1_address    :\"%s\"\n",param_1 + 0x600);
  FUN_000028bc("dns2_address    :\"%s\"\n",param_1 + 0x700);
  FUN_000028bc("phone_numbers1  :\"%s\"\n",param_1 + 0x800);
  FUN_000028bc("phone_numbers2  :\"%s\"\n",param_1 + 0x900);
  FUN_000028bc("phone_numbers3  :\"%s\"\n",param_1 + 0xa00);
  FUN_000028bc("auth_name       :\"%s\"\n",param_1 + 0xb00);
  FUN_000028bc("auth_key        :\"%s\"\n",param_1 + 0xc00);
  FUN_000028bc("peer_name       :\"%s\"\n",param_1 + 0xd00);
  FUN_000028bc("vendor          :\"%s\"\n",param_1 + 0xe00);
  FUN_000028bc("product         :\"%s\"\n",param_1 + 0xf00);
  FUN_000028bc("chat_additiona  :\"%s\"\n",param_1 + 0x1000);
  FUN_000028bc("outside_number  :\"%s\"\n",param_1 + 0x1100);
  FUN_000028bc("outside_delay   :\"%s\"\n",param_1 + 0x1200);
  FUN_000028bc("ifc_type        :\"%d\"\n",*(undefined4 *)(param_1 + 0x1300));
  FUN_000028bc("mtu             :\"%d\"\n",*(undefined4 *)(param_1 + 0x1304));
  FUN_000028bc("ifc_idle_timeout:\"%d\"\n",*(undefined4 *)(param_1 + 0x1308));
  FUN_000028bc("dev_type        :\"%d\"\n",*(undefined4 *)(param_1 + 0x130c));
  FUN_000028bc("phy_config      :\"%d\"\n",*(undefined4 *)(param_1 + 0x1310));
  FUN_000028bc("dialing_type    :\"%d\"\n",*(undefined4 *)(param_1 + 0x1314));
  FUN_000028bc("dev_idle_timeout:\"%d\"\n",*(undefined4 *)(param_1 + 0x1318));
  FUN_000028bc("dhcp            :\"%d\"\n",FUN_00001320[param_1]);
  FUN_000028bc("dns1_nego       :\"%d\"\n",*(undefined1 *)(param_1 + 0x1321));
  FUN_000028bc("dns2_nego       :\"%d\"\n",*(undefined1 *)(param_1 + 0x1322));
  FUN_000028bc("f_auth          :\"%d\"\n",*(undefined1 *)(param_1 + 0x1323));
  FUN_000028bc("auth            :\"%d\"\n",*(undefined1 *)(param_1 + 0x1324));
  FUN_000028bc("pppoe           :\"%d\"\n",*(undefined1 *)(param_1 + 0x1325));
  FUN_000028bc("prc_nego        :\"%d\"\n",*(undefined1 *)(param_1 + 0x1326));
  FUN_000028bc("acc_nego        :\"%d\"\n",*(undefined1 *)(param_1 + 0x1327));
  FUN_000028bc("accm_nego       :\"%d\"\n",*(undefined1 *)(param_1 + 0x1328));
  FUN_000028bc(&DAT_00002c50);
  return;
}


================================================================