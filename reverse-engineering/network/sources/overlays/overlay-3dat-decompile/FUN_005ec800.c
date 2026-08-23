FUNCTION FUN_005ec800 @ 0x005ec800  size=172
CALLERS (1): FUN_005ef220@0x005ef220
CALLEES (0): 
----------------------------------------------------------------

uint FUN_005ec800(byte *param_1)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  
  bVar1 = *param_1;
  uVar3 = (uint)bVar1;
  uVar2 = (uint)*(byte *)(*(short *)(iRam007012a0 + 0x124) + iRam007012a0 + 0x168);
  if (uVar3 == 0x2d) {
    bVar1 = param_1[1];
    if (((bVar1 < 0x3a) && (0x2f < bVar1)) && (uVar2 = 3 - (bVar1 - 0x30), (int)uVar2 < 1)) {
      uVar2 = 1;
    }
  }
  else if (uVar3 == 0x2b) {
    bVar1 = param_1[1];
    if (((bVar1 < 0x3a) && (0x2f < bVar1)) && (uVar2 = bVar1 - 0x2d, 7 < (int)uVar2)) {
      uVar2 = 7;
    }
  }
  else if ((bVar1 < 0x3a) && (0x2f < bVar1)) {
    uVar2 = uVar3 - 0x30;
  }
  return uVar2;
}



================================================================