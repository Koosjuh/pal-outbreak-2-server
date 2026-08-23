FUNCTION FUN_0000344c @ 0x0000344c size=324
CALLERS (1): FUN_00003590@0x00003590
CALLEES (10): FUN_000036fc@0x000036fc, FUN_00003694@0x00003694, FUN_0000368c@0x0000368c, FUN_00003780@0x00003780, FUN_00003728@0x00003728, FUN_000036c0@0x000036c0, FUN_00003798@0x00003798, FUN_00003704@0x00003704, FUN_00003808@0x00003808, FUN_000037cc@0x000037cc

undefined4 FUN_0000344c(void)

{
  int iVar1;
  char *pcVar2;
  undefined4 local_10 [2];
  
  FUN_0000368c(local_10);
  iVar1 = FUN_000036c0(&DAT_000035d0);
  FUN_00003694(local_10[0]);
  if ((iVar1 == 0) || (iVar1 == -0xd5)) {
    iVar1 = FUN_000036fc(&DAT_0000c5d0,&DAT_0000c5b8);
    pcVar2 = "iop: iopint: RemoveRpc Failed.\n";
    if (iVar1 != 0) {
      iVar1 = FUN_00003704(&DAT_0000c5b8);
      if (iVar1 != 0) {
        FUN_00003798(DAT_0000c614);
        FUN_00003780(DAT_0000c614);
        FUN_00003798(DAT_0000c618);
        FUN_00003780(DAT_0000c618);
        FUN_00003808(DAT_00009464);
        FUN_00003808(DAT_00006b88);
        FUN_00003808(DAT_00009420);
        FUN_00003808(DAT_00008be8);
        FUN_000037cc(DAT_00008bec);
        return 1;
      }
      pcVar2 = "iop: iopint: RemoveRpcQueue Failed.\n";
    }
  }
  else {
    if (iVar1 != -0xd7) {
      return 2;
    }
    pcVar2 = "iop: iopint: library inuse\n";
  }
  FUN_00003728(pcVar2);
  return 2;
}


================================================================