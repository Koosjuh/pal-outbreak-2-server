FUNCTION FUN_005c0ae0 @ 0x005c0ae0  size=580
CALLERS (0): 
CALLEES (4): FUN_005c7d00@0x005c7d00, FUN_005c0dc0@0x005c0dc0, FUN_005bdfe0@0x005bdfe0, FUN_005c50a0@0x005c50a0
----------------------------------------------------------------

void FUN_005c0ae0(char *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  FUN_005c7d00();
  if (*param_1 == '\0') {
    iVar1 = *(int *)(param_2 + 8);
    iVar6 = param_2 + 0xc;
    iVar5 = param_2 + 0x24;
    uRam006cbc84 = 0;
    for (iVar4 = 0; iVar4 < iVar1; iVar4 = iVar4 + 1) {
      FUN_005c50a0(*(undefined4 *)(iVar6 + 0x10),(uint)bRam006ca890 * 0x118 + 0x6cdbe6);
      func_0x00106b60((uint)bRam006ca890 * 0x118 + 0x6cdbf6,0,0x10);
      func_0x0010a4f0((uint)bRam006ca890 * 0x118 + 0x6cdbf6,iVar6,0x10);
      iVar2 = func_0x0010a050((uint)bRam006ca890 * 0x118 + 0x6cdbf6);
      uVar3 = (uint)bRam006ca890;
      iVar2 = uVar3 * 0x118 + 0x6ca950 + iVar2;
      if (*(char *)(iVar2 + 0x32a5) == '-') {
        *(undefined1 *)(iVar2 + 0x32a5) = 0;
      }
      func_0x001069a8(uVar3 * 0x118 + 0x6cdc0a,iVar5,0xf0);
      iVar5 = iVar6 + *(int *)(iVar6 + 0x14);
      iVar6 = iVar5 + 0x18;
      bRam006ca890 = bRam006ca890 + 1;
      iVar5 = iVar5 + 0x30;
    }
    uRam006fb738 = (undefined1)*(undefined4 *)(param_2 + 4);
    if ((param_1[1] == '\x01') && (*(short *)(param_1 + 2) != 0)) {
      return;
    }
  }
  else if (*param_1 == '\'') {
    uRam006cbc84 = 0xff;
  }
  uRam006cbc80 = (undefined2)*(undefined4 *)(param_1 + 0xc);
  uRam006cbc7e = 2;
  uRam006cbc7c = FUN_005c0dc0(0);
  FUN_005bdfe0(0);
  return;
}



================================================================