FUNCTION FUN_00003edc @ 0x00003edc size=92
CALLERS (1): FUN_0000f870@0x0000f870
CALLEES (0): 

undefined4 FUN_00003edc(short param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = (int)param_1;
  if (((iVar1 < (int)(uint)DAT_0001617e) && (-1 < iVar1)) &&
     (iVar1 = iVar1 * 0x30 + DAT_000161a0, *(short *)(iVar1 + 8) != 0)) {
    *(undefined4 *)(iVar1 + 0x28) = param_2;
    return 0;
  }
  return 0xfffffffc;
}


================================================================