
undefined4
FUN_001cde00(long param_1,uint param_2,undefined8 param_3,ulong param_4,undefined8 param_5)

{
  bool bVar1;
  long lVar2;
  long lVar3;
  uint uVar4;
  char *pcVar5;
  ulong extraout_a3;
  ulong extraout_a3_00;
  ulong uVar6;
  ulong extraout_a3_01;
  undefined1 extraout_t0_lo;
  undefined4 uVar7;
  long extraout_t0;
  undefined8 extraout_t0_00;
  ulong extraout_t1;
  ulong extraout_t1_00;
  ulong uVar8;
  undefined2 extraout_t2_lo;
  uint uVar9;
  uint uVar10;
  char cVar11;
  undefined1 *puVar12;
  
  cVar11 = '\0';
  if ((0x11ff < DAT_0024c7f8) && (DAT_0024c7f8 < 0x1400)) {
    cVar11 = '\x01';
  }
  if ((0x13ff < DAT_0024c7f8) && (DAT_0024c7f8 < 0x1800)) {
    cVar11 = '\x02';
  }
  if (cVar11 != '\0') {
    uVar7 = 4;
    if (((param_4 & 0xffffffff80000000) == 0) && (uVar7 = 1, (param_4 & 0x40000000) != 0)) {
      uVar7 = 2;
    }
    uVar10 = 0;
    bVar1 = (param_4 & 0x20000000) != 0;
    uVar9 = (uint)bVar1;
    uVar4 = (uint)bVar1 << 0xf;
    lVar2 = FUN_001cdc00(cVar11,param_2 & 0xffff | uVar4,param_3,uVar4,uVar7,param_3);
    if (lVar2 == 0) {
      uVar10 = 2;
      if ((extraout_t0 == 4) && (param_1 != 0)) {
        return 0;
      }
      lVar2 = FUN_001cdb60(extraout_t0);
      if (lVar2 == 0) {
        return 0;
      }
      puVar12 = (undefined1 *)lVar2;
      puVar12[3] = extraout_t0_lo;
      *(undefined2 *)(puVar12 + 10) = extraout_t2_lo;
      *puVar12 = 1;
      puVar12[8] = cVar11;
      uVar6 = extraout_a3_00;
      uVar8 = extraout_t1_00;
    }
    else {
      pcVar5 = (char *)lVar2;
      pcVar5[3] = (byte)extraout_t0 | pcVar5[3] & ~(byte)extraout_t0;
      uVar6 = extraout_a3;
      uVar8 = extraout_t1;
      if (param_1 != 0) {
        *pcVar5 = *pcVar5 + '\x01';
      }
    }
    lVar3 = FUN_001cd500(cVar11,uVar8 & 0xffff | uVar6 & 0xffff);
    if (lVar3 == 0) {
      uVar10 = uVar10 + 1;
      lVar3 = FUN_001cd570(cVar11,extraout_a3_01 & 0xffff,extraout_t0_00);
      if (lVar3 == -1) {
        return 0;
      }
      pcVar5 = (char *)((int)lVar3 * 0x14 + 0x36c422);
    }
    else {
      pcVar5 = (char *)lVar3;
      pcVar5[0xf] = (byte)extraout_t0_00 | pcVar5[0xf] & ~(byte)extraout_t0_00;
      if (param_1 != 0) {
        *pcVar5 = *pcVar5 + '\x01';
      }
      pcVar5 = pcVar5 + 2;
    }
    if (cVar11 == '\x01') {
      uVar9 = 0;
    }
    FUN_001ce090(param_2,*(undefined4 *)((int)lVar2 + 4),pcVar5,param_4 & 0x1fffffff,
                 uVar10 | uVar9 << 7,param_5,cVar11,param_1);
    if (param_1 != 0) {
      FUN_001cdc70(*(undefined4 *)((int)lVar2 + 4),param_1,uVar9);
    }
    return 1;
  }
  return 0;
}

