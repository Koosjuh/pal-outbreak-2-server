
undefined8 FUN_001afc40(char *param_1)

{
  undefined8 uVar1;
  long lVar2;
  long lVar3;
  uint uVar4;
  undefined8 uVar5;
  int iVar6;
  undefined1 auStack_100 [256];
  
  uVar5 = 0;
  if ((((cRam00337cc8 == '\x04') || (cRam00337cc8 == '\x03')) || (uVar1 = 1, cRam00337cc8 == '\x02')
      ) || (cRam00337cc8 == '\x01')) {
    uVar4 = (uint)(byte)param_1[cRam00337cc8 + -1];
    if (uVar4 == 0) {
      cRam00337cc8 = cRam00337cc8 + '\x01';
      uVar1 = uVar5;
    }
    else {
      if (uVar4 < 0x3a) {
        if (uVar4 == 2) {
          uVar4 = FUN_001a7120(1);
          FUN_00109728(auStack_100,0x245c78,0x245c50,*(undefined4 *)((uVar4 & 1) * 4 + 0x3c3da4));
        }
        else if (uVar4 == 3) {
          uVar4 = FUN_001a7120(1);
          FUN_00109728(auStack_100,0x245c78,0x245c50,*(undefined4 *)((uVar4 & 1) * 4 + 0x3c3d94));
        }
        else if (uVar4 == 4) {
          uVar4 = FUN_001a7120(1);
          FUN_00109728(auStack_100,0x245c78,0x245c50,*(undefined4 *)((uVar4 & 1) * 4 + 0x3c3d9c));
        }
        else {
          FUN_00109728(auStack_100,0x245c78,0x245c50,*(undefined4 *)(uVar4 * 4 + 0x3c3d8c));
        }
      }
      else {
        FUN_00109728(auStack_100,0x245c78,0x245c50,*(undefined4 *)(uVar4 * 4 + 0x3c3cc4));
      }
      iVar6 = iRam003435bc + 0x4000;
      lVar2 = FUN_001cb360(auStack_100,iVar6,1,0);
      if (lVar2 < 1) {
        uVar1 = 0xffffffffffffffff;
      }
      else {
        FUN_001a5a80(iVar6);
        cRam00337cc8 = cRam00337cc8 + '\x01';
        uVar1 = uVar5;
      }
    }
  }
  else if (cRam00337cc8 == '\0') {
    if (*param_1 == '\0') {
      uVar1 = 0xffffffffffffffff;
    }
    else {
      FUN_001a5a50(iRam003435bc + 0x8003fU & 0xffffffc0,iRam003435bc + 0xc003fU & 0xffffffc0);
      FUN_00109728(auStack_100,0x245c38,0x245c50);
      uVar4 = iRam003435bc + 0x403fU & 0xffffffc0;
      lVar2 = FUN_001cb360(auStack_100,uVar4,1,0);
      if (lVar2 < 1) {
        uVar1 = 0xffffffffffffffff;
      }
      else {
        FUN_00109728(auStack_100,0x245c68,0x245c50);
        lVar3 = FUN_001cb360(auStack_100,uVar4 + (int)lVar2,1,0);
        if (lVar3 < 1) {
          uVar1 = 0xffffffffffffffff;
        }
        else {
          FUN_001a59b0(uVar4,lVar2,lVar3);
          cRam00337cc8 = cRam00337cc8 + '\x01';
          uVar1 = uVar5;
        }
      }
    }
  }
  return uVar1;
}

