FUNCTION FUN_005c3370 @ 0x005c3370  size=284
CALLERS (0): 
CALLEES (1): FUN_005c7d00@0x005c7d00
----------------------------------------------------------------

void FUN_005c3370(char *param_1,int param_2)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  undefined2 *puVar4;
  undefined2 *puVar5;
  int iVar6;
  int iVar7;
  undefined1 auStack_f0 [220];
  char cStack_14;
  undefined2 auStack_10 [8];
  
  FUN_005c7d00();
  if (*param_1 == '\0') {
    iVar2 = *(int *)(param_2 + 8);
    iVar7 = param_2 + 0xc;
    param_2 = param_2 + 0x24;
    for (iVar6 = 0; iVar6 < iVar2; iVar6 = iVar6 + 1) {
      func_0x001069a8(auStack_f0,param_2,0xf0);
      if (cStack_14 != '\0') {
        puVar5 = auStack_10;
        puVar4 = (undefined2 *)0x7005d0;
        iVar3 = 4;
        do {
          iVar3 = iVar3 + -1;
          uVar1 = puVar5[1];
          *puVar4 = *puVar5;
          puVar5 = puVar5 + 2;
          puVar4[1] = uVar1;
          puVar4 = puVar4 + 2;
        } while (0 < iVar3);
      }
      param_2 = iVar7 + *(int *)(iVar7 + 0x14);
      iVar7 = param_2 + 0x18;
      cRam006ca890 = cRam006ca890 + '\x01';
      param_2 = param_2 + 0x30;
    }
    if ((param_1[1] != '\x01') || (*(short *)(param_1 + 2) == 0)) {
      uRam006cba55 = 1;
    }
  }
  else if (*param_1 == '\'') {
    uRam006cba55 = 2;
  }
  return;
}



================================================================