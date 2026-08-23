FUNCTION FUN_0000dc5c @ 0x0000dc5c size=160
CALLERS (1): FUN_0000e0e0@0x0000e0e0
CALLEES (3): FUN_0000d698@0x0000d698, FUN_00010070@0x00010070, FUN_00010c38@0x00010c38

void FUN_0000dc5c(undefined1 *param_1,byte param_2)

{
  byte bVar1;
  int iVar2;
  
  bVar1 = param_1[2];
  iVar2 = *(int *)(param_1 + 0xc);
  param_1[2] = bVar1 & ~param_2;
  if ((bVar1 & ~param_2 & 0x30) == 0) {
    if ((DAT_00012efc & 2) != 0) {
      FUN_00010c38("  PAP: fsm state ==> Opened\n");
    }
    *param_1 = 5;
  }
  FUN_00010070(param_1 + 0x10);
  *(byte *)(iVar2 + 2) = *(byte *)(iVar2 + 2) & ~param_2;
  FUN_0000d698();
  return;
}


================================================================