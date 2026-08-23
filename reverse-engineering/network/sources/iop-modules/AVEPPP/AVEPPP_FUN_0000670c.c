FUNCTION FUN_0000670c @ 0x0000670c size=176
CALLERS (1): FUN_00006f6c@0x00006f6c
CALLEES (3): FUN_00010c38@0x00010c38, FUN_0000d698@0x0000d698, FUN_00010070@0x00010070

void FUN_0000670c(undefined1 *param_1,uint param_2)

{
  byte bVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0xc);
  FUN_00010070(param_1 + 0x10);
  bVar1 = param_1[2];
  param_1[2] = (char)((uint)bVar1 & ~param_2);
  if (((uint)bVar1 & ~param_2 & 0x10) == 0) {
    if ((DAT_00012efc & 2) != 0) {
      FUN_00010c38("  CHAP: fsm state ==> Opened\n");
    }
    *param_1 = 5;
  }
  bVar1 = *(byte *)(iVar2 + 2) & ~(byte)param_2;
  *(byte *)(iVar2 + 2) = bVar1;
  if (param_2 == 0x10) {
    *(byte *)(iVar2 + 2) = bVar1 & 0xdf;
  }
  FUN_0000d698(iVar2);
  return;
}


================================================================