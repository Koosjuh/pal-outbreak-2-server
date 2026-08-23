FUNCTION FUN_005d1d60 @ 0x005d1d60  size=288
CALLERS (1): FUN_005d1e80@0x005d1e80
CALLEES (0): 
----------------------------------------------------------------

undefined4 FUN_005d1d60(void)

{
  ushort uVar1;
  undefined4 uVar2;
  uint uVar3;
  
  uVar3 = (uint)*(byte *)(iRam00715da8 + 0x49d);
  if (uVar3 == 0x28) {
    uVar2 = 0xffffffff;
  }
  else if (((uVar3 == 0x52) || (uVar3 - 0x4f < 2)) || (uVar3 == 0x51)) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar3 = (uint)*(byte *)(iRam00715da8 + 0x49c);
    if (((uVar3 == 0x52) || (uVar3 - 0x4f < 2)) || (uVar3 == 0x51)) {
      uVar2 = 0xffffffff;
    }
    else {
      uVar1 = *(ushort *)(iRam00701068 + 0x4f8a0);
      if ((((uVar1 & 4) == 0) && ((uVar1 & 1) == 0)) && (((uVar1 & 8) == 0 && ((uVar1 & 2) == 0))))
      {
        uVar1 = *(ushort *)(iRam00701068 + 0x4f8a4);
        if (((((uVar1 & 4) == 0) && ((uVar1 & 1) == 0)) && ((uVar1 & 8) == 0)) && ((uVar1 & 2) == 0)
           ) {
          uVar2 = 0xffffffff;
          if (*(char *)(iRam00701068 + 0x4f8a8) == '\0') {
            uVar2 = 1;
          }
        }
        else {
          uVar2 = 0xffffffff;
        }
      }
      else {
        uVar2 = 0xffffffff;
      }
    }
  }
  return uVar2;
}



================================================================