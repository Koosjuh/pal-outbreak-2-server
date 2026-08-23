
void FUN_001d3f60(void)

{
  undefined1 *puVar1;
  long lVar2;
  undefined1 auStack_100 [256];
  
  puVar1 = puRam0034361c;
  FUN_00109728(auStack_100,0x24d578,0x24d590,uRam0034357a);
  lVar2 = FUN_001cb360(auStack_100,puVar1,0x10001,0);
  if (lVar2 < 1) {
    *puVar1 = 0xff;
  }
  return;
}

