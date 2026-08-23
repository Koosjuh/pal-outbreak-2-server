FUNCTION FUN_00004a94 @ 0x00004a94 size=212
CALLERS (1): FUN_00004b68@0x00004b68
CALLEES (0): 

undefined4 FUN_00004a94(int param_1,int param_2)

{
  short *psVar1;
  code *pcVar2;
  int iVar3;
  
  if (((*(int *)(param_2 + 4) == *(int *)(param_1 + 0x44)) && (*(char *)(param_2 + 2) == '\x06')) &&
     (*(char *)(param_2 + 1) == '\x01')) {
    iVar3 = *(int *)(param_1 + 8);
    psVar1 = (short *)0x0;
    if (iVar3 != 0) {
      psVar1 = (short *)(iVar3 + 0x88);
    }
    if (*psVar1 == *(short *)(param_2 + 0x1c)) {
      pcVar2 = (code *)0x2;
      if (iVar3 != 0) {
        pcVar2 = (code *)(iVar3 + 0x8a);
      }
      if (*(short *)pcVar2 == *(short *)(param_2 + 0x1e)) {
        psVar1 = (short *)0x4;
        if (iVar3 != 0) {
          psVar1 = (short *)(iVar3 + 0x8c);
        }
        if (*psVar1 == *(short *)(param_2 + 0x20)) {
          return 0;
        }
      }
    }
  }
  return 1;
}


================================================================