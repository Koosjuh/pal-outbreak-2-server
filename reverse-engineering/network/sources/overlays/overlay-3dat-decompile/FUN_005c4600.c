FUNCTION FUN_005c4600 @ 0x005c4600  size=140
CALLERS (2): FUN_00616d30@0x00616d30, FUN_006173c0@0x006173c0
CALLEES (2): FUN_005bf1e0@0x005bf1e0, FUN_005c3b10@0x005c3b10
----------------------------------------------------------------

undefined8 FUN_005c4600(undefined4 *param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  
  uVar1 = FUN_005bf1e0(2);
  uRam0086f840 = *(undefined4 *)(((uVar1 & 0xffff) - 1) * 0x24 + 0x6fee8c);
  FUN_005c3b10(0x6fb76b);
  iVar2 = 0x195;
  puVar3 = (undefined4 *)0x6fb758;
  do {
    iVar2 = iVar2 + -1;
    *param_1 = *puVar3;
    puVar3 = puVar3 + 1;
    param_1 = param_1 + 1;
  } while (0 < iVar2);
  return 0;
}



================================================================