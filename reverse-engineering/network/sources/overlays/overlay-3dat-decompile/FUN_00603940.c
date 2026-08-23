FUNCTION FUN_00603940 @ 0x00603940  size=176
CALLERS (1): FUN_00601d50@0x00601d50
CALLEES (3): FUN_005af2e0@0x005af2e0, FUN_005af2c0@0x005af2c0, FUN_005af1e0@0x005af1e0
----------------------------------------------------------------

void FUN_00603940(void)

{
  undefined2 *puVar1;
  long lVar2;
  long lVar3;
  
  FUN_005af2e0(0x12);
  lVar2 = (long)cRam006c553a;
  puVar1 = (undefined2 *)(iRam003435d4 + 0xcd5ac + cRam006c555c * 0x80);
  if (9 < lVar2) {
    lVar2 = 9;
  }
  for (lVar3 = 0; lVar3 < lVar2; lVar3 = (long)((int)lVar3 + 1)) {
    FUN_005af2c0(*puVar1);
    FUN_005af1e0(0x34,(int)lVar3 * 0x14 + 0x92,0,puVar1 + 1);
    puVar1 = puVar1 + 0x40;
  }
  return;
}



================================================================