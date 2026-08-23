FUNCTION FUN_00008bfc @ 0x00008bfc size=108
CALLERS (1): FUN_00008ddc@0x00008ddc
CALLEES (0): 

int FUN_00008bfc(int param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  piVar1 = &DAT_0000c220;
  iVar3 = 0;
  do {
    if (*piVar1 == -1) {
      *piVar1 = param_1;
      *(undefined4 *)((int)&DAT_0000c340 + iVar3) = param_2;
      DAT_0000c6b0 = DAT_0000c6b0 + 1;
      return iVar2;
    }
    piVar1 = piVar1 + 0x49;
    iVar2 = iVar2 + 1;
    iVar3 = iVar3 + 0x124;
  } while (iVar2 < 4);
  return -1;
}


================================================================