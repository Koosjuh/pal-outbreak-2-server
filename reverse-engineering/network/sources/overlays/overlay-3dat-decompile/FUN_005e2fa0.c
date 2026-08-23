FUNCTION FUN_005e2fa0 @ 0x005e2fa0  size=2744
CALLERS (1): FUN_005daf30@0x005daf30
CALLEES (10): thunk_EXT_FUN_001ae3e0@0x005dfce0, FUN_005e1a30@0x005e1a30, FUN_005e0570@0x005e0570, FUN_005e0440@0x005e0440, FUN_005dfbc0@0x005dfbc0, FUN_005ddc20@0x005ddc20, FUN_005e1da0@0x005e1da0, FUN_005e07c0@0x005e07c0, FUN_005e19b0@0x005e19b0, FUN_005e15e0@0x005e15e0
----------------------------------------------------------------

void FUN_005e2fa0(byte *param_1)

{
  byte bVar1;
  int iVar2;
  long lVar3;
  short sVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  undefined1 auStack_280 [640];
  
  param_1[1] = 0;
  bVar1 = param_1[2];
  if (bVar1 == 0xf) {
    return;
  }
  if (bVar1 == 0x10) {
    return;
  }
  if (bVar1 == 0xd) {
    if (*param_1 == 4) {
      return;
    }
    if (1 < *param_1) {
      if ((float)((*(int *)(iRam00701070 + 4) + 0x280) - (int)*(short *)(iRam00701070 + 0x20)) <
          *(float *)(param_1 + 0x34)) {
        return;
      }
      if (*(float *)(param_1 + 0x34) <
          (float)*(int *)(iRam00701070 + 4) - *(float *)(param_1 + 0x40)) {
        return;
      }
      if (*(float *)(param_1 + 0x38) <
          (float)*(int *)(iRam00701070 + 8) - *(float *)(param_1 + 0x44)) {
        return;
      }
      if ((float)(*(int *)(iRam00701070 + 8) + 0x1ac) < *(float *)(param_1 + 0x38)) {
        return;
      }
    }
  }
  else {
    if ((float)((*(int *)(iRam00701070 + 4) + 0x280) - (int)*(short *)(iRam00701070 + 0x20)) <
        *(float *)(param_1 + 0x34)) {
      return;
    }
    if (*(float *)(param_1 + 0x34) < (float)*(int *)(iRam00701070 + 4) - *(float *)(param_1 + 0x40))
    {
      return;
    }
    if (*(float *)(param_1 + 0x38) < (float)(*(int *)(iRam00701070 + 8) + -0x28)) {
      return;
    }
    if ((float)(*(int *)(iRam00701070 + 8) + 0x1ac) < *(float *)(param_1 + 0x38)) {
      return;
    }
  }
  param_1[1] = 1;
  fVar5 = *(float *)(param_1 + 0x40);
  fVar8 = *(float *)(param_1 + 0x34) - (float)*(int *)(iRam00701070 + 4);
  fVar9 = *(float *)(param_1 + 0x38) - (float)*(int *)(iRam00701070 + 8);
  fVar6 = fVar8 + fVar5;
  fVar7 = fVar9 + *(float *)(param_1 + 0x44);
  switch(param_1[2]) {
  case 1:
    FUN_005ddc20(fVar8,fVar9,param_1[0x5c],*(undefined4 *)(param_1 + 0x58),param_1[0x5d],param_1[4],
                 *(undefined4 *)(param_1 + 0x60));
    break;
  case 2:
  case 0x12:
    FUN_005ddc20(fVar8,fVar9,param_1[0x5c],*(undefined4 *)(param_1 + 0x58),param_1[0x5d],param_1[4],
                 *(undefined4 *)(param_1 + 100));
    if ((int)(*(ushort *)(iRam00701070 + 0x18) & 0x80) >> 7 != 0) {
      FUN_005e0440(fVar8,fVar7 - 2.0,fVar6,fVar7,*(uint *)(param_1 + 0x58) | 0xff000000);
    }
    break;
  case 3:
  case 4:
  case 5:
    if (*(int *)(iRam00701068 + 0x69018) == 0) {
      param_1[5] = 0;
    }
    if (param_1[5] == 1) {
      FUN_005e07c0(fVar8,fVar9,*(undefined4 *)(param_1 + 0x40),*(undefined4 *)(param_1 + 0x44),9,0);
      FUN_005ddc20(fVar8 + 3.0,fVar9 + 2.0,param_1[0x5c],0xffffffffffffffff,param_1[0x5d],param_1[4]
                   ,*(undefined4 *)(param_1 + 0x60));
    }
    else if (param_1[5] == 0) {
      FUN_005e07c0(fVar8,fVar9,*(undefined4 *)(param_1 + 0x40),*(undefined4 *)(param_1 + 0x44),8,0);
      lVar3 = func_0x0010a050(*(undefined4 *)(param_1 + 0x60));
      if (lVar3 == 1) {
        FUN_005ddc20(fVar8 + 6.0,fVar9 + 1.0,param_1[0x5c],0xffffffffffffffff,param_1[0x5d],
                     param_1[4],*(undefined4 *)(param_1 + 0x60));
      }
      else {
        FUN_005ddc20(fVar8 + 3.0,fVar9 + 1.0,param_1[0x5c],0xffffffffffffffff,param_1[0x5d],
                     param_1[4],*(undefined4 *)(param_1 + 0x60));
      }
    }
    break;
  case 6:
    FUN_005e07c0(fVar8,fVar9,7,0);
    lVar3 = func_0x0010a050(*(undefined4 *)(param_1 + 100));
    if (lVar3 != 0) {
      fVar5 = *(float *)(param_1 + 0x40);
      bVar1 = param_1[4];
      iVar2 = thunk_EXT_FUN_001ae3e0(*(undefined4 *)(param_1 + 100));
      iVar2 = (uint)bVar1 * (iVar2 + 1);
      if (iVar2 < 0) {
        iVar2 = iVar2 + 1;
      }
      fVar6 = fVar5;
      if (2.1474836e+09 <= fVar5) {
        fVar6 = fVar5 - 2.1474836e+09;
      }
      if ((int)((int)fVar6 & 0xffffU) < iVar2 >> 1) {
        FUN_005dfbc0(auStack_280,*(undefined4 *)(param_1 + 100),
                     (int)(fVar5 - (float)(param_1[4] >> 1)));
        FUN_005ddc20(fVar8 + 4.0,fVar9 + 3.0,param_1[0x5c],0xffffffffffffffff,param_1[0x5d],
                     param_1[4],auStack_280);
      }
      else {
        FUN_005ddc20(fVar8 + 4.0,fVar9 + 3.0,param_1[0x5c],0xffffffffffffffff,param_1[0x5d],bVar1,
                     *(undefined4 *)(param_1 + 100));
      }
    }
    break;
  case 7:
    FUN_005e07c0(fVar8,fVar9,7,0);
    lVar3 = func_0x0010a050(*(undefined4 *)(param_1 + 100));
    if (lVar3 != 0) {
      FUN_005ddc20(fVar8 + 4.0,fVar9 + 3.0,param_1[0x5c],0xffffffffffffffff,param_1[0x5d],param_1[4]
                   ,0x6466c0);
    }
    break;
  case 8:
    if (*param_1 - 0xb < 2) {
      if (*param_1 == 0xb) {
        FUN_005e07c0(fVar8,fVar9,0x16,0);
      }
      else {
        FUN_005e07c0(fVar8,fVar9,0x17,0);
        if (*(int *)(iRam00701068 + 0x69018) == 0) {
          *param_1 = 0xb;
        }
      }
      FUN_005ddc20(fVar8 + 4.0,fVar9 + 2.0,param_1[0x5c],0xffffffffffffffff,param_1[0x5d],param_1[4]
                   ,*(undefined4 *)(param_1 + 0x60));
    }
    break;
  case 10:
    sVar4 = (short)(int)*(float *)(param_1 + 0x44);
    if (sVar4 == 4) {
      if ((short)(int)fVar5 == 2) {
        fVar5 = fVar8 + 1.0;
        FUN_005e0440(fVar8,fVar9,fVar5,fVar9 + 1.0,0xffffffffff000001);
        FUN_005e0440(fVar8,fVar9 + 2.0,fVar5,fVar9 + 3.0,0xffffffffffd0d0d0);
      }
      else {
        FUN_005e1a30(fVar8,fVar9,fVar6 - 2.0,fVar9,0xffffffffff000001);
        FUN_005e1a30(fVar8,fVar7 - 2.0,fVar6 - 2.0,fVar7 - 2.0,0xffffffffffd0d0d0);
      }
    }
    else if (sVar4 == 2) {
      if ((short)(int)fVar5 == 2) {
        FUN_005e0440(fVar8,fVar9,fVar8 + 1.0,fVar9 + 1.0,0xffffffffff000001);
      }
      else {
        FUN_005e1a30(fVar8,fVar9,fVar6,fVar9,0xffffffffff000001);
      }
    }
    else if ((short)(int)fVar5 == 2) {
      FUN_005e0440(fVar8,fVar9,fVar8 + 1.0,fVar7 - 2.0,0xffffffffffd0d0d0);
    }
    else {
      FUN_005e1a30(fVar8,fVar9,fVar6,fVar9,0xffffffffff000001);
      FUN_005e1a30(fVar8,fVar7 - 2.0,fVar6,fVar7 - 2.0,0xffffffffffd0d0d0);
      FUN_005e19b0(fVar6,fVar9,fVar6,fVar7 - 2.0,0xffffffffffd0d0d0);
      FUN_005e19b0(fVar8,fVar9,fVar8,fVar7 - 2.0,0xffffffffff000001);
    }
    break;
  case 0xb:
    if (param_1[5] == 1) {
      FUN_005e0570(fVar8,fVar9,0x19);
    }
    else {
      FUN_005e0570(fVar8,fVar9,0x18);
    }
    break;
  case 0xc:
    if (param_1[5] == 1) {
      FUN_005e0570(fVar8,fVar9,0x1b);
    }
    else {
      FUN_005e0570(fVar8,fVar9,0x1a);
    }
    break;
  case 0xd:
    if (param_1[5] == 2) {
      bVar1 = param_1[0x5f];
      if (*(int *)((uint)bVar1 * 4 + iRam00701068 + 0x68dd8) != 0) {
        if (**(char **)(param_1 + 100) == '\0') {
          return;
        }
        iVar2 = (uint)bVar1 * 2 + iRam00701068;
        FUN_005e15e0(fVar8,fVar9,bVar1,*(undefined2 *)(iVar2 + 0x68e28),
                     *(undefined2 *)(iVar2 + 0x68e50));
        return;
      }
    }
    if ((param_1[0x5d] & 0x80) == 0) {
      FUN_005e1da0(fVar8,fVar9,fVar6 - 1.0,fVar7 - 1.0,0xffffffffff000001);
      FUN_005e19b0(fVar6 - 2.0,fVar9,fVar6 - 2.0,fVar7,0xffffffffffd0d0d0);
      FUN_005e1a30(fVar8,fVar7 - 2.0,fVar6,fVar7 - 2.0,0xffffffffffd0d0d0);
      if (*(int *)(param_1 + 0x68) != 0) {
        FUN_005ddc20(fVar8 + 4.0,fVar9 + 2.0,param_1[0x5c],0xffffffffffffffff,param_1[0x5d],
                     param_1[4]);
      }
    }
    break;
  case 0x11:
    FUN_005ddc20(fVar8,fVar9,param_1[0x5c],*(undefined4 *)(param_1 + 0x58),param_1[0x5d],param_1[4],
                 *(undefined4 *)(param_1 + 100));
    fVar5 = fVar7 - (float)(param_1[4] >> 1);
    FUN_005e0440(fVar8,fVar5 - 1.0,fVar6,fVar5 + 2.0,*(uint *)(param_1 + 0x58) | 0xff000000);
    lVar3 = func_0x0010a050(*(undefined4 *)(param_1 + 0x60));
    if (lVar3 != 0) {
      FUN_005e0440(fVar8,fVar7 - 2.0,fVar6,fVar7,*(uint *)(param_1 + 0x58) | 0xff000000);
    }
  }
  return;
}



================================================================