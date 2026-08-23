FUNCTION FUN_00004078 @ 0x00004078 size=184
CALLERS (2): FUN_000044dc@0x000044dc, FUN_000045a4@0x000045a4
CALLEES (3): FUN_000038a4@0x000038a4, FUN_0000a9c0@0x0000a9c0, FUN_00011d90@0x00011d90

void FUN_00004078(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  undefined1 auStack_38 [4];
  undefined1 auStack_34 [28];
  
  FUN_0000a9c0(&DAT_0001b120,auStack_38,4);
  FUN_0000a9c0(&DAT_0001b124,auStack_34,3);
  if ((DAT_0001b850 & 0x20) != 0) {
    FUN_00011d90("DHCP: Snd DHCPREQUEST(lease) to=0x%lx xid=0x%lx\n",param_3,param_4);
  }
  FUN_000038a4(param_1,param_5,param_3,param_4,auStack_38,7);
  return;
}


================================================================