FUNCTION FUN_00003e54 @ 0x00003e54 size=184
CALLERS (0): 
CALLEES (4): FUN_0000b0ac@0x0000b0ac, FUN_000038a4@0x000038a4, FUN_00017ad8@0x00017ad8, FUN_00011d90@0x00011d90

void FUN_00003e54(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  
  *(undefined4 *)(param_1 + 0xc) = 0;
  uVar2 = FUN_0000b0ac();
  uVar1 = DAT_0001b850;
  *(undefined4 *)(param_1 + 0x44) = uVar2;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  if ((uVar1 & 0x20) != 0) {
    FUN_00011d90("DHCP: Snd DHCPDISCOVER xid=0x%lx\n");
  }
  FUN_000038a4(param_1,0,0xffffffff,uVar2,&DAT_0001b15c,7);
  *(undefined4 *)(param_1 + 0x1c) = 1;
  if (*(int *)(param_1 + 0x80) < 1) {
    uVar2 = *(undefined4 *)(param_1 + 0x78);
  }
  else {
    *(int *)(param_1 + 0x80) = *(int *)(param_1 + 0x80) + -1;
    uVar2 = 5000;
  }
  uVar2 = FUN_00017ad8(FUN_000043a8,param_1,uVar2);
  *(undefined4 *)(param_1 + 0xc) = uVar2;
  return;
}


================================================================