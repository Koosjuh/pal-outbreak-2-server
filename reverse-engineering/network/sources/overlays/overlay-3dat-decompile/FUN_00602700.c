FUNCTION FUN_00602700 @ 0x00602700  size=4588
CALLERS (2): FUN_005fede0@0x005fede0, FUN_00600200@0x00600200
CALLEES (6): FUN_0062fea0@0x0062fea0, FUN_005af810@0x005af810, FUN_006038f0@0x006038f0, FUN_005bac80@0x005bac80, FUN_005bacf0@0x005bacf0, FUN_00602670@0x00602670
----------------------------------------------------------------

void FUN_00602700(int param_1)

{
  char cVar1;
  uint uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  long lVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  ushort uVar11;
  int iVar12;
  int iVar13;
  uint *puVar14;
  ushort uVar15;
  ushort uVar16;
  int iVar17;
  undefined1 auStack_60 [96];
  
  iVar10 = iRam003435d4;
  iVar12 = param_1 + 0x1e50;
  *(undefined1 *)(param_1 + 0x9aa) = 0;
  puVar14 = (uint *)(iVar10 + 0xcf5c0);
  cVar1 = *(char *)(param_1 + 0x9ab);
  iVar9 = iVar10 + 0xcd5ac;
  if (cVar1 == '\x03') {
    lVar7 = FUN_005af810();
    if (lVar7 != 0) {
      uVar3 = FUN_005bacf0(uRam00343625);
      uVar4 = FUN_0062fea0(0x50);
      uVar5 = FUN_0062fea0(0x51);
      func_0x00109728(iVar10 + 0xcd5ae,0x649f18,uVar4,uVar3,uVar5);
      iVar9 = FUN_006038f0(iVar9,0x15,iVar10 + 0xcd5ae);
    }
    uVar3 = FUN_0062fea0(0x40);
    func_0x00109728(iVar9 + 2,0x649d70,uVar3);
    uVar3 = FUN_006038f0(iVar9,0x15,iVar9 + 2);
    iVar10 = 1;
    while( true ) {
      iVar9 = (int)uVar3;
      if ((int)(uint)bRam00341ae4 <= iVar10) break;
      lVar7 = func_0x00109d70(param_1 + 0x3f6c,param_1 + 0x1e3c);
      if (lVar7 == 0) {
        if (*(short *)(iVar12 + iVar10 * 2 + 0x1c) == 0) {
          uVar4 = FUN_0062fea0(0x43);
          func_0x00109728(iVar9 + 2,0x649d70,uVar4);
        }
        else {
          if ((*(byte *)(iVar12 + iVar10 + 0x9c) & 0xf) == 0) {
            lVar7 = FUN_0062fea0(0x43);
          }
          else {
            lVar7 = FUN_005bac80((char)iVar10);
            if (lVar7 == 0) {
              lVar7 = FUN_0062fea0(0x43);
            }
          }
          func_0x00109728(iVar9 + 2,0x649d70,lVar7);
        }
      }
      else if (*(short *)(iVar12 + iVar10 * 2 + 0x1c) == 0) {
        uVar4 = FUN_0062fea0(0x43);
        func_0x00109728(iVar9 + 2,0x649d70,uVar4);
      }
      else {
        if ((*(byte *)((int)puVar14 + iVar10 + 0x9c) & 0xf) == 0) {
          lVar7 = FUN_0062fea0(0x43);
        }
        else {
          lVar7 = FUN_005bac80((char)iVar10);
          if (lVar7 == 0) {
            lVar7 = FUN_0062fea0(0x43);
          }
        }
        func_0x00109728(iVar9 + 2,0x649d70,lVar7);
      }
      uVar3 = FUN_006038f0(uVar3,0,iVar9 + 2);
      iVar10 = iVar10 + 1;
    }
    uVar4 = FUN_0062fea0(0x41);
    func_0x00109728(iVar9 + 2,0x649d70,uVar4);
    uVar3 = FUN_006038f0(uVar3,0x15,iVar9 + 2);
    iVar10 = 1;
    while( true ) {
      iVar9 = (int)uVar3;
      if ((int)(uint)bRam00341ae4 <= iVar10) break;
      lVar7 = func_0x00109d70(param_1 + 0x3f6c,param_1 + 0x1e3c);
      if (lVar7 == 0) {
        if (*(short *)((int)puVar14 + iVar10 * 2 + 0x1c) == 0) {
          uVar4 = FUN_0062fea0(0x43);
          func_0x00109728(iVar9 + 2,0x649d70,uVar4);
        }
        else {
          if ((*(byte *)(iVar12 + iVar10 + 0x9c) & 0xf0) == 0) {
            lVar7 = FUN_0062fea0(0x43);
          }
          else {
            lVar7 = FUN_005bac80((char)iVar10);
            if (lVar7 == 0) {
              lVar7 = FUN_0062fea0(0x43);
            }
          }
          func_0x00109728(iVar9 + 2,0x649d70,lVar7);
        }
      }
      else if (*(short *)(iVar12 + iVar10 * 2 + 0x1c) == 0) {
        uVar4 = FUN_0062fea0(0x43);
        func_0x00109728(iVar9 + 2,0x649d70,uVar4);
      }
      else {
        if ((*(byte *)((int)puVar14 + iVar10 + 0x9c) & 0xf0) == 0) {
          lVar7 = FUN_0062fea0(0x43);
        }
        else {
          lVar7 = FUN_005bac80((char)iVar10);
          if (lVar7 == 0) {
            lVar7 = FUN_0062fea0(0x43);
          }
        }
        func_0x00109728(iVar9 + 2,0x649d70,lVar7);
      }
      uVar3 = FUN_006038f0(uVar3,0,iVar9 + 2);
      iVar10 = iVar10 + 1;
    }
    uVar4 = FUN_0062fea0(0x42);
    func_0x00109728(iVar9 + 2,0x649d70,uVar4);
    uVar3 = FUN_006038f0(uVar3,0x15,iVar9 + 2);
    for (iVar10 = 1; iVar10 < (int)(uint)bRam00341ae4; iVar10 = iVar10 + 1) {
      lVar7 = func_0x00109d70(param_1 + 0x3f6c,param_1 + 0x1e3c);
      iVar9 = (int)uVar3;
      if (lVar7 == 0) {
        if (*(short *)((int)puVar14 + iVar10 * 2 + 0x1c) == 0) {
          uVar4 = FUN_0062fea0(0x43);
          uVar4 = FUN_00602670(uVar4);
          func_0x00109728(iVar9 + 2,0x649d70,uVar4);
        }
        else {
          uVar2 = *(uint *)(iVar12 + iVar10 * 4 + 0x5c);
          iVar8 = 0x3b;
          if (uVar2 < 0xa4cb62) {
            iVar17 = (int)uVar2 / 0x1e;
            iVar8 = iVar17 / 0x3c;
            iVar13 = iVar8 / 0x3c;
            iVar8 = iVar8 % 0x3c;
            iVar17 = iVar17 % 0x3c;
          }
          else {
            iVar13 = 99;
            iVar17 = iVar8;
          }
          lVar7 = FUN_005bac80((char)iVar10);
          if (lVar7 == 0) {
            lVar7 = FUN_0062fea0(0x43);
          }
          if (*(short *)((int)puVar14 + iVar10 * 2 + 0x3c) == 0) {
            uVar4 = FUN_0062fea0(0x43);
            uVar4 = FUN_00602670(uVar4);
            func_0x00109728(iVar9 + 2,0x649d70,uVar4);
          }
          else {
            uVar4 = FUN_00602670(lVar7);
            uVar5 = FUN_0062fea0(99);
            uVar6 = FUN_0062fea0(100);
            FUN_0062fea0(0x65);
            func_0x00109728(iVar9 + 2,0x649f60,uVar4,iVar13,uVar5,iVar8,uVar6,iVar17);
          }
        }
      }
      else if (*(short *)(iVar12 + iVar10 * 2 + 0x1c) == 0) {
        uVar4 = FUN_0062fea0(0x43);
        uVar4 = FUN_00602670(uVar4);
        func_0x00109728(iVar9 + 2,0x649d70,uVar4);
      }
      else {
        iVar8 = 0x3b;
        if (puVar14[iVar10 + 0x17] < 0xa4cb62) {
          iVar17 = (int)puVar14[iVar10 + 0x17] / 0x1e;
          iVar8 = iVar17 / 0x3c;
          iVar13 = iVar8 / 0x3c;
          iVar8 = iVar8 % 0x3c;
          iVar17 = iVar17 % 0x3c;
        }
        else {
          iVar13 = 99;
          iVar17 = iVar8;
        }
        lVar7 = FUN_005bac80((char)iVar10);
        if (lVar7 == 0) {
          lVar7 = FUN_0062fea0(0x43);
        }
        if (*(short *)((int)puVar14 + iVar10 * 2 + 0x3c) == 0) {
          uVar4 = FUN_0062fea0(0x43);
          uVar4 = FUN_00602670(uVar4);
          func_0x00109728(iVar9 + 2,0x649d70,uVar4);
        }
        else {
          uVar4 = FUN_00602670(lVar7);
          uVar5 = FUN_0062fea0(99);
          uVar6 = FUN_0062fea0(100);
          FUN_0062fea0(0x65);
          func_0x00109728(iVar9 + 2,0x649f60,uVar4,iVar13,uVar5,iVar8,uVar6,iVar17);
        }
      }
      uVar3 = FUN_006038f0(uVar3,0,iVar9 + 2);
    }
  }
  else if (cVar1 == '\x01') {
    uVar3 = FUN_0062fea0(0x31);
    func_0x00109728(iVar10 + 0xcd5ae,0x649d70,uVar3);
    uVar3 = FUN_006038f0(iVar9,0x15,iVar10 + 0xcd5ae);
    uVar15 = *(ushort *)(iVar10 + 0xcf676);
    if (9999 < uVar15) {
      uVar15 = 9999;
    }
    uVar4 = FUN_0062fea0(0x10);
    func_0x00109728((int)uVar3 + 2,0x649f30,uVar15,uVar4);
    uVar3 = FUN_006038f0(uVar3,0,(int)uVar3 + 2);
    uVar4 = FUN_0062fea0(0x32);
    func_0x00109728((int)uVar3 + 2,0x649d70,uVar4);
    uVar3 = FUN_006038f0(uVar3,0x15,(int)uVar3 + 2);
    iVar9 = 0;
    do {
      uVar4 = FUN_0062fea0(iVar9 + 0x39);
      func_0x00109728((int)uVar3 + 2,0x649f38,uVar4,*(undefined1 *)((int)puVar14 + iVar9 + 0xc4));
      uVar3 = FUN_006038f0(uVar3,0,(int)uVar3 + 2);
      iVar9 = iVar9 + 1;
    } while (iVar9 < 4);
    uVar4 = FUN_0062fea0(0x33);
    func_0x00109728((int)uVar3 + 2,0x649d70,uVar4);
    uVar3 = FUN_006038f0(uVar3,0x15,(int)uVar3 + 2);
    uVar15 = *(ushort *)(iVar10 + 0xcf66c);
    if (9999 < uVar15) {
      uVar15 = 9999;
    }
    uVar4 = FUN_0062fea0(0x10);
    func_0x00109728((int)uVar3 + 2,0x649f30,uVar15,uVar4);
    uVar3 = FUN_006038f0(uVar3,0,(int)uVar3 + 2);
    uVar4 = FUN_0062fea0(0x34);
    func_0x00109728((int)uVar3 + 2,0x649d70,uVar4);
    uVar3 = FUN_006038f0(uVar3,0x15,(int)uVar3 + 2);
    uVar15 = *(ushort *)(iVar10 + 0xcf66e);
    if (9999 < uVar15) {
      uVar15 = 9999;
    }
    uVar4 = FUN_0062fea0(0x10);
    func_0x00109728((int)uVar3 + 2,0x649f30,uVar15,uVar4);
    uVar3 = FUN_006038f0(uVar3,0,(int)uVar3 + 2);
    uVar4 = FUN_0062fea0(0x35);
    func_0x00109728((int)uVar3 + 2,0x649d70,uVar4);
    uVar3 = FUN_006038f0(uVar3,0x15,(int)uVar3 + 2);
    uVar15 = *(ushort *)(iVar10 + 0xcf670);
    if (9999 < uVar15) {
      uVar15 = 9999;
    }
    uVar4 = FUN_0062fea0(0x36);
    uVar5 = FUN_0062fea0(0x10);
    func_0x00109728((int)uVar3 + 2,0x649f48,uVar4,uVar15,uVar5);
    uVar3 = FUN_006038f0(uVar3,0,(int)uVar3 + 2);
    uVar15 = *(ushort *)(iVar10 + 0xcf672);
    if (9999 < uVar15) {
      uVar15 = 9999;
    }
    uVar4 = FUN_0062fea0(0x37);
    uVar5 = FUN_0062fea0(0x10);
    func_0x00109728((int)uVar3 + 2,0x649f48,uVar4,uVar15,uVar5);
    uVar3 = FUN_006038f0(uVar3,0,(int)uVar3 + 2);
    uVar4 = FUN_0062fea0(0x38);
    func_0x00109728((int)uVar3 + 2,0x649d70,uVar4);
    uVar3 = FUN_006038f0(uVar3,0x15,(int)uVar3 + 2);
    uVar15 = *(ushort *)(iVar10 + 0xcf674);
    if (9999 < uVar15) {
      uVar15 = 9999;
    }
    uVar4 = FUN_0062fea0(0x10);
    func_0x00109728((int)uVar3 + 2,0x649f30,uVar15,uVar4);
    FUN_006038f0(uVar3,0,(int)uVar3 + 2);
  }
  else if (cVar1 == '\x02') {
    lVar7 = FUN_005af810();
    if (lVar7 != 0) {
      uVar3 = FUN_005bacf0(uRam00343625);
      uVar4 = FUN_0062fea0(0x50);
      uVar5 = FUN_0062fea0(0x51);
      func_0x00109728(iVar10 + 0xcd5ae,0x649f18,uVar4,uVar3,uVar5);
      iVar9 = FUN_006038f0(iVar9,0x15,iVar10 + 0xcd5ae);
    }
    uVar3 = FUN_0062fea0(0x3e);
    func_0x00109728(iVar9 + 2,0x649d70,uVar3);
    uVar3 = FUN_006038f0(iVar9,0x15,iVar9 + 2);
    for (iVar10 = 1; iVar10 < (int)(uint)bRam00341ae4; iVar10 = iVar10 + 1) {
      lVar7 = func_0x00109d70(param_1 + 0x3f6c,param_1 + 0x1e3c);
      iVar9 = iVar10 * 2;
      iVar8 = (int)uVar3;
      if (lVar7 == 0) {
        iVar9 = iVar12 + iVar10 * 2;
        uVar15 = *(ushort *)(iVar9 + 0x3c);
        if (9999 < uVar15) {
          uVar15 = 9999;
        }
        uVar11 = *(ushort *)(iVar9 + 0x1c);
        uVar16 = uVar11;
        if (9999 < uVar11) {
          uVar16 = 9999;
        }
        if (uVar11 == 0) {
          uVar4 = FUN_0062fea0(0x43);
          uVar4 = FUN_00602670(uVar4);
          uVar5 = FUN_0062fea0(0x10);
          uVar6 = FUN_0062fea0(0x10);
          func_0x00109728(iVar8 + 2,0x649f20,uVar4,uVar15,uVar5,uVar16,uVar6);
        }
        else {
          lVar7 = FUN_005bac80((char)iVar10);
          if (lVar7 == 0) {
            lVar7 = FUN_0062fea0(0x43);
          }
          uVar4 = FUN_00602670(lVar7);
          uVar5 = FUN_0062fea0(0x10);
          uVar6 = FUN_0062fea0(0x10);
          func_0x00109728(iVar8 + 2,0x649f20,uVar4,uVar15,uVar5,uVar16,uVar6);
        }
      }
      else {
        uVar15 = *(ushort *)((int)puVar14 + iVar9 + 0x3c);
        if (9999 < uVar15) {
          uVar15 = 9999;
        }
        uVar11 = *(ushort *)((int)puVar14 + iVar9 + 0x1c);
        if (9999 < uVar11) {
          uVar11 = 9999;
        }
        if (*(short *)(iVar12 + iVar9 + 0x1c) == 0) {
          uVar4 = FUN_0062fea0(0x43);
          uVar4 = FUN_00602670(uVar4);
          uVar5 = FUN_0062fea0(0x10);
          uVar6 = FUN_0062fea0(0x10);
          func_0x00109728(iVar8 + 2,0x649f20,uVar4,uVar15,uVar5,uVar11,uVar6);
        }
        else {
          lVar7 = FUN_005bac80((char)iVar10);
          if (lVar7 == 0) {
            lVar7 = FUN_0062fea0(0x43);
          }
          uVar4 = FUN_00602670(lVar7);
          uVar5 = FUN_0062fea0(0x10);
          uVar6 = FUN_0062fea0(0x10);
          func_0x00109728(iVar8 + 2,0x649f20,uVar4,uVar15,uVar5,uVar11,uVar6);
        }
      }
      uVar3 = FUN_006038f0(uVar3,0,iVar8 + 2);
    }
  }
  else if (cVar1 == '\0') {
    uVar3 = FUN_0062fea0(0x2c);
    func_0x00109728(iVar10 + 0xcd5ae,0x649d70,uVar3);
    uVar3 = FUN_006038f0(iVar9,0x15,iVar10 + 0xcd5ae);
    if (*puVar14 < 0x405f7de2) {
      iVar8 = (int)*puVar14 / 0x1e;
      iVar9 = iVar8 / 0x3c;
      iVar12 = iVar9 / 0x3c;
      iVar9 = iVar9 % 0x3c;
      iVar8 = iVar8 % 0x3c;
    }
    else {
      iVar9 = 0x3b;
      iVar12 = 9999;
      iVar8 = iVar9;
    }
    uVar4 = FUN_0062fea0(99);
    uVar5 = FUN_0062fea0(100);
    uVar6 = FUN_0062fea0(0x65);
    func_0x00109728((int)uVar3 + 2,0x649ec0,iVar12,uVar4,iVar9,uVar5,iVar8,uVar6);
    uVar3 = FUN_006038f0(uVar3,0,(int)uVar3 + 2);
    uVar4 = FUN_0062fea0(0x2d);
    func_0x00109728((int)uVar3 + 2,0x649d70,uVar4);
    uVar3 = FUN_006038f0(uVar3,0x15,(int)uVar3 + 2);
    iVar9 = *(int *)(iVar10 + 0xcf5c4);
    if (9999999 < iVar9) {
      iVar9 = 9999999;
    }
    uVar4 = FUN_0062fea0(0x66);
    func_0x00109728((int)uVar3 + 2,0x649ed8,iVar9,uVar4);
    uVar3 = FUN_006038f0(uVar3,0,(int)uVar3 + 2);
    uVar4 = FUN_0062fea0(0x2e);
    func_0x00109728((int)uVar3 + 2,0x649d70,uVar4);
    uVar3 = FUN_006038f0(uVar3,0x15,(int)uVar3 + 2);
    iVar12 = 0;
    iVar9 = (int)uVar3;
    do {
      func_0x00106b60(iVar9 + 2,0,0x80);
      iVar13 = 0;
      iVar9 = iVar12 * 3;
      iVar8 = iVar9;
      do {
        if (iVar8 == 8) {
          uVar4 = FUN_0062fea0(2);
          func_0x00109728(auStack_60,0x649ee0,uVar4,
                          *(undefined1 *)((int)puVar14 + iVar13 + iVar9 + 0xb8));
        }
        else {
          func_0x00109728(auStack_60,0x649ee0,(&PTR_s_Kevin_0068ade0)[iVar8],
                          *(undefined1 *)((int)puVar14 + iVar13 + iVar9 + 0xb8));
        }
        func_0x00109ab0((int)uVar3 + 2,auStack_60);
        iVar13 = iVar13 + 1;
        iVar8 = iVar13 + iVar9;
      } while (iVar13 < 3);
      uVar3 = FUN_006038f0(uVar3,0,(int)uVar3 + 2);
      iVar12 = iVar12 + 1;
      iVar9 = (int)uVar3;
    } while (iVar12 < 3);
    uVar4 = FUN_0062fea0(0x2f);
    func_0x00109728(iVar9 + 2,0x649d70,uVar4);
    uVar3 = FUN_006038f0(uVar3,0x15,iVar9 + 2);
    iVar12 = *(int *)(iVar10 + 0xcf5c8) / 100;
    iVar9 = iVar12 / 1000;
    if (9999999 < iVar9) {
      iVar9 = 9999999;
    }
    func_0x00109728((int)uVar3 + 2,0x649ef0,iVar9,iVar12 % 1000);
    uVar3 = FUN_006038f0(uVar3,0,(int)uVar3 + 2);
    uVar4 = FUN_0062fea0(0x52);
    func_0x00109728((int)uVar3 + 2,0x649d70,uVar4);
    uVar3 = FUN_006038f0(uVar3,0x15,(int)uVar3 + 2);
    iVar9 = (int)uVar3;
    func_0x00106b60(iVar9 + 2,0,0x80);
    func_0x00109728(iVar9 + 2,0x649f00,*(undefined1 *)(iVar10 + 0xcf682));
    uVar3 = FUN_006038f0(uVar3,0,iVar9 + 2);
    uVar4 = FUN_0062fea0(0x58);
    func_0x00109728((int)uVar3 + 2,0x649d70,uVar4);
    uVar3 = FUN_006038f0(uVar3,0x15,(int)uVar3 + 2);
    iVar9 = 0;
    iVar12 = (int)uVar3;
    do {
      func_0x00106b60(iVar12 + 2,0,0x80);
      uVar4 = FUN_0062fea0(iVar9 + 0x53);
      func_0x00109728((int)uVar3 + 2,0x649f08,uVar4,*(undefined1 *)((int)puVar14 + iVar9 + 0xc));
      uVar3 = FUN_006038f0(uVar3,0,(int)uVar3 + 2);
      iVar9 = iVar9 + 1;
      iVar12 = (int)uVar3;
    } while (iVar9 < 5);
    uVar4 = FUN_0062fea0(0x59);
    func_0x00109728(iVar12 + 2,0x649d70,uVar4);
    uVar3 = FUN_006038f0(uVar3,0x15,iVar12 + 2);
    iVar9 = (int)uVar3;
    func_0x00106b60(iVar9 + 2,0,0x80);
    func_0x00109728(iVar9 + 2,0x649f00,*(undefined1 *)(iVar10 + 0xcf683));
    FUN_006038f0(uVar3,0,iVar9 + 2);
  }
  return;
}



================================================================