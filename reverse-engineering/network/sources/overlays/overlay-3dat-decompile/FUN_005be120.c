FUNCTION FUN_005be120 @ 0x005be120  size=336
CALLERS (1): FUN_005bdfe0@0x005bdfe0
CALLEES (0): 
----------------------------------------------------------------

int FUN_005be120(undefined4 *param_1,long param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  uStack_10 = *param_1;
  uStack_c = param_1[1];
  uStack_8 = param_1[2];
  if (param_2 == 1) {
    for (iVar2 = 0; iVar2 < 0x80; iVar2 = iVar2 + 1) {
      iVar1 = iVar2 * 0x20;
      if ((sRam006cbc80 == *(short *)(iVar1 + 0x6ca97e)) &&
         (sRam006cbc7c == *(short *)(iVar1 + 0x6ca97c))) {
        *(undefined1 *)(iVar1 + 0x6ca980) = 0;
        *(undefined1 *)(iVar1 + 0x6ca981) = 0;
        *(undefined2 *)(iVar1 + 0x6ca97c) = 0;
        if (*(code **)(iVar1 + 0x6ca96c) == (code *)0x0) {
          return iVar2;
        }
        (**(code **)(iVar1 + 0x6ca96c))(&uStack_10,&uStack_10);
        return iVar2;
      }
    }
    param_3 = -1;
  }
  else if (param_2 == 2) {
    iVar2 = param_3 * 0x20;
    *(undefined1 *)(iVar2 + 0x6ca980) = 0;
    *(undefined1 *)(iVar2 + 0x6ca981) = 0;
    if (*(code **)(iVar2 + 0x6ca96c) != (code *)0x0) {
      (**(code **)(iVar2 + 0x6ca96c))(&uStack_10,&uStack_10);
    }
  }
  else {
    param_3 = -1;
  }
  return param_3;
}



================================================================