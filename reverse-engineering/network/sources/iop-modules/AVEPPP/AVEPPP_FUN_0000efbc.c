FUNCTION FUN_0000efbc @ 0x0000efbc size=1136
CALLERS (1): FUN_00004550@0x00004550
CALLEES (7): FUN_0000f710@0x0000f710, FUN_00001c68@0x00001c68, FUN_00000710@0x00000710, FUN_0000f5a8@0x0000f5a8, FUN_0000e730@0x0000e730, FUN_00000090@0x00000090, FUN_0000075c@0x0000075c

int FUN_0000efbc(int param_1,int *param_2)

{
  short sVar1;
  byte *pbVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  
  *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + 1;
  sVar1 = FUN_00000710(*param_2);
  if (sVar1 < 3) {
    *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + 1;
    return 0;
  }
  if (((param_2 == (int *)0x0) || (iVar5 = *param_2, iVar5 == 0)) || (*(ushort *)(iVar5 + 4) < 2)) {
    sVar1 = FUN_0000075c(param_2,&DAT_00013794,1);
    uVar7 = 0xffffffff;
    if (sVar1 == 1) {
      uVar7 = (uint)DAT_00013794;
    }
  }
  else {
    *(ushort *)(iVar5 + 4) = *(ushort *)(iVar5 + 4) - 1;
    pbVar2 = *(byte **)*param_2;
    uVar7 = (uint)*pbVar2;
    *(byte **)*param_2 = pbVar2 + 1;
  }
  if ((uVar7 & 0x40) == 0) {
    if ((*(byte *)(param_1 + 0xd) & 1) == 0) goto LAB_0000f17c;
LAB_0000f194:
    iVar5 = 0;
    *(int *)(param_1 + 0x34) = *(int *)(param_1 + 0x34) + 1;
  }
  else {
    if (((param_2 == (int *)0x0) || (iVar5 = *param_2, iVar5 == 0)) || (*(ushort *)(iVar5 + 4) < 2))
    {
      sVar1 = FUN_0000075c(param_2,&DAT_00013794,1);
      uVar6 = 0xffffffff;
      if (sVar1 == 1) {
        uVar6 = (uint)DAT_00013794;
      }
    }
    else {
      *(ushort *)(iVar5 + 4) = *(ushort *)(iVar5 + 4) - 1;
      pbVar2 = *(byte **)*param_2;
      uVar6 = (uint)*pbVar2;
      *(byte **)*param_2 = pbVar2 + 1;
    }
    if ((-1 < (int)uVar6) && ((int)uVar6 <= (int)(uint)*(byte *)(param_1 + 9))) {
      *(char *)(param_1 + 0xc) = (char)uVar6;
      *(byte *)(param_1 + 0xd) = *(byte *)(param_1 + 0xd) & 0xfe;
LAB_0000f17c:
      if (*(byte *)(param_1 + 9) < *(byte *)(param_1 + 0xc)) goto LAB_0000f194;
      iVar5 = *(int *)(param_1 + 4) + (uint)*(byte *)(param_1 + 0xc) * 0x8c;
      sVar1 = FUN_0000075c(param_2,&DAT_00013790);
      if (sVar1 == 2) {
        uVar6 = FUN_00001c68(&DAT_00013790);
        uVar6 = uVar6 & 0xffff;
      }
      else {
        uVar6 = 0xffffffff;
      }
      if (uVar6 != 0xffffffff) {
        *(byte *)(iVar5 + 0x5f) = (byte)(uVar7 >> 4) & 1;
        *(short *)(iVar5 + 0x56) = (short)uVar6;
        if ((uVar7 & 0xf) == 0xb) {
          iVar3 = (int)(((uint)*(ushort *)(iVar5 + 0x10) - (*(byte *)(iVar5 + 0x1f) + 0x28)) *
                       0x10000) >> 0x10;
          *(int *)(iVar5 + 0x4c) = *(int *)(iVar5 + 0x4c) + iVar3;
          *(int *)(iVar5 + 0x50) = *(int *)(iVar5 + 0x50) + iVar3;
        }
        else if ((uVar7 & 0xf) == 0xf) {
          *(uint *)(iVar5 + 0x4c) =
               *(int *)(iVar5 + 0x4c) +
               ((*(ushort *)(iVar5 + 0x10) - 0x28) - (uint)*(byte *)(iVar5 + 0x1f));
        }
        else {
          if ((uVar7 & 1) == 0) {
            *(undefined1 *)(iVar5 + 0x5d) = 0;
          }
          else {
            *(undefined1 *)(iVar5 + 0x5d) = 1;
            iVar3 = FUN_0000e730(param_2);
            if (iVar3 == -1) goto LAB_0000f3ec;
            *(short *)(iVar5 + 0x58) = (short)iVar3;
          }
          if ((uVar7 & 2) != 0) {
            iVar3 = FUN_0000e730(param_2);
            if (iVar3 == -1) goto LAB_0000f3ec;
            *(short *)(iVar5 + 0x54) = *(short *)(iVar5 + 0x54) + (short)iVar3;
          }
          if ((uVar7 & 4) != 0) {
            iVar3 = FUN_0000e730(param_2);
            if (iVar3 == -1) goto LAB_0000f3ec;
            *(int *)(iVar5 + 0x50) = *(int *)(iVar5 + 0x50) + iVar3;
          }
          if ((uVar7 & 8) != 0) {
            iVar3 = FUN_0000e730(param_2);
            if (iVar3 == -1) goto LAB_0000f3ec;
            *(int *)(iVar5 + 0x4c) = *(int *)(iVar5 + 0x4c) + iVar3;
          }
        }
        if ((uVar7 & 0x20) == 0) {
          sVar1 = *(short *)(iVar5 + 0x12) + 1;
LAB_0000f398:
          *(short *)(iVar5 + 0x12) = sVar1;
          iVar3 = FUN_00000710(*param_2);
          iVar3 = iVar3 + *(byte *)(iVar5 + 0x1f) + 0x28;
          *(short *)(iVar5 + 0x10) = (short)iVar3;
          iVar4 = FUN_0000f710(iVar5 + 0x48,*param_2,0);
          *param_2 = iVar4;
          iVar5 = FUN_00000090(iVar5 + 8,iVar4,0);
          *param_2 = iVar5;
          return iVar3 * 0x10000 >> 0x10;
        }
        iVar3 = FUN_0000e730(param_2);
        if (iVar3 != -1) {
          sVar1 = *(short *)(iVar5 + 0x12) + (short)iVar3;
          goto LAB_0000f398;
        }
      }
    }
LAB_0000f3ec:
    *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + 1;
    sVar1 = FUN_0000f5a8();
    iVar5 = (int)sVar1;
  }
  return iVar5;
}


================================================================