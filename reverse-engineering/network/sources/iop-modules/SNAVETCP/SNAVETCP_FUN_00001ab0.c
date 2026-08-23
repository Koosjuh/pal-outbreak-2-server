FUNCTION FUN_00001ab0 @ 0x00001ab0 size=800
CALLERS (1): FUN_00005828@0x00005828
CALLEES (12): FUN_00001454@0x00001454, FUN_00000fa0@0x00000fa0, FUN_0000139c@0x0000139c, FUN_00001018@0x00001018, FUN_00003cf8@0x00003cf8, FUN_0000f09c@0x0000f09c, FUN_000013bc@0x000013bc, FUN_00011d00@0x00011d00, FUN_00002020@0x00002020, FUN_000010c0@0x000010c0, FUN_00003b30@0x00003b30, FUN_00001dd0@0x00001dd0

undefined4 FUN_00001ab0(uint *param_1,ushort param_2,undefined4 param_3)

{
  int iVar1;
  short sVar2;
  undefined1 *puVar3;
  uint *puVar4;
  uint uVar5;
  undefined4 uVar6;
  uint uVar7;
  uint *puVar8;
  int iVar9;
  uint *puVar10;
  int iVar11;
  undefined1 auStack_80 [16];
  undefined1 auStack_70 [2];
  undefined2 local_6e;
  byte local_68 [9];
  char local_5f;
  undefined4 local_58;
  undefined1 auStack_50 [8];
  undefined1 auStack_48 [16];
  undefined4 local_38;
  undefined4 local_30;
  undefined4 local_2c;
  
  puVar4 = param_1 + 3;
  param_1[1] = param_1[1] - (uint)param_2;
  *(ushort *)(param_1 + 2) = (short)param_1[2] - param_2;
  FUN_00001454(puVar4,(int)(short)param_2);
  if ((char)param_1[4] == '\x01') {
    puVar3 = (undefined1 *)FUN_000013bc(puVar4);
  }
  else {
    FUN_0000139c(auStack_70,auStack_80);
    FUN_000010c0(auStack_70,puVar4,0xc);
    puVar3 = auStack_80;
  }
  FUN_00003b30(0,param_1,0);
  switch(*puVar3) {
  case 0:
  case 4:
  case 0xb:
  case 0xc:
  case 0xd:
  case 0xe:
  case 0x11:
  case 0x12:
    break;
  default:
    return 0xffffffff;
  case 3:
    param_1 = param_1 + 3;
    FUN_00001454(param_1,8);
    FUN_0000139c(auStack_50,local_68);
    FUN_000010c0(auStack_50,param_1,0x14);
    FUN_00001454(param_1,(local_68[0] & 0xf) << 2);
    if (local_5f != '\x06') {
      if (local_5f == '\x11') {
        FUN_0000139c(auStack_50,auStack_70);
        FUN_000010c0(auStack_50,param_1,8);
        FUN_00003cf8(local_6e,local_58,puVar3[1]);
        return 0;
      }
      return 0;
    }
    break;
  case 5:
    FUN_00001454(param_1 + 3,8);
    FUN_0000139c(auStack_70,auStack_48);
    FUN_000010c0(auStack_70,param_1 + 3,0x14);
    if ((puVar3[1] == '\0') || (puVar3[1] == '\x02')) {
      FUN_00011d00(&local_30,puVar3 + 4,4);
      local_38 = FUN_00002020(local_38);
      uVar6 = 2;
    }
    else {
      FUN_00011d00(&local_2c,puVar3 + 4,4);
      uVar6 = 6;
      local_30 = local_2c;
    }
    FUN_0000f09c(local_38,local_30,uVar6,param_3);
    break;
  case 8:
    puVar4 = (uint *)FUN_00000fa0();
    if (puVar4 == (uint *)0x0) {
      return 0xffffffff;
    }
    *puVar4 = *param_1;
    puVar4[1] = param_1[1];
    uVar5 = *param_1;
    uVar7 = 0;
    if (uVar5 != 0) {
      iVar11 = 8;
      puVar8 = param_1 + uVar5 * 3;
      iVar9 = uVar5 * 0xc + 8;
      puVar10 = puVar4;
      do {
        iVar1 = iVar11 + 4;
        iVar11 = iVar11 + 0xc;
        uVar7 = uVar7 + 1;
        *(short *)(puVar10 + 2) = (short)puVar8[-1];
        FUN_00011d00((int)puVar4 + iVar1,(int)param_1 + iVar9 + -8,8);
        puVar10 = puVar10 + 3;
        puVar8 = puVar8 + -3;
        iVar9 = iVar9 + -0xc;
      } while (uVar7 < *param_1);
    }
    sVar2 = FUN_00001dd0(0,0,param_3,puVar4);
    if (sVar2 == -1) {
      FUN_00001018(puVar4);
      return 0xffffffff;
    }
    FUN_00001018(puVar4);
    return 0;
  }
  return 0;
}


================================================================