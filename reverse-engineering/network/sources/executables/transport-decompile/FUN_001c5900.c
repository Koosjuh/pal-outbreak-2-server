
long FUN_001c5900(undefined8 param_1)

{
  undefined4 uVar1;
  long lVar2;
  int iVar3;
  
  iVar3 = (int)param_1;
  *(undefined4 *)(iVar3 + 0x9c) = 0;
  if (*(int *)(iVar3 + 4) == 0) {
    FUN_00109728(0x361a50,0x248830,uRam0035ba80);
    *(undefined4 *)(iVar3 + 0xa0) = 0x361a50;
  }
  else {
    *(int *)(iVar3 + 0xa0) = *(int *)(iVar3 + 4);
  }
  if (*(int *)(iVar3 + 8) == 0) {
    *(undefined4 *)(iVar3 + 0xd4) = uRam0035ccc8;
  }
  else {
    *(int *)(iVar3 + 0xd4) = *(int *)(iVar3 + 8);
  }
  uVar1 = FUN_0010a050(*(undefined4 *)(iVar3 + 0xa0));
  *(undefined4 *)(iVar3 + 0xa4) = uVar1;
  *(undefined4 *)(iVar3 + 0xe4) = *(undefined4 *)(iVar3 + 0xd4);
  *(undefined4 *)(iVar3 + 0xe8) = 0;
  FUN_001c3c90(param_1,0x26,1,0);
  FUN_001c3ea0(param_1,*(undefined4 *)(iVar3 + 0x9c));
  FUN_001c4020(param_1,*(undefined4 *)(iVar3 + 0xa0));
  **(ushort **)(iVar3 + 0x28) = *(ushort *)(iVar3 + 0x38) << 8 | *(ushort *)(iVar3 + 0x38) >> 8;
  FUN_001ee590(*(undefined4 *)(iVar3 + 0x1c),*(undefined4 *)(iVar3 + 0x28),
               (short)*(undefined4 *)(iVar3 + 0x38) + 8);
  lVar2 = FUN_001c3840(param_1);
  if (-2 < lVar2) {
    lVar2 = 0;
    *(undefined1 *)(iVar3 + 0xd) = 0x20;
  }
  return lVar2;
}

