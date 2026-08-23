FUNCTION FUN_005e2060 @ 0x005e2060  size=1788
CALLERS (3): FUN_005e4840@0x005e4840, FUN_005cd3e0@0x005cd3e0, FUN_005dc010@0x005dc010
CALLEES (6): FUN_005e2030@0x005e2030, FUN_005e0440@0x005e0440, FUN_005ddb40@0x005ddb40, FUN_005ddc20@0x005ddc20, FUN_005de330@0x005de330, FUN_005e00e0@0x005e00e0
----------------------------------------------------------------

void FUN_005e2060(void)

{
  char cVar1;
  short sVar2;
  int iVar3;
  undefined8 uVar4;
  long lVar5;
  
  iVar3 = iRam00701070;
  if (*(char *)(iRam00701070 + 0x5c3) == '\0') {
    if (*(char *)(iRam00701070 + 0x34) == '\0') {
      FUN_005e0440(0,0,0x44200000,(float)(int)*(short *)(iRam00701070 + 0x1a),0xffffffffff000001);
      FUN_005e0440(0,(float)(0x1c0 - *(short *)(iRam00701070 + 0x1c)),0x44200000,0x43e00000,
                   0xffffffffff000001);
      if (*(char *)(iRam00701070 + 0x36) == '\0') {
        FUN_005e0440(0,(float)(int)*(short *)(iRam00701070 + 0x1a),
                     (float)(int)*(short *)(iRam00701070 + 0x1e),
                     (float)(0x1c0 - *(short *)(iRam00701070 + 0x1c)),0xffffffffff000001);
        FUN_005e0440((float)(0x280 - *(short *)(iRam00701070 + 0x20)),
                     (float)(int)*(short *)(iRam00701070 + 0x1a),0x44200000,
                     (float)(0x1c0 - *(short *)(iRam00701070 + 0x1c)),0xffffffffff000001);
      }
    }
    else {
      FUN_005e0440(0,0,0x44200000,(float)(int)*(short *)(iRam00701070 + 0x1a),0xffffffffff000000);
      FUN_005e0440(0,(float)(int)*(short *)(iRam00701070 + 0x1a),
                   (float)(int)*(short *)(iRam00701070 + 0x1e),
                   (float)(0x1c0 - *(short *)(iRam00701070 + 0x1c)),0xffffffffff000000);
      FUN_005e0440(0,(float)(0x1c0 - *(short *)(iRam00701070 + 0x1c)),0x44200000,0x43e00000,
                   0xffffffffff000000);
      FUN_005e0440((float)(0x280 - *(short *)(iRam00701070 + 0x20)),
                   (float)(int)*(short *)(iRam00701070 + 0x1a),0x44200000,
                   (float)(0x1c0 - *(short *)(iRam00701070 + 0x1c)),0xffffffffff000000);
    }
  }
  else {
    uVar4 = FUN_005e00e0(2);
    FUN_005ddb40(0xffffffffffffffff,uVar4,0,0,0x280,*(undefined2 *)(iVar3 + 0x1a),0xf8,0xf8);
    sVar2 = *(short *)(iRam00701070 + 0x1c);
    uVar4 = FUN_005e00e0(2);
    FUN_005ddb40(0xffffffffffffffff,uVar4,0,0x1c0 - sVar2,0x280,sVar2,0xf8,0xf8);
    switch(*(undefined1 *)(iRam00701070 + 0x5c3)) {
    case 1:
      uVar4 = FUN_005de330(9,5);
      FUN_005ddc20(0x42400000,0x41880000,0xd,0xffffffffffffffff,1,0x23,uVar4);
      break;
    case 2:
    case 3:
      uVar4 = FUN_005de330(9,6);
      FUN_005ddc20(0x42400000,0x41880000,0xd,0xffffffffffffffff,1,0x23,uVar4);
      break;
    case 4:
    case 5:
      uVar4 = FUN_005de330(9,7);
      FUN_005ddc20(0x42400000,0x41880000,0xd,0xffffffffffffffff,1,0x23,uVar4);
      break;
    case 6:
      uVar4 = FUN_005de330(9,4);
      FUN_005ddc20(0x42400000,0x41880000,0xd,0xffffffffffffffff,1,0x23,uVar4);
      break;
    case 7:
      uVar4 = FUN_005de330(9,8);
      FUN_005ddc20(0x42400000,0x41880000,0xd,0xffffffffffffffff,1,0x23,uVar4);
      break;
    case 9:
      iVar3 = *(int *)(*(int *)(iRam00701068 + 0x5ffc0) + 0x60);
      if ((iVar3 != 0) && (iVar3 != 0x6466b8)) {
        FUN_005ddc20(0x42400000,0x41700000,0xd,0xffffffffffffffff,1,0x23);
      }
    }
    if ((int)(*(ushort *)(iRam00701070 + 0x18) & 0x100) >> 8 != 0) {
      lVar5 = func_0x0010a050(iRam00701070 + 0x33b);
      if (lVar5 == 0) {
        uVar4 = FUN_005e00e0(0);
        FUN_005ddb40(0xffffffffffffffff,uVar4,0x1e0,0x1e,0x48,0x18,0x80,0x60);
        uVar4 = FUN_005e00e0(0);
        FUN_005ddb40(0xffffffffffffffff,uVar4,0x228,0x1e,0x18,0x18,0xa0,0);
      }
      else {
        uVar4 = FUN_005e00e0(0);
        FUN_005ddb40(0xffffffffffffffff,uVar4,0x1e0,0x1e,0x48,0x18,0x80,0x80);
        uVar4 = FUN_005e00e0(0);
        FUN_005ddb40(0xffffffffffffffff,uVar4,0x228,0x1e,0x18,0x18,0xa0,0);
      }
    }
  }
  if (((*(ushort *)(iRam00701070 + 0x18) & 1) == 0) &&
     (((*(char *)(iRam00701068 + 0x68e83) != '\0' || (*(char *)(iRam00701068 + 0x68e84) != '\x02'))
      || (*(char *)(iRam00701068 + 0x68e85) != '\x01')))) {
    FUN_005e2030();
  }
  if (*(char *)(iRam00701070 + 0x36) == '\0') {
    *(undefined1 *)(iRam00701070 + 0x3a) = 0;
  }
  else {
    cVar1 = *(char *)(iRam00701070 + 0x3a);
    if (cVar1 < '\x01') {
      if (cVar1 < '\0') {
        *(char *)(iRam00701070 + 0x3a) = cVar1 + '\x01';
        iVar3 = *(char *)(iRam00701070 + 0x3a) * 0xff;
        if (iVar3 < 0) {
          iVar3 = iVar3 + 0xf;
        }
        FUN_005e0440(0,0,0x44200000,0x43e00000,((iVar3 >> 4) + 0xff) * 0x1000000);
      }
    }
    else {
      *(char *)(iRam00701070 + 0x3a) = cVar1 + -1;
      iVar3 = *(char *)(iRam00701070 + 0x3a) * 0xff;
      if (iVar3 < 0) {
        iVar3 = iVar3 + 0xf;
      }
      FUN_005e0440(0,0,0x44200000,0x43e00000,(iVar3 >> 4) << 0x18);
    }
  }
  return;
}



================================================================