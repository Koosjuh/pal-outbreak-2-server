
long FUN_001c4c80(undefined8 param_1)

{
  long lVar1;
  int iVar2;
  
  FUN_001c3c90(param_1,0x14,1,0);
  FUN_001c3e10(param_1,uRam00368421);
  FUN_001c3ea0(param_1,uRam00368424);
  FUN_001c3e10(param_1,0x2f2);
  iVar2 = (int)param_1;
  **(ushort **)(iVar2 + 0x28) = *(ushort *)(iVar2 + 0x38) << 8 | *(ushort *)(iVar2 + 0x38) >> 8;
  FUN_001ee590(*(undefined4 *)(iVar2 + 0x1c),*(undefined4 *)(iVar2 + 0x28),
               (short)*(undefined4 *)(iVar2 + 0x38) + 8);
  lVar1 = FUN_001c3840(param_1);
  if (-2 < lVar1) {
    lVar1 = 0;
    *(undefined1 *)(iVar2 + 0xd) = 0x13;
  }
  return lVar1;
}

