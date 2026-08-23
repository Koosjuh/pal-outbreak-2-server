FUNCTION FUN_00606780 @ 0x00606780  size=508
CALLERS (1): FUN_006063c0@0x006063c0
CALLEES (5): FUN_00605d60@0x00605d60, FUN_005bea50@0x005bea50, FUN_005be9f0@0x005be9f0, FUN_005bea00@0x005bea00, FUN_005bea10@0x005bea10
----------------------------------------------------------------

void FUN_00606780(void)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  undefined1 auStack_30 [16];
  undefined1 auStack_20 [12];
  undefined1 auStack_14 [20];
  
  if (sRam0070cdca < 0) {
    sRam0070cdc8 = 99;
    uRam0035b723 = 5;
    sRam0070cdca = sRam0070cdca + -1;
  }
  else {
    sRam0070cdca = sRam0070cdca + -1;
    lVar3 = FUN_00605d60(uRam0035a6f4,0x7018c0,0x7012c0,0x600);
    if (lVar3 == -1) {
      sRam0070cdc8 = 99;
      uRam0035b723 = 5;
    }
    else if ((lVar3 != 0) && (CONCAT11(uRam007018c2,uRam007018c3) == 0x1031)) {
      func_0x001ca6b0(auStack_30,0x8710f1,(ushort)bRam007018c6 * 0x100 + (ushort)bRam007018c7);
      FUN_005be9f0(0x7018d0,0x1031);
      FUN_005bea00(0x7018d0,2);
      bRam007018da = bRam007018c6;
      bRam007018db = bRam007018c7;
      FUN_005bea50(0x7018d0,auStack_30,10);
      FUN_005bea10(0x7018d0);
      func_0x001069a8(auStack_20,0x7018d4,0xc);
      func_0x001069a8(auStack_14,0x7018e0,uRam007018d0);
      uVar1 = (uint)uRam007018d0;
      iVar2 = func_0x001ee590(uRam0035a6f4,auStack_20,(short)(uVar1 + 0xc));
      if (uVar1 + 0xc == iVar2) {
        sRam0070cdc8 = sRam0070cdc8 + 1;
      }
      else {
        sRam0070cdc8 = 99;
        uRam0035b723 = 5;
      }
    }
  }
  return;
}



================================================================