FUNCTION FUN_0060cb40 @ 0x0060cb40  size=1660
CALLERS (1): FUN_0060d4f0@0x0060d4f0
CALLEES (5): FUN_0060ca90@0x0060ca90, FUN_0060c2d0@0x0060c2d0, FUN_0060c230@0x0060c230, FUN_0060ae20@0x0060ae20, FUN_0060c9e0@0x0060c9e0
----------------------------------------------------------------

undefined4 FUN_0060cb40(uint *param_1,undefined8 param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  long lVar4;
  int iVar5;
  
  lVar4 = func_0x00106910(param_2,0x693558,8);
  if (lVar4 == 0) {
    uRam0070d174 = 0x2100;
    uRam0070d170 = FUN_0060c230(0x2100);
    uRam0070d158 = 0x70d100;
    lVar4 = FUN_0060ae20(0x70d128,0x64b5b8,0x48);
    if ((((lVar4 == -6) || (lVar4 == -2)) || (lVar4 == -4)) || (lVar4 != 0)) {
      uVar3 = 0;
    }
    else {
      uRam0070d1a8 = (undefined4)param_2;
      uRam0070d138 = uRam0070d170;
      uRam0070d13c = uRam0070d174;
      FUN_0060c2d0(0x70d100,8);
      do {
        FUN_0060c2d0(0x70d100,4);
        iVar5 = (uint)pbRam0070d108[3] +
                (uint)pbRam0070d108[2] * 0x100 +
                (uint)*pbRam0070d108 * 0x1000000 + (uint)pbRam0070d108[1] * 0x10000;
        FUN_0060c2d0();
        lVar4 = func_0x00106910(pbRam0070d108,0x693538,4);
        if (lVar4 == 0) {
          FUN_0060c2d0(0x70d100,0xd);
          uRam0070d110 = (uint)pbRam0070d108[3] +
                         (uint)pbRam0070d108[2] * 0x100 +
                         (uint)*pbRam0070d108 * 0x1000000 + (uint)pbRam0070d108[1] * 0x10000;
          uRam0070d114 = (uint)pbRam0070d108[7] +
                         (uint)pbRam0070d108[6] * 0x100 +
                         (uint)pbRam0070d108[4] * 0x1000000 + (uint)pbRam0070d108[5] * 0x10000;
          bRam0070d118 = pbRam0070d108[8];
          bRam0070d119 = pbRam0070d108[9];
          bRam0070d11a = pbRam0070d108[10];
          bRam0070d11b = pbRam0070d108[0xb];
          bRam0070d11c = pbRam0070d108[0xc];
          FUN_0060c2d0();
          if (bRam0070d119 == 6) {
            cRam0070d11d = '\x04';
          }
          else if (bRam0070d119 == 4) {
            cRam0070d11d = '\x02';
          }
          else if (bRam0070d119 == 2) {
            cRam0070d11d = '\x03';
          }
          else if ((bRam0070d119 == 3) || (bRam0070d119 == 0)) {
            cRam0070d11d = '\x01';
          }
          bRam0070d11e = bRam0070d118 * cRam0070d11d;
          uRam0070d120 = uRam0070d110 * bRam0070d11e + 7 >> 3;
        }
        else {
          lVar4 = func_0x00106910(pbRam0070d108,0x693550,4);
          if (lVar4 == 0) {
            if (bRam0070d119 == 2) {
              FUN_0060c2d0(0x70d100,iVar5);
              uRam0070d124 = 1;
              bRam0070d125 = pbRam0070d108[1];
              bRam0070d126 = pbRam0070d108[3];
              bRam0070d127 = pbRam0070d108[5];
            }
            else if (bRam0070d119 == 3) {
              uRam0070d124 = 1;
              pbRam0070d1b8 = pbRam0070d108 + 4;
              FUN_0060c2d0(0x70d100,iVar5);
              uRam0070d1bc = (undefined2)iVar5;
            }
            FUN_0060c2d0(0x70d100,4);
          }
          else {
            lVar4 = func_0x00106910(pbRam0070d108,0x693548,4);
            iVar1 = iRam0070d194;
            if ((lVar4 == 0) ||
               (lVar4 = func_0x00106910(pbRam0070d108,0x693540,4), iVar1 = iVar5, lVar4 == 0))
            break;
            lVar4 = func_0x00106910(pbRam0070d108,0x693560,4);
            if (lVar4 == 0) {
              pbRam0070d1b0 = pbRam0070d108 + 4;
              FUN_0060c2d0(0x70d100,iVar5);
              uRam0070d1b4 = (undefined2)(iVar5 / 3);
              FUN_0060c2d0();
            }
            else {
              FUN_0060c2d0(0x70d100,iVar5);
              FUN_0060c2d0();
            }
          }
        }
        iVar1 = iRam0070d194;
      } while (cRam0070d10c == '\0');
      iRam0070d194 = iVar1;
      if (cRam0070d10c == '\0') {
        if ((((bRam0070d118 == 8) && (uRam0070d110 < 0x101)) && (uRam0070d114 < 0x101)) &&
           ((((bRam0070d119 & 7) == 2 || (bRam0070d11e == 0x18)) ||
            (((bRam0070d119 & 7) == 3 || (bRam0070d11e == 8)))))) {
          param_1[1] = uRam0070d110;
          param_1[2] = uRam0070d114;
          uVar2 = FUN_0060ca90(param_1[2]);
          param_1[2] = uVar2;
          uVar2 = FUN_0060c9e0(param_1[1],param_1[2]);
          param_1[1] = uVar2;
          *param_1 = 0;
          if (bRam0070d11e == 8) {
            *param_1 = *param_1 | 4;
            param_1[5] = 1;
            param_1[3] = param_1[5] * param_1[1];
            param_1[7] = 0;
            param_1[6] = 0;
            param_1[8] = 0;
            param_1[10] = 0;
            param_1[9] = 0;
            param_1[0xb] = 0;
            param_1[0xd] = 0;
            param_1[0xc] = 0;
            param_1[0xe] = 0;
            param_1[0x10] = 0;
            param_1[0xf] = 0;
            param_1[0x11] = 0;
          }
          else {
            param_1[5] = 4;
            param_1[3] = param_1[1] << 2;
            param_1[6] = 8;
            param_1[7] = 0x10;
            param_1[8] = 0xff;
            param_1[9] = 8;
            param_1[10] = 8;
            param_1[0xb] = 0xff;
            param_1[0xc] = 8;
            param_1[0xd] = 0;
            param_1[0xe] = 0xff;
            param_1[0xf] = 8;
            param_1[0x10] = 0x18;
            param_1[0x11] = 0xff;
            param_1[7] = 0;
            param_1[0xd] = 0x10;
          }
          uVar3 = 1;
        }
        else {
          func_0x0019c840(0x64b5c0,bRam0070d119);
          uVar3 = 0;
        }
      }
      else {
        uVar3 = 0;
      }
    }
  }
  else {
    func_0x0019c840(0x64b580);
    uVar3 = 0;
  }
  return uVar3;
}



================================================================