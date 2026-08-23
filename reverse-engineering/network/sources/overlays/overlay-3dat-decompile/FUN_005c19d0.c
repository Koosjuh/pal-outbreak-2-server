FUNCTION FUN_005c19d0 @ 0x005c19d0  size=572
CALLERS (0): 
CALLEES (1): FUN_005c7d00@0x005c7d00
----------------------------------------------------------------

void FUN_005c19d0(char *param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  FUN_005c7d00();
  if (*param_1 == '\0') {
    iVar1 = *(int *)(param_2 + 8);
    param_2 = param_2 + 0xc;
    for (iVar5 = 0; iVar5 < iVar1; iVar5 = iVar5 + 1) {
      if (((*(uint *)(param_2 + 0x1c) & 0x40000000) == 0) && (uRam006ca898 < 0x1e)) {
        func_0x00109eb8(uRam006ca898 * 0x24 + 0x6fee6c,param_2);
        uVar2 = uRam006ca898;
        iVar3 = uRam006ca898 * 0x24;
        *(undefined4 *)(iVar3 + 0x6fee8c) = *(undefined4 *)(param_2 + 0x24);
        *(undefined4 *)(iVar3 + 0x6fee7c) = *(undefined4 *)(param_2 + 0x14);
        *(undefined4 *)(iVar3 + 0x6fee88) = *(undefined4 *)(param_2 + 0x20);
        *(undefined4 *)(iVar3 + 0x6fee84) = *(undefined4 *)(param_2 + 0x1c);
        *(undefined4 *)(iVar3 + 0x6fee80) = *(undefined4 *)(param_2 + 0x18);
        if (*(int *)(param_2 + 0x14) == *(int *)(param_2 + 0x20)) {
          *(undefined1 *)(uVar2 * 0x144 + 0x6cfb74) = 4;
        }
        else {
          *(undefined1 *)(uVar2 * 0x144 + 0x6cfb74) = 3;
        }
        iVar3 = uVar2 * 0x144;
        iVar4 = uRam006ca898 * 0x144;
        *(short *)(iVar4 + 0x6cfb60) = (short)uRam006ca898 + 1;
        *(short *)(iVar4 + 0x6cfb66) = (short)*(undefined4 *)(param_2 + 0x20);
        *(short *)(iVar4 + 0x6cfb62) = (short)*(undefined4 *)(param_2 + 0x14);
        *(uint *)(iVar4 + 0x6cfb5c) = *(uint *)(param_2 + 0x1c) >> 1;
        if ((*(uint *)(iVar4 + 0x6cfb5c) & 0x8000) == 0) {
          *(undefined1 *)(iVar3 + 0x6cfb75) = 0;
        }
        else {
          *(undefined1 *)(iVar3 + 0x6cfb75) = 1;
        }
        func_0x00109eb8(iVar3 + 0x6cfb76,param_2);
        uRam006ca898 = uRam006ca898 + 1;
      }
      param_2 = param_2 + 0x28;
    }
    uRam006ce5c2 = 0x1e;
    if ((param_1[1] != '\x01') || (*(short *)(param_1 + 2) == 0)) {
      uRam006cba2d = 1;
    }
  }
  else if (*param_1 == '\'') {
    uRam006cba2d = 2;
  }
  return;
}



================================================================