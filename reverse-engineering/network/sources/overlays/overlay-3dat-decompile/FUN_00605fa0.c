FUNCTION FUN_00605fa0 @ 0x00605fa0  size=84
CALLERS (1): FUN_005ac400@0x005ac400
CALLEES (1): FUN_00606000@0x00606000
----------------------------------------------------------------

undefined8 FUN_00605fa0(void)

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = FUN_00606000(1);
  if (lVar1 == 0) {
    uVar2 = 1;
  }
  else if (lVar1 == -2) {
    uVar2 = 0;
  }
  else {
    uVar2 = 0xffffffffffffffff;
  }
  return uVar2;
}



================================================================