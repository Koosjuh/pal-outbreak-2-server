FUNCTION FUN_0060be50 @ 0x0060be50  size=400
CALLERS (0): 
CALLEES (0): 
----------------------------------------------------------------

ulong FUN_0060be50(ulong param_1,byte *param_2,uint param_3)

{
  byte *pbVar1;
  byte *pbVar2;
  byte *pbVar3;
  byte *pbVar4;
  byte *pbVar5;
  byte *pbVar6;
  byte *pbVar7;
  byte *pbVar8;
  uint uVar9;
  ulong uVar10;
  ulong uVar11;
  long lVar12;
  long lVar13;
  long lVar14;
  long lVar15;
  long lVar16;
  long lVar17;
  long lVar18;
  long lVar19;
  long lVar20;
  long lVar21;
  long lVar22;
  long lVar23;
  long lVar24;
  long lVar25;
  long lVar26;
  
  uVar11 = param_1 & 0xffff;
  uVar10 = param_1 >> 0x10 & 0xffff;
  if (param_2 == (byte *)0x0) {
    uVar11 = 1;
  }
  else {
    while (param_3 != 0) {
      uVar9 = 0x15b0;
      if (param_3 < 0x15b0) {
        uVar9 = param_3;
      }
      param_3 = param_3 - uVar9;
      for (; 0xf < (int)uVar9; uVar9 = uVar9 - 0x10) {
        lVar12 = uVar11 + *param_2;
        lVar13 = lVar12 + (ulong)param_2[1];
        pbVar1 = param_2 + 8;
        pbVar2 = param_2 + 9;
        lVar14 = lVar13 + (ulong)param_2[2];
        pbVar3 = param_2 + 10;
        pbVar4 = param_2 + 0xb;
        lVar15 = lVar14 + (ulong)param_2[3];
        pbVar5 = param_2 + 0xc;
        pbVar6 = param_2 + 0xd;
        lVar16 = lVar15 + (ulong)param_2[4];
        pbVar7 = param_2 + 0xe;
        pbVar8 = param_2 + 0xf;
        lVar17 = lVar16 + (ulong)param_2[5];
        lVar18 = lVar17 + (ulong)param_2[6];
        lVar19 = lVar18 + (ulong)param_2[7];
        param_2 = param_2 + 0x10;
        lVar20 = lVar19 + (ulong)*pbVar1;
        lVar21 = lVar20 + (ulong)*pbVar2;
        lVar22 = lVar21 + (ulong)*pbVar3;
        lVar23 = lVar22 + (ulong)*pbVar4;
        lVar24 = lVar23 + (ulong)*pbVar5;
        lVar25 = lVar24 + (ulong)*pbVar6;
        lVar26 = lVar25 + (ulong)*pbVar7;
        uVar11 = lVar26 + (ulong)*pbVar8;
        uVar10 = uVar10 + lVar12 + lVar13 + lVar14 + lVar15 + lVar16 + lVar17 + lVar18 + lVar19 +
                 lVar20 + lVar21 + lVar22 + lVar23 + lVar24 + lVar25 + lVar26 + uVar11;
      }
      for (; uVar9 != 0; uVar9 = uVar9 - 1) {
        uVar11 = uVar11 + *param_2;
        param_2 = param_2 + 1;
        uVar10 = uVar10 + uVar11;
      }
      uVar11 = func_0x0010fcb8(uVar11,0xfff1);
      uVar10 = func_0x0010fcb8(uVar10,0xfff1);
    }
    uVar11 = uVar10 << 0x10 | uVar11;
  }
  return uVar11;
}



================================================================
FUNCTION thunk_FUN_0060c0f0 @ 0x0060bfe0  size=8
CALLERS (1): FUN_0060acb0@0x0060acb0
CALLEES (1): FUN_0060c0f0@0x0060c0f0
----------------------------------------------------------------

void thunk_FUN_0060c0f0(void)

{
  FUN_0060c0f0();
  return;
}



================================================================