FUNCTION FUN_00007abc @ 0x00007abc size=876
CALLERS (1): FUN_00007e28@0x00007e28
CALLEES (9): FUN_00009e60@0x00009e60, FUN_000078f0@0x000078f0, FUN_00017bf4@0x00017bf4, FUN_0000797c@0x0000797c, FUN_00017ad8@0x00017ad8, FUN_00007a2c@0x00007a2c, FUN_00011d90@0x00011d90, FUN_0000a9c0@0x0000a9c0, FUN_0000a318@0x0000a318

undefined4 FUN_00007abc(int param_1,int *param_2,byte *param_3,int *param_4)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  
  iVar6 = *(int *)(*param_2 + 0x14) - *(int *)(*param_2 + 0x10);
  DAT_0001b710 = DAT_0001b710 + iVar6;
  if ((DAT_0001b9dc >> 1 < DAT_0001b710) || (DAT_0001b9d4 <= DAT_0001b9e0)) {
    FUN_000078f0(DAT_0001b964);
    param_4 = (int *)FUN_00007a2c(param_3);
  }
  if (param_4 == (int *)0x0) {
    param_4 = (int *)FUN_0000797c(param_3,*param_2);
    if (param_4 == (int *)0x0) {
      DAT_0001b710 = DAT_0001b710 - iVar6;
      if ((DAT_0001b850 & 1) != 0) {
        FUN_00011d90("# ERR # %s:%d: %s\n",&DAT_0001b718,0x11f,"ip_reasm - no space for ipbuf");
      }
      goto LAB_00007dec;
    }
    param_4[0xc] = iVar6;
    *param_4 = (int)DAT_0001b960;
    piVar5 = param_4;
    piVar1 = param_4;
    if (DAT_0001b960 != (int *)0x0) {
      DAT_0001b960[1] = (int)param_4;
      piVar5 = param_4;
      piVar1 = DAT_0001b964;
    }
  }
  else {
    iVar2 = FUN_0000a318(param_4 + 10,*param_2);
    if (iVar2 != 0) {
      DAT_0001b710 = DAT_0001b710 - iVar6;
      if ((DAT_0001b850 & 1) != 0) {
        FUN_00011d90("# ERR # %s:%d: %s\n",&DAT_0001b718,0x128,"ip_reasm - invalid packet");
      }
      goto LAB_00007dec;
    }
    param_4[0xc] = param_4[0xc] + iVar6;
    piVar5 = DAT_0001b960;
    piVar1 = DAT_0001b964;
  }
  DAT_0001b964 = piVar1;
  DAT_0001b960 = piVar5;
  if ((*(ushort *)(param_3 + 6) & 0x2000) == 0) {
    param_4[7] = (uint)*(ushort *)(param_3 + 2) + (*param_3 & 0xf) * -4 + *(int *)(*param_2 + 8);
  }
  *param_2 = 0;
  if (param_4[7] != 0) {
    uVar4 = 0;
    for (piVar5 = (int *)param_4[10]; piVar5 != (int *)0x0; piVar5 = (int *)*piVar5) {
      if (((uint)piVar5[2] <= uVar4) && (uVar3 = piVar5[2] + (piVar5[5] - piVar5[4]), uVar4 < uVar3)
         ) {
        uVar4 = uVar3;
      }
    }
    uVar3 = param_4[7];
    if ((int)uVar3 <= (int)uVar4) {
      iVar6 = FUN_00009e60(0);
      *param_2 = iVar6;
      if (iVar6 != 0) {
        for (piVar5 = (int *)param_4[10]; piVar5 != (int *)0x0; piVar5 = (int *)*piVar5) {
          iVar6 = piVar5[2];
          uVar4 = iVar6 + (piVar5[5] - piVar5[4]);
          if (uVar3 < uVar4) {
            uVar4 = uVar3;
          }
          FUN_0000a9c0(piVar5[4],*(int *)(*param_2 + 0x14) + iVar6,uVar4 - iVar6);
        }
        *(uint *)(*param_2 + 0x14) = *(int *)(*param_2 + 0x14) + uVar3;
        FUN_000078f0(param_4);
        return 0;
      }
      FUN_000078f0(param_4);
      if ((DAT_0001b850 & 1) != 0) {
        FUN_00011d90("# ERR # %s:%d: %s\n",&DAT_0001b718,0x13c,"ip_reasm - no space for reasm buf");
      }
LAB_00007dec:
      *(int *)(*(int *)(param_1 + 0x1a0) + 0x24) = *(int *)(*(int *)(param_1 + 0x1a0) + 0x24) + 1;
      return 1;
    }
  }
  FUN_00017bf4(param_4[9]);
  param_4[8] = 0x1e;
  iVar6 = FUN_00017ad8(FUN_00007a0c,param_4,30000);
  param_4[9] = iVar6;
  return 1;
}


================================================================