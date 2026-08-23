FUNCTION FUN_005b7f00 @ 0x005b7f00  size=100
CALLERS (6): FUN_005b7f70@0x005b7f70, FUN_005b7de0@0x005b7de0, FUN_005b7320@0x005b7320, FUN_005b7cd0@0x005b7cd0, FUN_005b7270@0x005b7270, FUN_005b6ea0@0x005b6ea0
CALLEES (0): 
----------------------------------------------------------------

char FUN_005b7f00(byte *param_1)

{
  byte bVar1;
  char cVar2;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  
  bVar1 = *param_1;
  uVar5 = (uint)bVar1;
  cVar2 = '\x01';
  if ((bVar1 & 0x80) != 0) {
    bVar3 = 0;
    if ((bVar1 & 0x40) == 0) {
      cVar2 = -1;
    }
    else {
      while ((uVar4 = uVar5 << 1, bVar3 < 5 && (uVar5 = uVar4 & 0xff, (uVar4 & 0x80) != 0))) {
        cVar2 = cVar2 + '\x01';
        bVar3 = bVar3 + 1;
      }
    }
  }
  return cVar2;
}



================================================================