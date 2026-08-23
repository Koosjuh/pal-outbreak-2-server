FUNCTION FUN_005bb4d0 @ 0x005bb4d0  size=320
CALLERS (0): 
CALLEES (4): FUN_005c7d00@0x005c7d00, FUN_005bf1e0@0x005bf1e0, FUN_005bdfe0@0x005bdfe0, FUN_005c50a0@0x005c50a0
----------------------------------------------------------------

void FUN_005bb4d0(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  uint uVar2;
  ushort *puVar3;
  
  FUN_005c7d00();
  func_0x00106b60(0x6cd672,0,0x114);
  FUN_005c50a0(*(undefined4 *)((int)param_2 + 0x10),0x6cd672);
  func_0x00106b60(0x6cd682,0,0x10);
  func_0x0010a4f0(0x6cd682,param_2,0x10);
  iVar1 = func_0x001ae3e0(0x6cd682);
  if (*(char *)(iVar1 + 0x6cd681) == '-') {
    *(char *)(iVar1 + 0x6cd681) = '\0';
  }
  func_0x001069a8(0x6cd696,(int)param_2 + 0x18,0xf0);
  uRam006cbc84 = 0;
  uRam006cbc7e = 0x10;
  FUN_005bdfe0(0x1f);
  uVar2 = FUN_005bf1e0(2);
  iVar1 = (uVar2 & 0xffff) - 1;
  puVar3 = (ushort *)(iVar1 * 0x144 + 0x6cfb62);
  *puVar3 = *puVar3 + 1;
  if (4 < *puVar3) {
    *puVar3 = 4;
  }
  sRam006d2158 = (short)iVar1 + 1;
  uRam006d215a = *puVar3;
  FUN_005bdfe0(0x19);
  return;
}



================================================================