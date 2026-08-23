FUNCTION FUN_000110d0 @ 0x000110d0 size=320
CALLERS (1): FUN_000006d8@0x000006d8
CALLEES (4): FUN_00000fa0@0x00000fa0, FUN_00004cac@0x00004cac, FUN_000013ac@0x000013ac, FUN_00001018@0x00001018

undefined4 FUN_000110d0(ushort *param_1)

{
  ushort uVar1;
  undefined4 uVar2;
  uint *puVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  short sVar7;
  
  uVar2 = 0xfffffff4;
  if ((byte)param_1[4] < 5) {
    sVar7 = 0;
    puVar3 = (uint *)FUN_00000fa0();
    uVar6 = (uint)(byte)param_1[4];
    puVar3[1] = 0;
    *puVar3 = uVar6;
    if (uVar6 != 0) {
      do {
        uVar6 = uVar6 - 1;
        iVar4 = (int)sVar7;
        iVar5 = (int)(uVar6 * 0x10000) >> 0x10;
        sVar7 = sVar7 + 1;
        FUN_000013ac(puVar3 + iVar4 * 3 + 3,*(undefined4 *)(param_1 + iVar5 * 4 + 8));
        uVar1 = param_1[iVar5 * 4 + 6];
        *(ushort *)(puVar3 + iVar4 * 3 + 2) = uVar1;
        puVar3[1] = puVar3[1] + (int)(short)uVar1;
      } while (0 < iVar5);
    }
    iVar4 = FUN_00004cac(puVar3,*param_1 & 0x3f,*(undefined4 *)(param_1 + 2),0,
                         *(undefined1 *)((int)param_1 + 9),(char)param_1[5],
                         *(undefined1 *)((int)param_1 + 0xb),0,0);
    FUN_00001018(puVar3);
    uVar2 = 0;
    if (iVar4 << 0x10 < 0) {
      uVar2 = 0xfffffff0;
    }
  }
  return uVar2;
}


================================================================