FUNCTION FUN_0000cdd4 @ 0x0000cdd4 size=1088
CALLERS (2): FUN_0000f130@0x0000f130, FUN_0000f304@0x0000f304
CALLEES (12): FUN_000199ac@0x000199ac, FUN_000199c4@0x000199c4, FUN_00011d90@0x00011d90, FUN_0000a60c@0x0000a60c, FUN_00001530@0x00001530, FUN_0000a7e0@0x0000a7e0, FUN_0000bfe0@0x0000bfe0, FUN_0000e62c@0x0000e62c, FUN_000032fc@0x000032fc, FUN_00002b88@0x00002b88, FUN_0000cb4c@0x0000cb4c, FUN_000199bc@0x000199bc

int FUN_0000cdd4(uint *param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6,
                int param_7)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  if (param_3 < 1) {
    param_3 = 6000;
  }
  if (param_4 < 1) {
    param_4 = 4;
  }
  if ((DAT_0001b850 & 4) != 0) {
    FUN_00011d90("resolv: ms=%d nretry=%d\n",param_3,param_4);
  }
  iVar9 = -0x204;
  piVar2 = (int *)FUN_0000a60c(0x828);
  if (piVar2 == (int *)0x0) {
    uVar6 = 0x17d;
  }
  else {
    iVar9 = -0x205;
    iVar3 = FUN_0000e62c();
    piVar2[2] = iVar3;
    if (iVar3 == 0) {
      uVar6 = 0x180;
    }
    else {
      piVar2[0x206] = (int)param_1;
      piVar2[0x208] = param_5;
      piVar2[0x205] = DAT_0001b820;
      piVar2[0x209] = param_6;
      DAT_0001b820 = DAT_0001b820 + 1;
      piVar2[1] = (int)DAT_0001b990;
      piVar1 = piVar2;
      if (DAT_0001b990 != (int *)0x0) {
        *DAT_0001b990 = (int)piVar2;
        piVar1 = DAT_0001b98c;
      }
      DAT_0001b98c = piVar1;
      *piVar2 = 0;
      DAT_0001b990 = piVar2;
      if (piVar2[0x208] < 1) {
        FUN_000199bc(piVar2 + 0x183,param_2);
      }
      else {
        uVar5 = *param_1;
        FUN_000199ac(piVar2 + 0x183,"%ld.%ld.%ld.%ld.in-addr.arpa",uVar5 & 0xff,uVar5 >> 8 & 0xff,
                     uVar5 >> 0x10 & 0xff,uVar5 >> 0x18);
      }
      iVar3 = FUN_0000bfe0(piVar2 + 3,0x200,piVar2 + 0x183,piVar2[0x205],piVar2[0x208]);
      piVar2[0x203] = iVar3;
      if (-1 < iVar3) {
        if ((DAT_0001b850 & 4) != 0) {
          FUN_00011d90("resolv-req:\n");
          FUN_000032fc(piVar2 + 3,piVar2[0x203]);
        }
        iVar3 = 0;
        if (0 < param_4) {
          do {
            iVar8 = 0;
            if (*(int *)piVar2[2] != 0) {
              iVar7 = 0;
              do {
                if ((DAT_0001b850 & 4) != 0) {
                  FUN_00011d90("resolv: ns_addr=");
                  FUN_00001530(*(undefined4 *)(iVar7 + piVar2[2]));
                  FUN_00011d90(" retry=%d/%d",iVar3,param_4);
                  FUN_00011d90(" index=%d",iVar8);
                  FUN_00011d90(s_ms__d_0001b82c,param_3);
                }
                iVar9 = FUN_0000cb4c(piVar2,*(undefined4 *)(iVar7 + piVar2[2]),param_3);
                if ((iVar9 == 0) && (0 < piVar2[0x208])) {
                  iVar4 = FUN_000199c4(piVar2 + 0x103);
                  if ((uint)piVar2[0x208] < iVar4 - 1U) {
                    iVar9 = -0x200;
                    goto LAB_0000d130;
                  }
                  FUN_000199bc(param_2,piVar2 + 0x103);
                }
                if (((DAT_0001b850 & 4) != 0) && (iVar9 != 0)) {
                  FUN_00011d90("resolv_udp() -> %d\n",iVar9);
                }
                if (iVar9 != -0x204) goto LAB_0000d130;
                iVar7 = iVar7 + 4;
                iVar8 = iVar8 + 1;
              } while (*(int *)(iVar7 + piVar2[2]) != 0);
            }
            iVar3 = iVar3 + 1;
          } while (iVar3 < param_4);
        }
        goto LAB_0000d130;
      }
      uVar6 = 400;
    }
  }
  if ((DAT_0001b850 & 1) != 0) {
    FUN_00011d90("# ERR # %s:%d: %s\n","resolv.c",uVar6,s_resolv_0001b824);
  }
LAB_0000d130:
  if (piVar2 != (int *)0x0) {
    piVar1 = (int *)piVar2[1];
    if (*piVar2 != 0) {
      *(int **)(*piVar2 + 4) = (int *)piVar2[1];
      piVar1 = DAT_0001b990;
    }
    DAT_0001b990 = piVar1;
    piVar1 = (int *)*piVar2;
    if ((undefined4 *)piVar2[1] != (undefined4 *)0x0) {
      *(undefined4 *)piVar2[1] = (int *)*piVar2;
      piVar1 = DAT_0001b98c;
    }
    DAT_0001b98c = piVar1;
    FUN_0000a7e0(piVar2[2]);
    FUN_0000a7e0(piVar2);
  }
  if (((param_7 == 0) && (iVar9 != 0)) && (iVar9 != -0x1f5)) {
    iVar9 = -500;
  }
  if ((DAT_0001b850 & 4) != 0) {
    FUN_00011d90("resolv() -> %d (",iVar9);
    FUN_00002b88(iVar9);
    FUN_00011d90(&DAT_0001b834);
  }
  return iVar9;
}


================================================================