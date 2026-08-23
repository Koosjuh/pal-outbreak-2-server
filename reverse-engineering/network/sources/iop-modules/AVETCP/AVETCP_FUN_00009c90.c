FUNCTION FUN_00009c90 @ 0x00009c90 size=1344
CALLERS (1): FUN_00007000@0x00007000
CALLEES (4): FUN_00001454@0x00001454, FUN_000010c0@0x000010c0, FUN_00010bc0@0x00010bc0, FUN_00011d00@0x00011d00

undefined4 FUN_00009c90(uint *param_1,uint param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  undefined1 auStack_30 [8];
  undefined1 auStack_28 [8];
  
  if ((*(uint *)(param_3 + 0xd8) >> 1 & 1) != 0) {
    return 0xffffffff;
  }
  iVar6 = 0;
  uVar2 = 0;
  if (*param_1 != 0) {
    do {
      uVar2 = param_2 & 0xffff;
      iVar1 = iVar6 + 1;
      if (uVar2 < (ushort)param_1[(short)iVar6 * 3 + 2]) break;
      param_2 = param_2 - (ushort)param_1[(short)iVar6 * 3 + 2];
      uVar2 = 0;
      iVar6 = iVar1;
    } while ((uint)(iVar1 * 0x10000 >> 0x10) < *param_1);
  }
  if ((int)(short)iVar6 != *param_1) {
    if (*(char *)(param_3 + 0xc4) == '\0') {
LAB_0000a040:
      FUN_00011d00(auStack_30,param_3 + 0xac,8);
      FUN_00001454(auStack_30,(int)*(short *)(param_3 + 0xbc));
      if ((uint)(int)(short)iVar6 < *param_1) {
        do {
          FUN_00011d00(auStack_28,param_1 + (short)iVar6 * 3 + 3,8);
          if (uVar2 != 0) {
            FUN_00001454(auStack_28,(int)(short)uVar2);
          }
          uVar5 = (uint)(short)DAT_000161a4;
          uVar2 = (int)(short)param_1[(short)iVar6 * 3 + 2] - uVar2;
          uVar4 = uVar5 - *(int *)(param_3 + 0xb4);
          if (uVar4 < uVar2) {
            uVar2 = uVar4;
          }
          *(uint *)(param_3 + 0xb4) = *(int *)(param_3 + 0xb4) + uVar2;
          if (uVar5 <= *(int *)(param_3 + 0xbc) + uVar2) {
            FUN_000010c0(auStack_30,auStack_28,uVar5 - *(int *)(param_3 + 0xbc));
            FUN_00011d00(auStack_30,param_3 + 0xac,8);
            FUN_00001454(auStack_28,
                         (int)(((uint)DAT_000161a4 - (uint)*(ushort *)(param_3 + 0xbc)) * 0x10000)
                         >> 0x10);
            iVar1 = (int)(short)DAT_000161a4;
            iVar3 = *(int *)(param_3 + 0xbc);
            *(undefined4 *)(param_3 + 0xbc) = 0;
            uVar2 = uVar2 - (iVar1 - iVar3);
          }
          if (uVar2 != 0) {
            FUN_000010c0(auStack_30,auStack_28,uVar2);
            *(uint *)(param_3 + 0xbc) = *(int *)(param_3 + 0xbc) + uVar2;
            FUN_00001454(auStack_30,(int)(short)uVar2);
          }
          iVar6 = iVar6 + 1;
          uVar2 = 0;
        } while ((uint)(iVar6 * 0x10000 >> 0x10) < *param_1);
        return 0;
      }
    }
    else {
      FUN_00011d00(auStack_30,param_3 + 0xc0,8);
      if ((uint)(int)(short)iVar6 < *param_1) {
        do {
          while( true ) {
            FUN_00011d00(auStack_28,param_1 + (short)iVar6 * 3 + 3,8);
            if (uVar2 != 0) {
              FUN_00001454(auStack_28,(int)(short)uVar2);
            }
            uVar4 = *(int *)(param_3 + 200) - *(int *)(param_3 + 0xcc);
            uVar5 = (int)(short)param_1[(short)iVar6 * 3 + 2] - uVar2;
            if (uVar4 < uVar5) {
              FUN_000010c0(auStack_30,auStack_28,uVar4);
              uVar2 = uVar2 + uVar4;
              *(uint *)(param_3 + 0xcc) = *(int *)(param_3 + 0xcc) + uVar4;
            }
            else {
              FUN_000010c0(auStack_30,auStack_28);
              uVar2 = 0;
              iVar6 = iVar6 + 1;
              *(uint *)(param_3 + 0xcc) = *(int *)(param_3 + 0xcc) + uVar5;
              FUN_00001454(auStack_30,(int)(short)uVar5);
            }
            if (*(int *)(param_3 + 200) == *(int *)(param_3 + 0xcc)) break;
            if (*param_1 <= (uint)(int)(short)iVar6) goto LAB_00009f68;
          }
          *(undefined1 *)(param_3 + 0xc4) = 0;
          FUN_00010bc0((param_3 - DAT_00016180) * -0x69184000 >> 0x10,
                       *(undefined4 *)(param_3 + 0xd4),(int)*(short *)(param_3 + 0xcc),
                       (int)(((uint)*(ushort *)(param_3 + 0xcc) +
                             ((uint)*(ushort *)(param_3 + 0xfc) - (uint)*(ushort *)(param_3 + 0xf8))
                             ) * 0x10000) >> 0x10);
          if (*(char *)(param_3 + 0xc4) == '\0') goto LAB_0000a040;
          FUN_00011d00(auStack_30,param_3 + 0xc0,8);
        } while ((uint)(int)(short)iVar6 < *param_1);
        switch(*(undefined2 *)(param_3 + 0x13a)) {
        case 0:
        case 5:
        case 7:
        case 8:
        case 10:
          *(undefined1 *)(param_3 + 0xc4) = 0;
          FUN_00010bc0((param_3 - DAT_00016180) * -0x69184000 >> 0x10,
                       *(undefined4 *)(param_3 + 0xd4),0,
                       (int)(((uint)*(ushort *)(param_3 + 0xfc) - (uint)*(ushort *)(param_3 + 0xf8))
                            * 0x10000) >> 0x10);
          return 0;
        }
      }
      else {
LAB_00009f68:
        *(undefined1 *)(param_3 + 0xc4) = 0;
        FUN_00010bc0((param_3 - DAT_00016180) * -0x69184000 >> 0x10,*(undefined4 *)(param_3 + 0xd4),
                     (int)*(short *)(param_3 + 0xcc),
                     (int)(((uint)*(ushort *)(param_3 + 0xcc) +
                           ((uint)*(ushort *)(param_3 + 0xfc) - (uint)*(ushort *)(param_3 + 0xf8)))
                          * 0x10000) >> 0x10);
        if (*(char *)(param_3 + 0xc4) == '\0') {
          return 0;
        }
        switch(*(undefined2 *)(param_3 + 0x13a)) {
        case 0:
        case 5:
        case 7:
        case 8:
        case 10:
          *(undefined1 *)(param_3 + 0xc4) = 0;
          FUN_00010bc0((param_3 - DAT_00016180) * -0x69184000 >> 0x10,
                       *(undefined4 *)(param_3 + 0xd4),0,
                       (int)(((uint)*(ushort *)(param_3 + 0xfc) - (uint)*(ushort *)(param_3 + 0xf8))
                            * 0x10000) >> 0x10);
          return 0;
        }
      }
    }
  }
  return 0;
}


================================================================