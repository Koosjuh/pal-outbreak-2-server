FUNCTION FUN_005f1a80 @ 0x005f1a80  size=792
CALLERS (1): FUN_005f1da0@0x005f1da0
CALLEES (0): 
----------------------------------------------------------------

void FUN_005f1a80(int param_1,int param_2,int param_3)

{
  ushort uVar1;
  ushort uVar2;
  byte bVar3;
  byte *pbVar4;
  byte *pbVar5;
  int iVar6;
  int iVar7;
  byte *pbVar8;
  int iVar9;
  
  iVar7 = 0;
  do {
    while( true ) {
      iVar9 = iVar7 * 4;
      if (param_3 <= iVar7) {
        return;
      }
      pbVar5 = (byte *)(param_1 + iVar9);
      pbVar4 = (byte *)(param_2 + iVar9);
      if ((*pbVar5 & 1) != 0) break;
      if ((*pbVar4 & 1) == 0) {
        uVar1 = *(ushort *)(pbVar4 + 2);
        uVar2 = *(ushort *)(pbVar5 + 2);
        if (uVar2 < uVar1) {
          for (iVar9 = iVar7; iVar9 < param_3; iVar9 = iVar9 + 1) {
            iVar6 = param_1 + iVar9 * 4;
            *(ushort *)(iVar6 + 2) = *(short *)(iVar6 + 2) + (uVar1 - uVar2);
          }
        }
        else if ((uVar1 < uVar2) && ((*pbVar4 & 8) == 0)) {
          for (iVar9 = iVar7; iVar9 < param_3; iVar9 = iVar9 + 1) {
            iVar6 = param_2 + iVar9 * 4;
            *(ushort *)(iVar6 + 2) = *(short *)(iVar6 + 2) + (uVar2 - uVar1);
          }
        }
      }
      else {
        uVar1 = *(ushort *)(pbVar4 + 2);
        uVar2 = *(ushort *)(pbVar5 + 2);
        if (uVar2 < uVar1) {
          *(ushort *)(pbVar5 + 2) = uVar2 + (uVar1 - uVar2);
          iVar9 = iVar7;
LAB_005f1c88:
          iVar9 = iVar9 + 1;
          if (iVar9 < param_3) {
            pbVar8 = (byte *)(param_1 + iVar9 * 4);
            uVar1 = *(ushort *)(pbVar8 + -2);
            uVar2 = *(ushort *)(pbVar8 + 2);
            if (uVar2 < uVar1) {
              if ((*pbVar8 & 1) == 0) goto LAB_005f1c80;
              for (; iVar9 < param_3; iVar9 = iVar9 + 1) {
                iVar6 = param_1 + iVar9 * 4;
                *(ushort *)(iVar6 + 2) = *(short *)(iVar6 + 2) + (uVar1 - uVar2);
              }
              bVar3 = *pbVar4;
              goto LAB_005f1c98;
            }
          }
          bVar3 = *pbVar4;
LAB_005f1c98:
          *pbVar5 = bVar3;
        }
        else if (uVar1 < uVar2) {
          iVar9 = iVar7;
          while ((iVar9 < param_3 && (pbVar8 = (byte *)(param_1 + iVar9 * 4), (*pbVar8 & 1) == 0)))
          {
            iVar9 = iVar9 + 1;
            *(ushort *)(pbVar8 + 2) = *(short *)(pbVar8 + 2) - (uVar2 - uVar1);
          }
          *pbVar5 = *pbVar4;
        }
      }
LAB_005f1d80:
      iVar7 = iVar7 + 1;
    }
    pbVar4 = (byte *)(param_2 + iVar9);
    bVar3 = *pbVar4;
    if ((bVar3 & 1) == 0) {
      uVar1 = *(ushort *)(pbVar4 + 2);
      uVar2 = *(ushort *)(pbVar5 + 2);
      if (uVar2 < uVar1) {
        iVar9 = iVar7;
        while ((iVar9 < param_3 && (pbVar4 = (byte *)(param_2 + iVar9 * 4), (*pbVar4 & 1) == 0))) {
          iVar9 = iVar9 + 1;
          *(ushort *)(pbVar4 + 2) = *(short *)(pbVar4 + 2) - (uVar1 - uVar2);
        }
      }
      else if ((uVar1 < uVar2) && ((bVar3 & 8) == 0)) {
        for (iVar9 = iVar7; iVar9 < param_3; iVar9 = iVar9 + 1) {
          iVar6 = param_2 + iVar9 * 4;
          *(ushort *)(iVar6 + 2) = *(short *)(iVar6 + 2) + (uVar2 - uVar1);
        }
      }
      goto LAB_005f1d80;
    }
    uVar1 = *(ushort *)(pbVar4 + 2);
    uVar2 = *(ushort *)(pbVar5 + 2);
    if (uVar1 <= uVar2) {
      if ((uVar1 < uVar2) && ((bVar3 & 8) == 0)) {
        for (iVar9 = iVar7; iVar9 < param_3; iVar9 = iVar9 + 1) {
          iVar6 = param_2 + iVar9 * 4;
          *(ushort *)(iVar6 + 2) = *(short *)(iVar6 + 2) + (uVar2 - uVar1);
        }
      }
      goto LAB_005f1d80;
    }
    for (iVar9 = iVar7; iVar9 < param_3; iVar9 = iVar9 + 1) {
      iVar6 = param_1 + iVar9 * 4;
      *(ushort *)(iVar6 + 2) = *(short *)(iVar6 + 2) + (uVar1 - uVar2);
    }
    iVar7 = iVar7 + 1;
  } while( true );
LAB_005f1c80:
  *(ushort *)(pbVar8 + 2) = uVar1;
  goto LAB_005f1c88;
}



================================================================