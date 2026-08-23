
long FUN_001c6dc0(undefined8 param_1)

{
  long lVar1;
  int *piVar2;
  
  uRam00365e10 = 0;
  FUN_001c3c90(param_1,0x1c,1,0);
  piVar2 = (int *)param_1;
  if (*piVar2 == 1) {
    uRam00365e00 = 0;
  }
  FUN_001c3ea0(param_1,uRam00365e00);
  *(ushort *)piVar2[10] = *(ushort *)(piVar2 + 0xe) << 8 | *(ushort *)(piVar2 + 0xe) >> 8;
  FUN_001ee590(piVar2[7],piVar2[10],(short)piVar2[0xe] + 8);
  lVar1 = FUN_001c3840(param_1);
  if (-2 < lVar1) {
    lVar1 = 0;
    *(undefined1 *)((int)piVar2 + 0xd) = 5;
  }
  return lVar1;
}

