
long FUN_001c8f50(undefined8 param_1)

{
  long lVar1;
  int iVar2;
  undefined1 auStack_100 [256];
  
  FUN_001c3c90(param_1,10,1,0);
  FUN_001c3da0(param_1,1);
  FUN_00106b60(auStack_100,0,0x100);
  FUN_001c3590(0x35ba00,auStack_100,uRam0035b9f0,0xff);
  FUN_001c4020(param_1,auStack_100);
  iVar2 = (int)param_1;
  **(ushort **)(iVar2 + 0x28) = *(ushort *)(iVar2 + 0x38) << 8 | *(ushort *)(iVar2 + 0x38) >> 8;
  FUN_001ee590(*(undefined4 *)(iVar2 + 0x1c),*(undefined4 *)(iVar2 + 0x28),
               (short)*(undefined4 *)(iVar2 + 0x38) + 8);
  lVar1 = FUN_001c3840(param_1);
  if (-2 < lVar1) {
    lVar1 = 0;
    *(undefined1 *)(iVar2 + 0xd) = 0x35;
  }
  return lVar1;
}

