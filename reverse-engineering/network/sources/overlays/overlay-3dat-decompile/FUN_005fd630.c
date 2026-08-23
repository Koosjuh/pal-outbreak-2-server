FUNCTION FUN_005fd630 @ 0x005fd630  size=796
CALLERS (0): 
CALLEES (1): FUN_005bac80@0x005bac80
----------------------------------------------------------------

void FUN_005fd630(int param_1)

{
  uint uVar1;
  char cVar2;
  long lVar3;
  int iVar4;
  short unaff_s0_lo;
  float fVar5;
  
  if (*(char *)(param_1 + 4) != '\x01') {
    if (*(char *)(param_1 + 4) != '\0') {
      return;
    }
    *(undefined1 *)(param_1 + 4) = 1;
    *(undefined1 *)(param_1 + 8) = 0x14;
    *(undefined1 *)(param_1 + 9) = 0;
    *(undefined1 *)(param_1 + 10) = 0xff;
    *(undefined2 *)(param_1 + 0x3a) = 0;
    *(undefined4 *)(param_1 + 0x2c) = 0xffffffff;
    *(ushort *)(param_1 + 0x24) = *(ushort *)(param_1 + 0x24) | 0x80;
    if (*(char *)(param_1 + 2) == '\0') {
      *(undefined2 *)(param_1 + 0x26) = 0x128;
    }
  }
  if (cRam006c550e == '\0') {
    if (cRam006c5499 == '\0') {
      *(undefined1 *)(param_1 + 1) = 1;
    }
    else {
      *(undefined1 *)(param_1 + 1) = 0;
    }
    if (*(char *)(param_1 + 2) != '\0') {
      *(undefined2 *)(param_1 + 0x26) = 0x1e8;
    }
    *(undefined2 *)(param_1 + 0x28) = *(undefined2 *)(&DAT_00649b62 + cRam006c5499 * 2);
  }
  else {
    if (bRam006c5498 == 8) {
      if (sRam006c50ca < 2) {
        *(undefined1 *)(param_1 + 1) = 0;
      }
      else {
        *(undefined1 *)(param_1 + 1) = 1;
        lVar3 = FUN_005bac80(uRam006c4b96);
        if (lVar3 == 0) {
          *(undefined1 *)(param_1 + 1) = 0;
        }
        else {
          cVar2 = func_0x001ae3e0(lVar3);
          unaff_s0_lo = cVar2 * 9;
        }
      }
    }
    else if (bRam006c5498 == 9) {
      unaff_s0_lo = 0x6c;
      *(undefined1 *)(param_1 + 1) = 1;
    }
    else if (((bRam006c5498 < 2) || (bRam006c5498 == 10)) ||
            ((iVar4 = (int)(char)bRam006c5498, '\x01' < (char)bRam006c5498 &&
             (*(char *)(iVar4 * 0x14a8 + 0x6947e8) == '\0')))) {
      *(undefined1 *)(param_1 + 1) = 0;
    }
    else {
      cVar2 = func_0x001ae3e0(*(char *)(iVar4 * 0x14a8 + 0x6947ea) * 0x41 + (iVar4 + -2) * 0x14a8 +
                              0x69715d);
      *(undefined1 *)(param_1 + 1) = 1;
      unaff_s0_lo = cVar2 * 9;
    }
    if (*(char *)(param_1 + 2) != '\0') {
      *(short *)(param_1 + 0x26) = unaff_s0_lo + 0x158;
    }
    *(undefined2 *)(param_1 + 0x28) = *(undefined2 *)(&DAT_00649b50 + (char)bRam006c5498 * 2);
  }
  *(short *)(param_1 + 0x3a) = *(short *)(param_1 + 0x3a) + 0x400;
  *(ushort *)(param_1 + 0x3a) = *(ushort *)(param_1 + 0x3a) & 0x7fff;
  if (*(char *)(param_1 + 9) != '\0') {
    *(undefined2 *)(param_1 + 0x3a) = 0x4000;
    *(undefined1 *)(param_1 + 9) = 0;
  }
  fVar5 = (float)func_0x001886c0((DAT_006930f0 * (float)*(ushort *)(param_1 + 0x3a)) / 65536.0);
  fVar5 = fVar5 * 255.0;
  *(uint *)(param_1 + 0x2c) = (uint)((ulong)((long)*(int *)(param_1 + 0x2c) << 0x28) >> 0x28);
  if (fVar5 < 2.1474836e+09) {
    uVar1 = *(uint *)(param_1 + 0x2c);
  }
  else {
    fVar5 = fVar5 - 2.1474836e+09;
    uVar1 = *(uint *)(param_1 + 0x2c);
  }
  *(uint *)(param_1 + 0x2c) = uVar1 | (int)fVar5 << 0x18;
  return;
}



================================================================