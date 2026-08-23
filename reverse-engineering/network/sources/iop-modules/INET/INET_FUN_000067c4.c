FUNCTION FUN_000067c4 @ 0x000067c4 size=844
CALLERS (1): FUN_00007e28@0x00007e28
CALLEES (5): FUN_000060a8@0x000060a8, FUN_0000b0ac@0x0000b0ac, FUN_00009eec@0x00009eec, FUN_00006e70@0x00006e70, FUN_00011d90@0x00011d90

void FUN_000067c4(int param_1,int param_2,int param_3,undefined4 param_4,int param_5)

{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  short sVar4;
  int iVar5;
  uint uVar6;
  byte *pbVar7;
  uint uVar8;
  int *piVar9;
  
  pbVar7 = *(byte **)(param_5 + 0x10);
  piVar9 = (int *)(*(int *)(param_1 + 0x1a0) + 0xc);
  if ((uint)(*(int *)(param_5 + 0x14) - (int)pbVar7) < 8) {
    if ((DAT_0001b850 & 1) != 0) {
      FUN_00011d90("# ERR # %s:%d: %s\n",s_igmp_c_0001b700,0x40,"igmp_rcv - bad len");
    }
  }
  else {
    sVar4 = FUN_000060a8(0,pbVar7);
    if (sVar4 == -1) {
      uVar2 = *(undefined4 *)(pbVar7 + 4);
      pbVar7[4] = (byte)((uint)uVar2 >> 0x18);
      pbVar7[5] = (byte)((uint)uVar2 >> 0x10);
      pbVar7[6] = (byte)((uint)uVar2 >> 8);
      pbVar7[7] = (byte)uVar2;
      uVar8 = (uint)pbVar7[1];
      iVar3 = *(int *)(pbVar7 + 4);
      if (uVar8 == 0) {
        uVar8 = 1;
      }
      bVar1 = *pbVar7;
      if (bVar1 != 0x12) {
        if (bVar1 < 0x13) {
          if (bVar1 == 0x11) {
            if (pbVar7[1] == 0) {
              uVar8 = 100;
              *(undefined4 *)(*(int *)(param_1 + 0x1a0) + 0x14) = 1;
              *(undefined4 *)(*(int *)(param_1 + 0x1a0) + 0x18) = 0;
              if ((param_3 != -0x1fffffff) || (iVar3 != 0)) goto LAB_00006adc;
            }
            else if ((iVar3 != 0) && (iVar5 = FUN_00006e70(param_1,iVar3), iVar5 < 1))
            goto LAB_00006adc;
            for (piVar9 = (int *)*piVar9; piVar9 != (int *)0x0; piVar9 = (int *)*piVar9) {
              if (((piVar9[2] != -0x1fffffff) && ((iVar3 == 0 || (iVar3 == piVar9[2])))) &&
                 ((piVar9[6] == 0 || ((int)uVar8 < piVar9[6])))) {
                uVar6 = FUN_0000b0ac();
                if (uVar8 == 0) {
                  trap(0x1c00);
                }
                DAT_0001b6f8 = 1;
                piVar9[6] = (uVar6 & 0x7fffffff) % uVar8 + 1;
              }
            }
          }
          goto LAB_00006adc;
        }
        if (bVar1 != 0x16) goto LAB_00006adc;
      }
      if (param_1 == 0) {
        if (param_2 == 0) goto LAB_00006adc;
      }
      else if (param_2 == *(int *)(param_1 + 0x70)) goto LAB_00006adc;
      iVar5 = FUN_00006e70(param_1,iVar3);
      if (0 < iVar5) {
        for (piVar9 = (int *)*piVar9; piVar9 != (int *)0x0; piVar9 = (int *)*piVar9) {
          if ((piVar9[2] != -0x1fffffff) && ((iVar3 == 0 || (iVar3 == piVar9[2])))) {
            piVar9[6] = 0;
            piVar9[5] = 2;
          }
        }
      }
    }
    else if ((DAT_0001b850 & 1) != 0) {
      FUN_00011d90("# ERR # %s:%d: %s\n",s_igmp_c_0001b700,0x42,"igmp_rcv - bad sum");
    }
  }
LAB_00006adc:
  FUN_00009eec(param_5);
  return;
}


================================================================