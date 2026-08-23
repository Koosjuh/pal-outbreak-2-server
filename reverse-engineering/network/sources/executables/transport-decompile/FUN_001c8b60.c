
long FUN_001c8b60(undefined8 param_1)

{
  long lVar1;
  int iVar2;
  uint uVar3;
  
  FUN_001c3c90(param_1,0x35,1,0);
  FUN_001c3da0(param_1,uRam00365a70);
  FUN_001c3da0(param_1,uRam00365a71);
  FUN_001c3da0(param_1,uRam00365a72);
  FUN_001c4020(param_1,uRam00365a74);
  FUN_001c3da0(param_1,uRam00365a78);
  FUN_001c3da0(param_1,uRam00365a79);
  FUN_001c3ea0(param_1,uRam00365a7c);
  FUN_001c3ea0(param_1,uRam00365a80);
  uVar3 = 0;
  do {
    iVar2 = uVar3 * 8;
    FUN_001c4020(param_1,*(undefined4 *)(iVar2 + 0x365a84));
    FUN_001c3da0(param_1,*(undefined1 *)(iVar2 + 0x365a88));
    FUN_001c3da0(param_1,*(undefined1 *)(iVar2 + 0x365a89));
    uVar3 = uVar3 + 1;
  } while (uVar3 < 3);
  uVar3 = 0;
  do {
    FUN_001c3ea0(param_1,*(undefined4 *)(uVar3 * 4 + 0x365a9c));
    uVar3 = uVar3 + 1;
  } while (uVar3 < 8);
  iVar2 = (int)param_1;
  **(ushort **)(iVar2 + 0x28) = *(ushort *)(iVar2 + 0x38) << 8 | *(ushort *)(iVar2 + 0x38) >> 8;
  FUN_001ee590(*(undefined4 *)(iVar2 + 0x1c),*(undefined4 *)(iVar2 + 0x28),
               (short)*(undefined4 *)(iVar2 + 0x38) + 8);
  lVar1 = FUN_001c3840(param_1);
  if (-2 < lVar1) {
    lVar1 = 0;
    *(undefined1 *)(iVar2 + 0xd) = 0x2e;
  }
  return lVar1;
}

