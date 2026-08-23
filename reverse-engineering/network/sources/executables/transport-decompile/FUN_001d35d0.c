
void FUN_001d35d0(void)

{
  ulong uVar1;
  long lVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined1 auStack_80 [128];
  
  uVar1 = func_0x0072e9f0();
  if ((bRam004f9474 != uVar1) && (func_0x0072ecb0(), -1 < (long)uVar1)) {
    iVar6 = 0;
    iVar5 = iRam003435e8 + 0x6000;
    while( true ) {
      iVar3 = iRam003435e8;
      if (iRam004fa6e8 <= iVar6) break;
      iVar3 = iVar6 * 0x1100;
      if (*(short *)(iVar3 + 0x4e5c58) == 0) {
        uVar4 = (uint)*(byte *)(iVar3 + 0x4e5c40);
      }
      else if (*(short *)(iVar3 + 0x4e5c58) == 0x5b) {
        uVar4 = (uint)*(byte *)(iVar3 + 0x4e5c40);
      }
      else {
        uVar4 = *(byte *)(iVar3 + 0x4e5c40) + 9;
      }
      if (cRam00343577 == '\0') {
        FUN_00109728(auStack_80,0x24d310,uRam0034357a,uRam0034357a,uVar1,uVar4,
                     (&PTR_DAT_0024d2f0)[bRam0034359d]);
      }
      else {
        FUN_00109728(auStack_80,0x24d340,uRam0034357a,uVar1,uVar4,(&PTR_DAT_0024d2f0)[bRam0034359d])
        ;
      }
      lVar2 = FUN_001cb360(auStack_80,iVar5,0x10001,0);
      if ((lVar2 < 1) || (0x12800 < lVar2)) {
        *(undefined1 *)(*(byte *)(iVar3 + 0x4e5c40) + 0x7cf964) = 0xff;
      }
      else {
        func_0x0072e960(iVar5,0,iVar6);
      }
      iVar6 = iVar6 + 1;
      iVar5 = iVar5 + 0x12800;
    }
    if (cRam00343577 == '\0') {
      FUN_00109728(auStack_80,0x24d360,uRam0034357a,uRam0034357a,uVar1,
                   (&PTR_DAT_0024d2f0)[bRam0034359d]);
    }
    else {
      FUN_00109728(auStack_80,0x24d390,uRam0034357a,uVar1,(&PTR_DAT_0024d2f0)[bRam0034359d]);
    }
    lVar2 = FUN_001cb360(auStack_80,iVar3 + 0x50000,0x10001,0);
    if ((0 < lVar2) && (lVar2 < 0xc000)) {
      func_0x0072e960(iVar3 + 0x50000,0,4);
    }
    iVar5 = 0;
    iVar6 = iRam003435e8 + 0x5c000;
    while( true ) {
      iVar3 = iRam003435e8;
      if (iRam004fa6e8 <= iVar5) break;
      iVar3 = iVar5 * 0x1100;
      if (*(short *)(iVar3 + 0x4e5c58) == 0) {
        uVar4 = (uint)*(byte *)(iVar3 + 0x4e5c40);
      }
      else if (*(short *)(iVar3 + 0x4e5c58) == 0x5b) {
        uVar4 = (uint)*(byte *)(iVar3 + 0x4e5c40);
      }
      else {
        uVar4 = *(byte *)(iVar3 + 0x4e5c40) + 9;
      }
      if (cRam00343577 == '\0') {
        FUN_00109728(auStack_80,0x24d3b0,uRam0034357a,uRam0034357a,uVar1,uVar4,
                     (&PTR_DAT_0024d2f0)[bRam0034359d]);
      }
      else {
        FUN_00109728(auStack_80,0x24d3e0,uRam0034357a,uVar1,uVar4,(&PTR_DAT_0024d2f0)[bRam0034359d])
        ;
      }
      lVar2 = FUN_001cb360(auStack_80,iVar6,0x10001,0);
      if ((lVar2 < 1) || (0x8000 < lVar2)) {
        *(undefined1 *)(*(byte *)(iVar3 + 0x4e5c40) + 0x7cf964) = 0xff;
      }
      else {
        func_0x0072e960(iVar6,1,iVar5);
      }
      iVar5 = iVar5 + 1;
      iVar6 = iVar6 + 0x8000;
    }
    if (cRam00343577 == '\0') {
      FUN_00109728(auStack_80,0x24d400,uRam0034357a,uRam0034357a,uVar1,
                   (&PTR_DAT_0024d2f0)[bRam0034359d]);
    }
    else {
      FUN_00109728(auStack_80,0x24d430,uRam0034357a,uVar1,(&PTR_DAT_0024d2f0)[bRam0034359d]);
    }
    lVar2 = FUN_001cb360(auStack_80,iVar3 + 0x7c000,0x10001,0);
    if ((0 < lVar2) && (lVar2 < 0x8000)) {
      func_0x0072e960(iVar3 + 0x7c000,1,4);
    }
    bRam004f9474 = (byte)uVar1;
  }
  return;
}

