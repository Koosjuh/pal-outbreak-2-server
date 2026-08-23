FUNCTION FUN_00004c24 @ 0x00004c24 size=136
CALLERS (1): FUN_00010060@0x00010060
CALLEES (1): FUN_0001168c@0x0001168c

undefined4 FUN_00004c24(short param_1)

{
  short *psVar1;
  int iVar2;
  
  iVar2 = (int)param_1;
  if ((iVar2 < (int)(uint)DAT_0001619d) && (-1 < iVar2)) {
    psVar1 = (short *)(iVar2 * 0x14 + DAT_000161a8);
    if (*psVar1 != 0) {
      FUN_0001168c(iVar2,*(undefined4 *)(psVar1 + 6),1,0xff);
      *(undefined2 *)(iVar2 * 0x14 + DAT_000161a8) = 0;
      return 0;
    }
  }
  return 0xfffffffc;
}


================================================================