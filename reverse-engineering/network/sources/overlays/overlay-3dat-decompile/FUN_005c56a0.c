FUNCTION FUN_005c56a0 @ 0x005c56a0  size=224
CALLERS (0): 
CALLEES (1): FUN_005bdf90@0x005bdf90
----------------------------------------------------------------

void FUN_005c56a0(char *param_1,int *param_2)

{
  int iVar1;
  
  if (*param_1 == '\0') {
    for (iVar1 = 0; iVar1 < 0x1e; iVar1 = iVar1 + 1) {
      if ((*(int *)(iVar1 * 0x24 + 0x6fee8c) == *param_2) && (param_2[1] == 0x53544154)) {
        sRam006d2158 = (short)iVar1 + 1;
        *(int *)(iVar1 * 0x24 + 0x6fee84) = param_2[2];
        *(uint *)(iVar1 * 0x144 + 0x6cfb5c) = (uint)param_2[2] >> 1;
        uRam006cbc7e = 0x10;
        uRam006cbc84 = 0;
        FUN_005bdf90(0x29,0);
        return;
      }
    }
  }
  return;
}



================================================================