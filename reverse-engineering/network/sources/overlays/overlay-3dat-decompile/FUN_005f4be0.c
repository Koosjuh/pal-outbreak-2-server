FUNCTION FUN_005f4be0 @ 0x005f4be0  size=600
CALLERS (5): FUN_005fec30@0x005fec30, FUN_005fede0@0x005fede0, FUN_005f7c80@0x005f7c80, FUN_0062d640@0x0062d640, FUN_00600200@0x00600200
CALLEES (10): FUN_00637180@0x00637180, FUN_006345e0@0x006345e0, FUN_00634540@0x00634540, FUN_005f4b20@0x005f4b20, FUN_005b14b0@0x005b14b0, FUN_00637170@0x00637170, FUN_00634ab0@0x00634ab0, FUN_006371d0@0x006371d0, FUN_00632ce0@0x00632ce0, FUN_005c4af0@0x005c4af0
----------------------------------------------------------------

byte FUN_005f4be0(void)

{
  char cVar1;
  undefined2 uVar2;
  long lVar3;
  ulong uVar4;
  
  if (cRam006c4ba3 == '\0') {
    lVar3 = FUN_005b14b0(0x100);
    if (lVar3 != 0) {
      bRam006c50fb = bRam006c50fb ^ 1;
      if (bRam006c50fb != 0) {
        func_0x001b0140(1);
        return bRam006c50fb;
      }
      func_0x001b0140(2);
      return bRam006c50fb;
    }
    if (bRam006c50fb != 0) {
      lVar3 = FUN_005b14b0(0x200);
      if (lVar3 != 0) {
        bRam006c50fb = 0;
        func_0x001b0140(2);
        return 1;
      }
      return bRam006c50fb;
    }
    return 0;
  }
  if (cRam006c4ba4 == '\0') {
    cRam006c4ba4 = '\x01';
    func_0x00106b60(0x6c50fc,0,0x80);
    FUN_006371d0(0x42980000,0x118);
    FUN_006345e0(0,0,0x40,0x6c50fc);
    FUN_00634540(1);
    func_0x001b0380(0,0x42);
  }
  else {
    lVar3 = FUN_00637170();
    if (lVar3 == 0) {
      cRam006c4ba3 = 0;
      cRam006c4ba4 = 0;
      return 1;
    }
    cVar1 = FUN_00634ab0(0x6c50fc,uRam006c4610,uRam006c4618 | uRam006c4620);
    if (cVar1 != -1) {
      if (cVar1 != '\x01') {
        if (cVar1 != '\0') {
          return 1;
        }
        lVar3 = func_0x001ae3e0(0x6c50fc);
        if (lVar3 < 1) {
          return 1;
        }
        uVar2 = func_0x001ae3e0(0x6c50fc);
        FUN_005c4af0(uRam006c4b90,0x6c50fc,uVar2);
        func_0x00106b60(0x6c50fc,0,0x80);
        cRam006c4ba3 = 0;
        cRam006c4ba4 = 0;
        FUN_00637180();
        return 1;
      }
      FUN_00632ce0(0x6c50fc);
      uVar4 = FUN_005f4b20(0x6c50fc);
      if (0 < (long)uVar4) {
        FUN_005c4af0(uRam006c4b90,0x6c50fc,uVar4 & 0xffff);
      }
      cRam006c4ba3 = '\0';
      cRam006c4ba4 = '\0';
    }
    FUN_00637180();
  }
  return 1;
}



================================================================