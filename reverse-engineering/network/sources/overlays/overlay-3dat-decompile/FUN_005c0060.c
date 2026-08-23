FUNCTION FUN_005c0060 @ 0x005c0060  size=360
CALLERS (0): 
CALLEES (4): FUN_005c7d00@0x005c7d00, FUN_005bf2e0@0x005bf2e0, FUN_005c1e70@0x005c1e70, FUN_005bdfe0@0x005bdfe0
----------------------------------------------------------------

void FUN_005c0060(char *param_1,undefined4 *param_2)

{
  int iVar1;
  long lVar2;
  int iVar3;
  
  FUN_005c7d00();
  if (*param_1 == '\0') {
    uRam006cbc84 = 0;
    lVar2 = FUN_005bf2e0(*param_2);
    if (lVar2 != -1) {
      iVar1 = (int)lVar2;
      iVar3 = iVar1 * 0x24;
      *(undefined4 *)(iVar3 + 0x6fee8c) = *param_2;
      if (param_2[1] == 0x4d415849) {
        *(undefined4 *)(iVar3 + 0x6fee88) = param_2[2];
        *(short *)(iVar1 * 0x144 + 0x6cfb66) = (short)param_2[2];
        *(undefined2 *)(iVar1 * 0x144 + 0x6cfb6c) = 1;
      }
      else {
        if (param_2[1] != 0x55534552) {
          uRam006cbc80 = (undefined2)*(undefined4 *)(param_1 + 0xc);
          goto LAB_005c0188;
        }
        *(undefined4 *)(iVar3 + 0x6fee7c) = param_2[2];
        *(short *)(iVar1 * 0x144 + 0x6cfb62) = (short)param_2[2];
      }
    }
  }
  else if (*param_1 == '\'') {
    uRam006cbc84 = 0xff;
  }
  uRam006cbc80 = (undefined2)*(undefined4 *)(param_1 + 0xc);
LAB_005c0188:
  uRam006cbc7e = 2;
  uRam006cbc7c = FUN_005c1e70(2,0);
  FUN_005bdfe0(0);
  return;
}



================================================================