FUNCTION FUN_00606000 @ 0x00606000  size=916
CALLERS (1): FUN_00605fa0@0x00605fa0
CALLEES (1): FUN_00605d30@0x00605d30
----------------------------------------------------------------

undefined8 FUN_00606000(void)

{
  byte bVar1;
  undefined8 uVar2;
  long lVar3;
  byte *pbVar4;
  int iVar5;
  undefined4 uStack_4;
  
  uStack_4 = 0;
  if (sRam0070cdd0 == 2) {
    sRam0070cdd2 = sRam0070cdd2 + -1;
    if (sRam0070cdd2 < 1) {
      sRam0070cdd4 = sRam0070cdd4 + 1;
      sRam0070cdd2 = 0x3c;
      if (sRam0070cdd4 < 0x15) {
        lVar3 = func_0x001ee430(uRam0035a6f4,0x35a714);
        if (lVar3 < 0) {
          func_0x001ee650(uRam0035a6f4);
          func_0x001ee680(0x35a6f4);
          uVar2 = 0xffffffffffffffff;
        }
        else {
          uVar2 = 0xfffffffffffffffe;
          if (sRam0035a714 == 4) {
            uVar2 = 0;
            sRam0070cdd2 = 0;
            sRam0070cdd4 = 0;
            sRam0070cdd0 = 0;
          }
        }
      }
      else {
        func_0x001ee650(uRam0035a6f4);
        func_0x001ee680(0x35a6f4);
        uVar2 = 0xffffffffffffffff;
        sRam0070cdd2 = 0;
        sRam0070cdd4 = 0;
      }
    }
    else {
      uVar2 = 0xfffffffffffffffe;
    }
  }
  else if (sRam0070cdd0 == 1) {
    lVar3 = func_0x001c08e0(0x70cdd6,0x70bff0,&uStack_4,0x70bfb0);
    uVar2 = 0xffffffffffffffff;
    if (lVar3 == -1) {
      uRam0070cdd6 = 0;
    }
    else {
      if (lVar3 == 1) {
        uRam0070cdd6 = 0;
      }
      else if (lVar3 == 0) {
        return 0xfffffffffffffffe;
      }
      lVar3 = FUN_00605d30(uStack_4,(uRam0070bfa0 & 0xff) << 8 | (int)(uint)uRam0070bfa0 >> 8,0);
      uRam0035a6f4 = (undefined4)lVar3;
      if (lVar3 < 0) {
        uVar2 = 0xffffffffffffffff;
      }
      else {
        sRam0070cdd4 = 0;
        sRam0070cdd0 = 2;
        sRam0070cdd2 = 0x3c;
        uVar2 = 0xfffffffffffffffe;
      }
    }
  }
  else if (sRam0070cdd0 == 0) {
    uRam0070bfb0 = 0;
    uRam0070bfa0 = 0;
    uRam0070bff0 = 0;
    uRam0070cdd6 = 0;
    func_0x00106b60(0x70bfb0,0,0x40);
    for (iVar5 = 0; iVar5 < 10; iVar5 = iVar5 + 1) {
      lVar3 = func_0x0010a338(0x874410,iVar5 * 0x101 + 0x8716e3,0xc);
      if (lVar3 == 0) {
        func_0x0010a4f0(0x70bfb0,iVar5 * 0x62 + 0x87130f,0x40);
        func_0x001069a8(0x874f3c,iVar5 * 0x104 + 0x87450d,0x40);
        break;
      }
    }
    for (pbVar4 = (byte *)0x70bfb0; (bVar1 = *pbVar4, bVar1 != 0x3a && (bVar1 != 0));
        pbVar4 = pbVar4 + 1) {
    }
    if (bVar1 == 0x3a) {
      *pbVar4 = 0;
      while( true ) {
        pbVar4 = pbVar4 + 1;
        if ((*pbVar4 == 0x20) || (*pbVar4 == 0)) break;
        uRam0070bfa0 = uRam0070bfa0 * 10 + (*pbVar4 - 0x30);
      }
    }
    uVar2 = 0xfffffffffffffffe;
    sRam0070cdd0 = 1;
  }
  else {
    uVar2 = 0xffffffffffffffff;
  }
  return uVar2;
}



================================================================