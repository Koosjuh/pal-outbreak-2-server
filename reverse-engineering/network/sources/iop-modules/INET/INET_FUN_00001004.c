FUNCTION FUN_00001004 @ 0x00001004 size=260
CALLERS (1): FUN_0000ec64@0x0000ec64
CALLEES (4): FUN_00000cc8@0x00000cc8, FUN_00007e28@0x00007e28, FUN_00011d90@0x00011d90, FUN_00009eec@0x00009eec

int FUN_00001004(undefined4 param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  
  if ((uint)(*(int *)(param_2 + 0x14) - *(int *)(param_2 + 0x10)) < 0xe) {
    DAT_0001b854 = DAT_0001b854 + 1;
    if ((DAT_0001b850 & 1) != 0) {
      FUN_00011d90("# ERR # %s:%d: %s\n",s_arp_c_0001b3f8,299,"ether_rcv - bad len");
    }
  }
  else {
    iVar2 = *(int *)(param_2 + 0x10);
    *(int *)(param_2 + 0x10) = iVar2 + 0xe;
    DAT_0001b9c8 = DAT_0001b9c8 + 1;
    uVar1 = *(ushort *)(iVar2 + 0xc) << 8 | *(ushort *)(iVar2 + 0xc) >> 8;
    *(ushort *)(iVar2 + 0xc) = uVar1;
    if (uVar1 == 0x806) {
      param_2 = FUN_00000cc8(param_1,param_2);
    }
    else if ((uVar1 < 0x807) && (uVar1 == 0x800)) {
      param_2 = FUN_00007e28(param_1,param_2,1);
    }
    param_2 = FUN_00009eec(param_2);
  }
  return param_2;
}


================================================================