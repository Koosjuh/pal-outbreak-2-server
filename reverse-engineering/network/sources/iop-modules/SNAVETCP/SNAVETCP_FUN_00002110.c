FUNCTION FUN_00002110 @ 0x00002110 size=136
CALLERS (1): FUN_00004620@0x00004620
CALLEES (1): FUN_00011d48@0x00011d48

undefined4 FUN_00002110(void)

{
  int iVar1;
  int iVar2;
  
  DAT_00016526 = 0;
  iVar2 = 0;
  if (DAT_0001618c != 0) {
    iVar1 = 0;
    do {
      iVar2 = iVar2 + 1;
      iVar1 = iVar1 >> 0xb;
      (&DAT_000187a0)[iVar1] = 0;
      *(undefined4 *)((int)&DAT_000187ac + iVar1) = 0;
      *(undefined4 *)((int)&DAT_000187a8 + iVar1) = 0;
      iVar1 = iVar2 * 0x10000;
    } while (iVar2 * 0x10000 >> 0x10 < (int)(uint)DAT_0001618c);
  }
  FUN_00011d48(&DAT_00016520,0,6);
  return 0;
}


================================================================