FUNCTION FUN_00000524 @ 0x00000524 size=236
CALLERS (1): FUN_00002858@0x00002858
CALLEES (2): FUN_00003818@0x00003818, FUN_00003810@0x00003810

void FUN_00000524(int param_1)

{
  ushort uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  uVar1 = *(ushort *)(param_1 + 0x1c);
  FUN_00003818(DAT_00009464);
  if (uVar1 < 3) {
    iVar2 = (int)(short)uVar1;
    iVar4 = iVar2 * 0x14;
    uVar3 = 0xffffffff;
    if ((&DAT_00009428)[iVar2 * 10] != 0) {
      *(undefined4 *)(param_1 + 0x18) = 0;
      *(ushort *)(param_1 + 0x1c) = uVar1;
      *(undefined2 *)(param_1 + 0x1e) = *(undefined2 *)(&DAT_0000942a + iVar4);
      *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(&DAT_0000942c + iVar4);
      *(undefined2 *)(param_1 + 0x24) = *(undefined2 *)(&DAT_00009430 + iVar4);
      (&DAT_00009428)[iVar2 * 10] = 0;
      goto LAB_000005e8;
    }
  }
  else {
    uVar3 = 0xfffffffc;
  }
  *(undefined4 *)(param_1 + 0x18) = uVar3;
LAB_000005e8:
  FUN_00003810(DAT_00009464);
  return;
}


================================================================