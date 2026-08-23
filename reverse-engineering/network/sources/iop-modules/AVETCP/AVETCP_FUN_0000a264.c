FUNCTION FUN_0000a264 @ 0x0000a264 size=1168
CALLERS (1): FUN_0000dcd8@0x0000dcd8
CALLEES (5): FUN_00001454@0x00001454, FUN_000010c0@0x000010c0, FUN_00010bc0@0x00010bc0, FUN_00011d00@0x00011d00, FUN_0000b3d4@0x0000b3d4

undefined4 FUN_0000a264(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined1 auStack_30 [8];
  undefined1 auStack_28 [8];
  
  if (*(char *)(param_1 + 0xc4) != '\0') {
    return 0xffffffff;
  }
  if ((*(uint *)(param_1 + 0xd8) >> 1 & 1) != 0) {
    return 0xffffffff;
  }
  *(undefined4 *)(param_1 + 0xd4) = param_4;
  FUN_00011d00(param_1 + 0xc0,param_2,8);
  *(undefined4 *)(param_1 + 200) = param_3;
  *(undefined4 *)(param_1 + 0xcc) = 0;
  if (*(int *)(param_1 + 0xb4) == 0) {
    switch((int)((*(ushort *)(param_1 + 0x13a) + 1) * 0x10000) >> 0x10) {
    case 0:
      *(undefined1 *)(param_1 + 0xc4) = 0;
      FUN_00010bc0((param_1 - DAT_00016180) * -0x69184000 >> 0x10,*(undefined4 *)(param_1 + 0xd4),
                   0xfffffff1,
                   (int)(((uint)*(ushort *)(param_1 + 0xfc) - (uint)*(ushort *)(param_1 + 0xf8)) *
                        0x10000) >> 0x10);
      if (*(char *)(param_1 + 0xc4) != '\0') {
        do {
          *(undefined1 *)(param_1 + 0xc4) = 0;
          FUN_00010bc0((param_1 - DAT_00016180) * -0x69184000 >> 0x10,
                       *(undefined4 *)(param_1 + 0xd4),0xfffffff1,
                       (int)(((uint)*(ushort *)(param_1 + 0xfc) - (uint)*(ushort *)(param_1 + 0xf8))
                            * 0x10000) >> 0x10);
        } while (*(char *)(param_1 + 0xc4) != '\0');
        return 0;
      }
      break;
    case 1:
    case 6:
    case 8:
    case 9:
    case 0xb:
      *(undefined1 *)(param_1 + 0xc4) = 0;
      FUN_00010bc0((param_1 - DAT_00016180) * -0x69184000 >> 0x10,*(undefined4 *)(param_1 + 0xd4),0,
                   (int)(((uint)*(ushort *)(param_1 + 0xfc) - (uint)*(ushort *)(param_1 + 0xf8)) *
                        0x10000) >> 0x10);
      if (*(char *)(param_1 + 0xc4) != '\0') {
        do {
          *(undefined1 *)(param_1 + 0xc4) = 0;
          FUN_00010bc0((param_1 - DAT_00016180) * -0x69184000 >> 0x10,
                       *(undefined4 *)(param_1 + 0xd4),0,
                       (int)(((uint)*(ushort *)(param_1 + 0xfc) - (uint)*(ushort *)(param_1 + 0xf8))
                            * 0x10000) >> 0x10);
        } while (*(char *)(param_1 + 0xc4) != '\0');
        return 0;
      }
    }
  }
  else {
    do {
      uVar4 = *(uint *)(param_1 + 0xb4);
      if (*(uint *)(param_1 + 200) < *(uint *)(param_1 + 0xb4)) {
        uVar4 = *(uint *)(param_1 + 200);
      }
      *(uint *)(param_1 + 0xcc) = uVar4;
      FUN_00011d00(auStack_30,param_1 + 0xac,8);
      FUN_00001454(auStack_30,(int)*(short *)(param_1 + 0xb8));
      FUN_00011d00(auStack_28,param_1 + 0xc0,8);
      if ((uint)(int)(short)DAT_000161a4 < *(int *)(param_1 + 0xb8) + uVar4) {
        uVar2 = (uint)DAT_000161a4 - (uint)*(ushort *)(param_1 + 0xb8);
        uVar3 = uVar2 & 0xffff;
        FUN_000010c0(auStack_28,auStack_30,uVar3);
        FUN_00001454(auStack_28,(int)(uVar2 * 0x10000) >> 0x10);
        uVar4 = uVar4 - uVar3;
        *(undefined4 *)(param_1 + 0xb8) = 0;
        *(uint *)(param_1 + 0xb4) = *(int *)(param_1 + 0xb4) - uVar3;
        FUN_00011d00(auStack_30,param_1 + 0xac,8);
      }
      FUN_000010c0(auStack_28,auStack_30,uVar4);
      *(uint *)(param_1 + 0xb4) = *(int *)(param_1 + 0xb4) - uVar4;
      uVar2 = (uint)(short)DAT_000161a4;
      uVar4 = *(int *)(param_1 + 0xb8) + uVar4;
      *(uint *)(param_1 + 0xb8) = uVar4;
      if (uVar2 <= uVar4) {
        *(uint *)(param_1 + 0xb8) = uVar4 - uVar2;
      }
      *(undefined1 *)(param_1 + 0xc4) = 0;
      FUN_00010bc0((param_1 - DAT_00016180) * -0x69184000 >> 0x10,*(undefined4 *)(param_1 + 0xd4),
                   (int)*(short *)(param_1 + 0xcc),
                   (int)(((uint)*(ushort *)(param_1 + 0xcc) +
                         ((uint)*(ushort *)(param_1 + 0xfc) - (uint)*(ushort *)(param_1 + 0xf8))) *
                        0x10000) >> 0x10);
    } while ((*(char *)(param_1 + 0xc4) != '\0') && (*(int *)(param_1 + 0xb4) != 0));
    *(byte *)(param_1 + 0x13f) = *(byte *)(param_1 + 0x13f) & 0xfe;
    if (1 < (ushort)(*(short *)(param_1 + 0x13a) + 1U)) {
      FUN_0000b3d4(param_1);
    }
    if (*(char *)(param_1 + 0xc4) == '\0') {
      return 0;
    }
    switch((int)((*(ushort *)(param_1 + 0x13a) + 1) * 0x10000) >> 0x10) {
    case 0:
      uVar1 = 0xfffffff1;
      break;
    case 1:
    case 6:
    case 8:
    case 9:
    case 0xb:
      uVar1 = 0;
      break;
    default:
      goto switchD_0000a300_caseD_2;
    }
    FUN_00010bc0((param_1 - DAT_00016180) * -0x69184000 >> 0x10,*(undefined4 *)(param_1 + 0xd4),
                 uVar1,(int)(((uint)*(ushort *)(param_1 + 0xfc) - (uint)*(ushort *)(param_1 + 0xf8))
                            * 0x10000) >> 0x10);
  }
switchD_0000a300_caseD_2:
  return 0;
}


================================================================