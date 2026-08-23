FUNCTION FUN_005bc430 @ 0x005bc430  size=340
CALLERS (0): 
CALLEES (4): FUN_005c7d00@0x005c7d00, FUN_005bc370@0x005bc370, FUN_005c5120@0x005c5120, FUN_005bdfe0@0x005bdfe0
----------------------------------------------------------------

void FUN_005bc430(undefined8 param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iStack_4;
  
  FUN_005c7d00();
  if (cRam0070047c != '\0') {
    func_0x00106b60(0x6cd672,0,0x114);
    for (iVar3 = 0; iVar3 < 4; iVar3 = iVar3 + 1) {
      iVar2 = iVar3 * 0x118;
      FUN_005c5120(iVar2 + 0x6cdbe6,&iStack_4);
      piVar4 = param_2;
      if (iStack_4 == *param_2) {
        iVar1 = param_2[1];
        piVar4 = param_2 + 2;
        func_0x0010a4f0(0x6cd672,iVar2 + 0x6cdbe6,0x10);
        func_0x0010a4f0(0x6cd682,iVar2 + 0x6cdbf6,0x10);
        func_0x001069a8(0x6cd696,piVar4,iVar1);
        func_0x001069a8(iVar2 + 0x6cdc0a,piVar4,iVar1);
        if (*(char *)((int)param_2 + 0xe5) == '\x01') {
          uRam006cbc84 = 0;
          uRam006cbc7e = 0x10;
          FUN_005bdfe0(0x24);
          uRam006fb746 = FUN_005bc370();
          uRam006cbc7e = 0x10;
          FUN_005bdfe0(0x23);
          return;
        }
      }
      param_2 = piVar4;
    }
  }
  return;
}



================================================================