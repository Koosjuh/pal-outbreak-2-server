
void FUN_001cfc90(uint param_1,uint param_2,uint param_3)

{
  int iVar1;
  ulong uVar2;
  int iVar3;
  int *piVar4;
  undefined *puVar5;
  undefined1 auStack_110 [272];
  
  FUN_001cbc20((uint)bRam005a9048 * 0x30 + 0x2100);
  FUN_001a7b70(0x15,0);
  FUN_001a7b70(1,0);
  FUN_001a7b70(0x12,0);
  FUN_001a7b70(0x62,0);
  FUN_001a7b70(0xc,0);
  FUN_001a7b70(0x66,1);
  FUN_001a7b70(2,0);
  if (cRam00343577 == '\0') {
    uRam003f99cc = FUN_001ab460(0x400,7);
    uRam003f99dc = 0;
    FUN_001cce80(param_3 & 0xff | (param_1 & 0xff) << 0x10 | (param_2 & 0xff) << 8,
                 0xffffffffffffffff,0x3f91c4,2);
  }
  iVar3 = iRam003435bc;
  uRam003ce334 = 0x3f91c4;
  iRam003ce33c = 0;
  piVar4 = (int *)(iRam003435bc + 0x200000);
  iRam003ce340 = 0;
  iRam003ce344 = 0;
  FUN_00106b60(auStack_110,0,0x100);
  if (cRam00343577 == '\0') {
    FUN_00109728(auStack_110,0x24cbb0,uRam003c34d8,uRam0034357a,uRam0034357a,uRam0034357c,
                 uRam0034357e);
    uVar2 = FUN_001cb360(auStack_110,piVar4,1,0);
  }
  else {
    FUN_00109728(auStack_110,0x24cbd0,uRam0034357a,uRam0034357c,uRam0034357e);
    uVar2 = FUN_001a0df0(auStack_110,piVar4);
  }
  if (uVar2 != 0) {
    iVar1 = *piVar4;
    puVar5 = &DAT_00200004 + iVar3;
    iVar3 = iVar1 * 8;
    FUN_001069a8(0x3ce2b0,puVar5,iVar3);
    piVar4 = (int *)(puVar5 + iVar3);
    iRam003ce344 = *piVar4;
    piVar4 = piVar4 + 1;
    FUN_001069a8(0x3cdc90,piVar4,iRam003ce344 * 0xc);
    piVar4 = piVar4 + iRam003ce344 * 3;
    iVar3 = *piVar4;
    if (sRam003433a8 != 0) {
      if ((0x20 < iVar3) || (0x5000 < uVar2)) {
        while ((uRam003434a0 & 0x8000) == 0) {
          FUN_001a9050();
          FUN_001a7a80(1);
          if (iVar3 < 0x21) {
            FUN_001abf00(0xd,10,2,0xffffffffffffffff,0x24cc10,uVar2);
          }
          else {
            FUN_001abf00(0xd,10,2,0xffffffffffffffff,0x24cbf0,iVar3);
          }
          FUN_001abf00(0xd,0xb,2,0xffffffffffffffff,0x24cc30);
          FUN_001abf00(0xd,0xd,2,0xffffffffffffffff,0x24cc40);
          FUN_001b2470(1);
        }
      }
      FUN_001a7a80(0xc);
    }
    FUN_001069a8(0x3cdcb0,piVar4 + 1,iVar3 * 0x30);
    func_0x005f7f20(piVar4 + 1 + iVar3 * 0xc,0x3ce31c,0x3e9350);
    iRam003ce33c = iVar1;
    iRam003ce340 = iVar3;
  }
  return;
}

