FUNCTION FUN_005bb670 @ 0x005bb670  size=612
CALLERS (0): 
CALLEES (7): FUN_005c7d00@0x005c7d00, FUN_005bb610@0x005bb610, FUN_005bf1e0@0x005bf1e0, FUN_005bc370@0x005bc370, FUN_005bdfe0@0x005bdfe0, FUN_005c5120@0x005c5120, FUN_005c50a0@0x005c50a0
----------------------------------------------------------------

void FUN_005bb670(undefined8 param_1,int *param_2)

{
  uint uVar1;
  short *psVar2;
  ushort *puVar3;
  int iVar4;
  bool bVar5;
  ushort uVar6;
  int iVar7;
  int iStack_4;
  
  FUN_005c7d00();
  func_0x00106b60(0x6cd672,0,0x114);
  iStack_4 = *param_2;
  FUN_005c50a0(iStack_4,0x6cd672);
  iVar4 = 0;
  if (cRam0070047c == '\0') {
    uRam006cbc84 = 0;
    uRam006cbc7e = 0x10;
    FUN_005bdfe0(0x20);
    uVar1 = FUN_005bf1e0(2);
    iVar4 = (uVar1 & 0xffff) - 1;
    iVar7 = iVar4 * 0x144;
    psVar2 = (short *)(iVar7 + 0x6cfb62);
    *psVar2 = *psVar2 + -1;
    if (*psVar2 < 0) {
      *psVar2 = 0;
    }
    sRam006d2158 = (short)iVar4 + 1;
    sRam006d215a = *psVar2;
    FUN_005bdfe0(0x19);
    if (cRam006ff2b0 != '\0') {
      bVar5 = false;
      for (iVar4 = 0; iVar4 < 4; iVar4 = iVar4 + 1) {
        if (*(int *)(iVar4 * 8 + 0x7006d4) == iStack_4) {
          bVar5 = true;
          *(undefined4 *)(iVar4 * 8 + 0x7006d4) = 0;
          break;
        }
      }
      if (bVar5) {
        puVar3 = (ushort *)(iVar7 + 0x6cfb70);
        uVar6 = *(byte *)puVar3 - 1 & 0xff;
        if (uVar6 == 0) {
          uVar6 = 1;
        }
        *puVar3 = uVar6;
        FUN_005bdfe0(0x21);
        FUN_005bb610(iStack_4,uVar6);
      }
    }
  }
  else {
    iVar7 = 0;
    do {
      iVar7 = (iVar7 - iVar4) * 0x28 + 0x6cdbe6;
      FUN_005c5120(iVar7,&iStack_4);
      if (iStack_4 == *param_2) {
        func_0x0010a4f0(0x6cd672,iVar7,0x10);
        func_0x00106b60(iVar7,0,0x118);
        uRam006cbc84 = 0;
        uRam006cbc7e = 0x10;
        FUN_005bdfe0(0x25);
        uRam006fb746 = FUN_005bc370();
        uRam006cbc7e = 0x10;
        FUN_005bdfe0(0x23);
      }
      iVar4 = iVar4 + 1;
      iVar7 = iVar4 * 8;
    } while (iVar4 < 4);
  }
  return;
}



================================================================