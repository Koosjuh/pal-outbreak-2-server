FUNCTION FUN_00004bc8 @ 0x00004bc8 size=92
CALLERS (1): FUN_0000f870@0x0000f870
CALLEES (0): 

undefined4 FUN_00004bc8(short param_1,undefined4 param_2)

{
  short *psVar1;
  int iVar2;
  
  iVar2 = (int)param_1;
  if (((iVar2 < (int)(uint)DAT_0001619d) && (-1 < iVar2)) &&
     (psVar1 = (short *)(iVar2 * 0x14 + DAT_000161a8), *psVar1 != 0)) {
    *(undefined4 *)(psVar1 + 6) = param_2;
    return 0;
  }
  return 0xfffffffc;
}


================================================================