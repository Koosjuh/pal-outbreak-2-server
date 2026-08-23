FUNCTION FUN_005fc850 @ 0x005fc850  size=816
CALLERS (3): FUN_005f9540@0x005f9540, FUN_005f9280@0x005f9280, FUN_005fa490@0x005fa490
CALLEES (5): FUN_005ba7b0@0x005ba7b0, FUN_005b8130@0x005b8130, FUN_00618b60@0x00618b60, FUN_00618ba0@0x00618ba0, FUN_005ba570@0x005ba570
----------------------------------------------------------------

void FUN_005fc850(long param_1)

{
  short *psVar1;
  short sVar2;
  undefined1 *puVar3;
  int iVar4;
  long lVar5;
  int iVar6;
  uint uVar7;
  short *psVar8;
  char cVar9;
  
  uRam006c4fcd = 0xff;
  FUN_00618b60();
  cVar9 = (char)param_1;
  uVar7 = 0;
  if (cVar9 == '\x03') {
    for (; uVar7 < 3; uVar7 = uVar7 + 1) {
      iVar6 = uVar7 * 0xc;
      lVar5 = FUN_005b8130(iVar6 + 0x6498b0);
      if (lVar5 == 0) {
        return;
      }
      iVar4 = (int)lVar5;
      *(undefined2 *)(iVar4 + 0x26) =
           *(undefined2 *)(&DAT_00649aa0 + *(short *)(&DAT_006498b2 + iVar6) * 4);
      *(undefined2 *)(iVar4 + 0x28) =
           *(undefined2 *)(&DAT_00649aa2 + *(short *)(&DAT_006498b2 + iVar6) * 4);
      *(undefined1 *)(iVar4 + 2) = 3;
      if (uVar7 == 2) {
        *(undefined4 *)(iVar4 + 0x2c) = 0x32003cff;
      }
      *(undefined4 *)(iVar4 + 0x30) = 1;
    }
  }
  else {
    if (cVar9 == '\x02') {
      puVar3 = (undefined1 *)FUN_00618ba0();
      *puVar3 = 1;
      puVar3[1] = 1;
      *(undefined2 *)(puVar3 + 0x22) = 0x50;
      *(undefined1 **)(puVar3 + 0xc) = &LAB_005fd3e0;
      puVar3 = (undefined1 *)FUN_00618ba0();
      *puVar3 = 1;
      puVar3[1] = 1;
      *(undefined2 *)(puVar3 + 0x22) = 0x51;
      iVar6 = 0;
      *(undefined1 **)(puVar3 + 0xc) = &LAB_005fd3e0;
      puVar3[3] = 1;
      do {
        puVar3 = (undefined1 *)FUN_00618ba0();
        *puVar3 = 1;
        sVar2 = (short)iVar6;
        puVar3[1] = 1;
        puVar3[2] = (char)iVar6;
        puVar3[3] = 0;
        iVar6 = iVar6 + 1;
        *(short *)(puVar3 + 0x22) = sVar2 + 0xd9;
        *(code **)(puVar3 + 0xc) = FUN_005fd630;
      } while (iVar6 < 2);
    }
    else {
      if ((cVar9 != '\x01') && (cVar9 != '\0')) goto LAB_005fcaac;
      puVar3 = (undefined1 *)FUN_00618ba0();
      *puVar3 = 1;
      puVar3[1] = 1;
      *(undefined2 *)(puVar3 + 0x22) = 0x50;
      *(undefined1 **)(puVar3 + 0xc) = &LAB_005fd3e0;
      puVar3[2] = 2;
      puVar3 = (undefined1 *)FUN_00618ba0();
      *puVar3 = 1;
      puVar3[1] = 1;
      *(undefined2 *)(puVar3 + 0x22) = 0x51;
      *(undefined1 **)(puVar3 + 0xc) = &LAB_005fd3e0;
      iVar6 = 0;
      puVar3[2] = 2;
      puVar3[3] = 1;
      do {
        puVar3 = (undefined1 *)FUN_00618ba0();
        *puVar3 = 1;
        sVar2 = (short)iVar6;
        puVar3[1] = 1;
        puVar3[2] = (char)iVar6;
        puVar3[3] = 1;
        iVar6 = iVar6 + 1;
        *(short *)(puVar3 + 0x22) = sVar2 + 0xd9;
        *(code **)(puVar3 + 0xc) = FUN_005fd630;
      } while (iVar6 < 2);
    }
    puVar3 = (undefined1 *)FUN_00618ba0();
    *puVar3 = 1;
    puVar3[1] = 1;
    *(undefined2 *)(puVar3 + 0x22) = 0x50;
    *(undefined1 **)(puVar3 + 0xc) = &LAB_005fd3e0;
    puVar3[2] = 1;
  }
LAB_005fcaac:
  psVar8 = (short *)(&PTR_DAT_00649a90)[cVar9];
  while( true ) {
    if (*psVar8 < 0) {
      if (cVar9 == '\x01') {
        FUN_005ba570(0x1c);
      }
      else if ((param_1 == 0) || (cVar9 == '\x02')) {
        FUN_005ba570(0xb);
      }
      FUN_005ba7b0();
      return;
    }
    lVar5 = FUN_005b8130(psVar8);
    if (lVar5 == 0) break;
    iVar6 = (int)lVar5;
    *(undefined2 *)(iVar6 + 0x26) = *(undefined2 *)(&DAT_00649aa0 + psVar8[1] * 4);
    psVar1 = psVar8 + 1;
    psVar8 = psVar8 + 6;
    *(undefined2 *)(iVar6 + 0x28) = *(undefined2 *)(&DAT_00649aa2 + *psVar1 * 4);
    *(char *)(iVar6 + 2) = cVar9;
    *(undefined4 *)(iVar6 + 0x30) = 1;
  }
  return;
}



================================================================