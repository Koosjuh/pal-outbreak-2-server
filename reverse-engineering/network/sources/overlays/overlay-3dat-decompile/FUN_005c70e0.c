FUNCTION FUN_005c70e0 @ 0x005c70e0  size=236
CALLERS (0): 
CALLEES (2): FUN_005bdfe0@0x005bdfe0, FUN_005bf280@0x005bf280
----------------------------------------------------------------

void FUN_005c70e0(char *param_1,int param_2)

{
  int iVar1;
  long lVar2;
  int iVar3;
  int iVar4;
  
  if (*param_1 == '\0') {
    iVar1 = *(int *)(param_2 + 8);
    param_2 = param_2 + 0xc;
    for (iVar4 = 0; iVar4 < iVar1; iVar4 = iVar4 + 1) {
      lVar2 = FUN_005bf280(*(undefined4 *)(param_2 + 0x20));
      if (lVar2 != -1) {
        iVar3 = (int)lVar2 * 0x144;
        *(undefined4 *)((int)lVar2 * 0x24 + 0x6fec18) = *(undefined4 *)(param_2 + 0x10);
        sRam006d2158 = (short)lVar2 + 1;
        *(short *)(iVar3 + 0x6ce5de) = (short)*(undefined4 *)(param_2 + 0x10);
        param_2 = param_2 + 0x24;
        uRam006cbc7e = 0x10;
        uRam006cbc84 = 0;
        uRam006d215a = *(undefined2 *)(iVar3 + 0x6ce5de);
        uRam006d215c = *(undefined2 *)(iVar3 + 0x6ce5e0);
        FUN_005bdfe0(0xf);
      }
    }
  }
  return;
}



================================================================