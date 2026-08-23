FUNCTION FUN_005c2460 @ 0x005c2460  size=736
CALLERS (0): 
CALLEES (4): FUN_005c7d00@0x005c7d00, FUN_005bdfe0@0x005bdfe0, FUN_005c50a0@0x005c50a0, FUN_005c27d0@0x005c27d0
----------------------------------------------------------------

void FUN_005c2460(char *param_1,int param_2)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  FUN_005c7d00();
  if (*param_1 == '\0') {
    iVar3 = *(int *)(param_2 + 8);
    iVar9 = param_2 + 0xc;
    iVar8 = param_2 + 0x24;
    uRam006cbc84 = 0;
    for (iVar7 = 0; iVar7 < iVar3; iVar7 = iVar7 + 1) {
      FUN_005c50a0(*(undefined4 *)(iVar9 + 0x10),(uint)bRam006ca890 * 0x118 + 0x6cdbe6);
      func_0x00106b60((uint)bRam006ca890 * 0x118 + 0x6cdbf6,0,0x10);
      func_0x0010a4f0((uint)bRam006ca890 * 0x118 + 0x6cdbf6,iVar9,0x10);
      iVar2 = func_0x0010a050((uint)bRam006ca890 * 0x118 + 0x6cdbf6);
      uVar4 = (uint)bRam006ca890;
      iVar2 = uVar4 * 0x118 + 0x6ca950 + iVar2;
      if (*(char *)(iVar2 + 0x32a5) == '-') {
        *(undefined1 *)(iVar2 + 0x32a5) = 0;
      }
      func_0x001069a8(uVar4 * 0x118 + 0x6cdc0a,iVar8,0xf0);
      iVar8 = iVar9 + *(int *)(iVar9 + 0x14);
      iVar9 = iVar8 + 0x18;
      bRam006ca890 = bRam006ca890 + 1;
      iVar8 = iVar8 + 0x30;
    }
    uRam006fb738 = (undefined1)*(undefined4 *)(param_2 + 4);
    if ((param_1[1] == '\x01') && (*(short *)(param_1 + 2) != 0)) {
      return;
    }
  }
  iVar3 = 0;
  iVar7 = 0;
  iVar8 = 0;
  do {
    iVar8 = (iVar8 - iVar7) * 0x28;
    puVar6 = (undefined1 *)(iVar8 + 0x6cdbe6);
    if (*(char *)(iVar8 + 0x6cdce7) == '\x01') {
      iVar8 = 0x8c;
      puVar5 = (undefined1 *)(iVar3 * 0x118 + 0x6ce046);
      do {
        iVar8 = iVar8 + -1;
        uVar1 = puVar6[1];
        *puVar5 = *puVar6;
        puVar6 = puVar6 + 2;
        puVar5[1] = uVar1;
        puVar5 = puVar5 + 2;
      } while (0 < iVar8);
      iVar3 = iVar3 + 1;
    }
    iVar7 = iVar7 + 1;
    iVar8 = iVar7 * 8;
  } while (iVar7 < 4);
  uRam006fb739 = (undefined1)iVar3;
  uRam0070047c = 1;
  uRam006fb746 = (undefined2)iVar3;
  uRam006cbc80 = (undefined2)*(undefined4 *)(param_1 + 0xc);
  uRam006cbc7e = 2;
  uRam006cbc7c = FUN_005c27d0();
  FUN_005bdfe0(0);
  uRam006cbc7e = 0x10;
  FUN_005bdfe0(0x23);
  return;
}



================================================================