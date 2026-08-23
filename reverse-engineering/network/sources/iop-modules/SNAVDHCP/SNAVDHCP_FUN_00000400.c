FUNCTION FUN_00000400 @ 0x00000400 size=108
CALLERS (1): FUN_00000a64@0x00000a64
CALLEES (1): FUN_00002d90@0x00002d90

void FUN_00000400(void)

{
  undefined4 *puVar1;
  short *psVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = 0;
  iVar3 = 0;
  do {
    puVar1 = (undefined4 *)((int)&PTR_DAT_00002ec0 + iVar3);
    psVar2 = (short *)((int)&DAT_00002ebe + iVar3);
    *(undefined2 *)((int)&DAT_00002eba + iVar3) = 0;
    iVar3 = iVar3 + 0xc;
    uVar4 = uVar4 + 1;
    FUN_00002d90(*puVar1,0,(int)*psVar2);
  } while (uVar4 < 0xc);
  return;
}


================================================================