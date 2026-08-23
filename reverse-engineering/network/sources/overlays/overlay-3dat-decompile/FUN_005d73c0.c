FUNCTION FUN_005d73c0 @ 0x005d73c0  size=80
CALLERS (1): FUN_005d0a40@0x005d0a40
CALLEES (2): FUN_005d6a50@0x005d6a50, FUN_005d7310@0x005d7310
----------------------------------------------------------------

bool FUN_005d73c0(void)

{
  undefined8 uVar1;
  long lVar2;
  
  uVar1 = FUN_005d7310();
  lVar2 = FUN_005d6a50(uVar1,1);
  if (lVar2 == 0) {
    uVar1 = FUN_005d7310();
    FUN_005d6a50(uVar1,2);
  }
  return lVar2 == 0;
}



================================================================