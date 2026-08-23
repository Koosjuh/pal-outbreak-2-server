FUNCTION FUN_005fba80 @ 0x005fba80  size=360
CALLERS (3): FUN_005f8ec0@0x005f8ec0, FUN_005fb860@0x005fb860, FUN_005fa490@0x005fa490
CALLEES (5): FUN_005ba7b0@0x005ba7b0, FUN_00618b60@0x00618b60, FUN_00618ba0@0x00618ba0, FUN_005ba570@0x005ba570, FUN_005b7fd0@0x005b7fd0
----------------------------------------------------------------

void FUN_005fba80(void)

{
  undefined1 *puVar1;
  long lVar2;
  undefined1 uVar3;
  int iVar4;
  
  FUN_00618b60();
  uRam006c4fcd = 0xff;
  lVar2 = FUN_00618ba0();
  if (lVar2 != 0) {
    puVar1 = (undefined1 *)lVar2;
    *puVar1 = 1;
    puVar1[1] = 1;
    *(undefined2 *)(puVar1 + 0x22) = 0x42;
    *(undefined4 *)(puVar1 + 0x30) = 1;
    for (iVar4 = 0; iVar4 < 5; iVar4 = iVar4 + 1) {
      lVar2 = FUN_00618ba0();
      if (lVar2 == 0) {
        return;
      }
      puVar1 = (undefined1 *)lVar2;
      *puVar1 = 1;
      puVar1[1] = 0;
      *(undefined2 *)(puVar1 + 0x22) = 0x49;
      *(code **)(puVar1 + 0xc) = FUN_005fbbf0;
      uVar3 = (undefined1)iVar4;
      puVar1[3] = uVar3;
      puVar1[2] = 2;
      lVar2 = FUN_00618ba0();
      if (lVar2 == 0) {
        return;
      }
      puVar1 = (undefined1 *)lVar2;
      *puVar1 = 1;
      puVar1[1] = 0;
      *(undefined2 *)(puVar1 + 0x22) = 0x47;
      *(code **)(puVar1 + 0xc) = FUN_005fbbf0;
      puVar1[3] = uVar3;
      lVar2 = FUN_00618ba0();
      if (lVar2 == 0) {
        return;
      }
      puVar1 = (undefined1 *)lVar2;
      *puVar1 = 1;
      puVar1[1] = 0;
      *(undefined2 *)(puVar1 + 0x22) = 0x48;
      *(code **)(puVar1 + 0xc) = FUN_005fbbf0;
      puVar1[3] = uVar3;
      puVar1[2] = 1;
      *(undefined4 *)(puVar1 + 0x2c) = 0xff804000;
      *(undefined2 *)(puVar1 + 0x3a) = 1;
      *(ushort *)(puVar1 + 0x24) = *(ushort *)(puVar1 + 0x24) | 0x400;
      lVar2 = FUN_00618ba0();
      if (lVar2 == 0) {
        return;
      }
      puVar1 = (undefined1 *)lVar2;
      *puVar1 = 1;
      puVar1[1] = 1;
      *(undefined2 *)(puVar1 + 0x22) = 99;
      *(code **)(puVar1 + 0xc) = FUN_005fc000;
      puVar1[3] = uVar3;
      *(undefined4 *)(puVar1 + 0x30) = 1;
    }
    FUN_005b7fd0(8,0,0x6c4602,0);
    FUN_005ba570(6);
    FUN_005ba7b0();
  }
  return;
}



================================================================