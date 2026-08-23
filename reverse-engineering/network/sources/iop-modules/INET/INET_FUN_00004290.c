FUNCTION FUN_00004290 @ 0x00004290 size=280
CALLERS (1): FUN_00005da4@0x00005da4
CALLEES (3): FUN_000038a4@0x000038a4, FUN_0000a9c0@0x0000a9c0, FUN_00011d90@0x00011d90

void FUN_00004290(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 auStack_40 [4];
  undefined1 auStack_3c [3];
  undefined1 local_39;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  
  FUN_0000a9c0(&DAT_0001b120,auStack_40,4);
  FUN_0000a9c0(&DAT_0001b12c,auStack_3c,3);
  local_39 = 0x36;
  local_38 = 4;
  local_35 = (undefined1)((uint)param_2 >> 8);
  local_36 = (undefined1)((uint)param_2 >> 0x10);
  local_37 = (undefined1)((uint)param_2 >> 0x18);
  local_34 = (undefined1)param_2;
  if ((DAT_0001b850 & 0x20) != 0) {
    FUN_00011d90("DHCP: Snd DHCPRELEASE to=0x%lx xid=0x%lx\n",param_2,param_3);
  }
  FUN_000038a4(param_1,param_4,param_2,param_3,auStack_40,0xd);
  return;
}


================================================================