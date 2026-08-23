
void FUN_001d33d0(void)

{
  undefined4 *puVar1;
  undefined8 uVar2;
  long lVar3;
  undefined1 auStack_80 [128];
  
  puVar1 = puRam003435ec;
  if (cRam00343577 == '\0') {
    if (cRam0034359d == '\0') {
      FUN_00109728(auStack_80,0x24d248,0x24d260,uRam0034357a);
    }
    else {
      FUN_00109728(auStack_80,0x24d248,0x24d260,uRam0034357a);
      uVar2 = FUN_001cf2b0(auStack_80);
      FUN_00109eb8(auStack_80,uVar2);
    }
    lVar3 = FUN_001cb360(auStack_80,puVar1,1,0);
    if (lVar3 < 1) {
      *puVar1 = 0;
    }
  }
  else {
    if (cRam0034359d == '\0') {
      FUN_00109728(auStack_80,0x24d278,uRam0034357a);
    }
    else {
      FUN_00109728(auStack_80,0x24d278,uRam0034357a);
      uVar2 = FUN_001cf2b0(auStack_80);
      FUN_00109eb8(auStack_80,uVar2);
    }
    lVar3 = FUN_001a0df0(auStack_80,puVar1);
    if (lVar3 < 1) {
      *puVar1 = 0;
    }
  }
  return;
}

