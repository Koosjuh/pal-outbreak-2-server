
long FUN_001c85c0(undefined8 param_1)

{
  long lVar1;
  int iVar2;
  char cVar3;
  
  uRam00365e1a = 0xc;
  iVar2 = (uint)*(ushort *)(((uint)uRam00365e0c * 0x12 + (uint)uRam00365e0c) * 0x20 + 0x365f78) -
          (uint)uRam00365e18;
  if (iVar2 < 0xc) {
    uRam00365e1a = (ushort)iVar2;
  }
  uRam00365e18 = uRam00365e18 + uRam00365e1a;
  FUN_001c3c90(param_1,0x24,1,0);
  FUN_001c3da0(param_1,(undefined1)uRam00365e1a);
  for (cVar3 = '\0'; (long)cVar3 < (long)(ulong)uRam00365e1a; cVar3 = cVar3 + '\x01') {
    FUN_001c4020(param_1,*(undefined4 *)
                          (((uint)uRam00365e10 + (int)cVar3) * 4 +
                           ((uint)uRam00365e0c * 0x12 + (uint)uRam00365e0c) * 0x20 + 0x365f80));
  }
  FUN_001c4020(param_1,((uint)uRam00365e0c * 0x12 + (uint)uRam00365e0c) * 0x20 + 0x365e20);
  iVar2 = (int)param_1;
  **(ushort **)(iVar2 + 0x28) = *(ushort *)(iVar2 + 0x38) << 8 | *(ushort *)(iVar2 + 0x38) >> 8;
  FUN_001ee590(*(undefined4 *)(iVar2 + 0x1c),*(undefined4 *)(iVar2 + 0x28),
               (short)*(undefined4 *)(iVar2 + 0x38) + 8);
  lVar1 = FUN_001c3840(param_1);
  if (-2 < lVar1) {
    lVar1 = 0;
    *(undefined1 *)(iVar2 + 0xd) = 0xd;
  }
  return lVar1;
}

