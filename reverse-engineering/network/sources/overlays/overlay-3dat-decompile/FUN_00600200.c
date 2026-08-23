FUNCTION FUN_00600200 @ 0x00600200  size=2200
CALLERS (1): FUN_005ff9f0@0x005ff9f0
CALLEES (9): FUN_00600b60@0x00600b60, FUN_00602230@0x00602230, FUN_005f4b80@0x005f4b80, FUN_005b14b0@0x005b14b0, FUN_006020e0@0x006020e0, FUN_005f4be0@0x005f4be0, FUN_005b0b40@0x005b0b40, FUN_00602700@0x00602700, FUN_005b09b0@0x005b09b0
----------------------------------------------------------------

void FUN_00600200(undefined8 param_1)

{
  int iVar1;
  long lVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar1 = iRam003435d4;
  iVar4 = (int)param_1;
  cVar3 = *(char *)(iVar4 + 0xf);
  if (cVar3 != '\x02') {
    if (cVar3 == '\x01') {
      *(short *)(iVar4 + 0x16) = *(short *)(iVar4 + 0x16) + -1;
      if (-1 < *(short *)(iVar4 + 0x16)) {
        return;
      }
      *(char *)(iVar4 + 0xf) = *(char *)(iVar4 + 0xf) + '\x01';
      *(undefined1 *)(iVar4 + 0x454) = 1;
      return;
    }
    if (cVar3 != '\0') {
      return;
    }
    if (*(char *)(iVar4 + 0x10) == '\0') {
      FUN_006020e0();
      cVar3 = *(char *)(iVar4 + 0xf);
    }
    else {
      FUN_00602230();
      cVar3 = *(char *)(iVar4 + 0xf);
    }
    *(char *)(iVar4 + 0xf) = cVar3 + '\x01';
    *(undefined2 *)(iVar4 + 0x16) = 10;
    *(undefined1 *)(iVar4 + 0x45a) = 1;
    *(undefined2 *)(iVar4 + 0x43a) = 1;
    uRam0070b468 = 0;
    *(undefined1 *)(iVar4 + 0x9cc) = 0;
    func_0x001069a8(iRam003435d4 + 0xcb4ec,
                    iRam003435d4 + 0xc942c +
                    (*(char *)(iVar4 + 0x908) * 0x82 + (int)*(char *)(iVar4 + 0x908)) * 0x10,0x830);
    func_0x001069a8(iRam003435d4 + 0xcf5c0,
                    iVar4 + (*(char *)(iVar4 + 0x908) * 0x3c - (int)*(char *)(iVar4 + 0x908)) * 0x10
                    + 0x30c0,0xd4);
    func_0x001069a8(iVar4 + 0x3cdc,
                    iVar4 + (*(char *)(iVar4 + 0x908) * 0x3c - (int)*(char *)(iVar4 + 0x908)) * 0x10
                    + 0x2e1c,0x3b0);
    return;
  }
  if (*(char *)(iVar4 + 0x10) == '\0') {
    iVar6 = iRam003435d4 + 0xcb4ec;
    iVar5 = iRam003435d4 + 0xc942c;
    if (*(char *)(iRam003435d4 + 0xcb4ef) == '\0') {
      for (iVar7 = 0; iVar7 < 4; iVar7 = iVar7 + 1) {
        if (((*(char *)(iVar5 + 4) != '\0') &&
            (lVar2 = func_0x00109d70(iVar1 + 0xcb4f0,iVar5 + 4), lVar2 == 0)) &&
           (*(char *)(iVar5 + 3) != '\0')) {
          func_0x001069a8(iVar6,iVar5,0x830);
          break;
        }
        iVar5 = iVar5 + 0x830;
      }
    }
    sRam0070b460 = func_0x007deaf0(iVar1 + 0xcb51c);
    FUN_005f4b80();
    lVar2 = FUN_005f4be0();
    if (lVar2 == 0) {
      *(undefined1 *)(iVar4 + 0x992) = 1;
      lVar2 = FUN_005b09b0(iVar4 + 0x907,2,3);
      if (lVar2 == 0) {
        if (5 < sRam0070b460) {
          FUN_005b0b40(0x70b468,sRam0070b460 + -5,2);
        }
        lVar2 = FUN_005b14b0(0x10);
        if (lVar2 == 0) {
          lVar2 = FUN_005b14b0(0x200);
          if (lVar2 == 0) {
            lVar2 = FUN_00600b60(param_1);
            if (lVar2 != 0) {
              uRam0070b468 = 0;
              func_0x001069a8(iRam003435d4 + 0xcb4ec,
                              iRam003435d4 + 0xc942c +
                              (*(char *)(iVar4 + 0x908) * 0x82 + (int)*(char *)(iVar4 + 0x908)) *
                              0x10,0x830);
              func_0x001069a8(iRam003435d4 + 0xcf5c0,
                              iVar4 + (*(char *)(iVar4 + 0x908) * 0x3c -
                                      (int)*(char *)(iVar4 + 0x908)) * 0x10 + 0x30c0,0xd4);
              func_0x001069a8(iVar4 + 0x3cdc,
                              iVar4 + (*(char *)(iVar4 + 0x908) * 0x3c -
                                      (int)*(char *)(iVar4 + 0x908)) * 0x10 + 0x2e1c,0x3b0);
              cVar3 = *(char *)(iVar4 + 0x3f6c);
              goto LAB_006009c8;
            }
          }
          else if (*(char *)(iVar4 + 0x907) != '\x01') {
            func_0x001b0140(2);
            *(undefined1 *)(iVar4 + 0x907) = 1;
          }
        }
        else {
          if (*(char *)(iVar4 + 0x907) == '\x02') {
            *(undefined1 *)(iVar4 + 0xf) = 0;
            *(byte *)(iVar4 + 0x10) = *(byte *)(iVar4 + 0x10) ^ 1;
            *(undefined1 *)(iVar4 + 0x909) = *(undefined1 *)(iVar4 + 0x907);
            if (*(char *)((*(char *)(iVar4 + 0x908) * 0x3c - (int)*(char *)(iVar4 + 0x908)) * 0x10 +
                          iVar4 + 0x309c) == '\0') {
              *(undefined1 *)(iVar4 + 0x908) = 0;
            }
            if (*(char *)(iVar4 + 0x10) == '\0') {
              func_0x001069a8(iRam003435d4 + 0xcb4ec,
                              iRam003435d4 + 0xc942c +
                              (*(char *)(iVar4 + 0x908) * 0x82 + (int)*(char *)(iVar4 + 0x908)) *
                              0x10,0x830);
              func_0x001069a8(iRam003435d4 + 0xcf5c0,
                              iVar4 + (*(char *)(iVar4 + 0x908) * 0x3c -
                                      (int)*(char *)(iVar4 + 0x908)) * 0x10 + 0x30c0,0xd4);
              func_0x001069a8(iVar4 + 0x3cdc,
                              iVar4 + (*(char *)(iVar4 + 0x908) * 0x3c -
                                      (int)*(char *)(iVar4 + 0x908)) * 0x10 + 0x2e1c,0x3b0);
            }
            func_0x001b0140(1);
          }
          else if (*(char *)(iVar4 + 0x907) == '\x01') {
            *(char *)(iVar4 + 0xe) = *(char *)(iVar4 + 0xe) + '\x01';
            *(undefined1 *)(iVar4 + 0xf) = 2;
            *(undefined1 *)(iVar4 + 0x10) = 0;
            *(undefined1 *)(iVar4 + 0x992) = 0;
            *(undefined2 *)(iVar4 + 0x43a) = 0;
            func_0x001b0140();
            return;
          }
          *(undefined2 *)(iVar4 + 0x16) = 1;
        }
      }
    }
  }
  else {
    *(undefined1 *)(iVar4 + 0x992) = 1;
    lVar2 = FUN_00600b60();
    if (lVar2 == 0) {
      lVar2 = FUN_005b14b0(0x80);
      if (lVar2 == 0) {
        lVar2 = FUN_005b14b0(0x40);
        if (lVar2 == 0) {
          if ((cRam006c553a < '\n') ||
             (lVar2 = FUN_005b09b0(iVar4 + 0x9cc,cRam006c553a + -9,2), lVar2 == 0)) {
            FUN_005b09b0(iVar4 + 0x907,2,3);
            lVar2 = FUN_005b14b0(0x10);
            if (lVar2 == 0) {
              lVar2 = FUN_005b14b0(0x200);
              if ((lVar2 != 0) && (*(char *)(iVar4 + 0x907) != '\x01')) {
                func_0x001b0140(2);
                *(undefined1 *)(iVar4 + 0x907) = 1;
              }
            }
            else {
              if (*(char *)(iVar4 + 0x907) == '\x02') {
                *(undefined1 *)(iVar4 + 0xf) = 0;
                *(byte *)(iVar4 + 0x10) = *(byte *)(iVar4 + 0x10) ^ 1;
                *(undefined1 *)(iVar4 + 0x909) = *(undefined1 *)(iVar4 + 0x907);
                if (*(char *)((*(char *)(iVar4 + 0x908) * 0x3c - (int)*(char *)(iVar4 + 0x908)) *
                              0x10 + iVar4 + 0x309c) == '\0') {
                  *(undefined1 *)(iVar4 + 0x908) = 0;
                }
                if (*(char *)(iVar4 + 0x10) != '\0') {
                  func_0x001069a8(iRam003435d4 + 0xcb4ec,
                                  iRam003435d4 + 0xc942c +
                                  (*(char *)(iVar4 + 0x908) * 0x82 + (int)*(char *)(iVar4 + 0x908))
                                  * 0x10,0x830);
                  func_0x001069a8(iRam003435d4 + 0xcf5c0,
                                  iVar4 + (*(char *)(iVar4 + 0x908) * 0x3c -
                                          (int)*(char *)(iVar4 + 0x908)) * 0x10 + 0x30c0,0xd4);
                  func_0x001069a8(iVar4 + 0x3cdc,
                                  iVar4 + (*(char *)(iVar4 + 0x908) * 0x3c -
                                          (int)*(char *)(iVar4 + 0x908)) * 0x10 + 0x2e1c,0x3b0);
                }
                func_0x001b0140(1);
              }
              else if (*(char *)(iVar4 + 0x907) == '\x01') {
                *(char *)(iVar4 + 0xe) = *(char *)(iVar4 + 0xe) + '\x01';
                *(undefined1 *)(iVar4 + 0xf) = 2;
                *(undefined1 *)(iVar4 + 0x10) = 0;
                *(undefined1 *)(iVar4 + 0x992) = 0;
                *(undefined2 *)(iVar4 + 0x43a) = 0;
                func_0x001b0140();
                return;
              }
              *(undefined2 *)(iVar4 + 0x16) = 1;
            }
          }
        }
        else {
          *(char *)(iVar4 + 0x9ab) = *(char *)(iVar4 + 0x9ab) + -1;
          *(byte *)(iVar4 + 0x9ab) = *(byte *)(iVar4 + 0x9ab) & 3;
          *(undefined1 *)(iVar4 + 0x9cc) = 0;
        }
      }
      else {
        *(char *)(iVar4 + 0x9ab) = *(char *)(iVar4 + 0x9ab) + '\x01';
        *(byte *)(iVar4 + 0x9ab) = *(byte *)(iVar4 + 0x9ab) & 3;
        *(undefined1 *)(iVar4 + 0x9cc) = 0;
      }
    }
    else {
      func_0x001069a8(iRam003435d4 + 0xcb4ec,
                      iRam003435d4 + 0xc942c +
                      (*(char *)(iVar4 + 0x908) * 0x82 + (int)*(char *)(iVar4 + 0x908)) * 0x10,0x830
                     );
      func_0x001069a8(iRam003435d4 + 0xcf5c0,
                      iVar4 + (*(char *)(iVar4 + 0x908) * 0x3c - (int)*(char *)(iVar4 + 0x908)) *
                              0x10 + 0x30c0,0xd4);
      func_0x001069a8(iVar4 + 0x3cdc,
                      iVar4 + (*(char *)(iVar4 + 0x908) * 0x3c - (int)*(char *)(iVar4 + 0x908)) *
                              0x10 + 0x2e1c,0x3b0);
    }
    FUN_00602700(param_1);
  }
  cVar3 = *(char *)(iVar4 + 0x3f6c);
LAB_006009c8:
  if (cVar3 == '\0') {
    uRam0070b468 = 0;
    func_0x001069a8(iRam003435d4 + 0xcb4ec,
                    iRam003435d4 + 0xc942c +
                    (*(char *)(iVar4 + 0x908) * 0x82 + (int)*(char *)(iVar4 + 0x908)) * 0x10,0x830);
    func_0x001069a8(iRam003435d4 + 0xcf5c0,
                    iVar4 + (*(char *)(iVar4 + 0x908) * 0x3c - (int)*(char *)(iVar4 + 0x908)) * 0x10
                    + 0x30c0,0xd4);
    func_0x001069a8(iVar4 + 0x3cdc,
                    iVar4 + (*(char *)(iVar4 + 0x908) * 0x3c - (int)*(char *)(iVar4 + 0x908)) * 0x10
                    + 0x2e1c,0x3b0);
  }
  return;
}



================================================================