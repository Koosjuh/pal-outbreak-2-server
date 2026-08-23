FUNCTION FUN_000049e0 @ 0x000049e0 size=180
CALLERS (1): FUN_00000cc8@0x00000cc8
CALLEES (4): FUN_00004130@0x00004130, FUN_00017bf4@0x00017bf4, FUN_000043a8@0x000043a8, FUN_00011d90@0x00011d90

void FUN_000049e0(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  if ((param_2 != 0) && (piVar2 = DAT_0001b680, DAT_0001b680 != (int *)0x0)) {
    do {
      if ((param_1 == piVar2[2]) && (param_2 == piVar2[8])) break;
      piVar2 = (int *)*piVar2;
    } while (piVar2 != (int *)0x0);
    if (piVar2 != (int *)0x0) {
      FUN_00011d90("DHCP: arp reply (iadr=%<IADR> ip_addr=%<IADR>)\n",param_2,piVar2[8]);
      iVar1 = FUN_00017bf4(piVar2[6]);
      piVar2[6] = iVar1;
      iVar1 = FUN_00017bf4(piVar2[3]);
      piVar2[3] = iVar1;
      FUN_00004130(piVar2,piVar2[8],0xffffffff,piVar2[0x11]);
      piVar2[7] = 0;
      FUN_000043a8();
    }
  }
  return;
}


================================================================