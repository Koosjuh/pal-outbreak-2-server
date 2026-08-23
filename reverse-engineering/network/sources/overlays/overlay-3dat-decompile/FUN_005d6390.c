FUNCTION FUN_005d6390 @ 0x005d6390  size=200
CALLERS (1): FUN_005cc980@0x005cc980
CALLEES (4): FUN_005d59f0@0x005d59f0, FUN_005d5a40@0x005d5a40, FUN_005d5900@0x005d5900, FUN_005d5cc0@0x005d5cc0
----------------------------------------------------------------

undefined4 FUN_005d6390(void)

{
  undefined4 uVar1;
  long lVar2;
  char cVar3;
  
  if (*(char *)(iRam00701068 + 0x60dcb) == '\x01') {
    FUN_005d5cc0(iRam00701068 + 0x4f7a0);
    cVar3 = *(char *)(iRam00701068 + 0x60dcc) + '\x01';
    *(char *)(iRam00701068 + 0x60dcc) = cVar3;
    uVar1 = 0;
    if (cVar3 != '\x02') {
      lVar2 = func_0x00109d70(iRam00701068 + 0x4f7a0,0x8710fc);
      if (lVar2 == 0) {
        FUN_005d5900();
        FUN_005d5a40();
        uVar1 = 2;
      }
      else {
        FUN_005d59f0();
        uVar1 = 2;
      }
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



================================================================