FUNCTION FUN_00004968 @ 0x00004968 size=92
CALLERS (1): FUN_00004a30@0x00004a30
CALLEES (0): 

undefined4 FUN_00004968(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = (uint)DAT_0001619a;
  iVar3 = 0;
  if (uVar1 != 0) {
    iVar2 = 0;
    do {
      (&DAT_0001835e)[(iVar2 >> 0x10) * 0xe] = 0;
      iVar3 = iVar3 + 1;
      iVar2 = iVar3 * 0x10000;
    } while (iVar3 * 0x10000 >> 0x10 < (int)uVar1);
  }
  return 0;
}


================================================================