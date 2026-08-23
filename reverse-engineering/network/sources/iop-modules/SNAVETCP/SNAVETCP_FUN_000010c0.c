FUNCTION FUN_000010c0 @ 0x000010c0 size=732
CALLERS (15): FUN_0000313c@0x0000313c, FUN_00004ec4@0x00004ec4, FUN_000060c0@0x000060c0, FUN_00011514@0x00011514, FUN_0000eb64@0x0000eb64, FUN_00008c70@0x00008c70, FUN_00001ab0@0x00001ab0, FUN_00009c90@0x00009c90, FUN_00008dc4@0x00008dc4, FUN_00002ae8@0x00002ae8, FUN_0000a264@0x0000a264, FUN_0000ef14@0x0000ef14, FUN_000097cc@0x000097cc, FUN_00001dd0@0x00001dd0, FUN_00003840@0x00003840
CALLEES (1): FUN_00011d00@0x00011d00

void FUN_000010c0(uint *param_1,uint *param_2)

{
  byte bVar1;
  byte bVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  bVar1 = (byte)param_2[1];
  if (bVar1 == 2) {
    bVar1 = (byte)param_1[1];
    if (bVar1 == 2) {
      uVar4 = *param_2;
      piVar3 = (int *)((uVar4 >> 0x18) * 0x3c + DAT_00016188);
      uVar6 = *param_1;
      uVar5 = *piVar3 + (uint)*(ushort *)((int)piVar3 + ((int)(uVar4 & 0xff0000) >> 0x10) * 6 + 0xe)
                        + (uVar4 & 0xffff);
      piVar3 = (int *)((uVar6 >> 0x18) * 0x3c + DAT_00016188);
      uVar4 = *piVar3 + (uint)*(ushort *)((int)piVar3 + ((int)(uVar6 & 0xff0000) >> 0x10) * 6 + 0xe)
                        + (uVar6 & 0xffff);
    }
    else if (bVar1 < 3) {
      if (bVar1 != 1) {
        return;
      }
      uVar4 = *param_1;
      piVar3 = (int *)((*param_2 >> 0x18) * 0x3c + DAT_00016188);
      uVar5 = *piVar3 + (uint)*(ushort *)((int)piVar3 + (uint)*(byte *)((int)param_2 + 2) * 6 + 0xe)
                        + (*param_2 & 0xffff);
    }
    else {
      if (bVar1 != 3) {
        return;
      }
      uVar4 = *param_1;
      piVar3 = (int *)((*param_2 >> 0x18) * 0x3c + DAT_00016188);
      uVar5 = *piVar3 + (uint)*(ushort *)((int)piVar3 + (uint)*(byte *)((int)param_2 + 2) * 6 + 0xe)
                        + (*param_2 & 0xffff);
    }
    goto LAB_00001384;
  }
  if (bVar1 < 3) {
    if (bVar1 != 1) {
      return;
    }
    bVar2 = (byte)param_1[1];
    if (bVar2 == 2) {
      uVar5 = *param_2;
      piVar3 = (int *)((*param_1 >> 0x18) * 0x3c + DAT_00016188);
      uVar4 = *piVar3 + (uint)*(ushort *)((int)piVar3 + (uint)*(byte *)((int)param_1 + 2) * 6 + 0xe)
                        + (*param_1 & 0xffff);
      goto LAB_00001384;
    }
    if (bVar2 < 3) {
LAB_00001120:
      if (bVar2 != bVar1) {
        return;
      }
    }
    else if (bVar2 != 3) {
      return;
    }
  }
  else {
    if (bVar1 != 3) {
      return;
    }
    bVar2 = (byte)param_1[1];
    if (bVar2 == 2) {
      uVar5 = *param_2;
      piVar3 = (int *)((*param_1 >> 0x18) * 0x3c + DAT_00016188);
      uVar4 = *piVar3 + (uint)*(ushort *)((int)piVar3 + (uint)*(byte *)((int)param_1 + 2) * 6 + 0xe)
                        + (*param_1 & 0xffff);
      goto LAB_00001384;
    }
    if (2 < bVar2) goto LAB_00001120;
    if (bVar2 != 1) {
      return;
    }
  }
  uVar4 = *param_1;
  uVar5 = *param_2;
LAB_00001384:
  FUN_00011d00(uVar4,uVar5);
  return;
}


================================================================