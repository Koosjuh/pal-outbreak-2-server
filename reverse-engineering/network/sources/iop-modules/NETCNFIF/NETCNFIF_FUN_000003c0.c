FUNCTION FUN_000003c0 @ 0x000003c0 size=1724
CALLERS (0): 
CALLEES (23): FUN_00002754@0x00002754, FUN_000027a8@0x000027a8, FUN_0000275c@0x0000275c, FUN_000027dc@0x000027dc, FUN_000023b4@0x000023b4, FUN_00000b70@0x00000b70, FUN_00002714@0x00002714, FUN_0000272c@0x0000272c, FUN_000016c8@0x000016c8, FUN_00000e60@0x00000e60, FUN_000023e0@0x000023e0, FUN_00002784@0x00002784, FUN_000027d4@0x000027d4, FUN_0000271c@0x0000271c, FUN_00002340@0x00002340, FUN_00002724@0x00002724, FUN_0000276c@0x0000276c, FUN_000027b0@0x000027b0, FUN_00002764@0x00002764, FUN_0000277c@0x0000277c, FUN_00002704@0x00002704, FUN_0000270c@0x0000270c, FUN_00002284@0x00002284

int * FUN_000003c0(undefined4 param_1,int *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 *puVar8;
  int iVar9;
  int *piVar10;
  int iVar11;
  undefined4 *puVar12;
  undefined4 *puVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  int iVar16;
  int local_38;
  code *local_34;
  code *local_30;
  code *local_2c;
  undefined4 local_28 [2];
  
  iVar16 = 0;
  switch(param_1) {
  case 0:
    iVar16 = FUN_00002704(param_2 + 4,param_2[2]);
    break;
  case 1:
    iVar16 = FUN_00002704(param_2 + 4,param_2[2]);
    if (-1 < iVar16) {
      FUN_000027d4(local_28);
      puVar2 = (undefined4 *)FUN_000027a8(0,iVar16 * 0x208,0);
      if (puVar2 != (undefined4 *)0x0) {
        puVar3 = (undefined4 *)FUN_000027a8(0,*param_2 * 0x240,0);
        if (puVar3 != (undefined4 *)0x0) {
          FUN_000027dc(local_28[0]);
          iVar16 = FUN_0000270c(param_2 + 4,param_2[2],puVar2);
          if (-1 < iVar16) {
            iVar7 = 0;
            puVar12 = puVar2;
            puVar13 = puVar3;
            if (0 < *param_2) {
              do {
                if (iVar16 <= iVar7) break;
                puVar5 = puVar12;
                puVar1 = puVar13;
                do {
                  puVar8 = puVar1;
                  puVar4 = puVar5;
                  uVar6 = puVar4[1];
                  uVar14 = puVar4[2];
                  uVar15 = puVar4[3];
                  *puVar8 = *puVar4;
                  puVar8[1] = uVar6;
                  puVar8[2] = uVar14;
                  puVar8[3] = uVar15;
                  puVar5 = puVar4 + 4;
                  puVar1 = puVar8 + 4;
                } while (puVar5 != puVar12 + 0x80);
                uVar6 = puVar4[5];
                puVar8[4] = *puVar5;
                puVar8[5] = uVar6;
                iVar7 = iVar7 + 1;
                puVar12 = puVar12 + 0x82;
                puVar13 = puVar13 + 0x90;
              } while (iVar7 < *param_2);
            }
            uVar6 = FUN_00002340(puVar3,param_2[3],*param_2 * 0x240);
            do {
              iVar7 = FUN_000023b4(uVar6);
            } while (iVar7 != 0);
          }
          FUN_000027d4(local_28);
          FUN_000027b0(puVar2);
          FUN_000027b0(puVar3);
          FUN_000027dc(local_28[0]);
          goto LAB_00000a50;
        }
        FUN_000027b0(puVar2);
      }
      iVar16 = -2;
      FUN_000027dc(local_28[0]);
      goto LAB_00000a50;
    }
    break;
  case 2:
    FUN_00000e60(&DAT_00003450,DAT_00003430,DAT_00003434,param_2[1]);
    iVar16 = FUN_00002714(param_2 + 4,param_2[2],param_2 + 0x44,&DAT_00003450);
    if (iVar16 < 0) goto LAB_00000a50;
    FUN_00000b70(&DAT_00003cc0);
    iVar16 = FUN_000016c8(&DAT_00003cc0,&DAT_00003450,param_2[2]);
    if (-1 < iVar16) {
      uVar6 = FUN_00002340(&DAT_00003cc0,param_2[3],0x1340);
      do {
        iVar7 = FUN_000023b4(uVar6);
      } while (iVar7 != 0);
      *param_2 = iVar16;
      return param_2;
    }
    break;
  case 3:
    FUN_00000e60(&DAT_00003450,DAT_00003430,DAT_00003434,param_2[1]);
    iVar16 = FUN_00002284(&DAT_00003450,&DAT_00003cc0,param_2[2]);
    if (-1 < iVar16) {
      iVar16 = FUN_0000271c(param_2 + 4,param_2[2],param_2 + 0x44,&DAT_00003450);
    }
    break;
  case 4:
    FUN_00000e60(&DAT_00003450,DAT_00003430,DAT_00003434,param_2[1]);
    iVar16 = FUN_00002714(param_2 + 4,param_2[2],param_2 + 0x44,&DAT_00003450);
    if (-1 < iVar16) {
      DAT_00003458 = DAT_0000345c + 3 & 0xfffffffc;
      DAT_0000345c = DAT_00003458;
      iVar16 = FUN_00002284(&DAT_00003450,&DAT_00003cc0,param_2[2]);
      if (-1 < iVar16) {
        iVar16 = FUN_00002754(param_2 + 4,param_2[2],param_2 + 0x44,param_2 + 0x84,&DAT_00003450);
      }
    }
    break;
  case 5:
    iVar16 = FUN_00002724(param_2 + 4,param_2[2],param_2 + 0x44);
    break;
  case 6:
    iVar16 = FUN_0000272c(param_2 + 4,param_2[2],param_2 + 0x44);
    break;
  case 7:
    iVar16 = FUN_0000275c(param_2 + 4);
    break;
  case 8:
    iVar16 = FUN_00002764(param_2 + 4);
    break;
  case 9:
    iVar16 = FUN_0000276c(param_2 + 4,&DAT_00005000,0x100);
    break;
  case 10:
    FUN_00000e60(&DAT_00003450,DAT_00003430,DAT_00003434,param_2[1]);
    iVar16 = FUN_0000277c(param_2 + 4,param_2[2],param_2 + 0x44,&DAT_00003450);
    break;
  case 0xb:
    local_38 = param_2[2];
    local_34 = FUN_00002464;
    local_30 = FUN_00002558;
    local_2c = FUN_00002684;
    FUN_000023e0();
    FUN_00002784(&local_38);
    goto LAB_00000a50;
  case 0xf:
    FUN_00002784(0);
    goto LAB_00000a50;
  case 100:
    param_2[3] = (int)&DAT_00003cc0;
    break;
  case 0x65:
    if (DAT_00003430 == 0) {
      DAT_00003434 = *param_2;
      FUN_000027d4(local_28);
      DAT_00003430 = FUN_000027a8(0,DAT_00003434,0);
      FUN_000027dc(local_28[0]);
      if (DAT_00003430 == 0) {
        iVar16 = -2;
      }
    }
    goto LAB_00000a50;
  case 0x66:
    if (DAT_00003430 != 0) {
      FUN_000027d4(local_28);
      FUN_000027b0(DAT_00003430);
      FUN_000027dc(local_28[0]);
    }
    DAT_00003434 = 0;
    DAT_00003430 = 0;
    goto LAB_00000a50;
  case 0x67:
    FUN_00000e60(&DAT_00003450,DAT_00003430,DAT_00003434,param_2[1]);
    iVar16 = FUN_00002284(&DAT_00003450,&DAT_00003cc0,param_2[2]);
    if (iVar16 < 0) goto LAB_00000a50;
    if ((DAT_00003468 != (int *)0x0) && (*DAT_00003468 != 0)) {
      iVar7 = *(int *)(*DAT_00003468 + 0x14);
      iVar11 = 0;
      if (iVar7 != 0) {
        iVar9 = 0;
        do {
          if (((*(int *)(iVar7 + 0x38) != 0) && (iVar9 < 3)) && (-1 < iVar9)) {
            iVar11 = iVar11 + 1;
          }
          iVar9 = iVar9 + 1;
          iVar7 = iVar7 + 4;
        } while (iVar9 < 10);
        *(int *)(*(int *)(*DAT_00003468 + 0x14) + 0x28) = iVar11 + -1;
        piVar10 = *(int **)(*DAT_00003468 + 0x14);
        if ((*(char *)((int)piVar10 + 0x12e) != '\x01') && (*piVar10 != 2)) {
          *piVar10 = **(int **)(*DAT_00003468 + 0x18);
        }
      }
    }
    param_2[3] = (int)&DAT_00003450;
  }
LAB_00000a50:
  *param_2 = iVar16;
  return param_2;
}


================================================================