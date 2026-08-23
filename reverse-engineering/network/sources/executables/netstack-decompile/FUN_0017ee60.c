
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0017ee60(void)

{
  uint uVar1;
  undefined4 *puVar2;
  long lVar3;
  int iVar4;
  undefined1 auStack_70 [4];
  undefined4 uStack_6c;
  undefined4 uStack_68;
  
  if (ram0x0022f590 == 1) {
    return 1;
  }
  uRam0027e540 = 0;
  FUN_00115300(0);
  while (lVar3 = FUN_00115a98(0x27af88,0xffffffff80001300,0), -1 < lVar3) {
    iVar4 = 0x10000;
    if (iRam0027afac != 0) goto LAB_0017ef24;
    do {
      iVar4 = iVar4 + -1;
    } while (iVar4 != -1);
  }
LAB_0017f018:
  FUN_0017fd00(0x2589d0);
  return 0;
LAB_0017ef24:
  lVar3 = FUN_00115a98(0x27afb0,0xffffffff8000131b,0);
  if (lVar3 < 0) goto LAB_0017f018;
  iVar4 = 0x10000;
  if (iRam0027afd4 != 0) goto LAB_0017ef7c;
  do {
    iVar4 = iVar4 + -1;
  } while (iVar4 != -1);
  goto LAB_0017ef24;
LAB_0017ef7c:
  while (lVar3 = FUN_00115a98(0x27afd8,0xffffffff8000131c,0), -1 < lVar3) {
    iVar4 = 0x10000;
    if (iRam0027affc != 0) {
      uVar1 = FUN_0017ee08();
      if ((int)uVar1 >> 8 != 3) {
        FUN_00114ac8(0x2589e8);
        FUN_00114ac8(0x258a10,3,0,(int)uVar1 >> 8,uVar1 & 0xff);
        return 0;
      }
      uStack_68 = 1;
      uStack_6c = 0x7f;
      lVar3 = CreateSema(auStack_70);
      uRam0027e540 = (undefined4)lVar3;
      if (-1 < lVar3) {
        iVar4 = 0xf;
        puVar2 = (undefined4 *)0x27e53c;
        do {
          *puVar2 = 0;
          iVar4 = iVar4 + -1;
          puVar2 = puVar2 + -1;
        } while (-1 < iVar4);
        FUN_0017fd00(0x258a38,0x27e480);
        FUN_0017f0e8(0x27e480);
        ram0x0022f590 = 1;
        return 1;
      }
      return 0;
    }
    do {
      iVar4 = iVar4 + -1;
    } while (iVar4 != -1);
  }
  goto LAB_0017f018;
}

