FUNCTION FUN_00613f40 @ 0x00613f40  size=112
CALLERS (1): FUN_00613c30@0x00613c30
CALLEES (3): FUN_006146e0@0x006146e0, FUN_0060f830@0x0060f830, FUN_006147a0@0x006147a0
----------------------------------------------------------------

void FUN_00613f40(undefined8 param_1)

{
  short sVar1;
  int iVar2;
  int extraout_a2_lo;
  short *psVar3;
  
  iVar2 = FUN_0060f830(0x653ff0,*(undefined1 *)(iRam0070d1c0 + 0x4e),param_1);
  psVar3 = (short *)(iVar2 + extraout_a2_lo * 8);
  sVar1 = *psVar3;
  if (sVar1 == -1) {
    sVar1 = FUN_006147a0(*(undefined4 *)(psVar3 + 2),0x16);
  }
  FUN_006146e0(sVar1,psVar3[1],*(undefined4 *)(psVar3 + 2));
  return;
}



================================================================