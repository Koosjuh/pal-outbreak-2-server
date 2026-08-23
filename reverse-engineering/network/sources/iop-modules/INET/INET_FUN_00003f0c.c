FUNCTION FUN_00003f0c @ 0x00003f0c size=364
CALLERS (0): 
CALLEES (3): FUN_000038a4@0x000038a4, FUN_0000a9c0@0x0000a9c0, FUN_00011d90@0x00011d90

void FUN_00003f0c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 auStack_38 [4];
  undefined1 auStack_34 [3];
  undefined1 local_31;
  undefined1 local_30;
  undefined1 local_2f;
  undefined1 local_2e;
  undefined1 local_2d;
  undefined1 local_2c;
  undefined1 local_2b;
  undefined1 local_2a;
  undefined1 local_29;
  undefined1 local_28;
  undefined1 local_27;
  undefined1 local_26;
  undefined1 auStack_25 [13];
  
  FUN_0000a9c0(&DAT_0001b120,auStack_38,4);
  FUN_0000a9c0(&DAT_0001b124,auStack_34,3);
  local_31 = 0x32;
  local_2d = (undefined1)((uint)param_2 >> 8);
  local_2e = (undefined1)((uint)param_2 >> 0x10);
  local_30 = 4;
  local_2f = (undefined1)((uint)param_2 >> 0x18);
  local_2c = (undefined1)param_2;
  local_2b = 0x36;
  local_27 = (undefined1)((uint)param_3 >> 8);
  local_28 = (undefined1)((uint)param_3 >> 0x10);
  local_2a = 4;
  local_29 = (undefined1)((uint)param_3 >> 0x18);
  local_26 = (undefined1)param_3;
  FUN_0000a9c0(&DAT_0001b134,auStack_25,6);
  if ((DAT_0001b850 & 0x20) != 0) {
    FUN_00011d90("DHCP: Snd DHCPREQUEST to=0x%lx xid=0x%lx\n",0xffffffff,param_4);
  }
  FUN_000038a4(param_1,0,0xffffffff,param_4,auStack_38,0x19);
  return;
}


================================================================