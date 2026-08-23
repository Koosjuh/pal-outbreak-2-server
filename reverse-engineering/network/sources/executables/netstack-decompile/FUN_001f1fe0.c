
undefined4 FUN_001f1fe0(uint *param_1)

{
  long lVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  uint auStack_100 [36];
  undefined1 auStack_70 [4];
  undefined4 uStack_6c;
  undefined4 uStack_68;
  int aiStack_50 [4];
  
  FUN_00115300(0);
  while( true ) {
    lVar1 = FUN_00115a98(0x37e9e0,0xffffffff80000211,0);
    if (lVar1 < 0) {
      FUN_00114ac8(0x25a818);
      return 0xffffffff;
    }
    if (iRam0037ea04 != 0) break;
    iVar3 = 0x10000;
    do {
      iVar3 = iVar3 + -1;
    } while (iVar3 != -1);
  }
  uStack_6c = 1;
  uStack_68 = 1;
  lVar1 = CreateSema(auStack_70);
  DAT_0024e430 = (undefined4)lVar1;
  if (lVar1 == -1) {
    FUN_00114ac8(0x25a830);
    return 0xffffffff;
  }
  lVar1 = FUN_001f22a0(auStack_100);
  if (lVar1 == 0) {
    FUN_001f27c8(0,aiStack_50);
    if (((aiStack_50[0] == 0) && (0 < (int)auStack_100[0])) && ((int)auStack_100[0] < 0x80)) {
      uRam0037e940 = auStack_100[0];
      *param_1 = auStack_100[0];
      iRam0037e944 = 0x37eb10;
      uVar4 = 0;
      if (auStack_100[0] != 0) {
        do {
          iVar3 = uVar4 * 0x38;
          uVar4 = uVar4 + 1;
          puVar2 = (undefined4 *)(iVar3 + iRam0037e944);
          puVar2[2] = 1;
          puVar2[0xd] = 0;
          *puVar2 = 1;
          puVar2[1] = 1;
          puVar2[3] = 0;
          puVar2[4] = 0;
          puVar2[5] = 0;
          puVar2[6] = 0;
          puVar2[7] = 0;
          puVar2[0xb] = 0;
          puVar2[0xc] = 0;
          *(undefined2 *)(puVar2 + 8) = 0;
        } while (uVar4 < auStack_100[0]);
      }
      uRam0037e950 = 0;
      lVar1 = AddIntcHandler(3,0x1f2f40,0xffffffffffffffff);
      uRam0037e9dc = (undefined4)lVar1;
      if (lVar1 < 0) {
        DeleteSema(DAT_0024e430);
        DAT_0024e430 = 0xffffffff;
        return 0xffffffff;
      }
      FUN_001133e8(3);
      return 0;
    }
  }
  DeleteSema(DAT_0024e430);
  DAT_0024e430 = 0xffffffff;
  return 0xffffffff;
}

