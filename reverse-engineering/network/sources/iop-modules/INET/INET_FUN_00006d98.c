FUNCTION FUN_00006d98 @ 0x00006d98 size=212
CALLERS (1): FUN_00012170@0x00012170
CALLEES (3): FUN_00009e60@0x00009e60, FUN_00017ad8@0x00017ad8, FUN_00011d90@0x00011d90

void FUN_00006d98(void)

{
  int iVar1;
  int iVar2;
  undefined1 *puVar3;
  
  iVar2 = FUN_00009e60(0,4);
  DAT_0001b6fc = iVar2;
  if (iVar2 == 0) {
    FUN_00011d90("igmp_init: no space for router_alert\n");
  }
  else {
    puVar3 = *(undefined1 **)(iVar2 + 0x14);
    *puVar3 = 0x94;
    iVar1 = DAT_0001b6fc;
    *(undefined1 **)(iVar2 + 0x14) = puVar3 + 1;
    puVar3 = *(undefined1 **)(iVar1 + 0x14);
    *puVar3 = 4;
    iVar2 = DAT_0001b6fc;
    *(undefined1 **)(iVar1 + 0x14) = puVar3 + 1;
    puVar3 = *(undefined1 **)(iVar2 + 0x14);
    *puVar3 = 0;
    iVar1 = DAT_0001b6fc;
    *(undefined1 **)(iVar2 + 0x14) = puVar3 + 1;
    puVar3 = *(undefined1 **)(iVar1 + 0x14);
    *puVar3 = 0;
    *(undefined1 **)(iVar1 + 0x14) = puVar3 + 1;
    DAT_0001b6f8 = 0;
    DAT_0001b6f0 = FUN_00017ad8(FUN_00006d5c,0,1000);
    DAT_0001b6f4 = FUN_00017ad8(FUN_00006cd0,0,100);
  }
  return;
}


================================================================