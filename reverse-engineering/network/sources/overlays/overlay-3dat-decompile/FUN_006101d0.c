FUNCTION FUN_006101d0 @ 0x006101d0  size=940
CALLERS (2): FUN_00610580@0x00610580, FUN_0060f910@0x0060f910
CALLEES (12): FUN_0060ed40@0x0060ed40, FUN_0060eba0@0x0060eba0, FUN_00618530@0x00618530, FUN_0060ec60@0x0060ec60, FUN_00618230@0x00618230, FUN_00618520@0x00618520, FUN_0060f0c0@0x0060f0c0, FUN_0060eaa0@0x0060eaa0, FUN_00618210@0x00618210, FUN_00618510@0x00618510, FUN_0060ef20@0x0060ef20, FUN_0060e710@0x0060e710, ...
----------------------------------------------------------------

/* WARNING: Removing unreachable block (ram,0x0061032c) */
/* WARNING: Removing unreachable block (ram,0x00610334) */

undefined8 FUN_006101d0(void)

{
  char cVar1;
  undefined8 uVar2;
  long lVar3;
  long lVar4;
  byte bVar5;
  
  switch(*(char *)(iRam0070d1c0 + 0x2c)) {
  case '\0':
    *(char *)(iRam0070d1c0 + 0x2c) = *(char *)(iRam0070d1c0 + 0x2c) + '\x01';
    *(undefined1 *)(iRam0070d1c0 + 0x25) = 0;
    *(undefined1 *)(iRam0070d1c0 + 0x24) = 0;
    *(undefined1 *)(iRam0070d1c0 + 0x27) = 0;
    *(undefined1 *)(iRam0070d1c0 + 0x2f) = *(undefined1 *)(iRam0070d1c0 + 0x26);
    FUN_00618210(iRam0070d1c0 + 0x10d8);
    func_0x00106b60(iRam0070d1c0 + 0x1180,0,0x19d40);
    func_0x00106b60(iRam0070d1c0 + 600,0,600);
  case '\x01':
    lVar3 = FUN_00618230(iRam0070d1c0 + 0x10d8);
    if (-1 < lVar3) {
      *(byte *)(iRam0070d1c0 + 0x25) =
           *(byte *)(iRam0070d1c0 + 0x25) |
           (byte)((int)(uint)(*(byte *)(iRam0070d1c0 + 0x10da) | *(byte *)(iRam0070d1c0 + 0x10db))
                 >> 1) & 3;
      if (*(char *)(iRam0070d1c0 + 0x25) == '\0') {
        *(undefined1 *)(iRam0070d1c0 + 0x2c) = 0;
        return 0xfffffffffffffffe;
      }
      *(undefined1 *)(iRam0070d1c0 + 0x2c) = 2;
    }
    break;
  case '\x02':
  case '\x03':
    do {
      bVar5 = *(byte *)(iRam0070d1c0 + 0x2f);
      if (((uint)*(byte *)(iRam0070d1c0 + 0x25) & 1 << (bVar5 & 0x1f)) != 0) break;
      *(byte *)(iRam0070d1c0 + 0x2f) = bVar5 + 1 & 1;
      bVar5 = *(byte *)(iRam0070d1c0 + 0x2f);
    } while (bVar5 != *(byte *)(iRam0070d1c0 + 0x26));
    if ((*(char *)(iRam0070d1c0 + 0x2c) == '\x03') && (bVar5 == *(byte *)(iRam0070d1c0 + 0x26))) {
      *(undefined1 *)(iRam0070d1c0 + 0x2c) = 0;
      *(undefined1 *)(iRam0070d1c0 + 0x26) = *(undefined1 *)(iRam0070d1c0 + 0x2f);
      FUN_00618510(iRam0070d1c0 + 0x10d8,*(undefined1 *)(iRam0070d1c0 + 0x2f));
      return 0xffffffffffffffff;
    }
    *(undefined1 *)(iRam0070d1c0 + 0x2c) = 4;
    *(undefined1 *)(iRam0070d1c0 + 0x26) = *(undefined1 *)(iRam0070d1c0 + 0x2f);
    FUN_00618510(iRam0070d1c0 + 0x10d8,*(undefined1 *)(iRam0070d1c0 + 0x2f));
    return 0;
  case '\x04':
    lVar3 = FUN_00618530(iRam0070d1c0 + 0x10d8);
    if (lVar3 != -2) {
      if (lVar3 != -1) {
        return 0xffffffffffffffff;
      }
      *(undefined1 *)(iRam0070d1c0 + 0x2c) = 5;
    }
    break;
  case '\x05':
    uVar2 = FUN_00618520(iRam0070d1c0 + 0x10d8);
    FUN_0060f0c0(iRam0070d1c0 + 0x1180,uVar2);
    *(undefined1 *)(iRam0070d1c0 + 0x24) = 0;
    lVar3 = FUN_0060ef20(iRam0070d1c0 + 0x1180);
    if (lVar3 != 0) {
      return 0xfffffffffffffffd;
    }
    FUN_0060eaa0(iRam0070d1c0 + 0x1180,0);
    cVar1 = FUN_0060eba0(iRam0070d1c0 + 0x1180);
    *(char *)(iRam0070d1c0 + 0x24) = cVar1;
    FUN_0060ec60(iRam0070d1c0 + 0x1180);
    FUN_0060eaa0(iRam0070d1c0 + 0x1180,2);
    lVar3 = FUN_0060eba0(iRam0070d1c0 + 0x1180);
    FUN_0060ec60(iRam0070d1c0 + 0x1180);
    FUN_0060eaa0(iRam0070d1c0 + 0x1180,1);
    lVar4 = FUN_0060eba0(iRam0070d1c0 + 0x1180);
    FUN_0060ec60(iRam0070d1c0 + 0x1180);
    if (lVar4 != 0 && (lVar3 != 0 && cVar1 != '\0')) {
      FUN_0060ed40(iRam0070d1c0 + 0x1180);
      FUN_0060e710(iRam0070d1c0 + 0x1180,iRam0070d1c0 + 600);
      *(undefined1 *)(iRam0070d1c0 + 0x2c) = 0;
      return 1;
    }
    *(undefined1 *)(iRam0070d1c0 + 0x2c) = 0;
    return 0xffffffffffffffff;
  }
  return 0;
}



================================================================