FUNCTION FUN_00003c74 @ 0x00003c74 size=132
CALLERS (1): FUN_00003bac@0x00003bac
CALLEES (0): 

undefined4 FUN_00003c74(short param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (DAT_0001617e != 0) {
    iVar1 = 0;
    do {
      iVar1 = DAT_000161a0 + (iVar1 >> 0x10) * 0x30;
      if ((*(short *)(iVar1 + 8) != 0) && (param_1 == *(short *)(iVar1 + 0xc))) {
        return 1;
      }
      iVar2 = iVar2 + 1;
      iVar1 = iVar2 * 0x10000;
    } while (iVar2 * 0x10000 >> 0x10 < (int)(uint)DAT_0001617e);
  }
  return 0;
}


================================================================