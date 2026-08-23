FUNCTION FUN_0001866c @ 0x0001866c size=1436
CALLERS (2): FUN_00018de4@0x00018de4, FUN_00007e28@0x00007e28
CALLEES (11): FUN_00011d90@0x00011d90, FUN_0000e4e8@0x0000e4e8, FUN_00017f30@0x00017f30, FUN_00004b68@0x00004b68, FUN_0000a494@0x0000a494, FUN_00006e70@0x00006e70, FUN_000183f0@0x000183f0, FUN_00017e68@0x00017e68, FUN_000088e8@0x000088e8, FUN_00006200@0x00006200, FUN_00009eec@0x00009eec

void FUN_0001866c(int param_1,int param_2,int param_3,undefined4 param_4,int param_5)

{
  bool bVar1;
  short sVar2;
  int iVar3;
  ushort *puVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  int *piVar8;
  int iVar9;
  
  bVar1 = DAT_0001b9e0 < DAT_0001b9d4;
  *(int *)(*(int *)(param_1 + 0x1a0) + 0x3c) = *(int *)(*(int *)(param_1 + 0x1a0) + 0x3c) + 1;
  if (bVar1) {
    puVar4 = *(ushort **)(param_5 + 0x10);
    if ((uint)(*(int *)(param_5 + 0x14) - (int)puVar4) < 8) {
      uVar7 = 0xe9;
joined_r0x00018714:
      if ((DAT_0001b850 & 1) != 0) {
        FUN_00011d90("# ERR # %s:%d: %s\n",s_udp_c_0001b930,uVar7,"udp_rcv - bad len");
      }
    }
    else if ((puVar4[3] == 0) || (sVar2 = FUN_00006200(0x11,param_2,param_3,param_5), sVar2 == -1))
    {
      *puVar4 = *puVar4 << 8 | *puVar4 >> 8;
      puVar4[1] = puVar4[1] << 8 | puVar4[1] >> 8;
      puVar4[2] = puVar4[2] << 8 | puVar4[2] >> 8;
      uVar5 = (uint)puVar4[2];
      iVar6 = *(int *)(param_5 + 0x14) - *(int *)(param_5 + 0x10);
      if (iVar6 < (int)uVar5) {
        uVar7 = 0xef;
        goto joined_r0x00018714;
      }
      if ((int)uVar5 < iVar6) {
        *(uint *)(param_5 + 0x14) = *(int *)(param_5 + 0x10) + uVar5;
      }
      *(int *)(param_5 + 0x10) = *(int *)(param_5 + 0x10) + 8;
      if ((puVar4[1] == 0) || (*puVar4 == 0)) {
        if ((DAT_0001b850 & 1) != 0) {
          FUN_00011d90("# ERR # %s:%d: %s\n",s_udp_c_0001b930,0xf4,"udp_rcv - bad port");
        }
      }
      else {
        iVar6 = FUN_00006e70(param_1,param_3);
        if (iVar6 < 1) {
          iVar6 = FUN_00017f30(param_1,param_3,puVar4[1],param_2,*puVar4);
          if (iVar6 != 0) {
            if (*(int *)(iVar6 + 0xc) != 2) {
              if (*(int *)(iVar6 + 0xc) == 0) {
                FUN_00017e68(iVar6);
              }
              FUN_00004b68(param_1,puVar4[1],*puVar4,param_5);
              return;
            }
LAB_00018b64:
            FUN_000183f0(param_1,iVar6,param_2,param_3,*puVar4,puVar4[1],param_5);
            return;
          }
          uVar7 = 0xf9;
          goto joined_r0x000188e8;
        }
        iVar9 = 0;
        for (iVar6 = DAT_0001b9b8; iVar6 != 0; iVar6 = *(int *)(iVar6 + 4)) {
          if (((((*(int *)(iVar6 + 0x18) == 0) || (*(int *)(iVar6 + 0x18) == param_3)) &&
               ((*(ushort *)(iVar6 + 0x1e) == 0 || (*(ushort *)(iVar6 + 0x1e) == puVar4[1])))) &&
              ((*(int *)(iVar6 + 0x14) == 0 || (*(int *)(iVar6 + 0x14) == param_2)))) &&
             ((*(ushort *)(iVar6 + 0x1c) == 0 || (*(ushort *)(iVar6 + 0x1c) == *puVar4)))) {
            for (piVar8 = *(int **)(iVar6 + 0x50); piVar8 != (int *)0x0; piVar8 = (int *)*piVar8) {
              if ((param_3 == piVar8[2]) &&
                 (((iVar3 = FUN_000088e8(piVar8[3]), iVar3 != 0 ||
                   (iVar3 = FUN_0000e4e8(piVar8[2]), iVar3 != 0)) && (param_1 == iVar3)))) {
                iVar9 = iVar9 + 1;
                break;
              }
            }
          }
        }
        if (0 < iVar9) {
          for (iVar6 = DAT_0001b9b8; iVar6 != 0; iVar6 = *(int *)(iVar6 + 4)) {
            if ((((*(int *)(iVar6 + 0x18) == 0) || (*(int *)(iVar6 + 0x18) == param_3)) &&
                ((*(ushort *)(iVar6 + 0x1e) == 0 || (*(ushort *)(iVar6 + 0x1e) == puVar4[1])))) &&
               (((*(int *)(iVar6 + 0x14) == 0 || (*(int *)(iVar6 + 0x14) == param_2)) &&
                ((*(ushort *)(iVar6 + 0x1c) == 0 || (*(ushort *)(iVar6 + 0x1c) == *puVar4)))))) {
              for (piVar8 = *(int **)(iVar6 + 0x50); piVar8 != (int *)0x0; piVar8 = (int *)*piVar8)
              {
                if ((param_3 == piVar8[2]) &&
                   (((iVar3 = FUN_000088e8(piVar8[3]), iVar3 != 0 ||
                     (iVar3 = FUN_0000e4e8(piVar8[2]), iVar3 != 0)) && (param_1 == iVar3)))) {
                  if (iVar9 < 2) goto LAB_00018b64;
                  iVar3 = FUN_0000a494(param_5);
                  if (iVar3 != 0) {
                    FUN_000183f0(param_1,iVar6,param_2,param_3,*puVar4,puVar4[1],iVar3);
                  }
                  break;
                }
              }
            }
          }
          goto LAB_00018bb0;
        }
      }
    }
    else if ((DAT_0001b850 & 1) != 0) {
      FUN_00011d90("# ERR # %s:%d: %s\n",s_udp_c_0001b930,0xec,"udp_rcv - bad sum");
    }
  }
  else {
    uVar7 = 0xe7;
joined_r0x000188e8:
    if ((DAT_0001b850 & 1) != 0) {
      FUN_00011d90("# ERR # %s:%d: %s\n",s_udp_c_0001b930,uVar7,"udp_rcv - no space");
    }
  }
  *(int *)(*(int *)(param_1 + 0x1a0) + 0x44) = *(int *)(*(int *)(param_1 + 0x1a0) + 0x44) + 1;
LAB_00018bb0:
  FUN_00009eec(param_5);
  return;
}


================================================================