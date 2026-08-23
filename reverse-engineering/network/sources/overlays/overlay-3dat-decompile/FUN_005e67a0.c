FUNCTION FUN_005e67a0 @ 0x005e67a0  size=1452
CALLERS (1): FUN_005e7070@0x005e7070
CALLEES (4): FUN_005e5e50@0x005e5e50, FUN_005d9ea0@0x005d9ea0, FUN_005d9e30@0x005d9e30, FUN_005e6630@0x005e6630
----------------------------------------------------------------

void FUN_005e67a0(undefined8 param_1)

{
  byte bVar1;
  long lVar2;
  uint uVar3;
  byte bVar4;
  undefined1 auStack_310 [784];
  
  uVar3 = (uint)param_1 & 0xff;
  *(int *)(iRam007012a0 + 0xd964) = *(int *)(iRam007012a0 + 0xd964) + 5;
  bVar1 = bRam008744f8;
  switch(uVar3) {
  case 1:
    FUN_005d9e30();
    lVar2 = FUN_005e5e50(auStack_310,0x100);
    bVar1 = bRam008744f8;
    if (lVar2 == 0) {
      FUN_005d9ea0(6,0,auStack_310);
      lVar2 = FUN_005e5e50(auStack_310,0x100);
      bVar1 = bRam008744f8;
      if (lVar2 == 0) {
        FUN_005d9ea0(2,0,auStack_310);
        lVar2 = FUN_005e5e50(auStack_310,0x100);
        bVar1 = bRam008744f8;
        if (lVar2 == 0) {
          FUN_005d9ea0(4,0,auStack_310);
          lVar2 = FUN_005e5e50(auStack_310,0x100);
          bVar1 = bRam008744f8;
          if (lVar2 == 0) {
            FUN_005d9ea0(5,0,auStack_310);
            bVar1 = bRam008744f8;
          }
        }
      }
    }
    break;
  case 2:
    FUN_005d9e30();
    lVar2 = FUN_005e5e50(auStack_310,0x100);
    bVar1 = bRam008744f8;
    if (lVar2 == 0) {
      FUN_005d9ea0(6,0,auStack_310);
      lVar2 = FUN_005e5e50(auStack_310,0x100);
      bVar1 = bRam008744f8;
      if (lVar2 == 0) {
        FUN_005d9ea0(1,0,auStack_310);
        lVar2 = FUN_005e5e50(auStack_310,0x100);
        bVar1 = bRam008744f8;
        if (lVar2 == 0) {
          FUN_005d9ea0(2,0,auStack_310);
          lVar2 = FUN_005e5e50(auStack_310,0x100);
          bVar1 = bRam008744f8;
          if (lVar2 == 0) {
            FUN_005d9ea0(4,0,auStack_310);
            lVar2 = FUN_005e5e50(auStack_310,0x100);
            bVar1 = bRam008744f8;
            if (lVar2 == 0) {
              FUN_005d9ea0(5,0,auStack_310);
              bVar1 = bRam008744f8;
            }
          }
        }
      }
    }
    break;
  case 4:
    func_0x00106b60(0x874500,0,0xa28);
    FUN_005d9e30(param_1);
    lVar2 = FUN_005e5e50(auStack_310,0x100);
    bVar1 = bRam008744f8;
    if (lVar2 == 0) {
      FUN_005d9ea0(6,0,auStack_310);
      lVar2 = func_0x0010a338(auStack_310,0x6481a8,2);
      if (lVar2 == 0) {
        bVar4 = 0;
        while ((lVar2 = FUN_005e5e50(auStack_310,0x100), bVar1 = bVar4, lVar2 == 0 && (bVar4 < 10)))
        {
          bVar1 = bVar4 + 1;
          FUN_005d9ea0(7,bVar4,auStack_310);
          lVar2 = FUN_005e5e50(auStack_310,0x100);
          if (lVar2 != 0) break;
          FUN_005d9ea0(0xc,bVar4,auStack_310);
          lVar2 = FUN_005e5e50(auStack_310,0x100);
          if (lVar2 != 0) break;
          FUN_005d9ea0(0xd,bVar4,auStack_310);
          lVar2 = FUN_005e5e50(auStack_310,0x100);
          if (lVar2 != 0) break;
          FUN_005d9ea0(8,bVar4,auStack_310);
          FUN_005e6630(bVar4,auStack_310);
          lVar2 = FUN_005e5e50(auStack_310,0x100);
          if (lVar2 != 0) break;
          FUN_005d9ea0(9,bVar4,auStack_310);
          lVar2 = FUN_005e5e50(auStack_310,0x100);
          if (lVar2 != 0) break;
          FUN_005d9ea0(10,bVar4,auStack_310);
          bVar4 = bVar1;
        }
      }
      else {
        lVar2 = FUN_005e5e50(auStack_310,0x100);
        bVar1 = bRam008744f8;
        if (lVar2 == 0) {
          FUN_005d9ea0(0xb,0,auStack_310);
          bVar1 = bRam008744f8;
        }
      }
    }
    break;
  case 5:
    FUN_005d9e30();
    lVar2 = FUN_005e5e50(auStack_310,0x100);
    bVar1 = bRam008744f8;
    if (lVar2 == 0) {
      FUN_005d9ea0(6,0,auStack_310);
      lVar2 = func_0x0010a338(auStack_310,0x6481a8,2);
      bVar1 = bRam008744f8;
      if ((lVar2 != 0) &&
         (lVar2 = FUN_005e5e50(auStack_310,0x100), bVar1 = bRam008744f8, lVar2 == 0)) {
        FUN_005d9ea0(0xb,0,auStack_310);
        bVar1 = bRam008744f8;
      }
    }
    break;
  case 6:
    if (*(char *)(iRam007012a0 + 0x192) == '\0') {
      FUN_005d9e30(uVar3 + 1 & 0xff);
      lVar2 = FUN_005e5e50(auStack_310,0x100);
      bVar1 = bRam008744f8;
      if (lVar2 == 0) {
        FUN_005d9ea0(0x10,0,auStack_310);
        lVar2 = func_0x0010a338(auStack_310,0x6481b0,2);
        bVar1 = bRam008744f8;
        if (lVar2 != 0) {
          bVar4 = 0;
          while ((lVar2 = FUN_005e5e50(auStack_310,0x100), bVar1 = bRam008744f8, lVar2 == 0 &&
                 (bVar4 < 10))) {
            FUN_005d9ea0(0x11,bVar4,auStack_310);
            lVar2 = FUN_005e5e50(auStack_310,0x100);
            bVar1 = bRam008744f8;
            if (lVar2 != 0) break;
            FUN_005d9ea0(0x12,bVar4,auStack_310);
            lVar2 = FUN_005e5e50(auStack_310,0x100);
            bVar1 = bRam008744f8;
            if (lVar2 != 0) break;
            FUN_005d9ea0(0x13,bVar4,auStack_310);
            bVar4 = bVar4 + 1;
          }
        }
      }
    }
    else {
      *(undefined1 *)(iRam007012a0 + 0x192) = 0;
      FUN_005d9e30();
      lVar2 = FUN_005e5e50(auStack_310,0x100);
      bVar1 = bRam008744f8;
      if (lVar2 == 0) {
        FUN_005d9ea0(0xe,0,auStack_310);
        lVar2 = FUN_005e5e50(auStack_310,0x100);
        bVar1 = bRam008744f8;
        if (lVar2 == 0) {
          FUN_005d9ea0(0xf,0,auStack_310);
          return;
        }
      }
    }
    break;
  case 7:
    lVar2 = FUN_005e5e50(auStack_310,0x100);
    bVar1 = bRam008744f8;
    if (lVar2 == 0) {
      FUN_005d9ea0(6,0,auStack_310);
      lVar2 = FUN_005e5e50(auStack_310,0x100);
      bVar1 = bRam008744f8;
      if (lVar2 == 0) {
        FUN_005d9ea0(0xb,0,auStack_310);
        bVar1 = bRam008744f8;
      }
    }
  }
  bRam008744f8 = bVar1;
  *(undefined1 *)(iRam007012a0 + 0x191) = 0;
  return;
}



================================================================