FUNCTION FUN_005af4d0 @ 0x005af4d0  size=680
CALLERS (1): FUN_005acab0@0x005acab0
CALLEES (6): FUN_005af2e0@0x005af2e0, FUN_00618b60@0x00618b60, FUN_00618ba0@0x00618ba0, FUN_005af2c0@0x005af2c0, FUN_005af780@0x005af780, FUN_005af1e0@0x005af1e0
----------------------------------------------------------------

void FUN_005af4d0(undefined1 *param_1)

{
  undefined1 *puVar1;
  long lVar2;
  ushort uVar3;
  int iVar4;
  
  if (param_1[0xe] == '\x01') {
    lVar2 = FUN_005af780();
    if (lVar2 == 1) {
      *param_1 = 1;
      param_1[0xe] = 0;
      param_1[0xf] = 0;
      uRam006c45f8 = 0;
      uRam006c45fc = 0;
      uRam006c4600 = 0;
      uRam00874f33 = param_1[0x907];
    }
  }
  else if (param_1[0xe] == '\0') {
    FUN_00618b60();
    func_0x00106b60(param_1 + 0x900,0,0x20);
    param_1[0xe] = param_1[0xe] + '\x01';
    for (iVar4 = 0; iVar4 < 2; iVar4 = iVar4 + 1) {
      lVar2 = FUN_00618ba0();
      if (lVar2 == 0) {
        return;
      }
      puVar1 = (undefined1 *)lVar2;
      *puVar1 = 1;
      puVar1[1] = 1;
      *(undefined2 *)(puVar1 + 0x22) = 0x23;
      *(short *)(puVar1 + 0x26) = (short)iVar4 * 0x160 + 0x80;
      *(undefined2 *)(puVar1 + 0x28) = 0xa0;
      uVar3 = 0;
      if (iVar4 != 0) {
        uVar3 = 0x4000;
      }
      *(ushort *)(puVar1 + 0x24) = *(ushort *)(puVar1 + 0x24) | uVar3;
    }
    lVar2 = FUN_00618ba0();
    if (lVar2 == 0) {
      return;
    }
    puVar1 = (undefined1 *)lVar2;
    *puVar1 = 1;
    puVar1[1] = 1;
    *(undefined2 *)(puVar1 + 0x22) = 0x1e;
    *(undefined1 **)(puVar1 + 0x10) = param_1 + 0x900;
    *(undefined1 **)(puVar1 + 0xc) = &LAB_005af4a0;
    lVar2 = FUN_00618ba0();
    if (lVar2 == 0) {
      return;
    }
    puVar1 = (undefined1 *)lVar2;
    *puVar1 = 1;
    puVar1[1] = 1;
    *(undefined2 *)(puVar1 + 0x22) = 0x1d;
    lVar2 = FUN_00618ba0();
    if (lVar2 == 0) {
      return;
    }
    puVar1 = (undefined1 *)lVar2;
    *puVar1 = 1;
    puVar1[1] = 1;
    *(undefined2 *)(puVar1 + 0x22) = 5;
  }
  FUN_005af2c0(0);
  FUN_005af2e0(0x14);
  FUN_005af1e0(0x127,0x6ad,2,0x638860);
  FUN_005af2e0(0x10);
  FUN_005af1e0(0xe8,0x88,2,0x638870);
  FUN_005af1e0(0x168,0xc0,2,0x638878);
  FUN_005af1e0(0x198,0xd0,2,0x638888);
  FUN_005af1e0(0x158,0xe8,2,0x638890);
  FUN_005af1e0(0x198,0xf8,2,0x638888);
  FUN_005af1e0(0x131,0x118,2,0x6388a0);
  FUN_005af2e0(0x14);
  FUN_005af1e0(0x78,0x138,2,0x6388b0);
  FUN_005af1e0(0x78,0x14e,2,0x6388d0);
  FUN_005af1e0(0x78,0x164,2,0x6388f0);
  return;
}



================================================================