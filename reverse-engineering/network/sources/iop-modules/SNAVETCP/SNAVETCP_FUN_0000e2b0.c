FUNCTION FUN_0000e2b0 @ 0x0000e2b0 size=84
CALLERS (1): FUN_00000aa0@0x00000aa0
CALLEES (0): 

undefined4 FUN_0000e2b0(void)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  
  DAT_000168e0 = 0;
  iVar3 = 0;
  if (0 < (int)((uint)DAT_00016196 << 0x10)) {
    iVar2 = 0;
    do {
      uVar1 = DAT_00016196;
      iVar3 = iVar3 + 1;
      *(undefined4 *)((int)&DAT_00016190 + iVar2) = 0;
      iVar2 = iVar3 * 4;
    } while (iVar3 < (short)uVar1);
  }
  return 0;
}


================================================================