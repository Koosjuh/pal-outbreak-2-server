
long FUN_001c6b90(undefined8 param_1)

{
  long lVar1;
  int iVar2;
  
  FUN_001c3c90(param_1,0x47,1,0);
  FUN_001c3da0(param_1,1);
  iVar2 = (int)param_1;
  FUN_001c3ea0(param_1,*(undefined4 *)(iVar2 + 0x48));
  FUN_001c3e10(param_1,iRam0035b7d0 - *(int *)(iVar2 + 0x48) & 0xffff);
  **(ushort **)(iVar2 + 0x28) = *(ushort *)(iVar2 + 0x38) << 8 | *(ushort *)(iVar2 + 0x38) >> 8;
  FUN_001ee590(*(undefined4 *)(iVar2 + 0x1c),*(undefined4 *)(iVar2 + 0x28),
               (short)*(undefined4 *)(iVar2 + 0x38) + 8);
  lVar1 = FUN_001c3840(param_1);
  if (-2 < lVar1) {
    lVar1 = 0;
    *(undefined1 *)(iVar2 + 0xd) = 0x28;
  }
  return lVar1;
}

