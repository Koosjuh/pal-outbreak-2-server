
void FUN_001d2b30(void)

{
  undefined1 auStack_100 [256];
  
  if (cRam00343577 == '\0') {
    FUN_00109728(auStack_100,0x24d000,0x24d018,uRam0034357a,uRam0034357c,uRam0034357e);
    uRam003435cc = FUN_001cb360(auStack_100,uRam003435d0,1,0);
  }
  else {
    FUN_00109728(auStack_100,0x24d030,uRam0034357a,uRam0034357c,uRam0034357e);
    uRam003435cc = FUN_001a0df0(auStack_100,uRam003435d0);
  }
  return;
}

