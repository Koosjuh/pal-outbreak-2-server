FUNCTION FUN_00010f40 @ 0x00010f40 size=328
CALLERS (1): FUN_00000690@0x00000690
CALLEES (4): FUN_00000fa0@0x00000fa0, FUN_0000353c@0x0000353c, FUN_000013ac@0x000013ac, FUN_00001018@0x00001018

undefined4 FUN_00010f40(ushort *param_1)

{
  ushort uVar1;
  short sVar2;
  undefined4 uVar3;
  uint *puVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  
  uVar3 = 0xfffffff4;
  if ((byte)param_1[5] < 5) {
    sVar2 = 0;
    puVar4 = (uint *)FUN_00000fa0();
    uVar7 = (uint)(byte)param_1[5];
    puVar4[1] = 0;
    *puVar4 = uVar7;
    if (uVar7 != 0) {
      do {
        uVar7 = uVar7 - 1;
        iVar5 = (int)sVar2;
        iVar6 = (int)(uVar7 * 0x10000) >> 0x10;
        sVar2 = sVar2 + 1;
        FUN_000013ac(puVar4 + iVar5 * 3 + 3,*(undefined4 *)(param_1 + iVar6 * 4 + 10));
        uVar1 = param_1[iVar6 * 4 + 8];
        *(ushort *)(puVar4 + iVar5 * 3 + 2) = uVar1;
        puVar4[1] = puVar4[1] + (int)(short)uVar1;
      } while (0 < iVar6);
    }
    sVar2 = FUN_0000353c(puVar4,*(undefined4 *)(param_1 + 2),param_1[4],*param_1 & 0x7f,1,
                         *(undefined1 *)((int)param_1 + 0xb),(char)param_1[6],
                         *(undefined1 *)((int)param_1 + 0xd));
    FUN_00001018(puVar4);
    uVar3 = 0;
    if (sVar2 != 0) {
      uVar3 = 0xfffffff0;
    }
  }
  return uVar3;
}


================================================================