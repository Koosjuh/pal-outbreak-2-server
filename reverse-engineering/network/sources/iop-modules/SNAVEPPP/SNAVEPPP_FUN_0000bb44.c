FUNCTION FUN_0000bb44 @ 0x0000bb44 size=208
CALLERS (0): 
CALLEES (4): FUN_00010070@0x00010070, FUN_00010c38@0x00010c38, FUN_0000e814@0x0000e814, FUN_0000e904@0x0000e904

void FUN_0000bb44(undefined1 *param_1)

{
  undefined4 uVar1;
  int iVar2;
  short sVar3;
  short sVar4;
  
  iVar2 = *(int *)(param_1 + 0x30);
  sVar4 = 0;
  FUN_0000e904(*(undefined4 *)(iVar2 + 0x98));
  sVar3 = 0;
  *(undefined4 *)(iVar2 + 0x98) = 0;
  if ((*(ushort *)(iVar2 + 0x28) & 4) != 0) {
    sVar4 = *(short *)(iVar2 + 0x36);
  }
  if ((*(ushort *)(iVar2 + 0x74) & 4) != 0) {
    sVar3 = *(short *)(iVar2 + 0x82);
  }
  if ((sVar4 != 0) || (sVar3 != 0)) {
    uVar1 = FUN_0000e814((int)sVar4,(int)sVar3);
    *(undefined4 *)(iVar2 + 0x98) = uVar1;
  }
  FUN_00010070(param_1 + 0x10);
  if ((DAT_00012efc & 2) != 0) {
    FUN_00010c38("  IPCP: fsm state ==> Opened\n");
  }
  *param_1 = 5;
  return;
}


================================================================