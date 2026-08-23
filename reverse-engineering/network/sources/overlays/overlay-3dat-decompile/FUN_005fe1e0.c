FUNCTION FUN_005fe1e0 @ 0x005fe1e0  size=284
CALLERS (2): FUN_005f78c0@0x005f78c0, FUN_005f9280@0x005f9280
CALLEES (2): FUN_005baed0@0x005baed0, FUN_005bae80@0x005bae80
----------------------------------------------------------------

void FUN_005fe1e0(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  
  func_0x00106b60(param_1 + 0x4ba,0xffffffffffffffff,0x40);
  *(undefined2 *)(param_1 + 0x53a) = 0;
  uVar9 = uRam003424e8 >> 1;
  uVar2 = FUN_005bae80(bRam006c45f8 - 1);
  uVar3 = FUN_005baed0(bRam006c45f8 - 1);
  uVar1 = 1;
  uVar4 = 0;
  do {
    uVar7 = uVar1;
    if (((uVar9 & uVar2 | uVar3) & 1 << (uVar4 & 0x1f)) != 0) {
      *(short *)(param_1 + uVar7 * 2 + 0x4ba) = (short)uVar7;
      *(short *)(param_1 + 0x53a) = *(short *)(param_1 + 0x53a) + 1;
    }
    uVar1 = uVar7 + 1;
    uVar4 = uVar7;
  } while ((int)(uVar7 + 1) < 0xc);
  iVar6 = 1;
  iVar8 = 0;
  iVar5 = 2;
  do {
    if (-1 < *(short *)(param_1 + iVar5 + 0x4ba)) goto LAB_005fe2cc;
    iVar6 = iVar6 + 1;
    if (iVar6 < 1) {
      iVar6 = 0xb;
    }
    iVar8 = iVar8 + 1;
    iVar5 = iVar6 << 1;
  } while (iVar8 < 0x11);
  iVar6 = 1;
LAB_005fe2cc:
  *(short *)(param_1 + 0x53c) = (short)iVar6;
  *(undefined2 *)(param_1 + 6) = *(undefined2 *)(*(short *)(param_1 + 0x53c) * 2 + param_1 + 0x4ba);
  *(undefined2 *)(param_1 + 4) = 0;
  return;
}



================================================================