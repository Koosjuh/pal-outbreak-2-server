
void FUN_001a0eb0(undefined1 param_1,undefined1 param_2,undefined1 param_3)

{
  int iVar1;
  long lVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  undefined *puVar6;
  int iVar7;
  int iVar8;
  undefined1 auStack_150 [256];
  undefined1 auStack_50 [4];
  int iStack_4c;
  int iStack_3c;
  int iStack_2c;
  int iStack_1c;
  int iStack_c;
  
  iVar1 = iRam003435bc;
  FUN_00109728(auStack_150,0x23ade0,param_1,param_2,param_3);
  lVar2 = FUN_001a0df0(auStack_150,iVar1);
  if (0 < lVar2) {
    FUN_001069a8(auStack_50,iVar1,0x50);
    iVar8 = 0;
    bRam005a9048 = bRam005a9048 ^ 1;
    iVar7 = iRam003435bc + 0x180000;
    puVar6 = &DAT_00240000 + iRam003435bc;
    piVar5 = (int *)(iVar1 + iStack_4c);
    iVar3 = *piVar5;
    iVar4 = (uint)bRam005a9048 * 0x80 + 0x1800;
    while( true ) {
      piVar5 = piVar5 + 1;
      if (iVar3 <= iVar8) break;
      FUN_001a0a50(uRam0029bc20,*piVar5,iVar7);
      FUN_001a79b0(iVar7,puVar6);
      FUN_001cba30(puVar6,iVar4);
      iVar4 = iVar4 + 1;
      iVar8 = iVar8 + 1;
    }
    FUN_001841d0();
    FUN_001cbc20((uint)bRam005a9048 * 0x80 + 0x1800);
    uRam004de3a8 = FUN_001ab460(0x80,6);
    uRam004de3b8 = 0;
    FUN_001ce2d0(0x4ddba0,2,iVar1 + iStack_3c,iVar1 + iStack_2c,0);
    FUN_001841d0();
    for (iVar3 = 0; iVar3 < (int)(uint)uRam004de3b2; iVar3 = iVar3 + 1) {
      *(undefined1 *)(iVar3 + 0x4de3e0) = 1;
    }
    if (iStack_1c != 0) {
      FUN_001cbc20((uint)bRam005a9048 * 0x30 + 0x2100);
      FUN_001a7b70(0x15,0);
      FUN_001a7b70(1,0);
      FUN_001a7b70(0x12,0);
      FUN_001a7b70(0x62,0);
      FUN_001a7b70(0xc,0);
      FUN_001a7b70(0x66,1);
      FUN_001a7b70(2,0);
      uRam003f99cc = FUN_001ab460(0x400,7);
      uRam003f99dc = 0;
      FUN_001ce2d0(0x3f91c4,2,iVar1 + iStack_1c,iVar1 + iStack_c,0);
    }
  }
  return;
}

