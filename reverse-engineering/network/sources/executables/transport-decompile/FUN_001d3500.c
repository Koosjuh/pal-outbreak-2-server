
void FUN_001d3500(long param_1)

{
  undefined4 *puVar1;
  undefined8 uVar2;
  long lVar3;
  undefined1 auStack_80 [128];
  
  puVar1 = puRam003435e8;
  if (param_1 != 0) {
    puVar1 = (undefined4 *)(iRam003435dc + 0x10000);
  }
  if (cRam00343577 == '\0') {
    FUN_00109728(auStack_80,0x24d288,0x24d298,uRam0034357a);
    uVar2 = FUN_001cf2b0(auStack_80);
    lVar3 = FUN_001cb360(uVar2,puVar1,1,0);
  }
  else {
    FUN_00109728(auStack_80,0x24d2a8,uRam0034357a);
    uVar2 = FUN_001cf2b0(auStack_80);
    lVar3 = FUN_001a0df0(uVar2,puVar1);
  }
  if (lVar3 < 1) {
    *puVar1 = 0;
  }
  return;
}

